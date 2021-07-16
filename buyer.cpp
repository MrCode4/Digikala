#include "buyer.h"
#include "ui_buyer.h"

/*!
 * \brief Buyer::Buyer
 * buyer page
 * \param parent
 * \param buyer
 *
 */
Buyer::Buyer(QWidget *parent, Global::Buyer buyer) :
    QMainWindow(parent),
    ui(new Ui::Buyer)
{
    ui->setupUi(this);

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

