#include "buyer.h"
#include "ui_buyer.h"

Buyer::Buyer(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Buyer)
{
    ui->setupUi(this);
}

Buyer::~Buyer()
{
    delete ui;
}
