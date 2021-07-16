#include "buyer.h"
#include "ui_buyer.h"

Buyer::Buyer(QWidget *parent, Global::Buyer buyer) :
    QMainWindow(parent),
    ui(new Ui::Buyer)
{
    ui->setupUi(this);
}

Buyer::~Buyer()
{
    delete ui;
}

void Buyer::on_actionLogout_triggered()
{
    emit closed();
}

