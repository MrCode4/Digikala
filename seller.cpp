#include "seller.h"
#include "ui_seller.h"

/*!
 * \brief Seller::Seller
 * seller page
 * \param parent
 * \param seller
 */
Seller::Seller(QWidget *parent, Global::Seller sellerUser) :
    QMainWindow(parent),
    ui(new Ui::Seller)
{
    ui->setupUi(this);

    current_sellerUser = sellerUser;

    productListModel = new ProductListModel(this);

    ui->product_tableView->setModel(productListModel);
}

Seller::~Seller()
{
    delete ui;
}

void Seller::on_actionLogout_triggered()
{
    emit closed();
}


void Seller::on_actionProfile_triggered()
{
    profileDialog = new ProfileDialog(this, current_sellerUser.username, current_sellerUser.password);

    profileDialog->exec();
}

