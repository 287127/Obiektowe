#ifndef UCZEN_H
#define UCZEN_H

#include <QMainWindow>

namespace Ui {
class Uczen;
}

class Uczen : public QMainWindow
{
    Q_OBJECT

public:
    explicit Uczen(QWidget *parent = nullptr);
    ~Uczen();

private:
    Ui::Uczen *UczenUi;
};

#endif // UCZEN_H
