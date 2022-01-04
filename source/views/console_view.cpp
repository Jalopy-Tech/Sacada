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

#include "console_view.h"


ConsoleView::ConsoleView(QObject *parent)
    : View(parent)
{
    // Fix for Windows console issue with GUI and console in one application
    // Inert to non-windows platforms
    WindowsConsoleFix::initialize();

    presenter = new Presenter(this);
}

ConsoleView::~ConsoleView()
{
    delete (presenter);
    // Fix for Windows console issue with GUI and console in one application
    // Inert to non-windows platforms
    WindowsConsoleFix::finalize();
}

int ConsoleView::exec()
{

    if (!executable())
        return 1;

    // Fix for Windows console issue with GUI and console in one application
    // Inert to non-windows platforms
    //WindowsConsoleFix::initialize();

    int returnCode = 0;
    bool fBreak = false;

   // If artist or album is not set, display error and break

    if (!fBreak) {

        if (_albumArtist.isEmpty()) {
            printf ("The album artist is required. It can be specified using the -a or --artist option.\n");
            fBreak = true;
            returnCode = 1;
        }

        if (_album.isEmpty()) {
           printf ("The album is required. It can be specified using the -l or --album option.\n");
           fBreak = true;
           returnCode = 1;
        }
    }

    // update art details

    if (!fBreak)
        emit artDetailsUpdated(_albumArtist, _album, _size);

    // if final path is not set, display error and break

    if (!fBreak && _finalPath.isEmpty()) {
       printf ("The path to save the album art image is required. It can be specified using the -i or --image.\n");
       fBreak = true;
       returnCode = 1;
    }

    // update final path

    if (!fBreak)
        emit finalPathUpdated(_finalPath);

    // Find art.

     if (!fBreak) {
        _isArtFound = false;
        emit findArtRequested();

        // Use an event loop with a signal to wait for the find art to finish.
        QEventLoop loop;

        connect(this, &ConsoleView::findArtFinished, &loop, &QEventLoop::quit);
        connect(&findArtTimer, &QTimer::timeout, &loop, &QEventLoop::quit);

        findArtTimer.setSingleShot(true);
        findArtTimer.start(findArtTimeLimit);
        loop.exec();

        if(!findArtTimer.isActive()) {
            showError("Error: Searching for art timed out.\n");
            fBreak = true;
            returnCode = 1;
        } else if (_isArtFound) {
            emit setLocationsRequested();
            QList<bool> isApprovedList;

            for (int i = 0; i < _artPathList.size(); ++i)
                isApprovedList << true;

            emit saveArtRequested(isApprovedList);
        }
    }

    // Fix for Windows console issue with GUI and console in one application
    // Inert to non-windows platforms
   // WindowsConsoleFix::finalize();

    return returnCode;
}


void ConsoleView::setAlbumDetails(const QString& albumArtist,
                                  const QString& album,
                                  int size,
                                  const QString& finalPath)
{
    _albumArtist = albumArtist;
    _album = album;
    _size = size;
    _finalPath = finalPath;
}

void ConsoleView::setSacadCommand(const QString& sacadCommand) { _sacadCommand = sacadCommand; }

QString ConsoleView::sacadCommand() { return _sacadCommand; }

void ConsoleView::setSacadCommandOptionsList(const QStringList& sacadCommandOptionsList) {
    _sacadCommandOptionsList = sacadCommandOptionsList; }

QStringList ConsoleView::sacadCommandOptionsList() { return _sacadCommandOptionsList; }

void ConsoleView::appendLog(const QString& logText)
{
    QTextStream(stdout) << logText + "\n";
}

void ConsoleView::showError(const QString& msg)
{
    QTextStream(stderr) << "Error: " + msg << "\n";
}

void ConsoleView::showInformation(const QString& msg)
{
    QTextStream(stdout) << msg << "\n";
}

QString ConsoleView::getFindArtProcessCommand(const QString& applicationFilePath)
{

    QString findArtProcessCommand;

    QString msg = QString("\n") + \
        "The SACAD command executable file cannot be found. SACAD must be installed correctly." + \
        "\n\nThis error won't occur if the SACAD command executable file is in the current PATH or the current folder." + \
        " Alternatively, the path to the executable can be specified using the command line option:\n --sacad-command ""<PATH>"".\n";
    QTextStream(stdout) << msg;

    // Get input for executable until no error

    bool isFinished = false;
    while  (not(isFinished)) {
        isFinished = true;
        msg =  "\nPlease enter the path to the SACAD command executable file (ENTER to cancel):\n";
        QTextStream(stdout) << msg;

        findArtProcessCommand = QTextStream(stdin).readLine();

        // check if input was empty

        if (not(findArtProcessCommand.isEmpty())) {

            // check if executable file exists

            QFileInfo findArtProcessCommandFile(findArtProcessCommand);

            if (not(QFileInfo::exists(findArtProcessCommand)) || \
               (not(QFileInfo(findArtProcessCommand).isFile()))) {
                isFinished = false;
                QString msg = QString("") + \
                    "This file does not exist. Please choose again...";
                 showError(msg);
                 findArtProcessCommand = "";
            }
            // check if excutable file is this application

            else if (findArtProcessCommandFile.absoluteFilePath() == applicationFilePath) {
                isFinished = false;
                QString msg = QString("") + \
                    "The SACAD command executable file cannot be this application. Please choose again...";
                showError(msg);
                findArtProcessCommand = "";
            } //else if
        } //if
      } // while

    return findArtProcessCommand;

}

void ConsoleView::startProgress()
{
    QTextStream(stdout) <<  "Progress: 0%" << "\r";
    QTextStream(stdout).flush();

}

void ConsoleView::updateProgress(int progress, const QString& logText)
{
    findArtTimer.start(findArtTimeLimit);
    QTextStream(stdout) <<  "Progress: " << progress << "%" << "\r";
    QTextStream(stdout).flush();

}


void ConsoleView::showAlbumDetails(bool isArtFound,
                                   bool isSearchFinished,
                                   const QString& albumDetailsText,
                                   const QString& path)
{
    _isArtFound = isArtFound;
    QTextStream(stdout) << albumDetailsText << "\n";
}

void ConsoleView::showLocations(const QStringList& list,
                                const QStringList& relationshipList,
                                const QList<bool>& hasExistingArtList)
{

    _artPathList = list;
    _artRelationshipList = relationshipList;
    _artHasExistingArtList = hasExistingArtList;
    QTextStream(stdout) << "\n" << "The art will be copied to the folllowing location(s):" << "\n";
    for (int i = 0; i < _artPathList.size(); ++i)
        QTextStream(stdout) << _artPathList[i] << "\n";


}


void ConsoleView::showSummary(const QStringList& list,
                              const QStringList& relationshipList,
                              const QList<bool>& isApprovedList,
                              const QList<bool>& isSavedList)
{


}



