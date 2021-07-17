#include "buyer.h"
#include "ui_buyer.h"

/*!
 * \brief Buyer::Buyer
 * buyer page
 * \param parent
 * \param buyer
 *
 */
Buyer::Buyer(QWidget *parent, Global::Buyer current_buyerUser) :
    QMainWindow(parent),
    ui(new Ui::Buyer)
{
    ui->setupUi(this);

    this->current_buyerUser = current_buyerUser;

    ui->actionWallet->setText("Wallet: " + QString::number(current_buyerUser.wallet) + "Rial");

    productListModel = new ProductListModel(this);

    ui->product_tableView->setModel(productListModel);
}

Buyer::~Buyer()
{
    delete ui;
}

void Buyer::on_actionLogout_triggered()
{
    emit closed();
}


void Buyer::on_actionProfile_triggered()
{
    profileDialog = new ProfileDialog(this, current_buyerUser.username, current_buyerUser.password);

    profileDialog->exec();
}



