#include "productdialog.h"
#include "ui_productdialog.h"

productDialog::productDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::productDialog)
{
    ui->setupUi(this);
}

productDialog::~productDialog()
{
    delete ui;
}
