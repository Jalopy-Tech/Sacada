/********************************************************************************
** Form generated from reading UI file 'showsummarywizardpage.ui'
**
** Created by: Qt User Interface Compiler version 6.2.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHOWSUMMARYWIZARDPAGE_H
#define UI_SHOWSUMMARYWIZARDPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWizardPage>

QT_BEGIN_NAMESPACE

class Ui_ShowSummaryWizardPage
{
public:
    QLabel *artSavedPixmapLabel;
    QLabel *artSavedResultsLabel;
    QLabel *showHideLogLabel;
    QToolButton *logToolButton;
    QTextBrowser *logTextBrowser;
    QTableWidget *locationsTableWidget;

    void setupUi(QWizardPage *ShowSummaryWizardPage)
    {
        if (ShowSummaryWizardPage->objectName().isEmpty())
            ShowSummaryWizardPage->setObjectName(QString::fromUtf8("ShowSummaryWizardPage"));
        ShowSummaryWizardPage->resize(835, 515);
        artSavedPixmapLabel = new QLabel(ShowSummaryWizardPage);
        artSavedPixmapLabel->setObjectName(QString::fromUtf8("artSavedPixmapLabel"));
        artSavedPixmapLabel->setGeometry(QRect(30, 10, 51, 51));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(artSavedPixmapLabel->sizePolicy().hasHeightForWidth());
        artSavedPixmapLabel->setSizePolicy(sizePolicy);
        artSavedPixmapLabel->setAlignment(Qt::AlignCenter);
        artSavedResultsLabel = new QLabel(ShowSummaryWizardPage);
        artSavedResultsLabel->setObjectName(QString::fromUtf8("artSavedResultsLabel"));
        artSavedResultsLabel->setGeometry(QRect(100, 20, 521, 28));
        QFont font;
        font.setBold(true);
        artSavedResultsLabel->setFont(font);
        showHideLogLabel = new QLabel(ShowSummaryWizardPage);
        showHideLogLabel->setObjectName(QString::fromUtf8("showHideLogLabel"));
        showHideLogLabel->setGeometry(QRect(70, 210, 161, 28));
        logToolButton = new QToolButton(ShowSummaryWizardPage);
        logToolButton->setObjectName(QString::fromUtf8("logToolButton"));
        logToolButton->setGeometry(QRect(20, 200, 34, 34));
        logToolButton->setFocusPolicy(Qt::StrongFocus);
        logToolButton->setArrowType(Qt::RightArrow);
        logTextBrowser = new QTextBrowser(ShowSummaryWizardPage);
        logTextBrowser->setObjectName(QString::fromUtf8("logTextBrowser"));
        logTextBrowser->setEnabled(true);
        logTextBrowser->setGeometry(QRect(20, 240, 800, 260));
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(logTextBrowser->sizePolicy().hasHeightForWidth());
        logTextBrowser->setSizePolicy(sizePolicy1);
        locationsTableWidget = new QTableWidget(ShowSummaryWizardPage);
        if (locationsTableWidget->columnCount() < 3)
            locationsTableWidget->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        locationsTableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        locationsTableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        locationsTableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        locationsTableWidget->setObjectName(QString::fromUtf8("locationsTableWidget"));
        locationsTableWidget->setGeometry(QRect(20, 60, 800, 131));
        locationsTableWidget->setFocusPolicy(Qt::TabFocus);
        locationsTableWidget->setSelectionMode(QAbstractItemView::NoSelection);
        locationsTableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        locationsTableWidget->setWordWrap(false);
        locationsTableWidget->horizontalHeader()->setVisible(false);
        locationsTableWidget->horizontalHeader()->setCascadingSectionResizes(true);
        locationsTableWidget->horizontalHeader()->setStretchLastSection(false);
        locationsTableWidget->verticalHeader()->setVisible(false);
        locationsTableWidget->verticalHeader()->setMinimumSectionSize(34);
        locationsTableWidget->verticalHeader()->setDefaultSectionSize(34);
        locationsTableWidget->verticalHeader()->setHighlightSections(false);

        retranslateUi(ShowSummaryWizardPage);

        QMetaObject::connectSlotsByName(ShowSummaryWizardPage);
    } // setupUi

    void retranslateUi(QWizardPage *ShowSummaryWizardPage)
    {
        ShowSummaryWizardPage->setWindowTitle(QCoreApplication::translate("ShowSummaryWizardPage", "WizardPage", nullptr));
        ShowSummaryWizardPage->setTitle(QCoreApplication::translate("ShowSummaryWizardPage", "Summary of Art Saved", nullptr));
        ShowSummaryWizardPage->setSubTitle(QCoreApplication::translate("ShowSummaryWizardPage", "The table shows the art that has been saved. Click finish to finish.", nullptr));
        artSavedPixmapLabel->setText(QCoreApplication::translate("ShowSummaryWizardPage", "TextLabel", nullptr));
        artSavedResultsLabel->setText(QCoreApplication::translate("ShowSummaryWizardPage", "Save Results", nullptr));
        showHideLogLabel->setText(QCoreApplication::translate("ShowSummaryWizardPage", "View log", nullptr));
        logToolButton->setText(QString());
        QTableWidgetItem *___qtablewidgetitem = locationsTableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("ShowSummaryWizardPage", "Location", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = locationsTableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("ShowSummaryWizardPage", "Relationship", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = locationsTableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("ShowSummaryWizardPage", "Saved Status", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ShowSummaryWizardPage: public Ui_ShowSummaryWizardPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOWSUMMARYWIZARDPAGE_H
