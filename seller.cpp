#include "seller.h"
#include "ui_seller.h"

Seller::Seller(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Seller)
{
    ui->setupUi(this);
}

Seller::~Seller()
{
    delete ui;
}
