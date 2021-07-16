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
