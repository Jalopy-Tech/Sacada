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

#ifndef SAVEWIZARDPAGE_H
#define SAVEWIZARDPAGE_H


#include "ui_savewizardpage.h"
#include "artwizard.h"


class SaveWizardPage : public QWizardPage, private Ui::SaveWizardPage
{
	Q_OBJECT


public:
	explicit 		SaveWizardPage(QWidget *parent = nullptr);


    void 			showLocations(const QStringList& locationList, const QStringList& locationRelationshipList,  const QList<bool>& doesArtAlreadyExistList);
    void 			showSummary(const QStringList& list, const QStringList& relationshipList, const QList<bool>& isSavedList);

private slots:
    void 			setFinalPath();
    void 			showDiscSubfolderInformation();
    void setValid();
private:
	void 			initializePage();
    bool 			validatePage();
    void 			showFinalPath();


};

#endif
