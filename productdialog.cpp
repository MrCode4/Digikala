#include "productdialog.h"
#include "ui_productdialog.h"
#include <QDebug>

ProductDialog::ProductDialog(QWidget *parent, QString mode) :
    QDialog(parent),
    ui(new Ui::ProductDialog)
{
    ui->setupUi(this);

    if(mode == "read_only")
    {
        ui->addBtn->hide();
        ui->cancelBtn->hide();
        ui->count_lineEdit->setDisabled(true);
        ui->description_lineEdit->setDisabled(true);
        ui->price_lineEdit->setDisabled(true);
        ui->name_lineEdit->setDisabled(true);
    }
    else if(mode == "add")
    {
        ui->addBtn->show();
        ui->cancelBtn->show();
        ui->count_lineEdit->setDisabled(false);
        ui->description_lineEdit->setDisabled(false);
        ui->price_lineEdit->setDisabled(false);
        ui->name_lineEdit->setDisabled(false);
    }
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

void ProductDialog::on_addBtn_clicked()
{
    Product product;

    product.setDescription(ui->description_lineEdit->text());
    product.setCount(ui->count_lineEdit->text().toInt());
    product.setPrice(ui->price_lineEdit->text().toInt());
    product.setName(ui->name_lineEdit->text());

    emit added(product);
}

void ProductDialog::on_cancelBtn_clicked()
{
    emit closed();
}

