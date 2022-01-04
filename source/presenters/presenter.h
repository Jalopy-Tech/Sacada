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

    The Presenter carries out tasks requested by the view.It uses view independent logic:
    both Views use this same Presenter. The View signals to the Presenter when a task is
    needed and the Presenter calls View methods to provide the results.
*/

#ifndef PRESENTER_H
#define PRESENTER_H

#include "art.h"
#include "view.h"

#include <QApplication>
#include <QDebug>
#include <QCommandLineParser>
#include <QProcess>
#include <QTemporaryDir>
#include <QFile>
#include <QDesktopServices>
#include <QUrl>
#include <QRegExp>



class Presenter : public QObject
{
    Q_OBJECT

public:
    explicit       Presenter(View* view, QObject *parent = nullptr);


    View           *view;


signals:
	void           findArtFinished();

public slots:
    void           handleFindArtStarted();
    void           handleFindArtReadReady();
    void           handleFindArtErrorOccurred(QProcess::ProcessError error);
    void           handleFindArtFinished(int exitCode, QProcess::ExitStatus exitStatus); 
    void           handleFindArtProgressed(int progress, const QString& progressText);

    void           handleUpdateArtDetails(const QString& albumArtist, const QString& album, int size);
    void           handleSetFinalPath(const QString& finalPath);

    void           findArt();
    void           setLocations();
    void           saveArt(const QList<bool>& isApprovedList);
	void           openTempArt();
	void           openFinalArt();



private:

    Art            art;

    bool           hasNoGui;


    QString        sacadCommand;
    QStringList    sacadCommandOptionsList;
    QProcess       findArtProcess;

    QTemporaryDir  tempDir;
    int            progress;

    bool           fileExists(const QString& path);
};

#endif
