#include "uczen.h"
#include "ui_uczen.h"

Uczen::Uczen(QWidget *parent)
    : QMainWindow(parent)
    , UczenUi(new Ui::Uczen)
{
    UczenUi->setupUi(this);
}

Uczen::~Uczen()
{
    delete UczenUi;
}
