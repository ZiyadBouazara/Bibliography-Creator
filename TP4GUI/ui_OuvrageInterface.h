/********************************************************************************
** Form generated from reading UI file 'OuvrageInterface.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OUVRAGEINTERFACE_H
#define UI_OUVRAGEINTERFACE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OuvrageInterface
{
public:
    QLabel *label;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *auteurs;
    QHBoxLayout *horizontalLayout_6;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QLineEdit *annee;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_6;
    QLineEdit *ville;
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_8;
    QLineEdit *identifiant;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_7;
    QLineEdit *titre;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLineEdit *editeur;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout_11;
    QPushButton *btn_ajouterOuvrage;

    void setupUi(QDialog *OuvrageInterface)
    {
        if (OuvrageInterface->objectName().isEmpty())
            OuvrageInterface->setObjectName(QString::fromUtf8("OuvrageInterface"));
        OuvrageInterface->resize(700, 600);
        label = new QLabel(OuvrageInterface);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(170, 10, 361, 51));
        label->setAlignment(Qt::AlignCenter);
        gridLayoutWidget = new QWidget(OuvrageInterface);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(80, 80, 551, 401));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(20);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        auteurs = new QLineEdit(gridLayoutWidget);
        auteurs->setObjectName(QString::fromUtf8("auteurs"));

        horizontalLayout->addWidget(auteurs);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(5);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(25);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_4 = new QLabel(gridLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_3->addWidget(label_4);

        annee = new QLineEdit(gridLayoutWidget);
        annee->setObjectName(QString::fromUtf8("annee"));
        annee->setMaxLength(9999);

        horizontalLayout_3->addWidget(annee);


        horizontalLayout_6->addLayout(horizontalLayout_3);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(25);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_6 = new QLabel(gridLayoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_5->addWidget(label_6);

        ville = new QLineEdit(gridLayoutWidget);
        ville->setObjectName(QString::fromUtf8("ville"));

        horizontalLayout_5->addWidget(ville);


        horizontalLayout_6->addLayout(horizontalLayout_5);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(5);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));

        horizontalLayout_6->addLayout(horizontalLayout_4);


        gridLayout->addLayout(horizontalLayout_6, 3, 0, 1, 1);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(7);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_8 = new QLabel(gridLayoutWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout_8->addWidget(label_8);

        identifiant = new QLineEdit(gridLayoutWidget);
        identifiant->setObjectName(QString::fromUtf8("identifiant"));

        horizontalLayout_8->addWidget(identifiant);


        gridLayout->addLayout(horizontalLayout_8, 4, 0, 1, 1);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(37);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_7 = new QLabel(gridLayoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_7->addWidget(label_7);

        titre = new QLineEdit(gridLayoutWidget);
        titre->setObjectName(QString::fromUtf8("titre"));

        horizontalLayout_7->addWidget(titre);


        gridLayout->addLayout(horizontalLayout_7, 1, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(25);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_3 = new QLabel(gridLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_2->addWidget(label_3);

        editeur = new QLineEdit(gridLayoutWidget);
        editeur->setObjectName(QString::fromUtf8("editeur"));

        horizontalLayout_2->addWidget(editeur);


        gridLayout->addLayout(horizontalLayout_2, 2, 0, 1, 1);

        horizontalLayoutWidget = new QWidget(OuvrageInterface);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(180, 490, 341, 102));
        horizontalLayout_11 = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout_11->setSpacing(20);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        horizontalLayout_11->setContentsMargins(0, 0, 0, 0);
        btn_ajouterOuvrage = new QPushButton(horizontalLayoutWidget);
        btn_ajouterOuvrage->setObjectName(QString::fromUtf8("btn_ajouterOuvrage"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(btn_ajouterOuvrage->sizePolicy().hasHeightForWidth());
        btn_ajouterOuvrage->setSizePolicy(sizePolicy);
        btn_ajouterOuvrage->setMinimumSize(QSize(0, 50));
        btn_ajouterOuvrage->setMaximumSize(QSize(160, 16777215));
        QFont font;
        font.setFamily(QString::fromUtf8("Ubuntu"));
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        btn_ajouterOuvrage->setFont(font);

        horizontalLayout_11->addWidget(btn_ajouterOuvrage);


        retranslateUi(OuvrageInterface);
        QObject::connect(btn_ajouterOuvrage, SIGNAL(clicked()), OuvrageInterface, SLOT(valideEnregistrement()));

        QMetaObject::connectSlotsByName(OuvrageInterface);
    } // setupUi

    void retranslateUi(QDialog *OuvrageInterface)
    {
        OuvrageInterface->setWindowTitle(QApplication::translate("OuvrageInterface", "OuvrageInterface", nullptr));
        label->setText(QApplication::translate("OuvrageInterface", "<html><head/><body><p><span style=\" font-size:16pt; font-weight:600;\">Ajouter Une Reference Ouvrage</span></p></body></html>", nullptr));
        label_2->setText(QApplication::translate("OuvrageInterface", "Auteurs :", nullptr));
        label_4->setText(QApplication::translate("OuvrageInterface", "Annee :", nullptr));
        label_6->setText(QApplication::translate("OuvrageInterface", "Ville :", nullptr));
        label_8->setText(QApplication::translate("OuvrageInterface", "Identifiant :", nullptr));
        label_7->setText(QApplication::translate("OuvrageInterface", "Titre :", nullptr));
        label_3->setText(QApplication::translate("OuvrageInterface", "Editeur :", nullptr));
        btn_ajouterOuvrage->setText(QApplication::translate("OuvrageInterface", "Ajouter", nullptr));
    } // retranslateUi

};

namespace Ui {
    class OuvrageInterface: public Ui_OuvrageInterface {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OUVRAGEINTERFACE_H
