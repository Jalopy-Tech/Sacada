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


#ifndef SHOWSUMMARYWIZARDPAGE_H
#define SHOWSUMMARYWIZARDPAGE_H

#include "ui_showsummarywizardpage.h"
#include "artwizard.h"


#include <QStyle>


class ShowSummaryWizardPage : public QWizardPage, private Ui::ShowSummaryWizardPage
{
	Q_OBJECT


public:
	explicit 		ShowSummaryWizardPage(QWidget *parent = nullptr);

    void            showSummary(const QStringList& list,
                                const QStringList& relationshipList,
                                const QList<bool>& isApprovedList,
                                const QList<bool>& isSavedList);
    
private slots:


	void 			requestOpenFinalArt();

private:
	void 			initializePage();


};



#endif
