#ifndef NAUCZYCIEL_H
#define NAUCZYCIEL_H

#include <QMainWindow>
#include <QDialog>
#include <QSql>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlQuery>
#include <QSqlError>
#include <qsqlquerymodel.h>

namespace Ui {
class Nauczyciel;
}

class Nauczyciel : public QMainWindow
{
    Q_OBJECT
    friend class teachDatabase;

public:

    explicit Nauczyciel(int teachId, QWidget *parent = nullptr);

    ~Nauczyciel();

    QSqlQueryModel *GrdModel;
    QSqlQueryModel *NoteModel;
    QSqlQueryModel *AttndcModel;
    QSqlQueryModel *TeachSchdModel;
    int c_userId;

private slots:

    void on_TeachGrdBtn_clicked();
    void on_TeachNoteBtn_clicked();
    void on_TeachAttndcBtn_clicked();
    void on_TeachSchdBtn_clicked();
    void on_TeachLogoutBtn_clicked();

    void on_TeachAddGrdBtn_clicked();
    void on_TeachDelGrdBtn_clicked();
    void on_TeachEditGrdBtn_clicked();

    void on_TeachAddAttndcBtn_clicked();
    void on_TeachDelAttndcBtn_clicked();
    void on_TeachEditAttndcBtn_clicked();

    void on_TeachAddNoteBtn_clicked();
    void on_TeachDelNoteBtn_clicked();
    void on_TeachEditNoteBtn_clicked();

private:
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    Ui::Nauczyciel *NauczycielUi;
    void ComboBoxy(QSqlDatabase db, Ui::Nauczyciel *ui);
};

class teachDatabase {
public:
    int db_create_rest (QSqlDatabase db);
    void db_grd_list(QSqlDatabase db, QSqlQueryModel *model, Ui::Nauczyciel *ui);
    void db_note_list(QSqlDatabase db, QSqlQueryModel *model, Ui::Nauczyciel *ui);
    void db_attndc_list (QSqlDatabase db, QSqlQueryModel *model, Ui::Nauczyciel *ui);
    void db_schd_list(QSqlDatabase db, QSqlQueryModel *model, Ui::Nauczyciel *ui, int &id, int &id2);

};

#endif // NAUCZYCIEL_H
