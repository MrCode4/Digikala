#include "signuppage.h"
#include "ui_signuppage.h"

SignUpPage::SignUpPage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SignUpPage)
{
    ui->setupUi(this);


}

SignUpPage::~SignUpPage()
{
    delete ui;
}

void SignUpPage::on_signin_pushBtn_clicked()
{
    emit closed();
}


void SignUpPage::on_signup_pushBtn_clicked()
{
    if(ui->userMode_comboBox->currentText() == "Admin")
    {
        Global::Admin admin;
        admin.password = ui->password_lineEdit->text();
        admin.username = ui->username_lineEdit->text();

        GlobalSettings::getInstance()->addAdmin(admin);
    }
    else if(ui->userMode_comboBox->currentText() == "Buyer")
    {
        Global::Buyer buyer;
        buyer.address = ui->address_lineEdit->text();
        buyer.orders = QList<Product>();
        buyer.password = ui->password_lineEdit->text();
        buyer.telephone = ui->telephone_LIneEdit->text();
        buyer.username = ui->username_lineEdit->text();
        buyer.wallet = 0;

        GlobalSettings::getInstance()->addBuyer(buyer);
    }
    else if(ui->userMode_comboBox->currentText() == "Seller")
    {
        Global::Seller seller;
        seller.name = ui->name_lineEdit->text();
        seller.password = ui->password_lineEdit->text();
        seller.products = QList<Product>();
        seller.telephone = ui->telephone_LIneEdit->text();
        seller.username = ui->username_lineEdit->text();
        seller.wallet = 0;

        GlobalSettings::getInstance()->addSeller(seller);
    }

    emit closed();
}


void SignUpPage::on_userMode_comboBox_currentTextChanged(const QString &text)
{
    if(text == "Admin")
    {
        ui->telephone_lbl->hide();
        ui->name_lbl->hide();
        ui->address_lbl->hide();
        ui->telephone_LIneEdit->hide();
        ui->address_lineEdit->hide();
        ui->name_lineEdit->hide();
    }
    else if("Buyer")
    {
        ui->telephone_lbl->show();
        ui->name_lbl->hide();
        ui->address_lbl->show();
        ui->telephone_LIneEdit->show();
        ui->address_lineEdit->show();
        ui->name_lineEdit->hide();
    }
    else
    {
        ui->telephone_lbl->show();
        ui->name_lbl->show();
        ui->address_lbl->show();
        ui->telephone_LIneEdit->show();
        ui->address_lineEdit->show();
        ui->name_lineEdit->show();
    }
}

