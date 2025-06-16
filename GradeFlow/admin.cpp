#include "admin.h"
#include "ui_admin.h"
#include "login.h"

#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QInputDialog>
#include <QSql>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlQueryModel>
#include <QDebug>

Admin::Admin(QWidget *parent)
    : QMainWindow(parent)
    , AdminUi(new Ui::Admin)
{
    AdminUi->setupUi(this);

    AdminUi->AdminUsrMenu->hide();
    AdminUi->AdminSubjMenu->hide();
    AdminUi->AdminClassMenu->hide();
    AdminUi->AdminSchdMenu->hide();
    db.setDatabaseName("GradeFlow_db.db");

    UsrModel = new QSqlQueryModel(this);
    SchdModel = new QSqlQueryModel(this);
    ClassModel = new QSqlQueryModel(this);
    SubjModel = new QSqlQueryModel(this);

    AdminUi->UsrList->setModel(UsrModel);
    AdminUi->ClassList->setModel(ClassModel);
    AdminUi->SubjList->setModel(SubjModel);
    AdminUi->SchdList->setModel(SchdModel);
}

Admin::~Admin()
{
    delete AdminUi;
}

int db_create_rest(QSqlDatabase db, Ui::Admin *AdminUi)
{
    bool success;

    if (!db.open()) {
        qDebug() << "Błąd otwarcia bazy danych" << db.lastError().text();
        return 5;
    }

    QSqlQuery query;
    success = query.exec(
        "CREATE TABLE IF NOT EXISTS Classes ("
        "id INTEGER PRIMARY KEY AUTOINCREMENT, "
        "name TEXT NOT NULL UNIQUE )"
        );

    if (!success) {
        return 5;
    }

    success = query.exec(
        "CREATE TABLE IF NOT EXISTS Subjects("
        "id INTEGER PRIMARY KEY AUTOINCREMENT,"
        "name TEXT NOT NULL UNIQUE)"
        );

    if (!success) {
        return 5;
    }

    success = query.exec(
        "CREATE TABLE IF NOT EXISTS Students ("
        "id INTEGER PRIMARY KEY AUTOINCREMENT, "
        "name TEXT NOT NULL, "
        "surname TEXT NOT NULL,"
        "role_id INTEGER,"
        "user_id INTEGER,"
        "class_id INTEGER,"
        "FOREIGN KEY (class_id) REFERENCES Classes(id),"
        "FOREIGN KEY (role_id) REFERENCES UsrTypes(id),"
        "FOREIGN KEY (user_id) REFERENCES Users(id),"
        "UNIQUE (name, surname))"
        );

    if (!success) {
        return 5;
    }

    success = query.exec(
        "CREATE TABLE IF NOT EXISTS Teachers ("
        "id INTEGER PRIMARY KEY AUTOINCREMENT, "
        "name TEXT NOT NULL, "
        "surname TEXT NOT NULL,"
        "role_id INTEGER,"
        "user_id INTEGER,"
        "FOREIGN KEY (role_id) REFERENCES UsrTypes(id),"
        "FOREIGN KEY (user_id) REFERENCES Users(id),"
        "UNIQUE (name, surname))"
        );

    if (!success) {
        return 5;
    }

    success = query.exec(
        "CREATE TABLE IF NOT EXISTS TeachSubjs ("
        "teach_id INTEGER,"
        "subj_id INTEGER,"
        "FOREIGN KEY (teach_id) REFERENCES Teachers(id),"
        "FOREIGN KEY (subj_id) REFERENCES Subjects(id),"
        "UNIQUE (teach_id, subj_id))"
        );

    if(!success) {
        return 5;
    }

    success = query.exec(
        "CREATE TABLE IF NOT EXISTS Schedules ("
        "id INTEGER PRIMARY KEY AUTOINCREMENT,"
        "dotw TEXT NOT NULL CHECK (dotw IN ('poniedzialek', 'wtorek', 'sroda', 'czwartek', 'piatek')),"
        "hour TEXT NOT NULL ,"
        "subj_id INTEGER,"
        "teach_id INTEGER,"
        "class_id INTEGER,"
        "FOREIGN KEY (subj_id) REFERENCES Subjects(id),"
        "FOREIGN KEY (teach_id) REFERENCES Teachers(id),"
        "FOREIGN KEY (class_id) REFERENCES Classes(id),"
        "UNIQUE(dotw, hour, class_id, subj_id, teach_id))"
        );

    if(!success) {
        return 5;
    }

    success = query.exec(
        "CREATE TABLE IF NOT EXISTS GradeTypes("
        "id INTEGER PRIMARY KEY AUTOINCREMENT,"
        "name TEXT NOT NULL)"
        );

    if(!success) {
        return 5;
    }

    success = query.exec(
        "CREATE TABLE IF NOT EXISTS Grades("
        "id INTEGER PRIMARY KEY AUTOINCREMENT,"
        "val REAL NOT NULL CHECK (val >= 1.0 AND val <= 6.0),"
        "date TEXT NOT NULL,"
        "stud_id INTEGER,"
        "teach_id INTEGER,"
        "subj_id INTEGER,"
        "type_id INTEGER,"
        "FOREIGN KEY (stud_id) REFERENCES Students(id),"
        "FOREIGN KEY (teach_id) REFERENCES Teachers(id),"
        "FOREIGN KEY (subj_id) REFERENCES Subjects(id))"
        );

    if (!success) {
        return 5;
    }

    success = query.exec(
        "CREATE TABLE IF NOT EXISTS Attendance("
        "id INTEGER PRIMARY KEY AUTOINCREMENT,"
        "state TEXT NOT NULL CHECK (state IN ('obecny', 'nieobecny', 'spozniony', 'usprawiedliwiony', 'zwolniony')),"
        "stud_id INTEGER,"
        "less_id INTEGER,"
        "FOREIGN KEY (stud_id) REFERENCES Students(id),"
        "FOREIGN KEY (less_id) REFERENCES Schedules(id)"
        "UNIQUE(stud_id, less_id)"
        );

    if (!success) {
        return 5;
    }

    success = query.exec(
        "CREATE TABLE IF NOT EXISTS Notes ("
        "id INTEGER PRIMARY KEY AUTOINCREMENT, "
        "note TEXT NOT NULL, "
        "date TEXT NOT NULL, "
        "stud_id INTEGER, "
        "teach_id INTEGER, "
        "subj_id INTEGER, "
        "FOREIGN KEY (stud_id) REFERENCES Students(id), "
        "FOREIGN KEY (teach_id) REFERENCES Teachers(id), "
        "FOREIGN KEY (subj_id) REFERENCES Subjects(id))"
        );

    db.close();
    return 0;
}

void db_usr_list (QSqlDatabase db, Ui::Admin *AdminUi, QSqlQueryModel *model) {

    if (!db.open()) {
        return;
        }

    QSqlQuery query;
    bool success = query.exec(
        "SELECT "
        "Users.id,"
        "Users.username, "
        "Students.name AS Imie, "
        "Students.surname AS Nazwisko, "
        "Classes.name AS Klasa, "
        "UsrTypes.name AS Typ "
        "FROM Students "
        "JOIN Users ON Students.user_id = Users.id "
        "JOIN Classes ON Students.class_id = Classes.id "
        "JOIN UsrTypes ON Students.role_id = UsrTypes.id "
        "UNION "
        "SELECT "
        "Users.id,"
        "Users.username, "
        "Teachers.name AS Imie, "
        "Teachers.surname AS Nazwisko, "
        "NULL AS Klasa, "
        "UsrTypes.name AS Typ "
        "FROM Teachers "
        "JOIN Users ON Teachers.user_id = Users.id "
        "JOIN UsrTypes ON Teachers.role_id = UsrTypes.id; "
    );


    if (!success) {
        return;
    }

    if (success) {
        model->setQuery(std::move(query));
        AdminUi->UsrList->setModel(model);
        AdminUi->UsrList->resizeColumnsToContents();
    }
    db.close();
}

void db_subj_list (QSqlDatabase db, Ui::Admin *AdminUi, QSqlQueryModel *model) {

    bool success;
    if (!db.open()) {
        return;
    }

    QSqlQuery query;
    success = query.exec("SELECT id, name FROM Subjects");

    if (success){
        model->setQuery(std::move(query));
        AdminUi->SubjList->setModel(model);
        AdminUi->SubjList->resizeColumnsToContents();
    }
    db.close();
}

void db_schd_list (QSqlDatabase db, Ui::Admin *AdminUi, QSqlQueryModel *model) {

    bool success;
    if (!db.open()) {
        return;
    }

    QSqlQuery query;
    success = query.exec(
        "SELECT "
            "Schedules.id, "
            "Schedules.dotw AS Dzien, "
            "Schedules.hour AS Godzina, "
            "Subjects.name AS Przedmiot, "
            "Teachers.name || ' ' || Teachers.surname AS Nauczyciel, "
            "Classes.name AS Klasa "
        "FROM Schedules "
        "JOIN Subjects ON Schedules.subj_id = Subjects.id "
        "JOIN Teachers ON Schedules.teach_id = Teachers.id "
        "JOIN Classes ON Schedules.class_id = Classes.id "
        "ORDER BY Schedules.dotw, Schedules.hour"
        );

    if (!success) {
        return;
    }

    if(success){
        model->setQuery(std::move(query));
        AdminUi->SchdList->setModel(model);
        AdminUi->SchdList->resizeColumnsToContents();
    }
    db.close();
}

void db_class_list (QSqlDatabase db, Ui::Admin *AdminUi, QSqlQueryModel *model) {

    bool success;

    if (!db.open()) {
        return;
    }

    QSqlQuery query;
    success = query.exec("SELECT id, name AS 'Nazwa klasy' FROM Classes");
    if (!success) {
        return;
    }

    if(success) {
        model->setQuery(std::move(query));
        AdminUi->ClassList->setModel(model);
        AdminUi->ClassList->resizeColumnsToContents();
    }
    db.close();
}


void Admin::on_AdminLogoutBtn_clicked()
{
    this->close();
    Login *loginWindow = new Login;
    loginWindow -> show();
}

void Admin::on_AdminAddUsrBtn_clicked()
{
    db.open();

    QString username = QInputDialog::getText(this, "Dodaj użytkownika", "Login:");
    if (username.isEmpty()) return;

    QString password = QInputDialog::getText(this, "Dodaj użytkownika", "Hasło:");
    if (password.isEmpty()) return;

    QString firstName = QInputDialog::getText(this, "Dodaj użytkownika", "Imię:");
    if (firstName.isEmpty()) return;

    QString lastName = QInputDialog::getText(this, "Dodaj użytkownika", "Nazwisko:");
    if (lastName.isEmpty()) return;

    QStringList roleOptions = {"admin", "nauczyciel", "uczen"};
    QString selectedRole = QInputDialog::getItem(this, "Dodaj użytkownika", "Rola:", roleOptions, 0, false);
    if (selectedRole.isEmpty()) return;

    QSqlQuery roleQuery;
    roleQuery.prepare("SELECT id FROM UsrTypes WHERE name = :name");
    roleQuery.bindValue(":name", selectedRole);
    if (!roleQuery.exec() || !roleQuery.next()) {
        QMessageBox::warning(this, "Błąd", "Nie znaleziono roli w bazie.");
        return;
    }
    int roleId = roleQuery.value(0).toInt();

    QSqlQuery insertUser;
    insertUser.prepare("INSERT INTO Users (username, passwrd, role_id) "
                       "VALUES (:username, :password, :role_id)");
    insertUser.bindValue(":username", username);
    insertUser.bindValue(":password", password);
    insertUser.bindValue(":role_id", roleId);

    if (!insertUser.exec()) {
        QMessageBox::warning(this, "Błąd dodawania użytkownika", insertUser.lastError().text());
        return;
    }

    int userId = insertUser.lastInsertId().toInt();

    if (selectedRole == "uczen") {
        QStringList classList;
        QSqlQuery classQuery("SELECT name FROM Classes");
        while (classQuery.next()) {
            classList << classQuery.value(0).toString();
        }

        if (classList.isEmpty()) {
            QMessageBox::warning(this, "Błąd", "Brak klas w bazie.");
            return;
        }

        QString selectedClass = QInputDialog::getItem(this, "Klasa", "Wybierz klasę:", classList, 0, false);
        if (selectedClass.isEmpty()) return;

        QSqlQuery getClassId;
        getClassId.prepare("SELECT id FROM Classes WHERE name = :name");
        getClassId.bindValue(":name", selectedClass);
        if (!getClassId.exec() || !getClassId.next()) {
            QMessageBox::warning(this, "Błąd", "Nie znaleziono wybranej klasy.");
            return;
        }
        int classId = getClassId.value(0).toInt();

        QSqlQuery insertStudent;
        insertStudent.prepare("INSERT INTO Students (name, surname, role_id, user_id, class_id) "
                              "VALUES (:name, :surname, :role_id, :user_id, :class_id)");
        insertStudent.bindValue(":name", firstName);
        insertStudent.bindValue(":surname", lastName);
        insertStudent.bindValue(":role_id", roleId);
        insertStudent.bindValue(":user_id", userId);
        insertStudent.bindValue(":class_id", classId);

        if (!insertStudent.exec()) {
            QMessageBox::warning(this, "Błąd dodawania ucznia", insertStudent.lastError().text());
            return;
        }

    } else if (selectedRole == "nauczyciel") {
        QSqlQuery insertTeacher;
        insertTeacher.prepare("INSERT INTO Teachers (name, surname, role_id, user_id) "
                              "VALUES (:name, :surname, :role_id, :user_id)");
        insertTeacher.bindValue(":name", firstName);
        insertTeacher.bindValue(":surname", lastName);
        insertTeacher.bindValue(":role_id", roleId);
        insertTeacher.bindValue(":user_id", userId);

        if (!insertTeacher.exec()) {
            QMessageBox::warning(this, "Błąd dodawania nauczyciela", insertTeacher.lastError().text());
            return;
        }
    }

    QMessageBox::information(this, "Sukces", "Użytkownik został dodany.");
    ::db_usr_list(db, AdminUi, UsrModel);
    db.close();
}


void Admin::on_AdminDelUsrBtn_clicked()
{
    db.open();

    QModelIndex index = AdminUi->UsrList->currentIndex();
    if (!index.isValid()) {
        QMessageBox::warning(this, "Błąd", "Wybierz użytkownika z listy.");
        return;
    }

    int row = index.row();
    int userId = UsrModel->data(UsrModel->index(row, 0)).toInt();

    QMessageBox::StandardButton confirm = QMessageBox::question(
        this, "Potwierdź usunięcie",
        "Czy na pewno chcesz usunąć wybranego użytkownika?",
        QMessageBox::Yes | QMessageBox::No
        );

    if (confirm != QMessageBox::Yes) return;

    QSqlQuery del1, del2;
    del1.prepare("DELETE FROM Students WHERE user_id = :uid");
    del1.bindValue(":uid", userId);
    del1.exec();

    del2.prepare("DELETE FROM Teachers WHERE user_id = :uid");
    del2.bindValue(":uid", userId);
    del2.exec();

    QSqlQuery delUser;
    delUser.prepare("DELETE FROM Users WHERE id = :id");
    delUser.bindValue(":id", userId);
    if (!delUser.exec()) {
        QMessageBox::warning(this, "Błąd", delUser.lastError().text());
        return;
    }

    QMessageBox::information(this, "Sukces", "Użytkownik został usunięty.");
    ::db_usr_list(db, AdminUi, UsrModel);
    db.close();
}


void Admin::on_AdminEditUsrBtn_clicked()
{
    db.open();
    QModelIndex index = AdminUi->UsrList->currentIndex();
    if (!index.isValid()) {
        QMessageBox::warning(this, "Błąd", "Wybierz użytkownika z listy.");
        return;
    }

    int row = index.row();
    int userId = UsrModel->data(UsrModel->index(row, 0)).toInt();

    QString newPass = QInputDialog::getText(this, "Nowe hasło", "Wprowadź nowe hasło:");
    if (newPass.isEmpty()) return;

    QString newName = QInputDialog::getText(this, "Nowe imię", "Wprowadź nowe imię:");
    QString newSurname = QInputDialog::getText(this, "Nowe nazwisko", "Wprowadź nowe nazwisko:");

    QSqlQuery roleQuery;
    roleQuery.prepare("SELECT role_id FROM Users WHERE id = :id");
    roleQuery.bindValue(":id", userId);
    if (!roleQuery.exec() || !roleQuery.next()) return;
    int roleId = roleQuery.value(0).toInt();

    QSqlQuery updateUser;
    updateUser.prepare("UPDATE Users SET passwrd = :passwrd WHERE id = :id");
    updateUser.bindValue(":passwrd", newPass);
    updateUser.bindValue(":id", userId);
    updateUser.exec();

    if (roleId == 2) {
        QSqlQuery update;
        update.prepare("UPDATE Teachers SET name = :name, surname = :surname WHERE user_id = :uid");
        update.bindValue(":name", newName);
        update.bindValue(":surname", newSurname);
        update.bindValue(":uid", userId);
        update.exec();
    } else if (roleId == 3) {
        QSqlQuery update;
        update.prepare("UPDATE Students SET name = :name, surname = :surname WHERE user_id = :uid");
        update.bindValue(":name", newName);
        update.bindValue(":surname", newSurname);
        update.bindValue(":uid", userId);
        update.exec();
    }

    QMessageBox::information(this, "Zaktualizowano", "Dane użytkownika zostały zmienione.");
    ::db_usr_list(db, AdminUi, UsrModel);
    db.close();
}


void Admin::on_AdminAddClassBtn_clicked()
{
    if (!db.open()) return;

    QString name = QInputDialog::getText(nullptr, "Dodaj klasę", "Podaj nazwę nowej klasy:");
    if (name.isEmpty()) return;

    QSqlQuery insert;
    insert.prepare("INSERT OR IGNORE INTO Classes (name) VALUES (:name)");
    insert.bindValue(":name", name);

    if (!insert.exec()) {
        QMessageBox::warning(nullptr, "Błąd", insert.lastError().text());
        return;
    }

    QMessageBox::information(nullptr, "Sukces", "Klasa została dodana.");
    ::db_class_list(db, AdminUi, ClassModel);
    db.close();
}


void Admin::on_AdminDelClassBtn_clicked()
{
    if (!db.open()) return;

    QModelIndex index = AdminUi->ClassList->currentIndex();
    if (!index.isValid()) {
        QMessageBox::warning(nullptr, "Błąd", "Wybierz klasę z listy.");
        return;
    }

    int row = index.row();
    int classId = ClassModel->data(ClassModel->index(row, 0)).toInt();

    QMessageBox::StandardButton confirm = QMessageBox::question(
        nullptr, "Potwierdź usunięcie",
        "Czy na pewno chcesz usunąć wybraną klasę?",
        QMessageBox::Yes | QMessageBox::No
        );

    if (confirm != QMessageBox::Yes) return;

    QSqlQuery del;
    del.prepare("DELETE FROM Classes WHERE id = :id");
    del.bindValue(":id", classId);

    if (!del.exec()) {
        QMessageBox::warning(nullptr, "Błąd", del.lastError().text());
        return;
    }

    QMessageBox::information(nullptr, "Sukces", "Klasa została usunięta.");
    ::db_class_list(db, AdminUi, ClassModel);
    db.close();
}


void Admin::on_AdminEditClassBtn_clicked()
{
    if (!db.open()) return;

    QModelIndex index = AdminUi->ClassList->currentIndex();
    if (!index.isValid()) {
        QMessageBox::warning(nullptr, "Błąd", "Wybierz klasę z listy.");
        return;
    }

    int row = index.row();
    int classId = ClassModel->data(ClassModel->index(row, 0)).toInt();

    QString newName = QInputDialog::getText(nullptr, "Edycja klasy", "Wprowadź nową nazwę klasy:");
    if (newName.isEmpty()) return;

    QSqlQuery update;
    update.prepare("UPDATE Classes SET name = :name WHERE id = :id");
    update.bindValue(":name", newName);
    update.bindValue(":id", classId);

    if (!update.exec()) {
        QMessageBox::warning(nullptr, "Błąd", update.lastError().text());
        return;
    }

    QMessageBox::information(nullptr, "Sukces", "Nazwa klasy została zaktualizowana.");
    ::db_class_list(db, AdminUi, ClassModel);
    db.close();
}


void Admin::on_AdminAddSubjBtn_clicked()
{
    db.open();

    QString name = QInputDialog::getText(this, "Nowy przedmiot", "Nazwa:");
    if (name.isEmpty()) return;

    QSqlQuery query;
    query.prepare("INSERT INTO Subjects (name) VALUES (:name)");
    query.bindValue(":name", name);

    if (!query.exec()) {
        QMessageBox::warning(this, "Błąd", query.lastError().text());
    } else {
        QMessageBox::information(this, "Sukces", "Przedmiot dodany.");
    }

    ::db_subj_list(db, AdminUi, SubjModel);
    db.close();
}


void Admin::on_AdminDelSubjBtn_clicked()
{
    QModelIndex index = AdminUi->SubjList->currentIndex();
    if (!index.isValid()) {
        QMessageBox::warning(this, "Błąd", "Wybierz przedmiot z listy.");
        return;
    }

    int row = index.row();
    int id = SubjModel->data(SubjModel->index(row, 0)).toInt();

    QMessageBox::StandardButton confirm = QMessageBox::question(
        this, "Potwierdź", "Na pewno usunąć przedmiot?",
        QMessageBox::Yes | QMessageBox::No
        );

    if (confirm != QMessageBox::Yes) return;

    QSqlQuery query;
    query.prepare("DELETE FROM Subjects WHERE id = :id");
    query.bindValue(":id", id);
    query.exec();

    ::db_subj_list(db, AdminUi, SubjModel);
    db.close();
}


void Admin::on_AdminEditSubjBtn_clicked()
{
    db.open();

    QModelIndex index = AdminUi->SubjList->currentIndex();
    if (!index.isValid()) {
        QMessageBox::warning(this, "Błąd", "Wybierz przedmiot z listy.");
        return;
    }

    int row = index.row();
    int id = SubjModel->data(SubjModel->index(row, 0)).toInt();
    QString newName = QInputDialog::getText(this, "Edycja przedmiotu", "Nowa nazwa:");

    if (newName.isEmpty()) return;

    QSqlQuery query;
    query.prepare("UPDATE Subjects SET name = :name WHERE id = :id");
    query.bindValue(":name", newName);
    query.bindValue(":id", id);
    query.exec();

    ::db_subj_list(db, AdminUi, SubjModel);
    db.close();
}


void Admin::on_AdminAddSchdBtn_clicked()
{
    if (!db.open()) return;

    QStringList dni = {"poniedzialek", "wtorek", "sroda", "czwartek", "piatek"};
    QString dzien = QInputDialog::getItem(nullptr, "Dodaj lekcję", "Dzień tygodnia:", dni, 0, false);
    if (dzien.isEmpty()) return;

    QString godzina = QInputDialog::getText(nullptr, "Godzina", "Podaj godzinę (np. 08:00):");
    if (godzina.isEmpty()) return;

    QStringList przedmioty, nauczyciele, klasy;

    QSqlQuery q1("SELECT name FROM Subjects");
    while (q1.next()) przedmioty << q1.value(0).toString();

    QSqlQuery q2("SELECT name || ' ' || surname FROM Teachers");
    while (q2.next()) nauczyciele << q2.value(0).toString();

    QSqlQuery q3("SELECT name FROM Classes");
    while (q3.next()) klasy << q3.value(0).toString();

    QString przedmiot = QInputDialog::getItem(nullptr, "Przedmiot", "Wybierz przedmiot:", przedmioty, 0, false);
    QString nauczyciel = QInputDialog::getItem(nullptr, "Nauczyciel", "Wybierz nauczyciela:", nauczyciele, 0, false);
    QString klasa = QInputDialog::getItem(nullptr, "Klasa", "Wybierz klasę:", klasy, 0, false);

    if (przedmiot.isEmpty() || nauczyciel.isEmpty() || klasa.isEmpty()) return;

    QSqlQuery ids;
    ids.prepare(R"(
        SELECT
            (SELECT id FROM Subjects WHERE name = :s) AS subj_id,
            (SELECT id FROM Teachers WHERE name || ' ' || surname = :t) AS teach_id,
            (SELECT id FROM Classes WHERE name = :c) AS class_id
    )");
    ids.bindValue(":s", przedmiot);
    ids.bindValue(":t", nauczyciel);
    ids.bindValue(":c", klasa);
    if (!ids.exec() || !ids.next()) {
        QMessageBox::warning(nullptr, "Błąd", "Nie znaleziono ID");
        return;
    }

    int subj_id = ids.value(0).toInt();
    int teach_id = ids.value(1).toInt();
    int class_id = ids.value(2).toInt();
    QSqlQuery insertRel;
    insertRel.exec(
        "INSERT OR IGNORE INTO TeachSubjs (teach_id, subj_id) "
        "VALUES ("
        + QString::number(teach_id) + ", "
        + QString::number(subj_id) +
        ");"
        );

    QSqlQuery insert;
    insert.prepare("INSERT INTO Schedules (dotw, hour, subj_id, teach_id, class_id) "
                   "VALUES (:d, :h, :s, :t, :c)");
    insert.bindValue(":d", dzien);
    insert.bindValue(":h", godzina);
    insert.bindValue(":s", subj_id);
    insert.bindValue(":t", teach_id);
    insert.bindValue(":c", class_id);

    if (!insert.exec()) {
        QMessageBox::warning(nullptr, "Błąd", insert.lastError().text());
        return;
    }

    QMessageBox::information(nullptr, "Sukces", "Lekcja dodana.");
    ::db_schd_list(db, AdminUi, SchdModel);
    db.close();
}


void Admin::on_AdminDelSchdBtn_clicked()
{
    if (!db.open()) return;

    QModelIndex index = AdminUi->SchdList->currentIndex();
    if (!index.isValid()) {
        QMessageBox::warning(nullptr, "Błąd", "Wybierz lekcję do usunięcia.");
        return;
    }

    int row = index.row();
    int scheduleId = SchdModel->data(SchdModel->index(row, 0)).toInt();

    QMessageBox::StandardButton confirm = QMessageBox::question(
        nullptr, "Usuwanie",
        "Na pewno usunąć tę lekcję?",
        QMessageBox::Yes | QMessageBox::No
        );
    if (confirm != QMessageBox::Yes) return;

    QSqlQuery q;
    q.prepare("DELETE FROM Schedules WHERE id = :id");
    q.bindValue(":id", scheduleId);
    if (!q.exec()) {
        QMessageBox::warning(nullptr, "Błąd", q.lastError().text());
        return;
    }

    QMessageBox::information(nullptr, "Sukces", "Lekcja usunięta.");
    ::db_schd_list(db, AdminUi, SchdModel);
    db.close();
}


void Admin::on_AdminEditSchdBtn_clicked()
{
    if (!db.open()) return;

    QModelIndex index = AdminUi->SchdList->currentIndex();
    if (!index.isValid()) {
        QMessageBox::warning(nullptr, "Błąd", "Wybierz lekcję z listy.");
        return;
    }

    int row = index.row();
    int scheduleId = SchdModel->data(SchdModel->index(row, 0)).toInt();

    QStringList dni = {"poniedzialek", "wtorek", "sroda", "czwartek", "piatek"};
    QString dzien = QInputDialog::getItem(nullptr, "Edycja lekcji", "Dzień tygodnia:", dni, 0, false);
    if (dzien.isEmpty()) return;

    QString godzina = QInputDialog::getText(nullptr, "Godzina", "Nowa godzina (np. 08:00):");
    if (godzina.isEmpty()) return;

    QStringList przedmioty, nauczyciele, klasy;

    QSqlQuery q1("SELECT name FROM Subjects");
    while (q1.next()) przedmioty << q1.value(0).toString();

    QSqlQuery q2("SELECT name || ' ' || surname FROM Teachers");
    while (q2.next()) nauczyciele << q2.value(0).toString();

    QSqlQuery q3("SELECT name FROM Classes");
    while (q3.next()) klasy << q3.value(0).toString();

    QString przedmiot = QInputDialog::getItem(nullptr, "Przedmiot", "Wybierz przedmiot:", przedmioty, 0, false);
    QString nauczyciel = QInputDialog::getItem(nullptr, "Nauczyciel", "Wybierz nauczyciela:", nauczyciele, 0, false);
    QString klasa = QInputDialog::getItem(nullptr, "Klasa", "Wybierz klasę:", klasy, 0, false);

    if (przedmiot.isEmpty() || nauczyciel.isEmpty() || klasa.isEmpty()) return;

    QSqlQuery ids;
    ids.prepare(R"(
        SELECT
            (SELECT id FROM Subjects WHERE name = :s) AS subj_id,
            (SELECT id FROM Teachers WHERE name || ' ' || surname = :t) AS teach_id,
            (SELECT id FROM Classes WHERE name = :c) AS class_id
    )");
    ids.bindValue(":s", przedmiot);
    ids.bindValue(":t", nauczyciel);
    ids.bindValue(":c", klasa);
    if (!ids.exec() || !ids.next()) {
        QMessageBox::warning(nullptr, "Błąd", "Nie znaleziono ID.");
        return;
    }

    int subj_id = ids.value(0).toInt();
    int teach_id = ids.value(1).toInt();
    int class_id = ids.value(2).toInt();

    QSqlQuery insertRel;
    insertRel.exec(
        "INSERT OR IGNORE INTO TeachSubjs (teach_id, subj_id) "
        "VALUES ("
        + QString::number(teach_id) + ", "
        + QString::number(subj_id) +
        ");"
        );

    QSqlQuery update;
    update.prepare(R"(
        UPDATE Schedules SET
            dotw = :dzien,
            hour = :godzina,
            subj_id = :subj,
            teach_id = :teach,
            class_id = :class
        WHERE id = :id
    )");
    update.bindValue(":dzien", dzien);
    update.bindValue(":godzina", godzina);
    update.bindValue(":subj", subj_id);
    update.bindValue(":teach", teach_id);
    update.bindValue(":class", class_id);
    update.bindValue(":id", scheduleId);

    if (!update.exec()) {
        QMessageBox::warning(nullptr, "Błąd", update.lastError().text());
        return;
    }

    QMessageBox::information(nullptr, "Sukces", "Lekcja zaktualizowana.");
    ::db_schd_list(db, AdminUi, SchdModel);
    db.close();
}


void Admin::on_AdminUsrBtn_clicked()
{
    ::db_create_rest(db,AdminUi);
    if(AdminUi->AdminUsrMenu->isVisible()){
        AdminUi->AdminUsrMenu->hide();
    } else {
        AdminUi->AdminUsrMenu->show();
        ::db_usr_list(db, AdminUi, UsrModel);
        AdminUi->AdminSchdMenu -> hide();
        AdminUi->AdminSubjMenu -> hide();
        AdminUi->AdminClassMenu -> hide();
        AdminUi->AdminClassBtn->setChecked(false);
        AdminUi->AdminSubjBtn->setChecked(false);
        AdminUi->AdminSchdBtn->setChecked(false);
    }
}


void Admin::on_AdminClassBtn_clicked()
{
    ::db_create_rest(db,AdminUi);
    if(AdminUi->AdminClassMenu->isVisible()){
        AdminUi->AdminClassMenu->hide();
    } else {
        AdminUi->AdminClassMenu->show();
        ::db_class_list(db, AdminUi, ClassModel);
        AdminUi->AdminSchdMenu -> hide();
        AdminUi->AdminSubjMenu -> hide();
        AdminUi->AdminUsrMenu -> hide();
        AdminUi->AdminUsrBtn->setChecked(false);
        AdminUi->AdminSubjBtn->setChecked(false);
        AdminUi->AdminSchdBtn->setChecked(false);
    }
}


void Admin::on_AdminSubjBtn_clicked()
{
    ::db_create_rest(db,AdminUi);
    if(AdminUi->AdminSubjMenu->isVisible()){
        AdminUi->AdminSubjMenu->hide();
    } else {
        AdminUi->AdminSubjMenu->show();
        ::db_subj_list(db, AdminUi, SubjModel);
        AdminUi->AdminSchdMenu -> hide();
        AdminUi->AdminUsrMenu -> hide();
        AdminUi->AdminClassMenu -> hide();
        AdminUi->AdminUsrBtn->setChecked(false);
        AdminUi->AdminClassBtn->setChecked(false);
        AdminUi->AdminSchdBtn->setChecked(false);
    }
}


void Admin::on_AdminSchdBtn_clicked()
{
    ::db_create_rest(db,AdminUi);
    if(AdminUi->AdminSchdMenu->isVisible()){
        AdminUi->AdminSchdMenu->hide();
    } else {
        AdminUi->AdminSchdMenu->show();
        ::db_schd_list(db, AdminUi, SchdModel);
        AdminUi->AdminSubjMenu -> hide();
        AdminUi->AdminUsrMenu -> hide();
        AdminUi->AdminClassMenu -> hide();
        AdminUi->AdminUsrBtn->setChecked(false);
        AdminUi->AdminClassBtn->setChecked(false);
        AdminUi->AdminSubjBtn->setChecked(false);
    }
}

