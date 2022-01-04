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


#include "findwizardpage.h"


FindWizardPage::FindWizardPage(QWidget *parent)
    : QWizardPage(parent)
{
    // set up the GUI based on the UI file created by QDesigner (in QCreator suite)

    setupUi(this);


    // connect up GUI buttons on page

    connect(openArtImagePushButton, &QPushButton::clicked, this, &FindWizardPage::requestOpenTempArt);


    // register and hide the hidden checkbox. This field is used to stop the wizardpage
    // from conitnuing (next) without the final art path being set.

    registerField("artFound*", artFoundHiddenCheckBox);
    artFoundHiddenCheckBox->hide();
}


void FindWizardPage::initializePage()
{
    // initialize the GUI including the log and image to get ready for finding art

    artFoundPixmapLabel->setPixmap(QPixmap());
    albumDetailsLabel->setText("");
    logLabel->setText("");

    qobject_cast<ArtWizard *>(wizard())->registerLog(logTextBrowser, logToolButton, showHideLogLabel);
}

bool FindWizardPage::validatePage()
{


    return true;
}

void FindWizardPage::showAlbumDetails(bool isArtFound, bool isSearchFinished, const QString& albumDetailsText, const QString& path)
{
    // sets the results of trying to find art. This includes the art image found

    setField("artFound", isArtFound);
    albumDetailsLabel->setText(albumDetailsText);

    if (isSearchFinished) {
        if (isArtFound) {
            artFoundPixmapLabel->setPixmap(wizard()->style()->standardPixmap( \
                                           QStyle::SP_DialogYesButton).scaledToHeight(20, Qt::FastTransformation));

            QPixmap pixmap(path);
            artImageLabel->setPixmap(pixmap);
            artImageLabel->show();

        } else {
            artFoundPixmapLabel->setPixmap(wizard()->style()->standardPixmap( \
                                           QStyle::SP_DialogNoButton).scaledToHeight(20, Qt::FastTransformation));
            if (!artImageLabel->pixmap().isNull())
                artImageLabel->setPixmap(QPixmap());
        }
    } else {

        artFoundPixmapLabel->setPixmap(QPixmap());
        if (!artImageLabel->pixmap().isNull())
            artImageLabel->setPixmap(QPixmap());
    }
}

void FindWizardPage::startProgress()
{
    // set the log to its starting values ready for a new search for art

    progressBar->setValue(0);
    setField("artFound", false);
}

void FindWizardPage::updateProgress(int progress, const QString& logText)
{

    // update the progress based on incoming info

    progressBar->setValue(progress);
    logLabel->setText(logText);
}



void FindWizardPage::requestOpenTempArt()
{
    // request the controller to open the art

    qobject_cast<ArtWizard *>(wizard())->emit openTempArtRequested();
}
