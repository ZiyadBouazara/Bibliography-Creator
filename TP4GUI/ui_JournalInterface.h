/********************************************************************************
** Form generated from reading UI file 'JournalInterface.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_JOURNALINTERFACE_H
#define UI_JOURNALINTERFACE_H

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

class Ui_JournalInterface
{
public:
    QLabel *label;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_6;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QLineEdit *annee;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLineEdit *volume;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_6;
    QLineEdit *page;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_5;
    QLineEdit *numero;
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_8;
    QLineEdit *identifiant;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *auteurs;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_9;
    QLineEdit *nom;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_7;
    QLineEdit *titre;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout_11;
    QPushButton *btn_ajouterJournal;

    void setupUi(QDialog *JournalInterface)
    {
        if (JournalInterface->objectName().isEmpty())
            JournalInterface->setObjectName(QString::fromUtf8("JournalInterface"));
        JournalInterface->resize(700, 550);
        label = new QLabel(JournalInterface);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(190, 0, 361, 51));
        label->setAlignment(Qt::AlignCenter);
        gridLayoutWidget = new QWidget(JournalInterface);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(80, 50, 551, 401));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(5);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(5);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_4 = new QLabel(gridLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_3->addWidget(label_4);

        annee = new QLineEdit(gridLayoutWidget);
        annee->setObjectName(QString::fromUtf8("annee"));
        annee->setMaxLength(9999);

        horizontalLayout_3->addWidget(annee);


        horizontalLayout_6->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(5);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_3 = new QLabel(gridLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_2->addWidget(label_3);

        volume = new QLineEdit(gridLayoutWidget);
        volume->setObjectName(QString::fromUtf8("volume"));

        horizontalLayout_2->addWidget(volume);


        horizontalLayout_6->addLayout(horizontalLayout_2);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_6 = new QLabel(gridLayoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_5->addWidget(label_6);

        page = new QLineEdit(gridLayoutWidget);
        page->setObjectName(QString::fromUtf8("page"));

        horizontalLayout_5->addWidget(page);


        horizontalLayout_6->addLayout(horizontalLayout_5);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        label_5 = new QLabel(gridLayoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_10->addWidget(label_5);

        numero = new QLineEdit(gridLayoutWidget);
        numero->setObjectName(QString::fromUtf8("numero"));

        horizontalLayout_10->addWidget(numero);


        horizontalLayout_6->addLayout(horizontalLayout_10);

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

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(43);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        label_9 = new QLabel(gridLayoutWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        horizontalLayout_9->addWidget(label_9);

        nom = new QLineEdit(gridLayoutWidget);
        nom->setObjectName(QString::fromUtf8("nom"));

        horizontalLayout_9->addWidget(nom);


        gridLayout->addLayout(horizontalLayout_9, 2, 0, 1, 1);

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

        horizontalLayoutWidget = new QWidget(JournalInterface);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(180, 460, 341, 102));
        horizontalLayout_11 = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout_11->setSpacing(20);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        horizontalLayout_11->setContentsMargins(0, 0, 0, 0);
        btn_ajouterJournal = new QPushButton(horizontalLayoutWidget);
        btn_ajouterJournal->setObjectName(QString::fromUtf8("btn_ajouterJournal"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(btn_ajouterJournal->sizePolicy().hasHeightForWidth());
        btn_ajouterJournal->setSizePolicy(sizePolicy);
        btn_ajouterJournal->setMinimumSize(QSize(0, 50));
        btn_ajouterJournal->setMaximumSize(QSize(160, 16777215));
        QFont font;
        font.setFamily(QString::fromUtf8("Ubuntu"));
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        btn_ajouterJournal->setFont(font);

        horizontalLayout_11->addWidget(btn_ajouterJournal);


        retranslateUi(JournalInterface);
        QObject::connect(btn_ajouterJournal, SIGNAL(clicked()), JournalInterface, SLOT(valideEnregistrement()));

        QMetaObject::connectSlotsByName(JournalInterface);
    } // setupUi

    void retranslateUi(QDialog *JournalInterface)
    {
        JournalInterface->setWindowTitle(QApplication::translate("JournalInterface", "JournalInterface", nullptr));
        label->setText(QApplication::translate("JournalInterface", "<html><head/><body><p><span style=\" font-size:16pt; font-weight:600;\">Ajouter Une Reference Journal</span></p></body></html>", nullptr));
        label_4->setText(QApplication::translate("JournalInterface", "Annee :", nullptr));
        label_3->setText(QApplication::translate("JournalInterface", "Volume :", nullptr));
        label_6->setText(QApplication::translate("JournalInterface", "Page :", nullptr));
        label_5->setText(QApplication::translate("JournalInterface", "Numero :", nullptr));
        label_8->setText(QApplication::translate("JournalInterface", "Identifiant :", nullptr));
        label_2->setText(QApplication::translate("JournalInterface", "Auteurs :", nullptr));
        label_9->setText(QApplication::translate("JournalInterface", "Nom", nullptr));
        label_7->setText(QApplication::translate("JournalInterface", "Titre :", nullptr));
        btn_ajouterJournal->setText(QApplication::translate("JournalInterface", "Ajouter", nullptr));
    } // retranslateUi

};

namespace Ui {
    class JournalInterface: public Ui_JournalInterface {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JOURNALINTERFACE_H
