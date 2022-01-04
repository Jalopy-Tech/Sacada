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

#include "showsummarywizardpage.h"

ShowSummaryWizardPage::ShowSummaryWizardPage(QWidget *parent)
    : QWizardPage(parent)
{

    // set up the GUI based on the UI file created by QDesigner (in QCreator suite)
    setupUi(this);


    // set locationsTableWidget widgets to the windows background
    // so as to look read only

    QPalette pal = this->palette();
    pal.setColor(QPalette::Active, QPalette::Base, locationsTableWidget->palette().color(QPalette::Active, QPalette::Window));
    locationsTableWidget->setPalette(pal);


    // style the background of the locations column to the window background
    //   for a read-only look

    QColor color = locationsTableWidget->palette().color(QPalette::Active, QPalette::Base);
    locationsTableWidget->setStyleSheet(locationsTableWidget->styleSheet() + " QLineEdit[readOnly='true'] { background-color: " + color.name(QColor::HexRgb) + "  }");

    //locationsTableWidget->horizontalHeader()->setStyleSheet(locationsTableWidget->styleSheet() + " QLineEdit[readOnly='true'] { background-color: " + color.name(QColor::HexRgb) + "  }");

    // Stretch the first column in locationsTableWidget
    locationsTableWidget->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);

}


void ShowSummaryWizardPage::initializePage()
{

        qobject_cast<ArtWizard *>(wizard())->registerLog(logTextBrowser, logToolButton, showHideLogLabel);

}



void ShowSummaryWizardPage::requestOpenFinalArt()
{

    // emit a request for the contoller to open the art

    ArtWizard *artWizard = qobject_cast<ArtWizard *>(wizard());
    artWizard->emit openFinalArtRequested();

}


void ShowSummaryWizardPage::showSummary(
        const QStringList& locationList,
        const QStringList& relationshipList,
        const QList<bool>& isApprovedList,
        const QList<bool>& isSavedList)
{

    locationsTableWidget->clearContents();
    locationsTableWidget->setRowCount(0);

    QLineEdit *locationLineEdit;

    bool isAllSaved = true;
    int i = 0;
    for (int j = 0; j < locationList.size(); ++j) {

        if (isApprovedList[i]) {

            // insert new row

            locationsTableWidget->insertRow(locationsTableWidget->rowCount());


            // add location checkbox cell

            locationLineEdit = new QLineEdit;
            locationLineEdit->setText(QDir::toNativeSeparators(locationList[i]));
            locationLineEdit->setToolTip(locationList[i]);
            locationLineEdit->setReadOnly(true);
            locationLineEdit->setFrame(false);
            locationsTableWidget->setCellWidget(i, 0, locationLineEdit);


            // add relationship cell

            QTableWidgetItem *relationshipItem = new QTableWidgetItem(QTableWidgetItem::Type);
            relationshipItem->setText(relationshipList[i]);
            locationsTableWidget->setItem(i, 1, relationshipItem);


            // add saved status cell

            QTableWidgetItem *savedStatusItem = new QTableWidgetItem(QTableWidgetItem::Type);

            if (isSavedList[i]) {
                savedStatusItem->setIcon(wizard()->style()->standardPixmap(QStyle::SP_DialogYesButton).scaledToHeight(20, Qt::FastTransformation));
                savedStatusItem->setText("saved");
            } else {
                savedStatusItem->setIcon(wizard()->style()->standardPixmap(QStyle::SP_DialogNoButton).scaledToHeight(20, Qt::FastTransformation));
                savedStatusItem->setText("not saved");
                isAllSaved = false;
            }

            locationsTableWidget->setItem(i, 2, savedStatusItem);


            i++;
        } //if
    } //for

    // display save result in form

    if (isAllSaved) {
        artSavedPixmapLabel->setPixmap(wizard()->style()->standardPixmap( \
                                       QStyle::SP_DialogYesButton).scaledToHeight(20, Qt::FastTransformation));
        artSavedResultsLabel->setText("The art was saved successfully.");
    } else {
        artSavedPixmapLabel->setPixmap(wizard()->style()->standardPixmap( \
                                       QStyle::SP_DialogNoButton).scaledToHeight(20, Qt::FastTransformation));
        artSavedResultsLabel->setText("There were errors when saving the art.");
    }


}
