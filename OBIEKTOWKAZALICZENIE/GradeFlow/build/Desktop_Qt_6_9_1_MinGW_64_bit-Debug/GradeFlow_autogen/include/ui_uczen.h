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
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Uczen
{
public:
    QWidget *centralwidget;
    QFrame *StudSideBar;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *StudGrdBtn;
    QPushButton *StudSchdBtn;
    QPushButton *StudAttndcBtn;
    QPushButton *StudNoteBtn;
    QSpacerItem *verticalSpacer;
    QPushButton *StudLogoutBtn;
    QFrame *StudGrdMenu;
    QTableView *StudGrdList;
    QFrame *StudSchdMenu;
    QTableView *StudSchdList;
    QFrame *StudAttndcMenu;
    QTableView *StudAttndcList;
    QFrame *StudNotesMenu;
    QTableView *StudNotesList;

    void setupUi(QMainWindow *Uczen)
    {
        if (Uczen->objectName().isEmpty())
            Uczen->setObjectName("Uczen");
        Uczen->resize(1280, 720);
        Uczen->setMinimumSize(QSize(1280, 720));
        Uczen->setMaximumSize(QSize(1280, 720));
        Uczen->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:1, x2:0, y2:0, stop:0 rgba(33, 33, 33, 255), stop:1 rgba(48, 48, 48, 255));\n"
"color: rgb(255,255,255);"));
        centralwidget = new QWidget(Uczen);
        centralwidget->setObjectName("centralwidget");
        StudSideBar = new QFrame(centralwidget);
        StudSideBar->setObjectName("StudSideBar");
        StudSideBar->setEnabled(true);
        StudSideBar->setGeometry(QRect(0, 0, 161, 721));
        StudSideBar->setMinimumSize(QSize(0, 0));
        StudSideBar->setMaximumSize(QSize(16777215, 16777215));
        StudSideBar->setFrameShape(QFrame::Shape::StyledPanel);
        StudSideBar->setFrameShadow(QFrame::Shadow::Raised);
        verticalLayoutWidget = new QWidget(StudSideBar);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setEnabled(true);
        verticalLayoutWidget->setGeometry(QRect(0, 0, 160, 721));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        StudGrdBtn = new QPushButton(verticalLayoutWidget);
        StudGrdBtn->setObjectName("StudGrdBtn");
        StudGrdBtn->setEnabled(true);
        StudGrdBtn->setMinimumSize(QSize(0, 50));
        StudGrdBtn->setCheckable(true);

        verticalLayout->addWidget(StudGrdBtn);

        StudSchdBtn = new QPushButton(verticalLayoutWidget);
        StudSchdBtn->setObjectName("StudSchdBtn");
        StudSchdBtn->setEnabled(true);
        StudSchdBtn->setMinimumSize(QSize(0, 50));
        StudSchdBtn->setCheckable(true);

        verticalLayout->addWidget(StudSchdBtn);

        StudAttndcBtn = new QPushButton(verticalLayoutWidget);
        StudAttndcBtn->setObjectName("StudAttndcBtn");
        StudAttndcBtn->setEnabled(true);
        StudAttndcBtn->setMinimumSize(QSize(0, 50));
        StudAttndcBtn->setCheckable(true);

        verticalLayout->addWidget(StudAttndcBtn);

        StudNoteBtn = new QPushButton(verticalLayoutWidget);
        StudNoteBtn->setObjectName("StudNoteBtn");
        StudNoteBtn->setEnabled(true);
        StudNoteBtn->setMinimumSize(QSize(0, 50));
        StudNoteBtn->setCheckable(true);

        verticalLayout->addWidget(StudNoteBtn);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        StudLogoutBtn = new QPushButton(verticalLayoutWidget);
        StudLogoutBtn->setObjectName("StudLogoutBtn");
        StudLogoutBtn->setEnabled(true);
        StudLogoutBtn->setMinimumSize(QSize(0, 50));

        verticalLayout->addWidget(StudLogoutBtn);

        StudGrdMenu = new QFrame(centralwidget);
        StudGrdMenu->setObjectName("StudGrdMenu");
        StudGrdMenu->setEnabled(true);
        StudGrdMenu->setGeometry(QRect(170, 110, 1101, 561));
        StudGrdMenu->setFrameShape(QFrame::Shape::StyledPanel);
        StudGrdMenu->setFrameShadow(QFrame::Shadow::Raised);
        StudGrdList = new QTableView(StudGrdMenu);
        StudGrdList->setObjectName("StudGrdList");
        StudGrdList->setEnabled(true);
        StudGrdList->setGeometry(QRect(0, 0, 1101, 561));
        StudSchdMenu = new QFrame(centralwidget);
        StudSchdMenu->setObjectName("StudSchdMenu");
        StudSchdMenu->setEnabled(true);
        StudSchdMenu->setGeometry(QRect(170, 110, 1101, 561));
        StudSchdMenu->setFrameShape(QFrame::Shape::StyledPanel);
        StudSchdMenu->setFrameShadow(QFrame::Shadow::Raised);
        StudSchdList = new QTableView(StudSchdMenu);
        StudSchdList->setObjectName("StudSchdList");
        StudSchdList->setEnabled(true);
        StudSchdList->setGeometry(QRect(0, 0, 1101, 561));
        StudAttndcMenu = new QFrame(centralwidget);
        StudAttndcMenu->setObjectName("StudAttndcMenu");
        StudAttndcMenu->setEnabled(true);
        StudAttndcMenu->setGeometry(QRect(170, 110, 1101, 561));
        StudAttndcMenu->setFrameShape(QFrame::Shape::StyledPanel);
        StudAttndcMenu->setFrameShadow(QFrame::Shadow::Raised);
        StudAttndcList = new QTableView(StudAttndcMenu);
        StudAttndcList->setObjectName("StudAttndcList");
        StudAttndcList->setEnabled(true);
        StudAttndcList->setGeometry(QRect(0, 0, 1101, 561));
        StudNotesMenu = new QFrame(centralwidget);
        StudNotesMenu->setObjectName("StudNotesMenu");
        StudNotesMenu->setEnabled(true);
        StudNotesMenu->setGeometry(QRect(170, 110, 1101, 561));
        StudNotesMenu->setFrameShape(QFrame::Shape::StyledPanel);
        StudNotesMenu->setFrameShadow(QFrame::Shadow::Raised);
        StudNotesList = new QTableView(StudNotesMenu);
        StudNotesList->setObjectName("StudNotesList");
        StudNotesList->setEnabled(true);
        StudNotesList->setGeometry(QRect(0, 0, 1101, 561));
        Uczen->setCentralWidget(centralwidget);

        retranslateUi(Uczen);

        QMetaObject::connectSlotsByName(Uczen);
    } // setupUi

    void retranslateUi(QMainWindow *Uczen)
    {
        Uczen->setWindowTitle(QCoreApplication::translate("Uczen", "MainWindow", nullptr));
        StudGrdBtn->setText(QCoreApplication::translate("Uczen", "Oceny", nullptr));
        StudSchdBtn->setText(QCoreApplication::translate("Uczen", "Plan Zaj\304\231\304\207", nullptr));
        StudAttndcBtn->setText(QCoreApplication::translate("Uczen", "Frekwencja", nullptr));
        StudNoteBtn->setText(QCoreApplication::translate("Uczen", "Uwagi", nullptr));
        StudLogoutBtn->setText(QCoreApplication::translate("Uczen", "Wyloguj", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Uczen: public Ui_Uczen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UCZEN_H
