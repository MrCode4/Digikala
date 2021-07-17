#include "profiledialog.h"
#include "ui_profiledialog.h"

ProfileDialog::ProfileDialog(QWidget *parent, QString username, QString password) :
    QDialog(parent),
    ui(new Ui::ProfileDialog)
{
    ui->setupUi(this);

    ui->username_lineEdit->setText(username);
    ui->password_lineEdit->setText(password);
}

ProfileDialog::~ProfileDialog()
{
    delete ui;
}
