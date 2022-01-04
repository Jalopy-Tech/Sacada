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

#include "enterdetailswizardpage.h"


EnterDetailsWizardPage::EnterDetailsWizardPage(QWidget *parent)
    : QWizardPage(parent)
{

    // set up the GUI based on the UI file created by QDesigner (in QCreator suite)
    setupUi(this);
 

    // register the fields to allow the whole wizard and controller to access them easily

    registerField("albumArtist*",albumArtistLineEdit);
    registerField("album*",albumLineEdit);
    registerField("size",sizeSpinBox);
    registerField("sacadCommandText*",sacadCommandLineEdit);


} 

void EnterDetailsWizardPage::initializePage()
{
    ArtWizard::setForegroundToBackground(sacadCommandLineEdit);
    sacadCommandLineEdit->setText("sacad.exe");

    qobject_cast<ArtWizard *>(wizard())->registerLog(logTextBrowser, logToolButton, showHideLogLabel);


    versionLabel->setText( "Version " + QCoreApplication::applicationVersion());


    albumArtistLineEdit->setFocus();

}

bool EnterDetailsWizardPage::validatePage()
{

    // emit a signal to allow the controller to validate and update the art model

    ArtWizard *artWizard = qobject_cast<ArtWizard *>(wizard());
    artWizard->emit artDetailsUpdated(field("albumArtist").toString(), field("album").toString(), field("size").toInt());
    return true;



}

