#include "digikala.h"
#include "ui_digikala.h"

Digikala::Digikala(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Digikala)
{
    ui->setupUi(this);
}

Digikala::~Digikala()
{
    delete ui;
}

