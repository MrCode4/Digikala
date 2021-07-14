#include "buyer.h"
#include "ui_buyer.h"

buyer::buyer(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::buyer)
{
    ui->setupUi(this);
}

buyer::~buyer()
{
    delete ui;
}
