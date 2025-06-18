/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QFrame *LoginMainBox;
    QPushButton *LoginBtn;
    QCheckBox *showPass;
    QLineEdit *EmailBox;
    QLineEdit *PassBox;
    QLabel *LogowanieText;
    QLabel *EmailText;
    QLabel *HasloText;

    void setupUi(QDialog *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName("Login");
        Login->resize(500, 700);
        Login->setMinimumSize(QSize(500, 700));
        Login->setMaximumSize(QSize(500, 700));
        Login->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:1, x2:0, y2:0, stop:0 rgba(33, 33, 33, 255), stop:1 rgba(48, 48, 48, 255));\n"
"color: rgb(255,255,255);"));
        LoginMainBox = new QFrame(Login);
        LoginMainBox->setObjectName("LoginMainBox");
        LoginMainBox->setGeometry(QRect(50, 50, 400, 600));
        LoginMainBox->setStyleSheet(QString::fromUtf8("background-color: rgba(50, 50, 50,0);\n"
"border-radius: 15px;\n"
""));
        LoginMainBox->setFrameShape(QFrame::Shape::StyledPanel);
        LoginMainBox->setFrameShadow(QFrame::Shadow::Raised);
        LoginBtn = new QPushButton(LoginMainBox);
        LoginBtn->setObjectName("LoginBtn");
        LoginBtn->setGeometry(QRect(125, 450, 150, 30));
        QFont font;
        font.setFamilies({QString::fromUtf8("Urbanist")});
        font.setPointSize(18);
        font.setBold(true);
        LoginBtn->setFont(font);
        LoginBtn->setStyleSheet(QString::fromUtf8("background-color: rgb(255,255,255);\n"
"border-radius: 5px;\n"
"color:rgb(21,21,21);"));
        showPass = new QCheckBox(LoginMainBox);
        showPass->setObjectName("showPass");
        showPass->setGeometry(QRect(50, 350, 200, 30));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Urbanist")});
        font1.setPointSize(18);
        font1.setBold(false);
        showPass->setFont(font1);
        showPass->setStyleSheet(QString::fromUtf8("background-color: rgba(255,255,255,0);\n"
"border-radius: 5px;\n"
"color:rgb(255,255,255);"));
        EmailBox = new QLineEdit(LoginMainBox);
        EmailBox->setObjectName("EmailBox");
        EmailBox->setGeometry(QRect(50, 220, 300, 30));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Urbanist")});
        font2.setPointSize(12);
        font2.setBold(true);
        EmailBox->setFont(font2);
        EmailBox->setStyleSheet(QString::fromUtf8("background-color: rgb(255,255,255);\n"
"border-radius: 5px;\n"
"color:rgb(21,21,21);"));
        PassBox = new QLineEdit(LoginMainBox);
        PassBox->setObjectName("PassBox");
        PassBox->setGeometry(QRect(50, 310, 300, 30));
        PassBox->setFont(font2);
        PassBox->setStyleSheet(QString::fromUtf8("background-color: rgb(255,255,255);\n"
"border-radius: 5px;\n"
"color:rgb(21,21,21);"));
        LogowanieText = new QLabel(LoginMainBox);
        LogowanieText->setObjectName("LogowanieText");
        LogowanieText->setGeometry(QRect(62, 60, 276, 60));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Urbanist")});
        font3.setPointSize(36);
        font3.setBold(true);
        LogowanieText->setFont(font3);
        LogowanieText->setStyleSheet(QString::fromUtf8("background-color: rgba(0,0,0,0);\n"
"border-radius: 0px;\n"
"color: rgb(255,255,255);"));
        EmailText = new QLabel(LoginMainBox);
        EmailText->setObjectName("EmailText");
        EmailText->setGeometry(QRect(50, 180, 300, 30));
        EmailText->setFont(font1);
        EmailText->setStyleSheet(QString::fromUtf8("background-color: rgba(0,0,0,0);\n"
"border-radius: 0px;\n"
"color: rgb(255,255,255);"));
        HasloText = new QLabel(LoginMainBox);
        HasloText->setObjectName("HasloText");
        HasloText->setGeometry(QRect(50, 270, 300, 30));
        HasloText->setFont(font1);
        HasloText->setStyleSheet(QString::fromUtf8("background-color: rgba(0,0,0,0);\n"
"border-radius: 0px;\n"
"color: rgb(255,255,255);"));

        retranslateUi(Login);

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QDialog *Login)
    {
        Login->setWindowTitle(QCoreApplication::translate("Login", "Login", nullptr));
        LoginBtn->setText(QCoreApplication::translate("Login", "ZALOGUJ", nullptr));
        showPass->setText(QCoreApplication::translate("Login", "Poka\305\274 has\305\202o", nullptr));
        LogowanieText->setText(QCoreApplication::translate("Login", "LOGOWANIE", nullptr));
        EmailText->setText(QCoreApplication::translate("Login", "Login", nullptr));
        HasloText->setText(QCoreApplication::translate("Login", "Has\305\202o", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
