#include "seller.h"
#include "ui_seller.h"

Seller::Seller(QWidget *parent, Global::Seller seller) :
    QMainWindow(parent),
    ui(new Ui::Seller)
{
    ui->setupUi(this);
}

Seller::~Seller()
{
    delete ui;
}

void Seller::on_actionLogout_triggered()
{
    emit closed();
}

