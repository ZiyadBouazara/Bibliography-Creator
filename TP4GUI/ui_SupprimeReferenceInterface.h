/********************************************************************************
** Form generated from reading UI file 'SupprimeReferenceInterface.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUPPRIMEREFERENCEINTERFACE_H
#define UI_SUPPRIMEREFERENCEINTERFACE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SupprimeReferenceInterface
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *identifiant;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *supprimer;
    QLabel *label_2;

    void setupUi(QDialog *SupprimeReferenceInterface)
    {
        if (SupprimeReferenceInterface->objectName().isEmpty())
            SupprimeReferenceInterface->setObjectName(QString::fromUtf8("SupprimeReferenceInterface"));
        SupprimeReferenceInterface->resize(400, 300);
        verticalLayoutWidget = new QWidget(SupprimeReferenceInterface);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(50, 60, 301, 221));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(20);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label);

        identifiant = new QLineEdit(verticalLayoutWidget);
        identifiant->setObjectName(QString::fromUtf8("identifiant"));

        horizontalLayout->addWidget(identifiant);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(20);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        supprimer = new QPushButton(verticalLayoutWidget);
        supprimer->setObjectName(QString::fromUtf8("supprimer"));
        supprimer->setMinimumSize(QSize(0, 60));
        supprimer->setMaximumSize(QSize(180, 16777215));
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        supprimer->setFont(font);

        horizontalLayout_2->addWidget(supprimer);


        verticalLayout->addLayout(horizontalLayout_2);

        label_2 = new QLabel(SupprimeReferenceInterface);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(30, 10, 341, 41));
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setWeight(75);
        label_2->setFont(font1);
        label_2->setAlignment(Qt::AlignCenter);

        retranslateUi(SupprimeReferenceInterface);
        QObject::connect(supprimer, SIGNAL(clicked()), SupprimeReferenceInterface, SLOT(valideEnregistrement()));

        QMetaObject::connectSlotsByName(SupprimeReferenceInterface);
    } // setupUi

    void retranslateUi(QDialog *SupprimeReferenceInterface)
    {
        SupprimeReferenceInterface->setWindowTitle(QApplication::translate("SupprimeReferenceInterface", "SupprimeReferenceInterface", nullptr));
        label->setText(QApplication::translate("SupprimeReferenceInterface", "<html><head/><body><p align=\"justify\"><span style=\" font-size:12pt;\">Identitifant :</span></p></body></html>", nullptr));
        supprimer->setText(QApplication::translate("SupprimeReferenceInterface", "Supprimer", nullptr));
        label_2->setText(QApplication::translate("SupprimeReferenceInterface", "<html><head/><body><p><span style=\" font-size:18pt;\">Supprimer Une Reference</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SupprimeReferenceInterface: public Ui_SupprimeReferenceInterface {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUPPRIMEREFERENCEINTERFACE_H
