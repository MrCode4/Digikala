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

    ui->actionWallet->setText("Wallet: " + QString::number(sellerUser.wallet) + "Rial");

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

void Seller::addProduct(Product product)
{
    productListModel->addProduct(product);

    closeProductDialog();
}

void Seller::closeProductDialog()
{
    productDialog->close();

    delete productDialog;

    productDialog = nullptr;
}


void Seller::on_add_btn_clicked()
{
    productDialog = new ProductDialog(this, "add");

    connect(productDialog,SIGNAL(closed), this, SLOT(closeProductDialog()));

    connect(productDialog, SIGNAL(added(Product)), this, SLOT(addProduct(Product)));

    productDialog->exec();
}

