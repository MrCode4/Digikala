#include "seller.h"
#include "ui_seller.h"

/*!
 * \brief Seller::Seller
 * seller page
 * \param parent
 * \param seller
 */
Seller::Seller(QWidget *parent, Global::Seller seller) :
    QMainWindow(parent),
    ui(new Ui::Seller)
{
    ui->setupUi(this);

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

