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

   This is the abstract view class. All concrete views extend from this class.
   Each view has a presenter to carry out the view presentation logic.
*/

#ifndef VIEW_H
#define VIEW_H


#include <QObject>
#include <QTimer>
#include <QThread>

class Presenter;

class View : public QObject
{
    Q_OBJECT


public:
    explicit View(QObject *parent = nullptr);
    ~View();

    virtual int exec() = 0;
    void setExecutable(bool isExecutable);
    bool executable();

    virtual void showError(const QString& msg) = 0;
    virtual void showInformation(const QString& msg) = 0;

    virtual void    setAlbumDetails(const QString& albumArtist,
                                    const QString& album,
                                    int size,
                                    const QString& finalPath) = 0;

    virtual void setSacadCommand(const QString& sacadComamnd) = 0;
    virtual QString sacadCommand() = 0;

    virtual void setSacadCommandOptionsList(const QStringList& sacadComamndOptionsList) = 0;
    virtual QStringList sacadCommandOptionsList() = 0;


    virtual void    appendLog(const QString& logText) = 0;

    virtual QString getFindArtProcessCommand(const QString& applicationFilePath) = 0;
    virtual void    startProgress() = 0;
    virtual void    updateProgress(int progress, const QString& logText) = 0;

    virtual void    showAlbumDetails(bool isArtFound,
                                     bool isSearchStarted,
                                     const QString& albumDetailsText,
                                     const QString& tempPath) = 0;
    virtual void    showLocations(const QStringList& locationList,
                                  const QStringList& locationRelationshipList,
                                  const QList<bool>& hasExistingArt) = 0;
    virtual void    showSummary(const QStringList& list,
                                const QStringList& relationshipList,
                                const QList<bool>& isApprovedList,
                                const QList<bool>& isSavedList) = 0;


signals:
    void            artDetailsUpdated(const QString& albumArtist, const QString& album, int size);
    bool            finalPathUpdated(const QString& finalPath);
    void            saveArtRequested(const QList<bool>& isApprovedList);
    void            openTempArtRequested();
    void            openFinalArtRequested();
    void            setLocationsRequested();
    void            findArtRequested();
    void            findArtFinished();


protected:
    Presenter *presenter = NULL;

private:
    bool _isExecutable = true;
};


#endif

