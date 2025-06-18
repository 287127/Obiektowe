#ifndef UCZEN_H
#define UCZEN_H

#include <QMainWindow>
#include <QDialog>
#include <QSql>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlQuery>
#include <QSqlError>
#include <qsqlquerymodel.h>

namespace Ui {
class Uczen;
}

class Uczen : public QMainWindow
{
    Q_OBJECT
    friend class studDatabase;

public:

    explicit Uczen(int studId, QWidget *parent = nullptr);

    ~Uczen();
    int c_userId;


    QSqlQueryModel *StudGrdModel;
    QSqlQueryModel *StudNoteModel;
    QSqlQueryModel *StudAttndcModel;
    QSqlQueryModel *StudSchdModel;

private slots:


    void on_StudGrdBtn_clicked();

    void on_StudSchdBtn_clicked();

    void on_StudAttndcBtn_clicked();

    void on_StudNoteBtn_clicked();

    void on_StudLogoutBtn_clicked();

private:
    Ui::Uczen *UczenUi;
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");

};

class studDatabase{
public:
    void db_studgrd_list(QSqlDatabase db, QSqlQueryModel *model, Ui::Uczen *ui, int c_userId);
    void db_studattndc_list(QSqlDatabase db, QSqlQueryModel *model, Ui::Uczen *ui, int c_userId);
    void db_studschd_list(QSqlDatabase db, QSqlQueryModel *model, Ui::Uczen *ui, int c_userId);
    void db_studnote_list(QSqlDatabase db, QSqlQueryModel *model, Ui::Uczen *ui, int c_userId);
};

#endif // UCZEN_H
