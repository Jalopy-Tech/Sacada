/********************************************************************************
** Form generated from reading UI file 'enterdetailswizardpage.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ENTERDETAILSWIZARDPAGE_H
#define UI_ENTERDETAILSWIZARDPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWizardPage>

QT_BEGIN_NAMESPACE

class Ui_EnterDetailsWizardPage
{
public:
    QLabel *label_3;
    QLabel *label;
    QLabel *label_2;
    QLabel *pixelsLabel;
    QLabel *showHideLogLabel;
    QToolButton *logToolButton;
    QTextBrowser *logTextBrowser;
    QLabel *imageLabel;
    QLabel *versionLabel;
    QLineEdit *albumArtistLineEdit;
    QLineEdit *albumLineEdit;
    QSpinBox *sizeSpinBox;
    QLabel *sacadCommandLabel;
    QLineEdit *sacadCommandLineEdit;

    void setupUi(QWizardPage *EnterDetailsWizardPage)
    {
        if (EnterDetailsWizardPage->objectName().isEmpty())
            EnterDetailsWizardPage->setObjectName("EnterDetailsWizardPage");
        EnterDetailsWizardPage->resize(837, 460);
        label_3 = new QLabel(EnterDetailsWizardPage);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(20, 114, 191, 24));
        label = new QLabel(EnterDetailsWizardPage);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 18, 63, 24));
        label_2 = new QLabel(EnterDetailsWizardPage);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(20, 64, 63, 24));
        pixelsLabel = new QLabel(EnterDetailsWizardPage);
        pixelsLabel->setObjectName("pixelsLabel");
        pixelsLabel->setGeometry(QRect(340, 110, 82, 24));
        showHideLogLabel = new QLabel(EnterDetailsWizardPage);
        showHideLogLabel->setObjectName("showHideLogLabel");
        showHideLogLabel->setGeometry(QRect(70, 200, 161, 28));
        logToolButton = new QToolButton(EnterDetailsWizardPage);
        logToolButton->setObjectName("logToolButton");
        logToolButton->setGeometry(QRect(20, 200, 34, 34));
        logToolButton->setFocusPolicy(Qt::StrongFocus);
        logToolButton->setArrowType(Qt::RightArrow);
        logTextBrowser = new QTextBrowser(EnterDetailsWizardPage);
        logTextBrowser->setObjectName("logTextBrowser");
        logTextBrowser->setEnabled(true);
        logTextBrowser->setGeometry(QRect(20, 240, 800, 200));
        QSizePolicy sizePolicy(QSizePolicy::Policy::MinimumExpanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(logTextBrowser->sizePolicy().hasHeightForWidth());
        logTextBrowser->setSizePolicy(sizePolicy);
        logTextBrowser->setFocusPolicy(Qt::StrongFocus);
        imageLabel = new QLabel(EnterDetailsWizardPage);
        imageLabel->setObjectName("imageLabel");
        imageLabel->setGeometry(QRect(740, 20, 80, 80));
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(imageLabel->sizePolicy().hasHeightForWidth());
        imageLabel->setSizePolicy(sizePolicy1);
        imageLabel->setPixmap(QPixmap(QString::fromUtf8(":/images/sacada.png")));
        imageLabel->setScaledContents(true);
        versionLabel = new QLabel(EnterDetailsWizardPage);
        versionLabel->setObjectName("versionLabel");
        versionLabel->setGeometry(QRect(600, 200, 221, 20));
        versionLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        albumArtistLineEdit = new QLineEdit(EnterDetailsWizardPage);
        albumArtistLineEdit->setObjectName("albumArtistLineEdit");
        albumArtistLineEdit->setGeometry(QRect(102, 14, 591, 28));
        albumLineEdit = new QLineEdit(EnterDetailsWizardPage);
        albumLineEdit->setObjectName("albumLineEdit");
        albumLineEdit->setGeometry(QRect(100, 60, 591, 28));
        sizeSpinBox = new QSpinBox(EnterDetailsWizardPage);
        sizeSpinBox->setObjectName("sizeSpinBox");
        sizeSpinBox->setGeometry(QRect(220, 110, 91, 28));
        sizeSpinBox->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        sizeSpinBox->setMinimum(100);
        sizeSpinBox->setMaximum(10000);
        sizeSpinBox->setValue(500);
        sacadCommandLabel = new QLabel(EnterDetailsWizardPage);
        sacadCommandLabel->setObjectName("sacadCommandLabel");
        sacadCommandLabel->setGeometry(QRect(20, 164, 141, 24));
        sacadCommandLineEdit = new QLineEdit(EnterDetailsWizardPage);
        sacadCommandLineEdit->setObjectName("sacadCommandLineEdit");
        sacadCommandLineEdit->setGeometry(QRect(190, 160, 631, 28));
        sacadCommandLineEdit->setFocusPolicy(Qt::TabFocus);
        sacadCommandLineEdit->setFrame(false);
        sacadCommandLineEdit->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        sacadCommandLineEdit->setReadOnly(true);
        QWidget::setTabOrder(albumArtistLineEdit, albumLineEdit);
        QWidget::setTabOrder(albumLineEdit, sizeSpinBox);
        QWidget::setTabOrder(sizeSpinBox, sacadCommandLineEdit);
        QWidget::setTabOrder(sacadCommandLineEdit, logToolButton);
        QWidget::setTabOrder(logToolButton, logTextBrowser);

        retranslateUi(EnterDetailsWizardPage);

        QMetaObject::connectSlotsByName(EnterDetailsWizardPage);
    } // setupUi

    void retranslateUi(QWizardPage *EnterDetailsWizardPage)
    {
        EnterDetailsWizardPage->setWindowTitle(QCoreApplication::translate("EnterDetailsWizardPage", "WizardPage", nullptr));
        EnterDetailsWizardPage->setTitle(QCoreApplication::translate("EnterDetailsWizardPage", "Enter Album Details for Search", nullptr));
        EnterDetailsWizardPage->setSubTitle(QCoreApplication::translate("EnterDetailsWizardPage", "Enter the artist and album, then click next to search for album art.", nullptr));
        label_3->setText(QCoreApplication::translate("EnterDetailsWizardPage", "Create art image of size:", nullptr));
        label->setText(QCoreApplication::translate("EnterDetailsWizardPage", "Artist:", nullptr));
        label_2->setText(QCoreApplication::translate("EnterDetailsWizardPage", "Album:", nullptr));
        pixelsLabel->setText(QCoreApplication::translate("EnterDetailsWizardPage", "pixels", nullptr));
        showHideLogLabel->setText(QCoreApplication::translate("EnterDetailsWizardPage", "View log", nullptr));
        logToolButton->setText(QString());
        imageLabel->setText(QString());
        versionLabel->setText(QCoreApplication::translate("EnterDetailsWizardPage", "Version 1.0.0", nullptr));
        sacadCommandLabel->setText(QCoreApplication::translate("EnterDetailsWizardPage", "Sacad command:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EnterDetailsWizardPage: public Ui_EnterDetailsWizardPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENTERDETAILSWIZARDPAGE_H
