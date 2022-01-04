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


#include "savewizardpage.h"

SaveWizardPage::SaveWizardPage(QWidget *parent)
	: QWizardPage(parent)
{
	// set up the GUI based on the UI file created by QDesigner (in QCreator suite)

	setupUi(this);

    // register the fields to allow the whole wizard and controller to access them easily

    registerField("finalPath*", finalPathLineEdit);

    registerField("isFinalPathValid*", isFinalPathValidCheckBox);
    isFinalPathValidCheckBox->setVisible(false);

    // connect the button to open the art

    connect(browsePushButton, &QPushButton::clicked, this, &SaveWizardPage::setFinalPath);


    // setup the radio and check boxes

    discSubfolderInformationLabel->hide();

    connect(discSubfolderInformationPushButton, &QPushButton::clicked, this,
            &SaveWizardPage::showDiscSubfolderInformation);

    // set finalPathLineEdit and locationsTableWidget widgets to the windows background
    // so as to look read only

    ArtWizard::setForegroundToBackground(finalPathLineEdit);

    QPalette pal = finalPathLineEdit->palette();
    pal = locationsTableWidget->palette();
    pal.setColor(QPalette::Active, QPalette::Base, locationsTableWidget->palette().color(QPalette::Active, QPalette::Window));
    locationsTableWidget->setPalette(pal);


    // style the background of the locations column to the window background
    //   for a read-only look.

    QColor color = locationsTableWidget->palette().color(QPalette::Active, QPalette::Base);
    locationsTableWidget->setStyleSheet(locationsTableWidget->styleSheet() + " QLineEdit[readOnly='true'] { background-color: " + color.name(QColor::HexRgb) + "  }");

   // locationsTableWidget->horizontalHeader()->setStyleSheet(locationsTableWidget->styleSheet() + " QLineEdit[readOnly='true'] { background-color: " + color.name(QColor::HexRgb) + "  }");

    // indent the locationsTableWidget checkbox column slightly with padding

    locationsTableWidget->setStyleSheet(locationsTableWidget->styleSheet() + " QCheckBox { padding: 10px  }");


    // Stretch the first column in locationsTableWidget

    locationsTableWidget->horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents);
    locationsTableWidget->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);


	// set the page to commit page - the user can't go back after this page.

	setCommitPage(true);

}

void SaveWizardPage::initializePage()
{

    qobject_cast<ArtWizard *>(wizard())->registerLog(logTextBrowser, logToolButton, showHideLogLabel);

    // emit a request for the contoller to update the art path and save the art

    ArtWizard *artWizard = qobject_cast<ArtWizard *>(wizard());

    artWizard->emit finalPathUpdated(field("finalPath").toString());

    artWizard->emit setLocationsRequested();

    finalPathLineEdit->setToolTip(finalPathLineEdit->text());


}

void SaveWizardPage::setValid() {
    bool isValid = false;
    QCheckBox *locationCheckBox;

    for (int i = 0; i < locationsTableWidget->rowCount(); ++i) {
        locationCheckBox = qobject_cast<QCheckBox *>(locationsTableWidget->cellWidget(i,0));
        if (locationCheckBox->checkState() == Qt::Checked)
            isValid = true;
    }

    setField("isFinalPathValid",isValid);
}

bool SaveWizardPage::validatePage()
{


    // emit a request for the contoller to copy the art to disc subfolders

	QList<bool> isApprovedList;

    QCheckBox *locationCheckBox;

    for (int i = 0; i < locationsTableWidget->rowCount(); ++i) {
        locationCheckBox = qobject_cast<QCheckBox *>(locationsTableWidget->cellWidget(i,0));
        isApprovedList << (locationCheckBox->checkState() == Qt::Checked);
    }
	ArtWizard *artWizard = qobject_cast<ArtWizard *>(wizard());

    artWizard->emit setLocationsRequested();


    // emit a request for the contoller to update the art path and save the art

    artWizard->emit finalPathUpdated(field("finalPath").toString());

    artWizard->emit saveArtRequested(isApprovedList);

	return true;
}

void SaveWizardPage::showLocations(const QStringList& locationList, const QStringList& relationshipList, const QList<bool>& hasExistingArtList)
{

    //Qt::ItemFlags flags;
	locationsTableWidget->clearContents();
	locationsTableWidget->setRowCount(0);

    QCheckBox *saveArtCheckBox;
    QLineEdit *locationLineEdit;

	for (int i = 0; i < locationList.size(); ++i) {

        // insert new row

        locationsTableWidget->insertRow(locationsTableWidget->rowCount());


        // add save art check box

        saveArtCheckBox = new QCheckBox;
        saveArtCheckBox->setCheckState(Qt::Checked);
        locationsTableWidget->setCellWidget(i, 0, saveArtCheckBox);
        connect(saveArtCheckBox, &QCheckBox::clicked, this, &SaveWizardPage::setValid);

        // add location checkbox cell

        locationLineEdit = new QLineEdit;
        locationLineEdit->setText(QDir::toNativeSeparators(locationList[i]));
        locationLineEdit->setToolTip(locationList[i]);
        locationLineEdit->setReadOnly(true);
        locationLineEdit->setFrame(false);
        locationsTableWidget->setCellWidget(i, 1, locationLineEdit);


        // add relationship cell

        QTableWidgetItem *relationshipItem = new QTableWidgetItem(QTableWidgetItem::Type);
		relationshipItem->setFlags(Qt::ItemIsEnabled);
		relationshipItem->setText(relationshipList[i]);
        locationsTableWidget->setItem(i, 2, relationshipItem);


        // add existing art cell

        QTableWidgetItem *hasExistingArtItem = new QTableWidgetItem(QTableWidgetItem::Type);
		if (hasExistingArtList[i]) {
            hasExistingArtItem->setText("art exists");
		}
		else {
            hasExistingArtItem->setText("");
		}
        locationsTableWidget->setItem(i, 3, hasExistingArtItem);

    } //for

    setValid();
}



void SaveWizardPage::setFinalPath()
{

    QString fileName = QFileDialog::getSaveFileName(this, "Save Album Art", \
                       QDir::toNativeSeparators(finalPathLineEdit->text()));



    if (fileName != "") {
        finalPathLineEdit->setText(QDir::toNativeSeparators(fileName));
        finalPathLineEdit->setToolTip(finalPathLineEdit->text());

        // emit a request for the contoller to update the art path and save the art

        ArtWizard *artWizard = qobject_cast<ArtWizard *>(wizard());

        artWizard->emit finalPathUpdated(field("finalPath").toString());

        artWizard->emit setLocationsRequested();
     }


}

void SaveWizardPage::showFinalPath()
{



}



void SaveWizardPage::showDiscSubfolderInformation()
{
    // display extra info which is contained in hidden field in the UI file created with QDesigner

    QMessageBox::information(this, "Disc Subfolder Information", \
                             discSubfolderInformationLabel->text());
}
