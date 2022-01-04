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

   This class extends QWizard for the wizard of the appliciation. It uses the
   designer wizard form created using QT Designer.
*/


#ifndef ARTWIZARD_H
#define ARTWIZARD_H


#include "ui_artwizard.h"
#include "enterdetailswizardpage.h"
#include "findwizardpage.h"
#include "savewizardpage.h"
#include "showsummarywizardpage.h"

#include <QFileDialog>
#include <QMessageBox>
#include <QDesktopServices>
#include <QDebug>

#include <QPointer>
#include <QTextBrowser>
#include <QToolButton>
#include <QLabel>
#include <QWidget>



class ArtWizard : public QWizard, private Ui::ArtWizard
{
    Q_OBJECT

public:
          
    explicit        ArtWizard(QWidget *parent = nullptr);

    void            registerLog(QTextBrowser *textBrowser,
                                QToolButton *toolButton,
                                QLabel *label);
    void            showLog();
    void            hideLog();
    void            appendLog(const QString& logText);

    void            startProgress();
    void            updateProgress(int progress, const QString& logText);

    void static setForegroundToBackground(QWidget *widget);


    int             pageIdEnterDetailsWizardPage;
    int             pageIdFindWizardPage;
    int             pageIdSetLocationsWizardPage;
    int             pageIdSaveWizardPage;
    int             pageIdShowSummaryWizardPage;

    QList<QPointer<QTextBrowser>>
                    logTextBrowserList;
    QList<QPointer<QToolButton>>
                    logToolButtonList;
    QList<QPointer<QLabel>>
                    showHideLogLabelList;

signals:
    bool            artDetailsUpdated(const QString& albumArtist,
                                      const QString& album,
                                      int size);

    bool            finalPathUpdated(const QString& finalPath);
    void            findArtRequested();
    void            saveArtRequested(const QList<bool>& isApprovedList);
    void            openTempArtRequested();
    void            openFinalArtRequested();
    void            setLocationsRequested();

public slots:
    void            toggleShowOrHideLog();




private slots:
    void            handlePageChanged(int newID);
    void help();

private:

    void            resizeButtonBoxButtons(); 
    void            showDiscSubfolderInformation();


    int             originalHeight;
    bool            isVisibleLog;

 

    QString         logText;

    int             recentPage;
    int             logTextBrowserHeight = 0;


};

#endif

