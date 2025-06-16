/********************************************************************************
** Form generated from reading UI file 'admin.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMIN_H
#define UI_ADMIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Admin
{
public:
    QWidget *AdminWindow;
    QFrame *AdminUsrMenu;
    QTableView *UsrList;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *AdminHori1;
    QPushButton *AdminAddUsrBtn;
    QPushButton *AdminDelUsrBtn;
    QPushButton *AdminEditUsrBtn;
    QFrame *AdminSideBar;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *AdminVert;
    QPushButton *AdminUsrBtn;
    QPushButton *AdminClassBtn;
    QPushButton *AdminSubjBtn;
    QPushButton *AdminSchdBtn;
    QSpacerItem *verticalSpacer;
    QPushButton *AdminLogoutBtn;
    QFrame *AdminSubjMenu;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *AdminHori3;
    QPushButton *AdminAddSubjBtn;
    QPushButton *AdminDelSubjBtn;
    QPushButton *AdminEditSubjBtn;
    QTableView *SubjList;
    QFrame *AdminSchdMenu;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *AdminHori4;
    QPushButton *AdminAddSchdBtn;
    QPushButton *AdminDelSchdBtn;
    QPushButton *AdminEditSchdBtn;
    QTableView *SchdList;
    QFrame *AdminClassMenu;
    QWidget *horizontalLayoutWidget_4;
    QHBoxLayout *AdminHori2;
    QPushButton *AdminAddClassBtn;
    QPushButton *AdminDelClassBtn;
    QPushButton *AdminEditClassBtn;
    QTableView *ClassList;

    void setupUi(QMainWindow *Admin)
    {
        if (Admin->objectName().isEmpty())
            Admin->setObjectName("Admin");
        Admin->resize(1280, 720);
        Admin->setMinimumSize(QSize(1280, 720));
        Admin->setMaximumSize(QSize(1280, 720));
        Admin->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:1, x2:0, y2:0, stop:0 rgba(33, 33, 33, 255), stop:1 rgba(48, 48, 48, 255));\n"
"color: rgb(255,255,255);"));
        AdminWindow = new QWidget(Admin);
        AdminWindow->setObjectName("AdminWindow");
        AdminUsrMenu = new QFrame(AdminWindow);
        AdminUsrMenu->setObjectName("AdminUsrMenu");
        AdminUsrMenu->setGeometry(QRect(150, 0, 1131, 660));
        AdminUsrMenu->setMinimumSize(QSize(0, 660));
        AdminUsrMenu->setMaximumSize(QSize(16777215, 660));
        AdminUsrMenu->setFrameShape(QFrame::Shape::StyledPanel);
        AdminUsrMenu->setFrameShadow(QFrame::Shadow::Raised);
        UsrList = new QTableView(AdminUsrMenu);
        UsrList->setObjectName("UsrList");
        UsrList->setGeometry(QRect(0, 120, 1131, 541));
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::BrushStyle::SolidPattern);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::WindowText, brush);
        QLinearGradient gradient(0, 1, 0, 0);
        gradient.setSpread(QGradient::Spread::PadSpread);
        gradient.setCoordinateMode(QGradient::CoordinateMode::ObjectBoundingMode);
        gradient.setColorAt(0, QColor(33, 33, 33, 255));
        gradient.setColorAt(1, QColor(48, 48, 48, 255));
        QBrush brush1(gradient);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Button, brush1);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Text, brush);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::ButtonText, brush);
        QLinearGradient gradient1(0, 1, 0, 0);
        gradient1.setSpread(QGradient::Spread::PadSpread);
        gradient1.setCoordinateMode(QGradient::CoordinateMode::ObjectBoundingMode);
        gradient1.setColorAt(0, QColor(33, 33, 33, 255));
        gradient1.setColorAt(1, QColor(48, 48, 48, 255));
        QBrush brush2(gradient1);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Base, brush2);
        QLinearGradient gradient2(0, 1, 0, 0);
        gradient2.setSpread(QGradient::Spread::PadSpread);
        gradient2.setCoordinateMode(QGradient::CoordinateMode::ObjectBoundingMode);
        gradient2.setColorAt(0, QColor(33, 33, 33, 255));
        gradient2.setColorAt(1, QColor(48, 48, 48, 255));
        QBrush brush3(gradient2);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Window, brush3);
        QBrush brush4(QColor(255, 255, 255, 128));
        brush4.setStyle(Qt::BrushStyle::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::PlaceholderText, brush4);
#endif
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::WindowText, brush);
        QLinearGradient gradient3(0, 1, 0, 0);
        gradient3.setSpread(QGradient::Spread::PadSpread);
        gradient3.setCoordinateMode(QGradient::CoordinateMode::ObjectBoundingMode);
        gradient3.setColorAt(0, QColor(33, 33, 33, 255));
        gradient3.setColorAt(1, QColor(48, 48, 48, 255));
        QBrush brush5(gradient3);
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Button, brush5);
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Text, brush);
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::ButtonText, brush);
        QLinearGradient gradient4(0, 1, 0, 0);
        gradient4.setSpread(QGradient::Spread::PadSpread);
        gradient4.setCoordinateMode(QGradient::CoordinateMode::ObjectBoundingMode);
        gradient4.setColorAt(0, QColor(33, 33, 33, 255));
        gradient4.setColorAt(1, QColor(48, 48, 48, 255));
        QBrush brush6(gradient4);
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Base, brush6);
        QLinearGradient gradient5(0, 1, 0, 0);
        gradient5.setSpread(QGradient::Spread::PadSpread);
        gradient5.setCoordinateMode(QGradient::CoordinateMode::ObjectBoundingMode);
        gradient5.setColorAt(0, QColor(33, 33, 33, 255));
        gradient5.setColorAt(1, QColor(48, 48, 48, 255));
        QBrush brush7(gradient5);
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Window, brush7);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::PlaceholderText, brush4);
#endif
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::WindowText, brush);
        QLinearGradient gradient6(0, 1, 0, 0);
        gradient6.setSpread(QGradient::Spread::PadSpread);
        gradient6.setCoordinateMode(QGradient::CoordinateMode::ObjectBoundingMode);
        gradient6.setColorAt(0, QColor(33, 33, 33, 255));
        gradient6.setColorAt(1, QColor(48, 48, 48, 255));
        QBrush brush8(gradient6);
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Button, brush8);
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Text, brush);
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::ButtonText, brush);
        QLinearGradient gradient7(0, 1, 0, 0);
        gradient7.setSpread(QGradient::Spread::PadSpread);
        gradient7.setCoordinateMode(QGradient::CoordinateMode::ObjectBoundingMode);
        gradient7.setColorAt(0, QColor(33, 33, 33, 255));
        gradient7.setColorAt(1, QColor(48, 48, 48, 255));
        QBrush brush9(gradient7);
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Base, brush9);
        QLinearGradient gradient8(0, 1, 0, 0);
        gradient8.setSpread(QGradient::Spread::PadSpread);
        gradient8.setCoordinateMode(QGradient::CoordinateMode::ObjectBoundingMode);
        gradient8.setColorAt(0, QColor(33, 33, 33, 255));
        gradient8.setColorAt(1, QColor(48, 48, 48, 255));
        QBrush brush10(gradient8);
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Window, brush10);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::PlaceholderText, brush4);
#endif
        UsrList->setPalette(palette);
        UsrList->setStyleSheet(QString::fromUtf8("QHeaderView::section {\n"
"        background-color: #444444;\n"
"        color: white; \n"
"        font-weight: bold; \n"
"        padding: 4px;\n"
"        border: 1px solid #222222;\n"
"}"));
        horizontalLayoutWidget = new QWidget(AdminUsrMenu);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(0, -1, 1131, 121));
        AdminHori1 = new QHBoxLayout(horizontalLayoutWidget);
        AdminHori1->setObjectName("AdminHori1");
        AdminHori1->setContentsMargins(0, 0, 0, 0);
        AdminAddUsrBtn = new QPushButton(horizontalLayoutWidget);
        AdminAddUsrBtn->setObjectName("AdminAddUsrBtn");
        AdminAddUsrBtn->setMinimumSize(QSize(0, 0));

        AdminHori1->addWidget(AdminAddUsrBtn);

        AdminDelUsrBtn = new QPushButton(horizontalLayoutWidget);
        AdminDelUsrBtn->setObjectName("AdminDelUsrBtn");

        AdminHori1->addWidget(AdminDelUsrBtn);

        AdminEditUsrBtn = new QPushButton(horizontalLayoutWidget);
        AdminEditUsrBtn->setObjectName("AdminEditUsrBtn");

        AdminHori1->addWidget(AdminEditUsrBtn);

        AdminSideBar = new QFrame(AdminWindow);
        AdminSideBar->setObjectName("AdminSideBar");
        AdminSideBar->setGeometry(QRect(0, -1, 151, 720));
        AdminSideBar->setMaximumSize(QSize(16777215, 720));
        AdminSideBar->setStyleSheet(QString::fromUtf8("background-color: rgb(33, 33, 33);"));
        AdminSideBar->setFrameShape(QFrame::Shape::StyledPanel);
        AdminSideBar->setFrameShadow(QFrame::Shadow::Raised);
        verticalLayoutWidget = new QWidget(AdminSideBar);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(0, 0, 151, 722));
        AdminVert = new QVBoxLayout(verticalLayoutWidget);
        AdminVert->setSpacing(0);
        AdminVert->setObjectName("AdminVert");
        AdminVert->setContentsMargins(0, 0, 0, 0);
        AdminUsrBtn = new QPushButton(verticalLayoutWidget);
        AdminUsrBtn->setObjectName("AdminUsrBtn");
        AdminUsrBtn->setMinimumSize(QSize(0, 60));
        AdminUsrBtn->setCheckable(true);

        AdminVert->addWidget(AdminUsrBtn);

        AdminClassBtn = new QPushButton(verticalLayoutWidget);
        AdminClassBtn->setObjectName("AdminClassBtn");
        AdminClassBtn->setMinimumSize(QSize(0, 60));
        AdminClassBtn->setCheckable(true);

        AdminVert->addWidget(AdminClassBtn);

        AdminSubjBtn = new QPushButton(verticalLayoutWidget);
        AdminSubjBtn->setObjectName("AdminSubjBtn");
        AdminSubjBtn->setMinimumSize(QSize(0, 60));
        AdminSubjBtn->setCheckable(true);

        AdminVert->addWidget(AdminSubjBtn);

        AdminSchdBtn = new QPushButton(verticalLayoutWidget);
        AdminSchdBtn->setObjectName("AdminSchdBtn");
        AdminSchdBtn->setMinimumSize(QSize(0, 60));
        AdminSchdBtn->setCheckable(true);

        AdminVert->addWidget(AdminSchdBtn);

        verticalSpacer = new QSpacerItem(20, 420, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        AdminVert->addItem(verticalSpacer);

        AdminLogoutBtn = new QPushButton(verticalLayoutWidget);
        AdminLogoutBtn->setObjectName("AdminLogoutBtn");
        AdminLogoutBtn->setMinimumSize(QSize(0, 60));

        AdminVert->addWidget(AdminLogoutBtn);

        AdminSubjMenu = new QFrame(AdminWindow);
        AdminSubjMenu->setObjectName("AdminSubjMenu");
        AdminSubjMenu->setGeometry(QRect(150, 0, 1130, 660));
        AdminSubjMenu->setMinimumSize(QSize(1130, 660));
        AdminSubjMenu->setMaximumSize(QSize(1280, 1130));
        AdminSubjMenu->setFrameShape(QFrame::Shape::StyledPanel);
        AdminSubjMenu->setFrameShadow(QFrame::Shadow::Raised);
        horizontalLayoutWidget_2 = new QWidget(AdminSubjMenu);
        horizontalLayoutWidget_2->setObjectName("horizontalLayoutWidget_2");
        horizontalLayoutWidget_2->setGeometry(QRect(0, 0, 1131, 121));
        AdminHori3 = new QHBoxLayout(horizontalLayoutWidget_2);
        AdminHori3->setObjectName("AdminHori3");
        AdminHori3->setContentsMargins(0, 0, 0, 0);
        AdminAddSubjBtn = new QPushButton(horizontalLayoutWidget_2);
        AdminAddSubjBtn->setObjectName("AdminAddSubjBtn");

        AdminHori3->addWidget(AdminAddSubjBtn);

        AdminDelSubjBtn = new QPushButton(horizontalLayoutWidget_2);
        AdminDelSubjBtn->setObjectName("AdminDelSubjBtn");

        AdminHori3->addWidget(AdminDelSubjBtn);

        AdminEditSubjBtn = new QPushButton(horizontalLayoutWidget_2);
        AdminEditSubjBtn->setObjectName("AdminEditSubjBtn");

        AdminHori3->addWidget(AdminEditSubjBtn);

        SubjList = new QTableView(AdminSubjMenu);
        SubjList->setObjectName("SubjList");
        SubjList->setGeometry(QRect(0, 120, 1131, 541));
        SubjList->setStyleSheet(QString::fromUtf8("QHeaderView::section {\n"
"        background-color: #444444;\n"
"        color: white; \n"
"        font-weight: bold; \n"
"        padding: 4px;\n"
"        border: 1px solid #222222;\n"
"}"));
        AdminSchdMenu = new QFrame(AdminWindow);
        AdminSchdMenu->setObjectName("AdminSchdMenu");
        AdminSchdMenu->setGeometry(QRect(150, 0, 1130, 660));
        AdminSchdMenu->setFrameShape(QFrame::Shape::StyledPanel);
        AdminSchdMenu->setFrameShadow(QFrame::Shadow::Raised);
        horizontalLayoutWidget_3 = new QWidget(AdminSchdMenu);
        horizontalLayoutWidget_3->setObjectName("horizontalLayoutWidget_3");
        horizontalLayoutWidget_3->setGeometry(QRect(0, 0, 1131, 121));
        AdminHori4 = new QHBoxLayout(horizontalLayoutWidget_3);
        AdminHori4->setObjectName("AdminHori4");
        AdminHori4->setContentsMargins(0, 0, 0, 0);
        AdminAddSchdBtn = new QPushButton(horizontalLayoutWidget_3);
        AdminAddSchdBtn->setObjectName("AdminAddSchdBtn");

        AdminHori4->addWidget(AdminAddSchdBtn);

        AdminDelSchdBtn = new QPushButton(horizontalLayoutWidget_3);
        AdminDelSchdBtn->setObjectName("AdminDelSchdBtn");

        AdminHori4->addWidget(AdminDelSchdBtn);

        AdminEditSchdBtn = new QPushButton(horizontalLayoutWidget_3);
        AdminEditSchdBtn->setObjectName("AdminEditSchdBtn");

        AdminHori4->addWidget(AdminEditSchdBtn);

        SchdList = new QTableView(AdminSchdMenu);
        SchdList->setObjectName("SchdList");
        SchdList->setGeometry(QRect(0, 120, 1131, 541));
        SchdList->setStyleSheet(QString::fromUtf8("QHeaderView::section {\n"
"        background-color: #444444;\n"
"        color: white; \n"
"        font-weight: bold; \n"
"        padding: 4px;\n"
"        border: 1px solid #222222;\n"
"}"));
        AdminClassMenu = new QFrame(AdminWindow);
        AdminClassMenu->setObjectName("AdminClassMenu");
        AdminClassMenu->setGeometry(QRect(150, 0, 1130, 660));
        AdminClassMenu->setFrameShape(QFrame::Shape::StyledPanel);
        AdminClassMenu->setFrameShadow(QFrame::Shadow::Raised);
        horizontalLayoutWidget_4 = new QWidget(AdminClassMenu);
        horizontalLayoutWidget_4->setObjectName("horizontalLayoutWidget_4");
        horizontalLayoutWidget_4->setGeometry(QRect(0, 0, 1131, 121));
        AdminHori2 = new QHBoxLayout(horizontalLayoutWidget_4);
        AdminHori2->setObjectName("AdminHori2");
        AdminHori2->setContentsMargins(0, 0, 0, 0);
        AdminAddClassBtn = new QPushButton(horizontalLayoutWidget_4);
        AdminAddClassBtn->setObjectName("AdminAddClassBtn");

        AdminHori2->addWidget(AdminAddClassBtn);

        AdminDelClassBtn = new QPushButton(horizontalLayoutWidget_4);
        AdminDelClassBtn->setObjectName("AdminDelClassBtn");

        AdminHori2->addWidget(AdminDelClassBtn);

        AdminEditClassBtn = new QPushButton(horizontalLayoutWidget_4);
        AdminEditClassBtn->setObjectName("AdminEditClassBtn");

        AdminHori2->addWidget(AdminEditClassBtn);

        ClassList = new QTableView(AdminClassMenu);
        ClassList->setObjectName("ClassList");
        ClassList->setGeometry(QRect(0, 120, 1131, 541));
        ClassList->setStyleSheet(QString::fromUtf8("QHeaderView::section {\n"
"        background-color: #444444;\n"
"        color: white; \n"
"        font-weight: bold; \n"
"        padding: 4px;\n"
"        border: 1px solid #222222;\n"
"}"));
        Admin->setCentralWidget(AdminWindow);

        retranslateUi(Admin);

        QMetaObject::connectSlotsByName(Admin);
    } // setupUi

    void retranslateUi(QMainWindow *Admin)
    {
        Admin->setWindowTitle(QCoreApplication::translate("Admin", "AdminWindow", nullptr));
        AdminAddUsrBtn->setText(QCoreApplication::translate("Admin", "Dodaj u\305\274ytkownika", nullptr));
        AdminDelUsrBtn->setText(QCoreApplication::translate("Admin", "Usu\305\204 u\305\274ytkownika", nullptr));
        AdminEditUsrBtn->setText(QCoreApplication::translate("Admin", "Edytuj u\305\274ytkownika", nullptr));
        AdminUsrBtn->setText(QCoreApplication::translate("Admin", "U\305\274ytkownicy", nullptr));
        AdminClassBtn->setText(QCoreApplication::translate("Admin", "Klasy", nullptr));
        AdminSubjBtn->setText(QCoreApplication::translate("Admin", "Przedmioty", nullptr));
        AdminSchdBtn->setText(QCoreApplication::translate("Admin", "Plan Zaj\304\231\304\207", nullptr));
        AdminLogoutBtn->setText(QCoreApplication::translate("Admin", "Wyloguj", nullptr));
        AdminAddSubjBtn->setText(QCoreApplication::translate("Admin", "Dodaj przedmiot", nullptr));
        AdminDelSubjBtn->setText(QCoreApplication::translate("Admin", "Usu\305\204 przedmiot", nullptr));
        AdminEditSubjBtn->setText(QCoreApplication::translate("Admin", "Edytuj przedmiot", nullptr));
        AdminAddSchdBtn->setText(QCoreApplication::translate("Admin", "Dodaj lekcje", nullptr));
        AdminDelSchdBtn->setText(QCoreApplication::translate("Admin", "Usu\305\204 lekcje", nullptr));
        AdminEditSchdBtn->setText(QCoreApplication::translate("Admin", "Edytuj lekcje", nullptr));
        AdminAddClassBtn->setText(QCoreApplication::translate("Admin", "Dodaj Klase", nullptr));
        AdminDelClassBtn->setText(QCoreApplication::translate("Admin", "Usu\305\204 Klase", nullptr));
        AdminEditClassBtn->setText(QCoreApplication::translate("Admin", "Edytuj Klase", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Admin: public Ui_Admin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMIN_H
