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

public:
    explicit Nauczyciel(QWidget *parent = nullptr);
    ~Nauczyciel();

    QSqlQueryModel *GrdModel;
    QSqlQueryModel *NoteModel;
    QSqlQueryModel *AttndcModel;

private slots:

    void on_TeachGrdBtn_clicked();
    void on_TeachNoteBtn_clicked();
    void on_TeachAttndcBtn_clicked();
    void on_TeachSchdBtn_clicked();
    void on_TeachLogoutBtn_clicked();

    void on_TeachAddGrdBtn_clicked();
    void on_TeachDelGrdBtn_clicked();
    void on_TeachEditGrdBtn_clicked();

    /*void on_TeachAddNoteBtn_clicked();
    void on_TeachDelNoteBtn_clicked();
    void on_TeachEditNoteBtn_clicked();*/



    void on_TeachAddAttndcBtn_clicked();

    void on_TeachDelAttndcBtn_clicked();

    void on_TeachEditAttndcBtn_clicked();

private:
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    Ui::Nauczyciel *NauczycielUi;
    int m_currentUserId;

    int db_create_rest (QSqlDatabase db);
    void db_grd_list(QSqlDatabase db, Ui::Nauczyciel NauczycielUi, QSqlQueryModel GrdModel, int classId, int subjId);

    void ComboBoxy(QSqlDatabase db, Ui::Nauczyciel *ui);
};

#endif // NAUCZYCIEL_H
