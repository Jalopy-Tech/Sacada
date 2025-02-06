/********************************************************************************
** Form generated from reading UI file 'artwizard.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ARTWIZARD_H
#define UI_ARTWIZARD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWizard>

QT_BEGIN_NAMESPACE

class Ui_ArtWizard
{
public:

    void setupUi(QWizard *ArtWizard)
    {
        if (ArtWizard->objectName().isEmpty())
            ArtWizard->setObjectName("ArtWizard");
        ArtWizard->resize(884, 385);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ArtWizard->sizePolicy().hasHeightForWidth());
        ArtWizard->setSizePolicy(sizePolicy);
        ArtWizard->setSizeGripEnabled(false);
        ArtWizard->setWizardStyle(QWizard::ClassicStyle);
        ArtWizard->setOptions(QWizard::HaveHelpButton|QWizard::IndependentPages|QWizard::NoCancelButtonOnLastPage);

        retranslateUi(ArtWizard);

        QMetaObject::connectSlotsByName(ArtWizard);
    } // setupUi

    void retranslateUi(QWizard *ArtWizard)
    {
        ArtWizard->setWindowTitle(QCoreApplication::translate("ArtWizard", "SACADA", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ArtWizard: public Ui_ArtWizard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ARTWIZARD_H
