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

#include "artwizard.h"


ArtWizard::ArtWizard(QWidget *parent)
    : QWizard(parent)
{

    // set up the GUI based on the UI file created by QDesigner (in QCreator suite)

    setupUi(this);


    // connect a slot to handle page changes

    connect(this, &ArtWizard::currentIdChanged, this, &ArtWizard::handlePageChanged);
    connect(this, &ArtWizard::helpRequested, this, &ArtWizard::help);


    // add all the wizard pages to the wizard

    pageIdEnterDetailsWizardPage = addPage(new EnterDetailsWizardPage);
    pageIdFindWizardPage = addPage(new FindWizardPage);
    pageIdSaveWizardPage = addPage(new SaveWizardPage);
    pageIdShowSummaryWizardPage = addPage(new ShowSummaryWizardPage);

    recentPage = pageIdEnterDetailsWizardPage;

    // Add 75 pixels to the wizard height if it is macOS. This is a fudge as macOS has
    // a large margin at the bottom of the wizard page. Needa to be fixed properly some time.

    #ifdef Q_OS_MACX
    setGeometry(x(),y(),width(),height() + 75);
    #endif
    originalHeight = height();


    hideLog();
}

void ArtWizard::handlePageChanged(int newID) {

     
    if (newID == pageIdFindWizardPage && \
        recentPage == pageIdEnterDetailsWizardPage)
        emit findArtRequested();

    recentPage = newID;
}

void ArtWizard::help() {
    QString link = "https://github.com/Jalopy-Tech/Sacada/blob/master/Sacada.md";
    QDesktopServices::openUrl(QUrl(link));
}

void ArtWizard::registerLog(QTextBrowser *textBrowser, QToolButton *toolButton, QLabel *label)
{
    logTextBrowserList << textBrowser;
    logToolButtonList << toolButton;
    showHideLogLabelList << label;

    if (logTextBrowserHeight == 0)
        logTextBrowserHeight = textBrowser->height();

    textBrowser->setPlainText(logTextBrowserList[0]->toPlainText());

    connect(toolButton, &QPushButton::clicked, this, &ArtWizard::toggleShowOrHideLog);

    if (isVisibleLog)
        showLog();
    else
        hideLog();
}

void ArtWizard::hideLog()
{
    // hide the log and set the window size to the orginal (non-expanded) size

    isVisibleLog = false;
    resize(width(), originalHeight);

    for (int i = 0; i < logTextBrowserList.size(); ++i) {
        logTextBrowserList[i]->hide();
        logToolButtonList[i]->setArrowType(Qt::RightArrow);
        showHideLogLabelList[i]->setText("View log");
    }
}

void ArtWizard::showLog()
{
    // show the log and set the window size to an expanded size

    isVisibleLog = true;
    int newHeight = originalHeight + logTextBrowserHeight + 20;
    if (newHeight > height())
        resize(width(), newHeight);

    for (int i = 0; i < logTextBrowserList.size(); ++i) {
        logToolButtonList[i]->setArrowType(Qt::DownArrow);
        showHideLogLabelList[i]->setText("Hide log");
        logTextBrowserList[i]->show();
    }

}

void ArtWizard::toggleShowOrHideLog()
{
    if (isVisibleLog)
        hideLog();
    else
        showLog();
}

void ArtWizard::setForegroundToBackground(QWidget *widget) {
    QPalette pal = widget->palette();
    pal.setColor(QPalette::Active, QPalette::Base, widget->palette().color(QPalette::Active, QPalette::Window));
    widget->setPalette(pal);
}



