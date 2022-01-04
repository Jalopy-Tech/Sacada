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

#include "gui_view.h"


GuiView::GuiView(QObject *parent)
    : View(parent)
{

    #ifdef Q_OS_LINUX
    QApplication::setWindowIcon(QIcon(":images/sacada.png"));
    #endif

     #ifdef Q_OS_WIN32
    QApplication::setWindowIcon(QIcon(":images/sacada.png"));
    #endif

     #ifdef Q_OS_MACX
     QApplication::setWindowIcon(QIcon(":images/sacada.icns"));
     #endif

    connect(&artWizard, &ArtWizard::saveArtRequested, this, &GuiView::saveArtRequested);
    connect(&artWizard, &ArtWizard::artDetailsUpdated, this, &GuiView::artDetailsUpdated);
    connect(&artWizard, &ArtWizard::finalPathUpdated, this, &GuiView::finalPathUpdated);
    connect(&artWizard, &ArtWizard::findArtRequested, this, &GuiView::findArtRequested);
    connect(&artWizard, &ArtWizard::setLocationsRequested, this, &GuiView::setLocationsRequested);
    connect(&artWizard, &ArtWizard::openTempArtRequested, this, &GuiView::openTempArtRequested);
    connect(&artWizard, &ArtWizard::openFinalArtRequested, this, &GuiView::openFinalArtRequested);

    artWizard.show();
    presenter = new Presenter(this);
}

GuiView::~GuiView()
{
    delete (presenter);
}


int GuiView::exec()
{
    if (!executable())
        return 1;

        return qApp->exec();
}


void GuiView::showError(const QString& msg)
{
    QMessageBox::warning(&artWizard,"Error", msg);
}

void GuiView::showInformation(const QString& msg)
{
    QMessageBox::information(&artWizard,"Information", msg);
}

void GuiView::setAlbumDetails(const QString& albumArtist,
                              const QString& album,
                              int size,
                              const QString& finalPath)
{

    // set the GUI fields using the art members

    artWizard.setField("albumArtist",albumArtist);
    artWizard.setField("album",album);
    artWizard.setField("size",size);
    artWizard.setField("finalPath",QDir::toNativeSeparators(finalPath));
}

void GuiView::setSacadCommand(const QString& sacadCommand) {
    _sacadCommand = sacadCommand;
    showSacadCommand();

}

void GuiView::showSacadCommand() {

    QString sacadCommandText = "";

    sacadCommandText += QDir::toNativeSeparators(_sacadCommand);
    // add the user-requested sacad arguments

    for (int i = 0; i < _sacadCommandOptionsList.size(); ++i)
        sacadCommandText += " " + _sacadCommandOptionsList.at(i);

    artWizard.setField("sacadCommandText", sacadCommandText);
}
QString GuiView::sacadCommand() { return _sacadCommand; }

void GuiView::setSacadCommandOptionsList(const QStringList& sacadCommandOptionsList) {
    _sacadCommandOptionsList = sacadCommandOptionsList;
    showSacadCommand();
}

QStringList GuiView::sacadCommandOptionsList() { return _sacadCommandOptionsList; }

void GuiView::appendLog(const QString& logText)
{

    for (int i = 0; i < artWizard.logTextBrowserList.size(); ++i)
        artWizard.logTextBrowserList[i]->append(logText);
}



QString GuiView::getFindArtProcessCommand(const QString& applicationFilePath)
{
    QString findArtProcessCommand;

    QString msg = QString("") + \
        "The SACAD command executable file cannot be found. SACAD must be installed correctly." + \
        "\n\nThis error won't occur if the SACAD command executable file is in the current PATH or the current folder." + \
        " Alternatively, the path to the executable can be specified using the command line option:\n --sacad-command ""<PATH>"". " + \
        "\n\nWould you like to choose the location of the SACAD command executable file now?";

    QMessageBox::StandardButton reply = QMessageBox::question(&artWizard, "Error: SACAD command not found", msg, QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes){
        QFileDialog dialog(&artWizard, "Select SACAD command executable file");
        dialog.setFileMode(QFileDialog::ExistingFile);
        dialog.setLabelText(QFileDialog::Accept,"Select");
        dialog.setFilter(QDir::Executable);

        bool isFinished = false;
        while  (not(isFinished)) {
            isFinished = true;
            if (dialog.exec())
                findArtProcessCommand = dialog.selectedFiles()[0];

            if (findArtProcessCommand == applicationFilePath) {
                isFinished = false;
                QString msg = QString("") + \
                    "The SACAD command executable file cannot be this application. Please choose again...";


                showError(msg);
                findArtProcessCommand = "";
            }

          } // while


    } else
        findArtProcessCommand = "";

    return findArtProcessCommand;



}


void GuiView::startProgress()
{
    // defer starting the GUI log to the wizard page

    qobject_cast<FindWizardPage *>(artWizard.page(artWizard.pageIdFindWizardPage))->startProgress();
}

void GuiView::updateProgress(int progress, const QString& logText)
{
    // defer updating the GUI log to the wizard page

    qobject_cast<FindWizardPage *>(artWizard.page(artWizard.pageIdFindWizardPage))->updateProgress(progress, logText);
}



void GuiView::showAlbumDetails(bool isArtFound,
                               bool isSearchFinished,
                               const QString& albumDetailsText,
                               const QString& path)
{
    // defer updating the page GUI to the wizard page
    qobject_cast<FindWizardPage *>(artWizard.page(artWizard.pageIdFindWizardPage))-> \
    showAlbumDetails(isArtFound, isSearchFinished, albumDetailsText, path);
}

void GuiView::showLocations(const QStringList& list,
                            const QStringList& relationshipList,
                            const QList<bool>& hasExistingArtList)
{
    // defer updating the page GUI to the wizard page
    qobject_cast<SaveWizardPage *>(artWizard.page(artWizard.pageIdSaveWizardPage))-> \
    showLocations(list, relationshipList, hasExistingArtList);
}


void GuiView::showSummary(const QStringList& list,
                          const QStringList& relationshipList,
                          const QList<bool>& isApprovedList,
                          const QList<bool>& isSavedList)
{
    // defer updating the page GUI to the wizard page
    qobject_cast<ShowSummaryWizardPage *>(artWizard.page(artWizard.pageIdShowSummaryWizardPage))-> \
    showSummary(list, relationshipList, isApprovedList, isSavedList);
}


