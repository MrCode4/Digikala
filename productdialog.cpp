#include "productdialog.h"
#include "ui_productdialog.h"

ProductDialog::ProductDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ProductDialog)
{
    ui->setupUi(this);
}

ProductDialog::~ProductDialog()
{
    delete ui;
}

void ProductDialog::insert_information(const Product &product)
{
    ui->name_lineEdit->setText(product.getName());
    ui->price_lineEdit->setText(QString::number(product.getPrice()));
    ui->count_lineEdit->setText(QString::number(product.getCount()));
    ui->description_lineEdit->setText(product.getDescription());
}
