#ifndef ADMIN_H
#define ADMIN_H

#include <QMainWindow>
#include <QDialog>
#include <QSql>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlQuery>
#include <QSqlError>
#include <qsqlquerymodel.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class Admin;
}
QT_END_NAMESPACE

class Admin : public QMainWindow
{
    friend class adminDatabase;
    Q_OBJECT

public:
    explicit Admin(QWidget *parent = nullptr);
    ~Admin();
    QSqlQueryModel *UsrModel;
    QSqlQueryModel *SchdModel;
    QSqlQueryModel *SubjModel;
    QSqlQueryModel *ClassModel;


private slots:

    void on_AdminLogoutBtn_clicked();

    void on_AdminAddUsrBtn_clicked();

    void on_AdminDelUsrBtn_clicked();

    void on_AdminEditUsrBtn_clicked();

    void on_AdminAddClassBtn_clicked();

    void on_AdminDelClassBtn_clicked();

    void on_AdminEditClassBtn_clicked();

    void on_AdminAddSubjBtn_clicked();

    void on_AdminDelSubjBtn_clicked();

    void on_AdminEditSubjBtn_clicked();

    void on_AdminAddSchdBtn_clicked();

    void on_AdminDelSchdBtn_clicked();

    void on_AdminEditSchdBtn_clicked();

    void on_AdminUsrBtn_clicked();

    void on_AdminClassBtn_clicked();

    void on_AdminSubjBtn_clicked();

    void on_AdminSchdBtn_clicked();

private:

    Ui::Admin *AdminUi;

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");


};

class adminDatabase {
public:
    int db_create_rest(QSqlDatabase db, Ui::Admin *AdminUi);

    void db_usr_list (QSqlDatabase db, Ui::Admin *AdminUi, QSqlQueryModel *model);
    void db_add_usr(QSqlDatabase db, Ui::Admin *AdminUi);
    void db_del_usr(QSqlDatabase db, Ui::Admin *AdminUi);
    void db_edit_usr(QSqlDatabase db, Ui::Admin *AdminUi);

    void db_subj_list (QSqlDatabase db, Ui::Admin *AdminUi, QSqlQueryModel *model);
    void db_add_subj(QSqlDatabase db, Ui::Admin *AdminUi);
    void db_del_subj(QSqlDatabase db, Ui::Admin *AdminUi);
    void db_edit_subj(QSqlDatabase db, Ui::Admin *uAdminUii);

    void db_schd_list (QSqlDatabase db, Ui::Admin *AdminUi, QSqlQueryModel *model);
    void db_add_schd(QSqlDatabase db, Ui::Admin *AdminUi);
    void db_del_schd(QSqlDatabase db, Ui::Admin *AdminUi);
    void db_edit_schd(QSqlDatabase db, Ui::Admin *AdminUi);

    void db_class_list (QSqlDatabase db, Ui::Admin *AdminUi, QSqlQueryModel *model);
    void db_add_class(QSqlDatabase db, Ui::Admin *AdminUi);
    void db_del_class(QSqlDatabase db, Ui::Admin *AdminUi);
    void db_edit_class(QSqlDatabase db, Ui::Admin *AdminUi);
};

#endif // ADMIN_H
