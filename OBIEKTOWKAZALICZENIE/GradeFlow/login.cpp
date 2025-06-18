#include "login.h"
#include "./ui_login.h"
#include "admin.h"
#include "nauczyciel.h"
#include "uczen.h"

#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QSql>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>


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
        "name TEXT NOT NULL UNIQUE CHECK(name IN ('admin', 'nauczyciel', 'uczen'))) "
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

int db_check(QSqlDatabase db, QString pass, QString email,int &id, int &id2)
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
            int userId = query.value(0).toInt();
            int roleId = query.value(1).toInt();

            if (roleId == 1) {
                return 1;
            } else if (roleId == 2) {

                QSqlQuery teachQuery;
                teachQuery.prepare("SELECT id FROM Teachers WHERE user_id = :userId");
                teachQuery.bindValue(":userId", userId);

                if (teachQuery.exec() && teachQuery.next()) {
                    id = teachQuery.value(0).toInt();
                }
                return 2;
            } else if (roleId == 3) {
                QSqlQuery studQuery;
                studQuery.prepare("SELECT id FROM Students WHERE user_id = :userId");
                studQuery.bindValue(":userId", userId);

                if (studQuery.exec() && studQuery.next()) {
                    id2 = studQuery.value(0).toInt();
                }
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
    int teachId = -1;
    int studId = -1;

    QString email = LoginUi->EmailBox->text();
    QString pass = LoginUi->PassBox->text();

    if (email.isEmpty() || pass.isEmpty()) {
        QMessageBox::warning(this, "Błąd logowania", "Wypełnij wszystkie pola.");
    } else {
        int okno = ::db_check(db, pass, email, teachId, studId);
        db.close();

        if (okno == 1) {
            Admin *adminWindow = new Admin;
            this->hide();
            adminWindow -> show();
        } else if (okno == 2) {
            Nauczyciel *nauczycielWindow = new Nauczyciel(teachId);
            nauczycielWindow->show();
            this->hide();
        } else if (okno == 3) {
            qDebug() << studId;
            Uczen *uczenWindow = new Uczen(studId);
            uczenWindow->show();
            this->hide();
        }

    }
}
