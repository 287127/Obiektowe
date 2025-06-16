#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include <QSql>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlQuery>
#include <QSqlError>

QT_BEGIN_NAMESPACE
namespace Ui {
class Login;
}
QT_END_NAMESPACE

class Login : public QDialog
{
    Q_OBJECT

public:
    Login(QWidget *parent = nullptr);
    ~Login();

private slots:

    void on_LoginBtn_clicked();
    void on_showPass_toggled(bool checked);

private:
    Ui::Login *LoginUi;
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    void db_create(QSqlDatabase db);
    int db_check(QSqlDatabase db, QString pass, QString email);
};
#endif // LOGIN_H
