/********************************************************************************
** Form generated from reading UI file 'findwizardpage.ui'
**
** Created by: Qt User Interface Compiler version 6.2.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FINDWIZARDPAGE_H
#define UI_FINDWIZARDPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWizardPage>

QT_BEGIN_NAMESPACE

class Ui_FindWizardPage
{
public:
    QLabel *artFoundPixmapLabel;
    QLabel *artImageLabel;
    QToolButton *logToolButton;
    QLabel *label_5;
    QLabel *showHideLogLabel;
    QTextBrowser *logTextBrowser;
    QLabel *albumDetailsLabel;
    QLabel *logLabel;
    QProgressBar *progressBar;
    QPushButton *openArtImagePushButton;
    QCheckBox *artFoundHiddenCheckBox;

    void setupUi(QWizardPage *FindWizardPage)
    {
        if (FindWizardPage->objectName().isEmpty())
            FindWizardPage->setObjectName(QString::fromUtf8("FindWizardPage"));
        FindWizardPage->resize(835, 460);
        artFoundPixmapLabel = new QLabel(FindWizardPage);
        artFoundPixmapLabel->setObjectName(QString::fromUtf8("artFoundPixmapLabel"));
        artFoundPixmapLabel->setGeometry(QRect(30, 10, 51, 51));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(artFoundPixmapLabel->sizePolicy().hasHeightForWidth());
        artFoundPixmapLabel->setSizePolicy(sizePolicy);
        artFoundPixmapLabel->setAlignment(Qt::AlignCenter);
        artImageLabel = new QLabel(FindWizardPage);
        artImageLabel->setObjectName(QString::fromUtf8("artImageLabel"));
        artImageLabel->setGeometry(QRect(695, 34, 120, 120));
        sizePolicy.setHeightForWidth(artImageLabel->sizePolicy().hasHeightForWidth());
        artImageLabel->setSizePolicy(sizePolicy);
        artImageLabel->setFrameShape(QFrame::StyledPanel);
        artImageLabel->setScaledContents(true);
        logToolButton = new QToolButton(FindWizardPage);
        logToolButton->setObjectName(QString::fromUtf8("logToolButton"));
        logToolButton->setGeometry(QRect(20, 200, 34, 34));
        logToolButton->setFocusPolicy(Qt::StrongFocus);
        logToolButton->setArrowType(Qt::RightArrow);
        label_5 = new QLabel(FindWizardPage);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(695, 5, 91, 28));
        showHideLogLabel = new QLabel(FindWizardPage);
        showHideLogLabel->setObjectName(QString::fromUtf8("showHideLogLabel"));
        showHideLogLabel->setGeometry(QRect(70, 200, 161, 28));
        logTextBrowser = new QTextBrowser(FindWizardPage);
        logTextBrowser->setObjectName(QString::fromUtf8("logTextBrowser"));
        logTextBrowser->setEnabled(true);
        logTextBrowser->setGeometry(QRect(20, 240, 800, 200));
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(logTextBrowser->sizePolicy().hasHeightForWidth());
        logTextBrowser->setSizePolicy(sizePolicy1);
        albumDetailsLabel = new QLabel(FindWizardPage);
        albumDetailsLabel->setObjectName(QString::fromUtf8("albumDetailsLabel"));
        albumDetailsLabel->setEnabled(true);
        albumDetailsLabel->setGeometry(QRect(100, 20, 781, 28));
        QFont font;
        font.setBold(true);
        albumDetailsLabel->setFont(font);
        logLabel = new QLabel(FindWizardPage);
        logLabel->setObjectName(QString::fromUtf8("logLabel"));
        logLabel->setGeometry(QRect(20, 100, 641, 28));
        logLabel->setAutoFillBackground(true);
        progressBar = new QProgressBar(FindWizardPage);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(20, 60, 651, 30));
        progressBar->setValue(0);
        openArtImagePushButton = new QPushButton(FindWizardPage);
        openArtImagePushButton->setObjectName(QString::fromUtf8("openArtImagePushButton"));
        openArtImagePushButton->setGeometry(QRect(700, 160, 113, 35));
        artFoundHiddenCheckBox = new QCheckBox(FindWizardPage);
        artFoundHiddenCheckBox->setObjectName(QString::fromUtf8("artFoundHiddenCheckBox"));
        artFoundHiddenCheckBox->setGeometry(QRect(490, 130, 121, 34));
        artFoundHiddenCheckBox->setFocusPolicy(Qt::NoFocus);

        retranslateUi(FindWizardPage);

        QMetaObject::connectSlotsByName(FindWizardPage);
    } // setupUi

    void retranslateUi(QWizardPage *FindWizardPage)
    {
        FindWizardPage->setWindowTitle(QCoreApplication::translate("FindWizardPage", "WizardPage", nullptr));
        FindWizardPage->setTitle(QCoreApplication::translate("FindWizardPage", "View Search Result and Confirm", nullptr));
        FindWizardPage->setSubTitle(QCoreApplication::translate("FindWizardPage", "View the album art search result. If this is the right album art, click next to continue.", nullptr));
        artFoundPixmapLabel->setText(QCoreApplication::translate("FindWizardPage", "TextLabel", nullptr));
        artImageLabel->setText(QString());
        logToolButton->setText(QString());
        label_5->setText(QCoreApplication::translate("FindWizardPage", "Image:", nullptr));
        showHideLogLabel->setText(QCoreApplication::translate("FindWizardPage", "View log", nullptr));
        albumDetailsLabel->setText(QCoreApplication::translate("FindWizardPage", "Text", nullptr));
        logLabel->setText(QCoreApplication::translate("FindWizardPage", "TextLabel", nullptr));
        openArtImagePushButton->setText(QCoreApplication::translate("FindWizardPage", "&Open", nullptr));
        artFoundHiddenCheckBox->setText(QCoreApplication::translate("FindWizardPage", "CheckBox", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FindWizardPage: public Ui_FindWizardPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FINDWIZARDPAGE_H
