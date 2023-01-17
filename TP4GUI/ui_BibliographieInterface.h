/********************************************************************************
** Form generated from reading UI file 'BibliographieInterface.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BIBLIOGRAPHIEINTERFACE_H
#define UI_BIBLIOGRAPHIEINTERFACE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BibliographieInterface
{
public:
    QAction *actionJournal;
    QAction *actionOuvrage;
    QAction *actionSupprimer_une_Reference;
    QAction *actionQuitter;
    QWidget *centralwidget;
    QLabel *label;
    QLabel *affiche;
    QMenuBar *menubar;
    QMenu *menuMenu;
    QMenu *menuType_de_Reference;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *BibliographieInterface)
    {
        if (BibliographieInterface->objectName().isEmpty())
            BibliographieInterface->setObjectName(QString::fromUtf8("BibliographieInterface"));
        BibliographieInterface->resize(800, 600);
        actionJournal = new QAction(BibliographieInterface);
        actionJournal->setObjectName(QString::fromUtf8("actionJournal"));
        actionOuvrage = new QAction(BibliographieInterface);
        actionOuvrage->setObjectName(QString::fromUtf8("actionOuvrage"));
        actionSupprimer_une_Reference = new QAction(BibliographieInterface);
        actionSupprimer_une_Reference->setObjectName(QString::fromUtf8("actionSupprimer_une_Reference"));
        actionQuitter = new QAction(BibliographieInterface);
        actionQuitter->setObjectName(QString::fromUtf8("actionQuitter"));
        centralwidget = new QWidget(BibliographieInterface);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(160, 20, 441, 31));
        QFont font;
        font.setPointSize(30);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);
        affiche = new QLabel(centralwidget);
        affiche->setObjectName(QString::fromUtf8("affiche"));
        affiche->setGeometry(QRect(40, 80, 711, 471));
        affiche->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        affiche->setMargin(20);
        BibliographieInterface->setCentralWidget(centralwidget);
        menubar = new QMenuBar(BibliographieInterface);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        menuMenu = new QMenu(menubar);
        menuMenu->setObjectName(QString::fromUtf8("menuMenu"));
        menuType_de_Reference = new QMenu(menuMenu);
        menuType_de_Reference->setObjectName(QString::fromUtf8("menuType_de_Reference"));
        BibliographieInterface->setMenuBar(menubar);
        statusbar = new QStatusBar(BibliographieInterface);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        BibliographieInterface->setStatusBar(statusbar);

        menubar->addAction(menuMenu->menuAction());
        menuMenu->addAction(menuType_de_Reference->menuAction());
        menuMenu->addAction(actionSupprimer_une_Reference);
        menuMenu->addSeparator();
        menuMenu->addAction(actionQuitter);
        menuType_de_Reference->addAction(actionJournal);
        menuType_de_Reference->addAction(actionOuvrage);

        retranslateUi(BibliographieInterface);
        QObject::connect(actionJournal, SIGNAL(triggered()), BibliographieInterface, SLOT(dialogJournal()));
        QObject::connect(actionOuvrage, SIGNAL(triggered()), BibliographieInterface, SLOT(dialogOuvrage()));
        QObject::connect(actionSupprimer_une_Reference, SIGNAL(triggered()), BibliographieInterface, SLOT(dialogSupprime()));
        QObject::connect(actionQuitter, SIGNAL(triggered()), BibliographieInterface, SLOT(close()));

        QMetaObject::connectSlotsByName(BibliographieInterface);
    } // setupUi

    void retranslateUi(QMainWindow *BibliographieInterface)
    {
        BibliographieInterface->setWindowTitle(QApplication::translate("BibliographieInterface", "BibliographieInterface", nullptr));
        actionJournal->setText(QApplication::translate("BibliographieInterface", "Journal", nullptr));
        actionOuvrage->setText(QApplication::translate("BibliographieInterface", "Ouvrage", nullptr));
        actionSupprimer_une_Reference->setText(QApplication::translate("BibliographieInterface", "Supprimer une Reference", nullptr));
        actionQuitter->setText(QApplication::translate("BibliographieInterface", "Quitter", nullptr));
        label->setText(QApplication::translate("BibliographieInterface", "LISTE DE REFERENCES", nullptr));
        affiche->setText(QString());
        menuMenu->setTitle(QApplication::translate("BibliographieInterface", "Menu", nullptr));
        menuType_de_Reference->setTitle(QApplication::translate("BibliographieInterface", "Type de Reference", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BibliographieInterface: public Ui_BibliographieInterface {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BIBLIOGRAPHIEINTERFACE_H
