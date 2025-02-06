/*
    Copyright (C) 2020 Robert J. Joynt.

    This software uses the QT (https://www.qt.io/) GPLv3 Open Source License
    (https://doc.qt.io/qt-5/gpl.html).

    This software is distributed under the GNU General Public License Version 3.

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
    (https://www.gnu.org/licenses/).
*/

#include "presenter.h"

Presenter::Presenter(View *view, QObject *parent)
    : QObject(parent)
{
    this->view = view;

    art.setTempPath(tempDir.filePath("cover.jpg"));
    
    // setup coonnections with slots to handle running an external process

    connect(&findArtProcess, &QProcess::started, this, &Presenter::handleFindArtStarted);
    connect(&findArtProcess, &QProcess::readyRead, this, &Presenter::handleFindArtReadReady);
    connect(&findArtProcess, &QProcess::errorOccurred, this, &Presenter::handleFindArtErrorOccurred);
    connect(&findArtProcess, QOverload<int, QProcess::ExitStatus>::of(&QProcess::finished), \
            [=](int exitCode, QProcess::ExitStatus exitStatus) { handleFindArtFinished(exitCode, exitStatus); });


    // connect signals in preparation for the find art process

    connect(view, &View::saveArtRequested, this, &Presenter::saveArt);
    connect(view, &View::artDetailsUpdated, this, &Presenter::handleUpdateArtDetails);
    connect(view, &View::finalPathUpdated, this, &Presenter::handleSetFinalPath);
    connect(view, &View::findArtRequested, this, &Presenter::findArt);
    connect(view, &View::setLocationsRequested, this, &Presenter::setLocations);
    connect(view, &View::openTempArtRequested, this, &Presenter::openTempArt);
    connect(view, &View::openFinalArtRequested, this, &Presenter::openFinalArt);

    connect(this, &Presenter::findArtFinished, view, &View::findArtFinished);

}


void Presenter::findArt()
{
    QString appName = qApp->applicationName();
    QFileInfo appFile(appName);
    appName = appFile.fileName();
    if (appName.isEmpty())
        appName = qApp->applicationName();
    view->appendLog(appName.toUpper() + " Log");
    view->startProgress();
    
    art.deleteLocations();

    // Construct the external command line to find art.

    QString        findArtProcessCommand;
    QStringList    findArtProcessArguments;

    findArtProcessCommand = QDir::toNativeSeparators(view->sacadCommand());

    // add the user-requested sacad arguments specified in the command line

    for (int i = 0; i < view->sacadCommandOptionsList().size(); ++i)
        findArtProcessArguments << view->sacadCommandOptionsList().at(i);

    // add the standard album details arguments

    findArtProcessArguments << art.getAlbumArtist() << art.getAlbum() << QString::number(art.getSize()) << QDir::toNativeSeparators(art.getTempPath());
    view->appendLog("Command to find art:");
    view->appendLog(findArtProcessCommand + " \"" + findArtProcessArguments.join("\" \"") + "\"");
    progress = 0;

    // Set both stdout and stderr to the one output.

    findArtProcess.setProcessChannelMode(QProcess::MergedChannels);

    // Remove any pre-exisiting temporary art.

    if (QFile::exists(art.getTempPath())) {
        if (!QFile::remove(art.getTempPath())) {
            handleFindArtProgressed(progress, "Error: cannot delete temporary file: " + QDir::toNativeSeparators(art.getTempPath()));
        }
    }

    // Start the process. The rest will be covered by slots listening for signals from the process.


    findArtProcess.start(findArtProcessCommand, findArtProcessArguments);

}

void Presenter::handleFindArtStarted()
{

    QString msg = "Searching for \"" + art.getAlbumArtist() + "\" album \"" + art.getAlbum() + "\"...";
    view->appendLog(msg);
    if (!hasNoGui)
        view->showAlbumDetails(false, false, msg, "");


    handleFindArtProgressed(progress, "Search started...");
}

void Presenter::handleFindArtReadReady()
{
    // Read the next line of outut from the process and sebd out a signal with the line data.

    char buf[1024];
    qint64 lineLength = findArtProcess.readLine(buf, sizeof(buf));
    if (lineLength != -1) {

        if (progress < 80)
            progress += 5;
        else if (progress < 89)
            progress += 1;

        QString progressText = buf;
        progressText = progressText.simplified();

        // Send out signals to any listeners (such as a controller) about the state of the process

        handleFindArtProgressed(progress, progressText);
    }
}

void Presenter::handleFindArtErrorOccurred(QProcess::ProcessError error)
{
    QString msg = "";
    if (error == QProcess::FailedToStart)
        msg = QString("") + \
                "The SACAD command failed to start.";
    else  msg = QString("") + \
            "An error occurred when running the SACAD command.";

    msg = msg + "\n\nPlease check if SACAD has been installed properly.";
    view->showError(msg);

    emit findArtFinished();
}

void Presenter::handleFindArtFinished(int exitCode, QProcess::ExitStatus exitStatus)
{

    if (exitStatus == QProcess::NormalExit && exitCode == 0) {
        // Check for any final output before finishing up

        handleFindArtReadReady();


        // Send out signals to any listeners (such as a controller) about the state of the process

        progress = 100;

        if (QFile::exists(art.getTempPath())) {
            handleFindArtProgressed(progress, "Search finished: album art found.");
            QString msg = "Album art found for \"" + art.getAlbumArtist() + "\" album \"" + art.getAlbum() + "\".";
            view->showAlbumDetails(true, true, msg, art.getTempPath());
        } else {
            handleFindArtProgressed(progress, "Search finished: no album art found.");
            QString msg = "No album art for \"" + art.getAlbumArtist() + "\" album \"" + art.getAlbum() + "\".";
            view->showAlbumDetails(false, true, msg, "");
        }
    }


    emit findArtFinished();
}



void Presenter::handleFindArtProgressed(int progress, const QString& progressText)
{

    view->updateProgress(progress, progressText);
    view->appendLog(progressText);

}





void Presenter::handleUpdateArtDetails(const QString& albumArtist, const QString& album, int size)
{

    art.updateArtDetails(albumArtist, album, size);
}


void Presenter::handleSetFinalPath(const QString& finalPath)
{
    // set the final art path

    art.setFinalPath(finalPath);
}

bool Presenter::fileExists(const QString& path) {
    return QFileInfo::exists(path) && QFileInfo(path).isFile();
}

void Presenter::setLocations()
{


    // If the path does not include a filename, then add one by default

    QString finalPath = art.getFinalPath();



    if (QFileInfo::exists(finalPath) && not(QFileInfo(finalPath).isFile())) {
        finalPath = finalPath + "/" + "cover.jpg";
    }

    art.setFinalPath(QFileInfo(finalPath).QFileInfo::absoluteFilePath());

    // Delete (clear out) previous locations
    art.deleteLocations();

    QString path = art.getFinalPath();

    art.addLocation(path,"self", fileExists(path));


    QFileInfo finalArtFile(art.getFinalPath());
    QString finalArtDirPath = finalArtFile.absolutePath();
    QString finalArtFileName = finalArtFile.fileName();

    QDir finalArtDir(finalArtDirPath);
    QString finalArtDirName = finalArtDir.dirName();

    finalArtDir.setFilter(QDir::Dirs);
    QStringList filters;
    QString pattern = "*[dD][iI][sS][cCkK]*[0-9]*";

    filters << pattern;

    finalArtDir.setNameFilters(filters);
    finalArtDir.setSorting(QDir::Name);

    QFileInfoList discChildDirsInfoList =  finalArtDir.entryInfoList();

    for (int i = 0; i < discChildDirsInfoList.size(); ++i) {
        QString path = discChildDirsInfoList[i].absoluteFilePath() + "/" + finalArtFileName;
        art.addLocation(path,"child",fileExists(path));
    }

    QRegExp rx(pattern);
    rx.setPatternSyntax(QRegExp::Wildcard);
    bool isMatch = rx.exactMatch(finalArtDirName);
    if (isMatch) {
        if (finalArtDir.cdUp()) {
            QString finalArtParentDirName = finalArtDir.absolutePath();
            QString path = finalArtDir.absolutePath() + "/" + finalArtFileName;
            art.addLocation(path,"parent",fileExists(path));

            QFileInfoList discSiblingDirsInfoList =  finalArtDir.entryInfoList();

            for (int i = 0; i < discSiblingDirsInfoList.size(); ++i) {
                QString path = discSiblingDirsInfoList[i].absoluteFilePath() + "/" + finalArtFileName;
                QString finalPath = art.getFinalPath();
                if (path != finalPath)
                    art.addLocation(path,"sibling",fileExists(path));
            }
        }
    }

    view->showLocations(art.pathList(), art.relationshipList(),art.hasExistingArtList());
}


void Presenter::saveArt(const QList<bool>& isApprovedList)
{


    for (int i = 0; i < art.locationCount(); ++i) {
        // run the saveArt function to save the art to the final art path
        Location *location = art.location(i);

        location->setIsApproved(isApprovedList[i]);
        if (isApprovedList[i]) {

            bool errorFlag = false;
            location->setIsProcessed(true);

            
            // First remove any pre-existing final art

            if (QFile::exists(location->getPath())) {

                errorFlag = !(QFile::remove(location->getPath()));
                if (errorFlag) {
                    QString msg = QString("") + \
                            "The existing album art cannot be removed. Check the " + \
                            "permissions of the file or try to remove it manually." + \
                            "\n\nThe file is: " + location->getPath();

                    view->showError(msg);

                }
            }

            // Copy the temporary art to the final art path

            if (!errorFlag) {
                view->appendLog("Copying art from " + QDir::toNativeSeparators(art.getTempPath()) + " to " + QDir::toNativeSeparators(location->getPath()));
                errorFlag = !(QFile::copy(art.getTempPath(), location->getPath()));

                if (errorFlag) {
                    QString msg = QString("") + "The album art cannot be saved. Check the " + \
                            " permissions of the folder." + \
                            "\n\nThe destination path is: " + QDir::toNativeSeparators(location->getPath()) + \
                            "\n\nThe source file is: " + QDir::toNativeSeparators(art.getTempPath());

                    view->showError(msg);
                }
            }

            if (!errorFlag) {
                if (hasNoGui)
                    QTextStream(stdout) << "Album art copied to " + location->getPath() <<
                                           " successfully." << "\n";

            }

            location->setIsSaved(!errorFlag);
        }
    }

    view->showSummary(art.pathList(), art.relationshipList(), art.isApprovedList(), art.isSavedList());
}


void Presenter::openTempArt()
{

    // open the art in the operating systems default application

  QDesktopServices::openUrl(QUrl::fromLocalFile(art.getTempPath()));


}

void Presenter::openFinalArt()
{

    // open the art in the operating systems default application

    QDesktopServices::openUrl(QUrl::fromLocalFile(art.getFinalPath()));
}



