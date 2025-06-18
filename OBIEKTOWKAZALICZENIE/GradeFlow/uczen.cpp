#include "uczen.h"
#include "ui_uczen.h"
#include "login.h"

#include <QMessageBox>
#include <QInputDialog>
#include <QSql>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlQueryModel>
#include <QDebug>
#include <QDate>


Uczen::Uczen(int studId, QWidget *parent)
    : QMainWindow(parent)
    , UczenUi(new Ui::Uczen)
    , c_userId(studId)
{
    UczenUi->setupUi(this);
    UczenUi->StudAttndcMenu->hide();
    UczenUi->StudGrdMenu->hide();
    UczenUi->StudSchdMenu->hide();
    UczenUi->StudNotesMenu->hide();

    db.setDatabaseName("GradeFlow_db.db");
    StudGrdModel = new QSqlQueryModel(this);
    StudAttndcModel = new QSqlQueryModel(this);
    StudNoteModel = new QSqlQueryModel(this);
    StudSchdModel = new QSqlQueryModel(this);

    UczenUi->StudAttndcList->setModel(StudAttndcModel);
    UczenUi->StudGrdList->setModel(StudGrdModel);
    UczenUi->StudNotesList->setModel(StudNoteModel);
    UczenUi->StudSchdList->setModel(StudSchdModel);
}

Uczen::~Uczen()
{
    delete UczenUi;
    delete StudGrdModel;
    delete StudNoteModel;
    delete StudAttndcModel;
    delete StudSchdModel;
}

    /* OBSŁUGA BAZY DANYCH */
void db_studgrd_list(QSqlDatabase db, QSqlQueryModel *model, Ui::Uczen *ui, int c_userId)
{
    if (!db.open()){
        qDebug() << "Błąd połączenia z bazą danych";
        return;
    }

    QSqlQuery query;
    query.prepare(
        "SELECT "
        "Grades.id AS ID, "
        "Students.name || ' ' || Students.name AS Uczen, "
        "Subjects.name AS Przedmiot, "
        "Grades.val AS Ocena, "
        "Grades.date AS Data "
        "FROM Grades "
        "JOIN Students ON Grades.stud_id = Students.id "
        "JOIN Subjects ON Grades.subj_id = Subjects.id "
        "WHERE Students.id = :stud_id "
        "ORDER BY Grades.date DESC;"
        );
    query.bindValue(":stud_id", c_userId);

    if(!query.exec()) {
        qDebug() << query.lastError();
    }

    model -> setQuery(std::move(query));
    ui->StudGrdList->resizeColumnsToContents();
    db.close();
}

void db_studattndc_list(QSqlDatabase db, QSqlQueryModel *model, Ui::Uczen *ui, int c_userId)
{
    if (!db.open()){
        qDebug() << "Błąd połączenia z bazą danych";
        return;
    }

    QSqlQuery query;
    query.prepare(
        "SELECT "
        "Atndnc.id AS ID, "
        "Students.name || ' ' || Students.surname AS Uczen, "
        "Classes.name AS Klasa, "
        "Schedules.dotw AS Dzien, "
        "Schedules.hour AS Godzina, "
        "Atndnc.state AS Stan "
        "FROM Atndnc "
        "JOIN Students ON Atndnc.stud_id = Students.id "
        "JOIN Schedules ON Atndnc.less_id = Schedules.id "
        "JOIN Classes ON Schedules.class_id = Classes.id "
        "WHERE Students.id = :stud_id "
        "ORDER BY Classes.name, Schedules.dotw, Schedules.hour;"
        );
    query.bindValue(":stud_id", c_userId);

    if(!query.exec()) {
        qDebug() << query.lastError();
    }

    model -> setQuery(std::move(query));
    ui->StudAttndcList->resizeColumnsToContents();
    db.close();
}

void db_studschd_list(QSqlDatabase db, QSqlQueryModel *model, Ui::Uczen *ui, int c_userId)
{
    if (!db.open()){
        qDebug() << "Błąd połączenia z bazą danych";
        return;
    }

    QSqlQuery query;
    query.prepare(
        "SELECT "
        "Schedules.id AS ID, "
        "Schedules.dotw AS Dzien, "
        "Schedules.hour AS Godzina, "
        "Subjects.name AS Przedmiot, "
        "Classes.name AS Klasa "
        "FROM Schedules "
        "JOIN Subjects ON Schedules.subj_id = Subjects.id "
        "JOIN Classes ON Schedules.class_id = Classes.id "
        "JOIN Students ON Students.class_id = Classes.id "
        "WHERE Students.id = :stud_id "
        "ORDER BY CASE Schedules.dotw "
        "WHEN 'poniedzialek' THEN 1 "
        "WHEN 'wtorek' THEN 2 "
        "WHEN 'sroda' THEN 3 "
        "WHEN 'czwartek' THEN 4 "
        "WHEN 'piatek' THEN 5 END, "
        "Schedules.hour;"
        );
    query.bindValue(":stud_id", c_userId);

    if(!query.exec()) {
        qDebug() << query.lastError();
    }

    model -> setQuery(std::move(query));
    ui->StudSchdList->resizeColumnsToContents();
    db.close();
}

void db_studnote_list(QSqlDatabase db, QSqlQueryModel *model, Ui::Uczen *ui, int c_userId)
{
    if (!db.open()){
        qDebug() << "Błąd połączenia z bazą danych";
        return;
    }

    QSqlQuery query;
    query.prepare(
        "SELECT "
        "Notes.id AS ID, "
        "Students.name || ' ' || Students.surname AS Uczen, "
        "Subjects.name AS Przedmiot, "
        "Notes.note AS Uwaga, "
        "Notes.date AS Data "
        "FROM Notes "
        "JOIN Students ON Notes.stud_id = Students.id "
        "JOIN Subjects ON Notes.subj_id = Subjects.id "
        "WHERE Students.id = :stud_id "
        "ORDER BY Notes.date DESC;"
        );
    query.bindValue(":stud_id", c_userId);

    if(!query.exec()) {
        qDebug() << query.lastError();
    }

    model -> setQuery(std::move(query));
    ui->StudNotesList->resizeColumnsToContents();
    db.close();
}

    /* SIDE BAR */
void Uczen::on_StudGrdBtn_clicked()
{
    if (UczenUi->StudGrdMenu->isVisible()){
        UczenUi->StudGrdMenu->hide();
    } else {
        UczenUi->StudAttndcMenu->hide();
        UczenUi->StudSchdMenu->hide();
        UczenUi->StudNotesMenu->hide();

        UczenUi->StudAttndcBtn->setChecked(false);
        UczenUi->StudSchdBtn->setChecked(false);
        UczenUi->StudNoteBtn->setChecked(false);

        UczenUi->StudGrdMenu->show();
        ::db_studgrd_list(db, StudGrdModel, UczenUi, c_userId);
    }
}


void Uczen::on_StudSchdBtn_clicked()
{
    if (UczenUi->StudSchdMenu->isVisible()){
        UczenUi->StudSchdMenu->hide();
        UczenUi->StudSchdBtn->setChecked(false);
    } else {
        UczenUi->StudAttndcMenu->hide();
        UczenUi->StudGrdMenu->hide();
        UczenUi->StudNotesMenu->hide();

        UczenUi->StudAttndcBtn->setChecked(false);
        UczenUi->StudGrdBtn->setChecked(false);
        UczenUi->StudNoteBtn->setChecked(false);

        UczenUi->StudSchdMenu->show();
        ::db_studschd_list(db, StudSchdModel, UczenUi, c_userId);
    }
}


void Uczen::on_StudAttndcBtn_clicked()
{
    if (UczenUi->StudAttndcMenu->isVisible()){
        UczenUi->StudAttndcMenu->hide();
        UczenUi->StudAttndcBtn->setChecked(false);
    } else {
        UczenUi->StudGrdMenu->hide();
        UczenUi->StudSchdMenu->hide();
        UczenUi->StudNotesMenu->hide();

        UczenUi->StudGrdBtn->setChecked(false);
        UczenUi->StudSchdBtn->setChecked(false);
        UczenUi->StudNoteBtn->setChecked(false);

        UczenUi->StudAttndcMenu->show();
        ::db_studattndc_list(db, StudAttndcModel, UczenUi, c_userId);
    }
}


void Uczen::on_StudNoteBtn_clicked()
{
    if (UczenUi->StudNotesMenu->isVisible()){
        UczenUi->StudNotesMenu->hide();
        UczenUi->StudNoteBtn->setChecked(false);
    } else {
        UczenUi->StudGrdMenu->hide();
        UczenUi->StudSchdMenu->hide();
        UczenUi->StudAttndcMenu->hide();

        UczenUi->StudGrdBtn->setChecked(false);
        UczenUi->StudSchdBtn->setChecked(false);
        UczenUi->StudAttndcBtn->setChecked(false);

        UczenUi->StudNotesMenu->show();
        ::db_studnote_list(db, StudNoteModel, UczenUi, c_userId);
    }
}


void Uczen::on_StudLogoutBtn_clicked()
{
    this->close();
    Login *loginWindow = new Login;
    loginWindow -> show();
}
