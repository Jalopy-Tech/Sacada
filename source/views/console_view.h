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


   ------------------------------------------------------------------------------------

   This class extends the abstract View class to create a concrete view
   for a console interface. It has a presenter to carry out the view presentation
   logic.
*/

#ifndef CONSOLE_VIEW_H
#define CONSOLE_VIEW_H

#include "view.h"
#include "presenter.h"
#include "windows_console_fix.h"

#include <QObject>
#include <QTimer>
#include <QThread>
#include <QTextStream>
#include <QEventLoop>
#include <QFileInfo>



class Presenter;


class ConsoleView : public View
{
    Q_OBJECT


public:
    explicit ConsoleView(QObject *parent = nullptr);
    ~ConsoleView();
    int exec() override;

    void showError(const QString& msg) override;
    void showInformation(const QString& msg) override;

    void            setAlbumDetails(const QString& albumArtist,
                                    const QString& album,
                                    int size,
                                    const QString& finalPath) override;

    void setSacadCommand(const QString& sacadCommand) override;
    QString sacadCommand() override;

    void setSacadCommandOptionsList(const QStringList& sacadCommandOptionsList) override;
    QStringList sacadCommandOptionsList() override;

    void            appendLog(const QString& logText) override;


    QString         getFindArtProcessCommand(const QString& applicationFilePath) override;
    void            startProgress() override;
    void            updateProgress(int progress, const QString& logText) override;

    void            showAlbumDetails(bool isArtFound,
                                     bool isSearchStarted,
                                     const QString& albumDetailsText,
                                     const QString& tempPath) override;
    void            showLocations(const QStringList& locationList,
                                  const QStringList& locationRelationshipList,
                                  const QList<bool>& hasExistingArtList) override;
    void            showSummary(const QStringList& list,
                                const QStringList& relationshipList,
                                const QList<bool>& isApprovedList,
                                const QList<bool>& isSavedList) override;

private:

    QString         _albumArtist;
    QString         _album;
    int             _size;
    QString         _finalPath;

    QString _sacadCommand;
    QStringList _sacadCommandOptionsList;

    QStringList     _artPathList;
    QStringList     _artRelationshipList;
    QList<bool>     _artHasExistingArtList;

    bool            _isArtFound;

    QTimer         findArtTimer;
    const int      findArtTimeLimit = 10000;

};



#endif

