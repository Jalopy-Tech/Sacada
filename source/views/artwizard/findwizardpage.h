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

   This class extends QWizardPage for the wizard of the appliciation. It uses the
   designer wizard page form created using QT Designer.
*/

#ifndef FINDWIZARDPAGE_H
#define FINDWIZARDPAGE_H


#include "ui_findwizardpage.h"
#include "artwizard.h"


#include <QStyle>
#include <QTextBrowser>


class FindWizardPage : public QWizardPage, private Ui::FindWizardPage
{
    Q_OBJECT


public:
    explicit 		FindWizardPage(QWidget *parent = nullptr);

    void 			startProgress();
    void 			updateProgress(int progress, const QString& logText);
    void 			showAlbumDetails(bool isArtFound, bool isSearchFinished, const QString& albumDetailsText, const QString& path);


private slots:
    void 			requestOpenTempArt();


private:
    void 			initializePage();
    bool 			validatePage();
    QString 		getArtTempPath();
    QString 		artTempPath;

};

#endif
