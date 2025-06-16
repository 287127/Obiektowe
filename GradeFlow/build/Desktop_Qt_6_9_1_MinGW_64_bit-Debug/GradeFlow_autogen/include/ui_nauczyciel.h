/********************************************************************************
** Form generated from reading UI file 'nauczyciel.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NAUCZYCIEL_H
#define UI_NAUCZYCIEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Nauczyciel
{
public:
    QWidget *TeacherWindow;
    QFrame *TeachSideBar;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *TeachVert;
    QPushButton *TeachGrdBtn;
    QPushButton *TeachSchdBtn;
    QPushButton *TeachAttndcBtn;
    QPushButton *TeachNoteBtn;
    QSpacerItem *verticalSpacer;
    QPushButton *TeachLogoutBtn;
    QFrame *TeachGrdMenu;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *TeachHori1;
    QComboBox *TeachClassCBox;
    QComboBox *TeachSubjCBox;
    QLabel *TeachClassLabel;
    QLabel *TeachSubjLabel;
    QTableView *TeachGrdList;
    QWidget *horizontalLayoutWidget_4;
    QHBoxLayout *TeachHori;
    QPushButton *TeachAddGrdBtn;
    QPushButton *TeachDelGrdBtn;
    QPushButton *TeachEditGrdBtn;
    QFrame *TeachAttndcMenu;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *TeachHori3;
    QComboBox *TeachClassCBox_4;
    QComboBox *TeachSubjCBox_4;
    QComboBox *TeachDateCBox;
    QLabel *TeachClassLabel_2;
    QLabel *TeachSubjLabel_2;
    QTableView *TeachAttndcList;
    QLabel *TeachSubjLabel_3;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *TeachAddAttndcBtn;
    QPushButton *TeachDelAttndcBtn;
    QPushButton *TeachEditAttndcBtn;
    QFrame *TeachNoteMenu;
    QWidget *horizontalLayoutWidget_5;
    QHBoxLayout *TeachHori3_2;
    QComboBox *TeachClassCBox_5;
    QComboBox *TeachStudCBox_5;
    QLabel *TeachClassLabel_3;
    QLabel *TeachSubjLabel_4;
    QTableView *TeachNotesList;
    QWidget *horizontalLayoutWidget_6;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *TeachAddNoteBtn;
    QPushButton *TeachDelNoteBtn;
    QPushButton *TeachEditNoteBtn;
    QFrame *TeachSchdMenu;
    QScrollArea *TeachScroll;
    QWidget *TeachScrollContents;
    QWidget *TeachGridWidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;

    void setupUi(QMainWindow *Nauczyciel)
    {
        if (Nauczyciel->objectName().isEmpty())
            Nauczyciel->setObjectName("Nauczyciel");
        Nauczyciel->resize(1280, 720);
        Nauczyciel->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:1, x2:0, y2:0, stop:0 rgba(33, 33, 33, 255), stop:1 rgba(48, 48, 48, 255));\n"
"color: rgb(255,255,255);"));
        TeacherWindow = new QWidget(Nauczyciel);
        TeacherWindow->setObjectName("TeacherWindow");
        TeacherWindow->setMinimumSize(QSize(1280, 720));
        TeacherWindow->setMaximumSize(QSize(1280, 720));
        TeachSideBar = new QFrame(TeacherWindow);
        TeachSideBar->setObjectName("TeachSideBar");
        TeachSideBar->setGeometry(QRect(0, 0, 161, 720));
        TeachSideBar->setMinimumSize(QSize(0, 720));
        TeachSideBar->setMaximumSize(QSize(16777215, 720));
        TeachSideBar->setFrameShape(QFrame::Shape::StyledPanel);
        TeachSideBar->setFrameShadow(QFrame::Shadow::Raised);
        verticalLayoutWidget = new QWidget(TeachSideBar);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(0, 0, 160, 721));
        TeachVert = new QVBoxLayout(verticalLayoutWidget);
        TeachVert->setSpacing(0);
        TeachVert->setObjectName("TeachVert");
        TeachVert->setContentsMargins(0, 0, 0, 0);
        TeachGrdBtn = new QPushButton(verticalLayoutWidget);
        TeachGrdBtn->setObjectName("TeachGrdBtn");
        TeachGrdBtn->setMinimumSize(QSize(0, 50));
        TeachGrdBtn->setCheckable(true);

        TeachVert->addWidget(TeachGrdBtn);

        TeachSchdBtn = new QPushButton(verticalLayoutWidget);
        TeachSchdBtn->setObjectName("TeachSchdBtn");
        TeachSchdBtn->setMinimumSize(QSize(0, 50));
        TeachSchdBtn->setCheckable(true);

        TeachVert->addWidget(TeachSchdBtn);

        TeachAttndcBtn = new QPushButton(verticalLayoutWidget);
        TeachAttndcBtn->setObjectName("TeachAttndcBtn");
        TeachAttndcBtn->setMinimumSize(QSize(0, 50));
        TeachAttndcBtn->setCheckable(true);

        TeachVert->addWidget(TeachAttndcBtn);

        TeachNoteBtn = new QPushButton(verticalLayoutWidget);
        TeachNoteBtn->setObjectName("TeachNoteBtn");
        TeachNoteBtn->setMinimumSize(QSize(0, 50));
        TeachNoteBtn->setCheckable(true);

        TeachVert->addWidget(TeachNoteBtn);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        TeachVert->addItem(verticalSpacer);

        TeachLogoutBtn = new QPushButton(verticalLayoutWidget);
        TeachLogoutBtn->setObjectName("TeachLogoutBtn");
        TeachLogoutBtn->setMinimumSize(QSize(0, 50));

        TeachVert->addWidget(TeachLogoutBtn);

        TeachGrdMenu = new QFrame(TeacherWindow);
        TeachGrdMenu->setObjectName("TeachGrdMenu");
        TeachGrdMenu->setGeometry(QRect(160, -1, 1121, 671));
        TeachGrdMenu->setFrameShape(QFrame::Shape::StyledPanel);
        TeachGrdMenu->setFrameShadow(QFrame::Shadow::Raised);
        horizontalLayoutWidget = new QWidget(TeachGrdMenu);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(10, 98, 591, 41));
        TeachHori1 = new QHBoxLayout(horizontalLayoutWidget);
        TeachHori1->setSpacing(15);
        TeachHori1->setObjectName("TeachHori1");
        TeachHori1->setContentsMargins(0, 0, 0, 0);
        TeachClassCBox = new QComboBox(horizontalLayoutWidget);
        TeachClassCBox->setObjectName("TeachClassCBox");

        TeachHori1->addWidget(TeachClassCBox);

        TeachSubjCBox = new QComboBox(horizontalLayoutWidget);
        TeachSubjCBox->setObjectName("TeachSubjCBox");

        TeachHori1->addWidget(TeachSubjCBox);

        TeachClassLabel = new QLabel(TeachGrdMenu);
        TeachClassLabel->setObjectName("TeachClassLabel");
        TeachClassLabel->setGeometry(QRect(20, 78, 61, 16));
        TeachSubjLabel = new QLabel(TeachGrdMenu);
        TeachSubjLabel->setObjectName("TeachSubjLabel");
        TeachSubjLabel->setGeometry(QRect(320, 78, 71, 16));
        TeachGrdList = new QTableView(TeachGrdMenu);
        TeachGrdList->setObjectName("TeachGrdList");
        TeachGrdList->setGeometry(QRect(10, 150, 1101, 521));
        horizontalLayoutWidget_4 = new QWidget(TeachGrdMenu);
        horizontalLayoutWidget_4->setObjectName("horizontalLayoutWidget_4");
        horizontalLayoutWidget_4->setGeometry(QRect(10, 20, 1101, 61));
        TeachHori = new QHBoxLayout(horizontalLayoutWidget_4);
        TeachHori->setObjectName("TeachHori");
        TeachHori->setContentsMargins(0, 0, 0, 0);
        TeachAddGrdBtn = new QPushButton(horizontalLayoutWidget_4);
        TeachAddGrdBtn->setObjectName("TeachAddGrdBtn");
        TeachAddGrdBtn->setMinimumSize(QSize(0, 50));

        TeachHori->addWidget(TeachAddGrdBtn);

        TeachDelGrdBtn = new QPushButton(horizontalLayoutWidget_4);
        TeachDelGrdBtn->setObjectName("TeachDelGrdBtn");
        TeachDelGrdBtn->setMinimumSize(QSize(0, 50));

        TeachHori->addWidget(TeachDelGrdBtn);

        TeachEditGrdBtn = new QPushButton(horizontalLayoutWidget_4);
        TeachEditGrdBtn->setObjectName("TeachEditGrdBtn");
        TeachEditGrdBtn->setMinimumSize(QSize(0, 50));

        TeachHori->addWidget(TeachEditGrdBtn);

        TeachAttndcMenu = new QFrame(TeacherWindow);
        TeachAttndcMenu->setObjectName("TeachAttndcMenu");
        TeachAttndcMenu->setGeometry(QRect(160, 0, 1121, 671));
        TeachAttndcMenu->setFrameShape(QFrame::Shape::StyledPanel);
        TeachAttndcMenu->setFrameShadow(QFrame::Shadow::Raised);
        horizontalLayoutWidget_2 = new QWidget(TeachAttndcMenu);
        horizontalLayoutWidget_2->setObjectName("horizontalLayoutWidget_2");
        horizontalLayoutWidget_2->setGeometry(QRect(10, 100, 911, 41));
        TeachHori3 = new QHBoxLayout(horizontalLayoutWidget_2);
        TeachHori3->setSpacing(15);
        TeachHori3->setObjectName("TeachHori3");
        TeachHori3->setContentsMargins(0, 0, 0, 0);
        TeachClassCBox_4 = new QComboBox(horizontalLayoutWidget_2);
        TeachClassCBox_4->setObjectName("TeachClassCBox_4");

        TeachHori3->addWidget(TeachClassCBox_4);

        TeachSubjCBox_4 = new QComboBox(horizontalLayoutWidget_2);
        TeachSubjCBox_4->setObjectName("TeachSubjCBox_4");

        TeachHori3->addWidget(TeachSubjCBox_4);

        TeachDateCBox = new QComboBox(horizontalLayoutWidget_2);
        TeachDateCBox->setObjectName("TeachDateCBox");

        TeachHori3->addWidget(TeachDateCBox);

        TeachClassLabel_2 = new QLabel(TeachAttndcMenu);
        TeachClassLabel_2->setObjectName("TeachClassLabel_2");
        TeachClassLabel_2->setGeometry(QRect(20, 80, 61, 16));
        TeachSubjLabel_2 = new QLabel(TeachAttndcMenu);
        TeachSubjLabel_2->setObjectName("TeachSubjLabel_2");
        TeachSubjLabel_2->setGeometry(QRect(320, 80, 71, 16));
        TeachAttndcList = new QTableView(TeachAttndcMenu);
        TeachAttndcList->setObjectName("TeachAttndcList");
        TeachAttndcList->setGeometry(QRect(10, 150, 1101, 521));
        TeachSubjLabel_3 = new QLabel(TeachAttndcMenu);
        TeachSubjLabel_3->setObjectName("TeachSubjLabel_3");
        TeachSubjLabel_3->setGeometry(QRect(630, 80, 71, 16));
        horizontalLayoutWidget_3 = new QWidget(TeachAttndcMenu);
        horizontalLayoutWidget_3->setObjectName("horizontalLayoutWidget_3");
        horizontalLayoutWidget_3->setGeometry(QRect(10, 19, 1101, 61));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_3);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        TeachAddAttndcBtn = new QPushButton(horizontalLayoutWidget_3);
        TeachAddAttndcBtn->setObjectName("TeachAddAttndcBtn");
        TeachAddAttndcBtn->setMinimumSize(QSize(0, 50));

        horizontalLayout_2->addWidget(TeachAddAttndcBtn);

        TeachDelAttndcBtn = new QPushButton(horizontalLayoutWidget_3);
        TeachDelAttndcBtn->setObjectName("TeachDelAttndcBtn");
        TeachDelAttndcBtn->setMinimumSize(QSize(0, 50));

        horizontalLayout_2->addWidget(TeachDelAttndcBtn);

        TeachEditAttndcBtn = new QPushButton(horizontalLayoutWidget_3);
        TeachEditAttndcBtn->setObjectName("TeachEditAttndcBtn");
        TeachEditAttndcBtn->setMinimumSize(QSize(0, 50));

        horizontalLayout_2->addWidget(TeachEditAttndcBtn);

        TeachNoteMenu = new QFrame(TeacherWindow);
        TeachNoteMenu->setObjectName("TeachNoteMenu");
        TeachNoteMenu->setGeometry(QRect(160, 0, 1121, 671));
        TeachNoteMenu->setFrameShape(QFrame::Shape::StyledPanel);
        TeachNoteMenu->setFrameShadow(QFrame::Shadow::Raised);
        horizontalLayoutWidget_5 = new QWidget(TeachNoteMenu);
        horizontalLayoutWidget_5->setObjectName("horizontalLayoutWidget_5");
        horizontalLayoutWidget_5->setGeometry(QRect(10, 100, 601, 41));
        TeachHori3_2 = new QHBoxLayout(horizontalLayoutWidget_5);
        TeachHori3_2->setSpacing(15);
        TeachHori3_2->setObjectName("TeachHori3_2");
        TeachHori3_2->setContentsMargins(0, 0, 0, 0);
        TeachClassCBox_5 = new QComboBox(horizontalLayoutWidget_5);
        TeachClassCBox_5->setObjectName("TeachClassCBox_5");

        TeachHori3_2->addWidget(TeachClassCBox_5);

        TeachStudCBox_5 = new QComboBox(horizontalLayoutWidget_5);
        TeachStudCBox_5->setObjectName("TeachStudCBox_5");

        TeachHori3_2->addWidget(TeachStudCBox_5);

        TeachClassLabel_3 = new QLabel(TeachNoteMenu);
        TeachClassLabel_3->setObjectName("TeachClassLabel_3");
        TeachClassLabel_3->setGeometry(QRect(20, 80, 61, 16));
        TeachSubjLabel_4 = new QLabel(TeachNoteMenu);
        TeachSubjLabel_4->setObjectName("TeachSubjLabel_4");
        TeachSubjLabel_4->setGeometry(QRect(320, 80, 71, 16));
        TeachNotesList = new QTableView(TeachNoteMenu);
        TeachNotesList->setObjectName("TeachNotesList");
        TeachNotesList->setGeometry(QRect(10, 150, 1101, 521));
        horizontalLayoutWidget_6 = new QWidget(TeachNoteMenu);
        horizontalLayoutWidget_6->setObjectName("horizontalLayoutWidget_6");
        horizontalLayoutWidget_6->setGeometry(QRect(10, 19, 1101, 61));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget_6);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        TeachAddNoteBtn = new QPushButton(horizontalLayoutWidget_6);
        TeachAddNoteBtn->setObjectName("TeachAddNoteBtn");
        TeachAddNoteBtn->setMinimumSize(QSize(0, 50));

        horizontalLayout_3->addWidget(TeachAddNoteBtn);

        TeachDelNoteBtn = new QPushButton(horizontalLayoutWidget_6);
        TeachDelNoteBtn->setObjectName("TeachDelNoteBtn");
        TeachDelNoteBtn->setMinimumSize(QSize(0, 50));

        horizontalLayout_3->addWidget(TeachDelNoteBtn);

        TeachEditNoteBtn = new QPushButton(horizontalLayoutWidget_6);
        TeachEditNoteBtn->setObjectName("TeachEditNoteBtn");
        TeachEditNoteBtn->setMinimumSize(QSize(0, 50));

        horizontalLayout_3->addWidget(TeachEditNoteBtn);

        TeachSchdMenu = new QFrame(TeacherWindow);
        TeachSchdMenu->setObjectName("TeachSchdMenu");
        TeachSchdMenu->setGeometry(QRect(160, 0, 1121, 671));
        TeachSchdMenu->setFrameShape(QFrame::Shape::StyledPanel);
        TeachSchdMenu->setFrameShadow(QFrame::Shadow::Raised);
        TeachScroll = new QScrollArea(TeachSchdMenu);
        TeachScroll->setObjectName("TeachScroll");
        TeachScroll->setGeometry(QRect(9, 99, 1101, 571));
        TeachScroll->setWidgetResizable(true);
        TeachScrollContents = new QWidget();
        TeachScrollContents->setObjectName("TeachScrollContents");
        TeachScrollContents->setGeometry(QRect(0, 0, 1099, 569));
        TeachGridWidget = new QWidget(TeachScrollContents);
        TeachGridWidget->setObjectName("TeachGridWidget");
        TeachGridWidget->setGeometry(QRect(0, 0, 1101, 571));
        gridLayoutWidget = new QWidget(TeachGridWidget);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(0, 0, 1101, 571));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        TeachScroll->setWidget(TeachScrollContents);
        Nauczyciel->setCentralWidget(TeacherWindow);
        TeachSideBar->raise();
        TeachAttndcMenu->raise();
        TeachGrdMenu->raise();
        TeachNoteMenu->raise();
        TeachSchdMenu->raise();

        retranslateUi(Nauczyciel);

        QMetaObject::connectSlotsByName(Nauczyciel);
    } // setupUi

    void retranslateUi(QMainWindow *Nauczyciel)
    {
        Nauczyciel->setWindowTitle(QCoreApplication::translate("Nauczyciel", "MainWindow", nullptr));
        TeachGrdBtn->setText(QCoreApplication::translate("Nauczyciel", "Oceny", nullptr));
        TeachSchdBtn->setText(QCoreApplication::translate("Nauczyciel", "Plan Zaj\304\231\304\207", nullptr));
        TeachAttndcBtn->setText(QCoreApplication::translate("Nauczyciel", "Frekwencja", nullptr));
        TeachNoteBtn->setText(QCoreApplication::translate("Nauczyciel", "Uwagi", nullptr));
        TeachLogoutBtn->setText(QCoreApplication::translate("Nauczyciel", "Wyloguj", nullptr));
        TeachClassLabel->setText(QCoreApplication::translate("Nauczyciel", "Klasa", nullptr));
        TeachSubjLabel->setText(QCoreApplication::translate("Nauczyciel", "Przedmiot", nullptr));
        TeachAddGrdBtn->setText(QCoreApplication::translate("Nauczyciel", "Dodaj ocen\304\231", nullptr));
        TeachDelGrdBtn->setText(QCoreApplication::translate("Nauczyciel", "Usu\305\204 ocen\304\231", nullptr));
        TeachEditGrdBtn->setText(QCoreApplication::translate("Nauczyciel", "Edytuj ocen\304\231", nullptr));
        TeachClassLabel_2->setText(QCoreApplication::translate("Nauczyciel", "Klasa", nullptr));
        TeachSubjLabel_2->setText(QCoreApplication::translate("Nauczyciel", "Przedmiot", nullptr));
        TeachSubjLabel_3->setText(QCoreApplication::translate("Nauczyciel", "Data", nullptr));
        TeachAddAttndcBtn->setText(QCoreApplication::translate("Nauczyciel", "Dodaj obecno\305\233\304\207", nullptr));
        TeachDelAttndcBtn->setText(QCoreApplication::translate("Nauczyciel", "Usu\305\204 obecno\305\233\304\207", nullptr));
        TeachEditAttndcBtn->setText(QCoreApplication::translate("Nauczyciel", "Zmie\305\204 obecno\305\233\304\207", nullptr));
        TeachClassLabel_3->setText(QCoreApplication::translate("Nauczyciel", "Klasa", nullptr));
        TeachSubjLabel_4->setText(QCoreApplication::translate("Nauczyciel", "Ucze\305\204", nullptr));
        TeachAddNoteBtn->setText(QCoreApplication::translate("Nauczyciel", "Dodaj uwag\304\231", nullptr));
        TeachDelNoteBtn->setText(QCoreApplication::translate("Nauczyciel", "Usu\305\204 uwag\304\231", nullptr));
        TeachEditNoteBtn->setText(QCoreApplication::translate("Nauczyciel", "Zmie\305\204 uwag\304\231", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Nauczyciel: public Ui_Nauczyciel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NAUCZYCIEL_H
