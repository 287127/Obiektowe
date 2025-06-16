/********************************************************************************
** Form generated from reading UI file 'uczen.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UCZEN_H
#define UI_UCZEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Uczen
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Uczen)
    {
        if (Uczen->objectName().isEmpty())
            Uczen->setObjectName("Uczen");
        Uczen->resize(800, 600);
        centralwidget = new QWidget(Uczen);
        centralwidget->setObjectName("centralwidget");
        Uczen->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Uczen);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        Uczen->setMenuBar(menubar);
        statusbar = new QStatusBar(Uczen);
        statusbar->setObjectName("statusbar");
        Uczen->setStatusBar(statusbar);

        retranslateUi(Uczen);

        QMetaObject::connectSlotsByName(Uczen);
    } // setupUi

    void retranslateUi(QMainWindow *Uczen)
    {
        Uczen->setWindowTitle(QCoreApplication::translate("Uczen", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Uczen: public Ui_Uczen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UCZEN_H
