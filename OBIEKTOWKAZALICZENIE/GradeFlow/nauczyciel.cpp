#include "nauczyciel.h"
#include "ui_nauczyciel.h"
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


Nauczyciel::Nauczyciel(int teachId, QWidget *parent)
    : QMainWindow(parent)
    , NauczycielUi(new Ui::Nauczyciel)
    , c_userId(teachId)


{
    NauczycielUi->setupUi(this);
    NauczycielUi->TeachGrdMenu->hide();
    NauczycielUi->TeachAttndcMenu->hide();
    NauczycielUi->TeachSchdMenu->hide();
    NauczycielUi->TeachNoteMenu->hide();

    db.setDatabaseName("GradeFlow_db.db");

    GrdModel = new QSqlQueryModel(this);
    AttndcModel = new QSqlQueryModel(this);
    NoteModel = new QSqlQueryModel(this);
    TeachSchdModel = new QSqlQueryModel(this);

    NauczycielUi->TeachSchdList->setModel(TeachSchdModel);
    NauczycielUi->TeachGrdList->setModel(GrdModel);
    NauczycielUi->TeachAttndcList->setModel(AttndcModel);
    NauczycielUi->TeachNotesList->setModel(NoteModel);
}

Nauczyciel::~Nauczyciel()
{
    delete NauczycielUi;
    delete GrdModel;
    delete NoteModel;
    delete AttndcModel;
    delete TeachSchdModel;
}

    /* ZARZADZANIE BAZA DANYCH */
void db_grd_list (QSqlDatabase db, QSqlQueryModel *model, Ui::Nauczyciel *ui) {
    if (!db.open()) {
        return;
    }

    QSqlQuery query;
    bool ok = query.exec(
        "SELECT "
        "Grades.id AS ID, "
        "Students.name || ' ' || Students.surname AS Uczen, "
        "Subjects.name AS Przedmiot, "
        "Grades.val AS Ocena, "
        "Grades.date AS Data "
        "FROM Grades "
        "JOIN Students ON Grades.stud_id = Students.id "
        "JOIN Subjects ON Grades.subj_id = Subjects.id "
        "ORDER BY Data DESC;"
        );
    if (!ok) {
        return;
    }

    model->setQuery(std::move(query));
    ui->TeachGrdList->resizeColumnsToContents();
    db.close();
}

void db_attndc_list(QSqlDatabase db, QSqlQueryModel *model, Ui::Nauczyciel *ui) {
    if (!db.open()) return;

    QSqlQuery q;
    q.exec(
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
        "ORDER BY Classes.name, Schedules.dotw, Schedules.hour;"
        );
    model->setQuery(std::move(q));
    ui->TeachAttndcList->resizeColumnsToContents();
    db.close();
}

void db_schd_list(QSqlDatabase db, QSqlQueryModel *model, Ui::Nauczyciel *ui, int c_userId)
{
    if (!db.open()) return;

    QSqlQuery q;
    q.prepare(
        "SELECT id AS ID, "
        "dotw AS Dzien, "
        "hour AS Godzina, "
        "(SELECT name FROM Subjects WHERE id = subj_id) AS Przedmiot, "
        "(SELECT name FROM Classes WHERE id = class_id) AS Klasa "
        "FROM Schedules "
        "WHERE teach_id = :tid "
        "ORDER BY CASE dotw "
        "WHEN 'poniedzialek' THEN 1 "
        "WHEN 'wtorek' THEN 2 "
        "WHEN 'sroda' THEN 3 "
        "WHEN 'czwartek' THEN 4 "
        "WHEN 'piatek' THEN 5 END, "
        "hour;"
        );
    q.bindValue(":tid", c_userId);
    q.exec();

    model->setQuery(std::move(q));
    ui->TeachSchdList->resizeColumnsToContents();
    db.close();
}

void db_note_list(QSqlDatabase db, QSqlQueryModel *model, Ui::Nauczyciel *ui)
{
    if (!db.open()) return;

    QSqlQuery q;
    q.exec(
        "SELECT "
        "Notes.id AS ID, "
        "Students.name || ' ' || Students.surname AS Uczen, "
        "Subjects.name AS Przedmiot, "
        "Notes.note AS Uwaga, "
        "Notes.date AS Data "
        "FROM Notes "
        "JOIN Students ON Notes.stud_id = Students.id "
        "JOIN Subjects ON Notes.subj_id = Subjects.id "
        "ORDER BY Notes.date DESC;"
        );
    model->setQuery(std::move(q));
    ui->TeachNotesList->resizeColumnsToContents();
    db.close();
}

void Nauczyciel::ComboBoxy(QSqlDatabase db, Ui::Nauczyciel *ui){
    ui->TeachClassCBox->clear();
    ui->TeachSubjCBox->clear();
    ui->TeachClassCBox_4->clear();
    ui->TeachDateCBox->clear();
    ui->TeachSubjCBox_4->clear();


    if (!db.open()) {
        QMessageBox::warning(this, "Błąd bazy", db.lastError().text());
        return;
    }

    QSqlQuery query;
    bool success;

    success = query.exec(
        "SELECT id, name "
        "FROM Classes "
        "ORDER BY name;"
        );
    if (!success) {
        return;
    }

    while (query.next()) {
        int id   = query.value(0).toInt();
        QString name = query.value(1).toString();
        ui->TeachClassCBox->addItem(name, id);
    }

    success = query.exec(
        "SELECT id, name "
        "FROM Subjects "
        "ORDER BY name; "
        );
    if (!success) {
        return;
    }
    while (query.next()) {
        ui->TeachSubjCBox->addItem(query.value(1).toString(), query.value(0).toInt());
    }

    query.exec(
        "SELECT id, name "
        "FROM Classes "
        "ORDER BY name;"
        );
    while (query.next()) {
        ui->TeachClassCBox_4->addItem(
            query.value(1).toString(),
            query.value(0).toInt()
            );
    }


    query.exec(
        "SELECT DISTINCT dotw "
        "FROM Schedules "
        "ORDER BY CASE dotw "
        "WHEN 'poniedzialek' THEN 1 "
        "WHEN 'wtorek'      THEN 2 "
        "WHEN 'sroda'       THEN 3 "
        "WHEN 'czwartek'    THEN 4 "
        "WHEN 'piatek'      THEN 5 END;"
        );
        while (query.next()){
        ui->TeachDateCBox->addItem(
            query.value(0).toString()
            );
        }

    query.exec(
            "SELECT id, name "
            "FROM Subjects "
            "ORDER BY name;"
            );
        while (query.next()) {
            ui->TeachSubjCBox_4->addItem(
                query.value(1).toString(),
                query.value(0).toInt()
                );
        }
    db.close();
}

    /* SIDE BAR */
void Nauczyciel::on_TeachGrdBtn_clicked()
{
    if(NauczycielUi->TeachGrdMenu->isVisible()){
        NauczycielUi->TeachGrdMenu->hide();
    } else {
        Nauczyciel::ComboBoxy(db, NauczycielUi);
        ::db_grd_list(db, GrdModel, NauczycielUi);
        NauczycielUi->TeachAttndcMenu->hide();
        NauczycielUi->TeachSchdMenu->hide();
        NauczycielUi->TeachNoteMenu->hide();
        NauczycielUi->TeachAttndcBtn->setChecked(false);
        NauczycielUi->TeachSchdBtn->setChecked(false);
        NauczycielUi->TeachNoteBtn->setChecked(false);
        NauczycielUi->TeachGrdMenu->show();
    }
}

void Nauczyciel::on_TeachNoteBtn_clicked()
{
    if(NauczycielUi->TeachNoteMenu->isVisible()){
        NauczycielUi->TeachNoteMenu->hide();
    } else {
        Nauczyciel::ComboBoxy(db, NauczycielUi);
        NauczycielUi->TeachAttndcMenu->hide();
        NauczycielUi->TeachSchdMenu->hide();
        NauczycielUi->TeachGrdMenu->hide();
        NauczycielUi->TeachAttndcBtn->setChecked(false);
        NauczycielUi->TeachSchdBtn->setChecked(false);
        NauczycielUi->TeachGrdBtn->setChecked(false);
        NauczycielUi->TeachNoteMenu->show();
        ::db_note_list(db, NoteModel, NauczycielUi);
    }
}

void Nauczyciel::on_TeachAttndcBtn_clicked()
{
    if(NauczycielUi->TeachAttndcMenu->isVisible()){
        NauczycielUi->TeachAttndcMenu->hide();
    } else {
        Nauczyciel::ComboBoxy(db, NauczycielUi);
        NauczycielUi->TeachGrdMenu->hide();
        NauczycielUi->TeachSchdMenu->hide();
        NauczycielUi->TeachNoteMenu->hide();
        NauczycielUi->TeachGrdBtn->setChecked(false);
        NauczycielUi->TeachSchdBtn->setChecked(false);
        NauczycielUi->TeachNoteBtn->setChecked(false);
        NauczycielUi->TeachAttndcMenu->show();
        ::db_attndc_list(db, AttndcModel, NauczycielUi);
    }
}

void Nauczyciel::on_TeachSchdBtn_clicked()
{
    if(NauczycielUi->TeachSchdMenu->isVisible()){
        NauczycielUi->TeachSchdMenu->hide();
    } else {
        Nauczyciel::ComboBoxy(db, NauczycielUi);
        NauczycielUi->TeachAttndcMenu->hide();
        NauczycielUi->TeachGrdMenu->hide();
        NauczycielUi->TeachNoteMenu->hide();
        NauczycielUi->TeachAttndcBtn->setChecked(false);
        NauczycielUi->TeachGrdBtn->setChecked(false);
        NauczycielUi->TeachNoteBtn->setChecked(false);
        NauczycielUi->TeachSchdMenu->show();
        ::db_schd_list(db, TeachSchdModel, NauczycielUi, c_userId);
    }
}

void Nauczyciel::on_TeachLogoutBtn_clicked()
{
    this->close();
    Login *loginWindow = new Login;
    loginWindow -> show();
}

    /* ZARZADZANIE OCENAMI */
void Nauczyciel::on_TeachAddGrdBtn_clicked()
{
    db.open();
    QStringList studentOptions;
    {
        QSqlQuery q("SELECT name || ' ' || surname FROM Students");
        while (q.next())
            studentOptions << q.value(0).toString();
    }
    QString selectedStudent = QInputDialog::getItem(this, "Dodaj ocenę", "Uczeń:", studentOptions, 0, false);
    if (selectedStudent.isEmpty()) return;

    QSqlQuery stuQ;
    stuQ.prepare("SELECT id FROM Students WHERE name || ' ' || surname = :fullName");
    stuQ.bindValue(":fullName", selectedStudent);
    if (!stuQ.exec() || !stuQ.next()) {
        QMessageBox::warning(this, "Błąd", "Nie znaleziono ucznia.");
        return;
    }
    int stud_id = stuQ.value(0).toInt();

    bool okVal;
    double val = QInputDialog::getDouble(this, "Ocena", "Podaj wartość oceny (1.0–6.0):", 1.0, 1.0, 6.0, 1, &okVal);
    if (!okVal) return;

    QStringList subjOptions;
    {
        QSqlQuery q("SELECT name FROM Subjects ORDER BY name");
        while (q.next())
            subjOptions << q.value(0).toString();
    }
    QString selectedSubj = QInputDialog::getItem(this, "Dodaj ocenę", "Przedmiot:", subjOptions, 0, false);
    if (selectedSubj.isEmpty()) return;

    QSqlQuery subQ;
    subQ.prepare("SELECT id FROM Subjects WHERE name = :name;");
    subQ.bindValue(":name", selectedSubj);
    if (!subQ.exec() || !subQ.next()) {
        QMessageBox::warning(this, "Błąd", "Nie znaleziono przedmiotu.");
        return;
    }
    int subj_id = subQ.value(0).toInt();

    QSqlQuery insertQ;
    insertQ.prepare(R"(
        INSERT INTO Grades (val, date, stud_id, teach_id, subj_id)
        VALUES (:val, :date, :stud_id, :teach_id, :subj_id);
    )");
    insertQ.bindValue(":val", val);
    insertQ.bindValue(":date", QDate::currentDate().toString("yyyy-MM-dd"));
    insertQ.bindValue(":stud_id", stud_id);
    insertQ.bindValue(":teach_id", c_userId);
    insertQ.bindValue(":subj_id", subj_id);
    if (!insertQ.exec()) {
        QMessageBox::warning(this, "Błąd dodawania oceny", insertQ.lastError().text());
        return;
    }

    QMessageBox::information(this, "Sukces", "Ocena dodana.");
    ::db_grd_list(QSqlDatabase::database(), GrdModel, NauczycielUi);
    db.close();
}

void Nauczyciel::on_TeachDelGrdBtn_clicked()
{
    db.open();
    QModelIndex index = NauczycielUi->TeachGrdList->currentIndex();
    if (!index.isValid()) {
        QMessageBox::warning(this, "Błąd", "Wybierz ocenę z listy.");
        return;
    }
    int row = index.row();
    int gradeId = GrdModel->data(GrdModel->index(row, 0)).toInt();

    QMessageBox::StandardButton confirm = QMessageBox::question(
        this, "Potwierdź usunięcie",
        "Czy na pewno chcesz usunąć wybraną ocenę?",
        QMessageBox::Yes | QMessageBox::No
        );
    if (confirm != QMessageBox::Yes) return;

    QSqlQuery delQ;
    delQ.prepare("DELETE FROM Grades WHERE id = :id;");
    delQ.bindValue(":id", gradeId);
    if (!delQ.exec()) {
        QMessageBox::warning(this, "Błąd usuwania", delQ.lastError().text());
        return;
    }

    QMessageBox::information(this, "Sukces", "Ocena została usunięta.");
    ::db_grd_list(QSqlDatabase::database(), GrdModel, NauczycielUi);
    db.close();
}

void Nauczyciel::on_TeachEditGrdBtn_clicked()
{
    db.open();
    QModelIndex index = NauczycielUi->TeachGrdList->currentIndex();
    if (!index.isValid()) {
        QMessageBox::warning(this, "Błąd", "Wybierz ocenę z listy.");
        return;
    }
    int row = index.row();
    int gradeId = GrdModel->data(GrdModel->index(row, 0)).toInt();
    double oldVal = GrdModel->data(GrdModel->index(row, 4)).toDouble();

    bool okVal;
    double newVal = QInputDialog::getDouble(this, "Edytuj ocenę", "Nowa wartość:", oldVal, 1.0, 6.0, 1, &okVal);
    if (!okVal) return;

    QSqlQuery updQ;
    updQ.prepare("UPDATE Grades SET val = :val WHERE id = :id");
    updQ.bindValue(":val", newVal);
    updQ.bindValue(":id", gradeId);
    if (!updQ.exec()) {
        QMessageBox::warning(this, "Błąd edycji", updQ.lastError().text());
        return;
    }

    QMessageBox::information(this, "Sukces", "Ocena została zaktualizowana.");
    ::db_grd_list(QSqlDatabase::database(), GrdModel, NauczycielUi);
    db.close();
}

    /* ZARZADZANIE FREKWENCJA */
void Nauczyciel::on_TeachAddAttndcBtn_clicked()
{
    db.open();

    QStringList classOptions;
    {
        QSqlQuery q;
        q.exec("SELECT name FROM Classes ORDER BY name;");
        while (q.next())
            classOptions << q.value(0).toString();
    }
    QString selectedClass = QInputDialog::getItem(this, "Dodaj frekwencję", "Klasa:", classOptions, 0, false);
    if (selectedClass.isEmpty()) { db.close(); return; }

    QSqlQuery clsQ;
    clsQ.prepare("SELECT id FROM Classes WHERE name = :name");
    clsQ.bindValue(":name", selectedClass);
    if (!clsQ.exec() || !clsQ.next()) {
        QMessageBox::warning(this, "Błąd", "Nie znaleziono klasy.");
        db.close();
        return;
    }
    int class_id = clsQ.value(0).toInt();

    QStringList lessonOptions;
    {
        QSqlQuery q;
        q.prepare("SELECT dotw || ' ' || hour FROM Schedules WHERE class_id = :cid ORDER BY dotw, hour;");
        q.bindValue(":cid", class_id);
        q.exec();
        while (q.next())
            lessonOptions << q.value(0).toString();
    }
    QString selectedLesson = QInputDialog::getItem(this, "Dodaj frekwencję", "Lekcja:", lessonOptions, 0, false);
    if (selectedLesson.isEmpty()) { db.close(); return; }

    QSqlQuery lesQ;
    lesQ.prepare("SELECT id FROM Schedules WHERE class_id = :cid AND dotw || ' ' || hour = :desc");
    lesQ.bindValue(":cid", class_id);
    lesQ.bindValue(":desc", selectedLesson);
    if (!lesQ.exec() || !lesQ.next()) {
        QMessageBox::warning(this, "Błąd", "Nie znaleziono lekcji.");
        db.close();
        return;
    }
    int less_id = lesQ.value(0).toInt();

    QStringList studentOptions;
    {
        QSqlQuery q;
        q.prepare("SELECT name || ' ' || surname FROM Students WHERE class_id = :cid;");
        q.bindValue(":cid", class_id);
        q.exec();
        while (q.next())
            studentOptions << q.value(0).toString();
    }
    QString selectedStudent = QInputDialog::getItem(this, "Dodaj frekwencję", "Uczeń:", studentOptions, 0, false);
    if (selectedStudent.isEmpty()) { db.close(); return; }

    QSqlQuery stuQ;
    stuQ.prepare("SELECT id FROM Students WHERE name || ' ' || surname = :fullName AND class_id = :cid");
    stuQ.bindValue(":fullName", selectedStudent);
    stuQ.bindValue(":cid", class_id);
    if (!stuQ.exec() || !stuQ.next()) {
        QMessageBox::warning(this, "Błąd", "Nie znaleziono ucznia.");
        db.close();
        return;
    }
    int stud_id = stuQ.value(0).toInt();

    QStringList stateOptions = {"obecny", "nieobecny", "spozniony", "usprawiedliwiony", "zwolniony"};
    QString selectedState = QInputDialog::getItem(this, "Dodaj frekwencję", "Stan:", stateOptions, 0, false);


    QSqlQuery insQ;
    insQ.prepare(
        "INSERT INTO Atndnc (state, stud_id, less_id) "
        "VALUES (:state, :stud_id, :less_id)"
        );
    insQ.bindValue(":state", selectedState);
    insQ.bindValue(":stud_id", stud_id);
    insQ.bindValue(":less_id", less_id);
    if (!insQ.exec()) {
        QMessageBox::warning(this, "Błąd dodawania", insQ.lastError().text());
        return;
    }

    QMessageBox::information(this, "Sukces", "Frekwencja dodana.");
    ::db_attndc_list(QSqlDatabase::database(), AttndcModel, NauczycielUi);
    db.close();
}

void Nauczyciel::on_TeachDelAttndcBtn_clicked()
{
    db.open();

    QModelIndex idx = NauczycielUi->TeachAttndcList->currentIndex();
    if (!idx.isValid()) {
        QMessageBox::warning(this, "Błąd", "Wybierz wpis frekwencji.");
        db.close();
        return;
    }
    int id = AttndcModel->data(AttndcModel->index(idx.row(), 0)).toInt();

    QMessageBox::StandardButton confirm = QMessageBox::question(
        this, "Potwierdź usunięcie",
        "Czy na pewno usunąć wpis?",
        QMessageBox::Yes | QMessageBox::No
        );
    if (confirm != QMessageBox::Yes) { db.close(); return; }

    QSqlQuery delQ;
    delQ.prepare("DELETE FROM Atndnc WHERE id = :id");
    delQ.bindValue(":id", id);
    if (!delQ.exec()) {
        QMessageBox::warning(this, "Błąd usuwania", delQ.lastError().text());
        db.close();
        return;
    }

    QMessageBox::information(this, "Sukces", "Usunięto wpis.");
    ::db_attndc_list(QSqlDatabase::database(), AttndcModel, NauczycielUi);
    db.close();
}

void Nauczyciel::on_TeachEditAttndcBtn_clicked()
{
    db.open();

    QModelIndex idx = NauczycielUi->TeachAttndcList->currentIndex();
    if (!idx.isValid()) {
        QMessageBox::warning(this, "Błąd", "Wybierz wpis frekwencji.");
        db.close();
        return;
    }
    int id = AttndcModel->data(AttndcModel->index(idx.row(), 0)).toInt();
    QString oldState = AttndcModel->data(AttndcModel->index(idx.row(), 5)).toString();

    QStringList stateOptions = {"obecny", "nieobecny", "spozniony", "usprawiedliwiony", "zwolniony"};
    int defaultIdx = stateOptions.indexOf(oldState);
    if (defaultIdx < 0) defaultIdx = 0;
    QString newState = QInputDialog::getItem(this, "Edytuj frekwencję", "Stan:", stateOptions, defaultIdx, false);
    if (newState.isEmpty()) { db.close(); return; }

    QSqlQuery updQ;
    updQ.prepare("UPDATE Atndnc SET state = :state WHERE id = :id");
    updQ.bindValue(":state", newState);
    updQ.bindValue(":id", id);
    if (!updQ.exec()) {
        QMessageBox::warning(this, "Błąd edycji", updQ.lastError().text());
        db.close();
        return;
    }

    QMessageBox::information(this, "Sukces", "Zaktualizowano wpis.");
    ::db_attndc_list(QSqlDatabase::database(), AttndcModel, NauczycielUi);
    db.close();
}

    /* ZARZADZANIE UWAGAMI */
void Nauczyciel::on_TeachAddNoteBtn_clicked()
{
    db.open();

    QStringList studentOptions;
    {
        QSqlQuery q;
        q.exec("SELECT name || ' ' || surname FROM Students ORDER BY name, surname;");
        while (q.next())
            studentOptions << q.value(0).toString();
    }
    QString selectedStudent = QInputDialog::getItem(this,
                                                    "Dodaj uwagę", "Uczeń:", studentOptions, 0, false);
    if (selectedStudent.isEmpty()) { db.close(); return; }

    QSqlQuery stuQ;
    stuQ.prepare(
        "SELECT id FROM Students "
        "WHERE name || ' ' || surname = :fullName"
        );
    stuQ.bindValue(":fullName", selectedStudent);
    if (!stuQ.exec() || !stuQ.next()) {
        QMessageBox::warning(this, "Błąd", "Nie znaleziono ucznia.");
        db.close(); return;
    }
    int stud_id = stuQ.value(0).toInt();

    QStringList subjOptions;
    {
        QSqlQuery q;
        q.exec("SELECT name FROM Subjects ORDER BY name;");
        while (q.next())
            subjOptions << q.value(0).toString();
    }
    QString selectedSubj = QInputDialog::getItem(this,
                                                 "Dodaj uwagę", "Przedmiot:", subjOptions, 0, false);
    if (selectedSubj.isEmpty()) { db.close(); return; }

    QSqlQuery subQ;
    subQ.prepare(
        "SELECT id FROM Subjects WHERE name = :name"
        );
    subQ.bindValue(":name", selectedSubj);
    if (!subQ.exec() || !subQ.next()) {
        QMessageBox::warning(this, "Błąd", "Nie znaleziono przedmiotu.");
        db.close(); return;
    }
    int subj_id = subQ.value(0).toInt();

    QString note = QInputDialog::getText(this,
                                         "Treść uwagi", "Wpisz treść uwagi:");
    if (note.isEmpty()) { db.close(); return; }

    QSqlQuery insQ;
    insQ.prepare(
        "INSERT INTO Notes (note, date, stud_id, teach_id, subj_id) "
        "VALUES (:note, :date, :stud_id, :teach_id, :subj_id)"
        );
    insQ.bindValue(":note", note);
    insQ.bindValue(":date", QDate::currentDate().toString("yyyy-MM-dd"));
    insQ.bindValue(":stud_id", stud_id);
    insQ.bindValue(":teach_id", c_userId);
    insQ.bindValue(":subj_id", subj_id);
    if (!insQ.exec()) {
        QMessageBox::warning(this, "Błąd dodawania", insQ.lastError().text());
        db.close(); return;
    }

    QMessageBox::information(this, "Sukces", "Uwaga dodana.");
    ::db_note_list(db, NoteModel, NauczycielUi);
    db.close();
}

void Nauczyciel::on_TeachDelNoteBtn_clicked()
{
    db.open();

    QModelIndex idx = NauczycielUi->TeachNotesList->currentIndex();
    if (!idx.isValid()) {
        QMessageBox::warning(this, "Błąd", "Wybierz uwagę z listy.");
        db.close(); return;
    }
    int noteId = NoteModel->data(NoteModel->index(idx.row(), 0)).toInt();

    QMessageBox::StandardButton confirm = QMessageBox::question(
        this, "Potwierdź usunięcie",
        "Czy na pewno usunąć wybraną uwagę?",
        QMessageBox::Yes | QMessageBox::No
        );
    if (confirm != QMessageBox::Yes) { db.close(); return; }

    QSqlQuery delQ;
    delQ.prepare("DELETE FROM Notes WHERE id = :id");
    delQ.bindValue(":id", noteId);
    if (!delQ.exec()) {
        QMessageBox::warning(this, "Błąd usuwania", delQ.lastError().text());
        db.close(); return;
    }

    QMessageBox::information(this, "Usunięto", "Uwaga usunięta.");
    ::db_note_list(db, NoteModel, NauczycielUi);
    db.close();
}

void Nauczyciel::on_TeachEditNoteBtn_clicked()
{
    db.open();

    QModelIndex idx = NauczycielUi->TeachNotesList->currentIndex();
    if (!idx.isValid()) {
        QMessageBox::warning(this, "Błąd", "Wybierz uwagę z listy.");
        db.close(); return;
    }
    int noteId = NoteModel->data(NoteModel->index(idx.row(), 0)).toInt();
    QString oldNote = NoteModel->data(NoteModel->index(idx.row(), 3)).toString();

    QString newNote = QInputDialog::getText(this,
                                            "Edytuj uwagę", "Nowa treść uwagi:", QLineEdit::Normal, oldNote);
    if (newNote.isEmpty()) { db.close(); return; }

    QSqlQuery updQ;
    updQ.prepare("UPDATE Notes SET note = :note WHERE id = :id");
    updQ.bindValue(":note", newNote);
    updQ.bindValue(":id", noteId);
    if (!updQ.exec()) {
        QMessageBox::warning(this, "Błąd edycji", updQ.lastError().text());
        db.close(); return;
    }

    QMessageBox::information(this, "Sukces", "Uwaga zaktualizowana.");
    ::db_note_list(db, NoteModel, NauczycielUi);
    db.close();
}

