#include "login.h"
#include "./ui_login.h"
#include "admin.h"

#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QSql>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <iostream>


Login::Login(QWidget *parent)
    : QDialog(parent)
    , LoginUi(new Ui::Login)
{
    LoginUi->setupUi(this);
    LoginUi->PassBox->setEchoMode(QLineEdit::Password);
    db.setDatabaseName("GradeFlow_db.db");
}

Login::~Login()
{
    delete LoginUi;
}
    /* Widocznosc hasła */
void Login::on_showPass_toggled(bool checked)
{
    if(checked == true){
        LoginUi->PassBox->setEchoMode(QLineEdit::Normal);
    } else {
        LoginUi->PassBox->setEchoMode(QLineEdit::Password);
    }
}
    /* Obsługa bazy danych */

void db_create(QSqlDatabase db)
{
    if (!db.open()) {
        return;
    }

    QSqlQuery query;

    bool success;
    success = query.exec(
        "CREATE TABLE IF NOT EXISTS UsrTypes ("
        "id INTEGER PRIMARY KEY AUTOINCREMENT, "
        "name TEXT NOT NULL CHECK(name IN ('admin', 'nauczyciel', 'uczen'))) "
        );

    if (!success) {
        return;
    }

    success = query.exec(
        "CREATE TABLE IF NOT EXISTS Users ("
        "id INTEGER PRIMARY KEY AUTOINCREMENT, "
        "username TEXT NOT NULL UNIQUE, "
        "passwrd TEXT NOT NULL,"
        "role_id INTEGER,"
        "FOREIGN KEY (role_id) REFERENCES UsrTypes(id))"
        );

    if (!success) {
        return;
    }

    success = query.exec("INSERT OR IGNORE INTO UsrTypes (name) VALUES ('admin'), ('nauczyciel'), ('uczen')");

    if (!success) {
        return;
    }

    success = query.exec("INSERT OR IGNORE INTO Users (username, passwrd, role_id) VALUES ('admin', '123', 1), ('nauczyciel', '123', 2), ('uczen', '123', 3)");

    if (!success) {
        return;
    }
    db.close();
}

int db_check(QSqlDatabase db, QString pass, QString email)
{
    if (!db.open()) {
        return -1;
    }


    QSqlQuery query;
    query.prepare("SELECT id, role_id FROM Users WHERE username = :username AND passwrd = :passwrd");
    query.bindValue(":username", email);
    query.bindValue(":passwrd", pass);

    if (query.exec()) {
        if (query.next()) {

            int roleId = query.value(1).toInt();
            std::cout << roleId;

            if (roleId == 1) {
                return 1;
            } else if (roleId == 2) {
                return 2;
            } else if (roleId == 3) {
                return 3;
            }
        } else {
            QMessageBox::warning(nullptr, "Błąd logowania", "Niepoprawny login lub hasło.");
            return 5;
        }
    }
    db.close();
}
// BRAK RETURN POZA WARUNKIEM JEST CELOWY!!!

    /* Funkcja Logowania */

void Login::on_LoginBtn_clicked()
{
    ::db_create(db);

    QString email = LoginUi->EmailBox->text();                                                  //zamien text z boxa na stringa
    QString pass = LoginUi->PassBox->text();                                                    //zamien text z boxa na stringa

    if (email.isEmpty() || pass.isEmpty()) {                                               //sprawdz czy uzytkownik w ogole cos wpisal
        QMessageBox::warning(this, "Błąd logowania", "Wypełnij wszystkie pola.");
    } else {
        int okno = ::db_check(db, pass, email);
        if (okno == 1) {
            Admin *adminWindow = new Admin;
            this->hide();
            adminWindow -> show();
        } /*else if (okno == 2) {
            Nauczyciel *nauczycielWindow = new Nauczyciel;
            nauczycielWindow->show();
            this->hide();
        } else if (okno == 3) {
            Uczen *uczenWindow = new Uczen;
            uczenWindow->show();
            this->hide();
        }*/

    }
}




