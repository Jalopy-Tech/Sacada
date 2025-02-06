/********************************************************************************
** Form generated from reading UI file 'savewizardpage.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SAVEWIZARDPAGE_H
#define UI_SAVEWIZARDPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWizardPage>

QT_BEGIN_NAMESPACE

class Ui_SaveWizardPage
{
public:
    QTableWidget *locationsTableWidget;
    QLabel *showHideLogLabel;
    QToolButton *logToolButton;
    QTextBrowser *logTextBrowser;
    QPushButton *browsePushButton;
    QLabel *saveToLabel;
    QLineEdit *finalPathLineEdit;
    QLabel *discSubfolderInformationLabel;
    QPushButton *discSubfolderInformationPushButton;
    QCheckBox *isFinalPathValidCheckBox;

    void setupUi(QWizardPage *SaveWizardPage)
    {
        if (SaveWizardPage->objectName().isEmpty())
            SaveWizardPage->setObjectName("SaveWizardPage");
        SaveWizardPage->resize(835, 460);
        locationsTableWidget = new QTableWidget(SaveWizardPage);
        if (locationsTableWidget->columnCount() < 4)
            locationsTableWidget->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setTextAlignment(Qt::AlignLeading|Qt::AlignVCenter);
        locationsTableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setTextAlignment(Qt::AlignLeading|Qt::AlignVCenter);
        locationsTableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setTextAlignment(Qt::AlignLeading|Qt::AlignVCenter);
        locationsTableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        __qtablewidgetitem3->setTextAlignment(Qt::AlignLeading|Qt::AlignVCenter);
        locationsTableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        locationsTableWidget->setObjectName("locationsTableWidget");
        locationsTableWidget->setGeometry(QRect(20, 50, 800, 141));
        locationsTableWidget->setFocusPolicy(Qt::TabFocus);
        locationsTableWidget->setSelectionMode(QAbstractItemView::NoSelection);
        locationsTableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        locationsTableWidget->setWordWrap(false);
        locationsTableWidget->horizontalHeader()->setVisible(false);
        locationsTableWidget->horizontalHeader()->setCascadingSectionResizes(true);
        locationsTableWidget->horizontalHeader()->setMinimumSectionSize(30);
        locationsTableWidget->horizontalHeader()->setStretchLastSection(false);
        locationsTableWidget->verticalHeader()->setVisible(false);
        locationsTableWidget->verticalHeader()->setMinimumSectionSize(34);
        locationsTableWidget->verticalHeader()->setDefaultSectionSize(34);
        locationsTableWidget->verticalHeader()->setHighlightSections(false);
        showHideLogLabel = new QLabel(SaveWizardPage);
        showHideLogLabel->setObjectName("showHideLogLabel");
        showHideLogLabel->setGeometry(QRect(70, 200, 161, 28));
        logToolButton = new QToolButton(SaveWizardPage);
        logToolButton->setObjectName("logToolButton");
        logToolButton->setGeometry(QRect(20, 200, 34, 34));
        logToolButton->setFocusPolicy(Qt::StrongFocus);
        logToolButton->setArrowType(Qt::RightArrow);
        logTextBrowser = new QTextBrowser(SaveWizardPage);
        logTextBrowser->setObjectName("logTextBrowser");
        logTextBrowser->setEnabled(true);
        logTextBrowser->setGeometry(QRect(20, 240, 800, 200));
        QSizePolicy sizePolicy(QSizePolicy::Policy::MinimumExpanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(logTextBrowser->sizePolicy().hasHeightForWidth());
        logTextBrowser->setSizePolicy(sizePolicy);
        logTextBrowser->setFocusPolicy(Qt::StrongFocus);
        browsePushButton = new QPushButton(SaveWizardPage);
        browsePushButton->setObjectName("browsePushButton");
        browsePushButton->setGeometry(QRect(720, 5, 100, 35));
        saveToLabel = new QLabel(SaveWizardPage);
        saveToLabel->setObjectName("saveToLabel");
        saveToLabel->setGeometry(QRect(20, 10, 91, 28));
        finalPathLineEdit = new QLineEdit(SaveWizardPage);
        finalPathLineEdit->setObjectName("finalPathLineEdit");
        finalPathLineEdit->setGeometry(QRect(110, 10, 591, 28));
        finalPathLineEdit->setFocusPolicy(Qt::TabFocus);
        finalPathLineEdit->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        finalPathLineEdit->setReadOnly(true);
        discSubfolderInformationLabel = new QLabel(SaveWizardPage);
        discSubfolderInformationLabel->setObjectName("discSubfolderInformationLabel");
        discSubfolderInformationLabel->setGeometry(QRect(320, 200, 171, 21));
        discSubfolderInformationLabel->setFrameShape(QFrame::NoFrame);
        discSubfolderInformationLabel->setWordWrap(true);
        discSubfolderInformationPushButton = new QPushButton(SaveWizardPage);
        discSubfolderInformationPushButton->setObjectName("discSubfolderInformationPushButton");
        discSubfolderInformationPushButton->setGeometry(QRect(640, 200, 181, 35));
        isFinalPathValidCheckBox = new QCheckBox(SaveWizardPage);
        isFinalPathValidCheckBox->setObjectName("isFinalPathValidCheckBox");
        isFinalPathValidCheckBox->setEnabled(true);
        isFinalPathValidCheckBox->setGeometry(QRect(180, 200, 101, 23));
        isFinalPathValidCheckBox->setFocusPolicy(Qt::NoFocus);
        isFinalPathValidCheckBox->setChecked(false);
        QWidget::setTabOrder(browsePushButton, discSubfolderInformationPushButton);
        QWidget::setTabOrder(discSubfolderInformationPushButton, logToolButton);
        QWidget::setTabOrder(logToolButton, logTextBrowser);
        QWidget::setTabOrder(logTextBrowser, finalPathLineEdit);

        retranslateUi(SaveWizardPage);

        QMetaObject::connectSlotsByName(SaveWizardPage);
    } // setupUi

    void retranslateUi(QWizardPage *SaveWizardPage)
    {
        SaveWizardPage->setWindowTitle(QCoreApplication::translate("SaveWizardPage", "WizardPage", nullptr));
        SaveWizardPage->setTitle(QCoreApplication::translate("SaveWizardPage", "Save Art", nullptr));
        SaveWizardPage->setSubTitle(QCoreApplication::translate("SaveWizardPage", "The folder(s) to save the album art are displayed. Click commit to save the album art.", nullptr));
        QTableWidgetItem *___qtablewidgetitem = locationsTableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("SaveWizardPage", "Save", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = locationsTableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("SaveWizardPage", "Location", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = locationsTableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("SaveWizardPage", "Relationship", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = locationsTableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("SaveWizardPage", "Existing Art", nullptr));
        showHideLogLabel->setText(QCoreApplication::translate("SaveWizardPage", "View log", nullptr));
        logToolButton->setText(QString());
        browsePushButton->setText(QCoreApplication::translate("SaveWizardPage", "Browse", nullptr));
        saveToLabel->setText(QCoreApplication::translate("SaveWizardPage", "Save to:", nullptr));
        discSubfolderInformationLabel->setText(QCoreApplication::translate("SaveWizardPage", "Albums with multiple discs may be stored in multiple disc folders. This option will check if the folder containing the album art has other disc folders. It will also check if this folder is, itself, a disc folder. The album art can then be copied into each of the other folders upon confirmation. Confirmation for each disc folder found can be done in the next step.", nullptr));
        discSubfolderInformationPushButton->setText(QCoreApplication::translate("SaveWizardPage", "More &Information", nullptr));
        isFinalPathValidCheckBox->setText(QCoreApplication::translate("SaveWizardPage", "CheckBox", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SaveWizardPage: public Ui_SaveWizardPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SAVEWIZARDPAGE_H
