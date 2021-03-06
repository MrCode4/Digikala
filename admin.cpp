#include "admin.h"
#include "ui_admin.h"
#include <QPixmap>
#include <QDebug>

Admin::Admin(QWidget *parent, Global::Admin adminUser) :
    QMainWindow(parent),
    ui(new Ui::Admin)
{
    ui->setupUi(this);

    current_adminUser = adminUser;

    submiting_list.submitingListModel = new ItemListModel(this);
    canceling_list.cancelingListModel = new ItemListModel(this);
    buying_list.buyingListModel = new ItemListModel(this);
    productListModel = new ProductListModel(this);

    ui->submiting_tableView->setModel(submiting_list.submitingListModel);
    ui->cancel_tableView->setModel(canceling_list.cancelingListModel);
    ui->buying_tableView->setModel(buying_list.buyingListModel);
    ui->product_tableView->setModel(productListModel);

    p1.setName("hassan");
    p2.setName("hosian");

    p3.setName("ali");
    p4.setName("gholi");

    p5.setName("ghasem");
    p6.setName("mohsen");

    productListModel->addProduct(p6);

    add_new_submiting_product(p1);
    add_new_submiting_product(p2);

    add_new_canceling_product(p3);
    add_new_canceling_product(p4);

    add_new_buying_product(p5);
    add_new_buying_product(p6);

}

void Admin::show_productDialog(const Product& product)
{
    productDialog = new ProductDialog(this,"read_only");

    productDialog->insert_information(product);

    productDialog->exec();
}


void Admin::add_new_submiting_product(Product &product)
{
    submiting_list.submitingListModel->addProduct(product);

    QPushButton *detail_btn = new QPushButton();
    detail_btn->setText("more details");
    submiting_list.detail_btn_list.append(detail_btn);

    connect(detail_btn, &QPushButton::clicked, this, [this,product]()
    {
        show_productDialog(product);
    });

    QPushButton *confirm_btn = new QPushButton();
    confirm_btn->setText("confirm");
    confirm_btn->setStyleSheet("background-color: rgb(0, 99, 0);"
                               "color: rgb(255, 255, 255);");
    submiting_list.confirm_btn_list.append(confirm_btn);

    connect(confirm_btn, &QPushButton::clicked, this, [this,product]()
    {
        productListModel->addProduct(product);

        this->submiting_list.submitingListModel->deleteProduct(product);
    });

    QPushButton *decline_btn = new QPushButton();
    decline_btn->setText("decline");
    decline_btn->setStyleSheet("background-color: rgb(143, 0, 0);"
                               "color: rgb(255, 255, 255);");
    submiting_list.decline_btn_list.append(decline_btn);

    connect(decline_btn, &QPushButton::clicked, this, [this,product]()
    {
        this->submiting_list.submitingListModel->deleteProduct(product);
    });

    ui->submiting_tableView->setIndexWidget(submiting_list.submitingListModel->index(submiting_list.submitingListModel->getProductListSize()-1,1,QModelIndex()), detail_btn);
    ui->submiting_tableView->setIndexWidget(submiting_list.submitingListModel->index(submiting_list.submitingListModel->getProductListSize()-1,2,QModelIndex()), confirm_btn);
    ui->submiting_tableView->setIndexWidget(submiting_list.submitingListModel->index(submiting_list.submitingListModel->getProductListSize()-1,3,QModelIndex()), decline_btn);

}

void Admin::add_new_canceling_product(Product &product)
{
    canceling_list.cancelingListModel->addProduct(product);

    QPushButton *detail_btn = new QPushButton();
    detail_btn->setText("more details");
    canceling_list.detail_btn_list.append(detail_btn);

    connect(detail_btn, &QPushButton::clicked, this, [this,product]()
    {
        show_productDialog(product);
    });

    QPushButton *confirm_btn = new QPushButton();
    confirm_btn->setText("confirm");
    confirm_btn->setStyleSheet("background-color: rgb(0, 99, 0);"
                               "color: rgb(255, 255, 255);");
    canceling_list.confirm_btn_list.append(confirm_btn);

    connect(confirm_btn, &QPushButton::clicked, this, [this,product]()
    {
        //TODO::product canceling accepted

        this->canceling_list.cancelingListModel->deleteProduct(product);
    });

    QPushButton *decline_btn = new QPushButton();
    decline_btn->setText("decline");
    decline_btn->setStyleSheet("background-color: rgb(143, 0, 0);"
                               "color: rgb(255, 255, 255);");
    canceling_list.decline_btn_list.append(decline_btn);

    connect(decline_btn, &QPushButton::clicked, this, [this,product]()
    {
        this->canceling_list.cancelingListModel->deleteProduct(product);
    });

    ui->cancel_tableView->setIndexWidget(canceling_list.cancelingListModel->index(canceling_list.cancelingListModel->getProductListSize()-1,1,QModelIndex()), detail_btn);
    ui->cancel_tableView->setIndexWidget(canceling_list.cancelingListModel->index(canceling_list.cancelingListModel->getProductListSize()-1,2,QModelIndex()), confirm_btn);
    ui->cancel_tableView->setIndexWidget(canceling_list.cancelingListModel->index(canceling_list.cancelingListModel->getProductListSize()-1,3,QModelIndex()), decline_btn);

}

void Admin::add_new_buying_product(Product &product)
{
    buying_list.buyingListModel->addProduct(product);

    QPushButton *detail_btn = new QPushButton();
    detail_btn->setText("more details");
    buying_list.detail_btn_list.append(detail_btn);

    connect(detail_btn, &QPushButton::clicked, this, [this,product]()
    {
        show_productDialog(product);
    });

    QPushButton *confirm_btn = new QPushButton();
    confirm_btn->setText("confirm");
    confirm_btn->setStyleSheet("background-color: rgb(0, 99, 0);"
                               "color: rgb(255, 255, 255);");
    buying_list.confirm_btn_list.append(confirm_btn);

    connect(confirm_btn, &QPushButton::clicked, this, [this,product]()
    {
      //TODO::buing product accepted

        this->buying_list.buyingListModel->deleteProduct(product);
    });

    QPushButton *decline_btn = new QPushButton();
    decline_btn->setText("decline");
    decline_btn->setStyleSheet("background-color: rgb(143, 0, 0);"
                               "color: rgb(255, 255, 255);");
    buying_list.decline_btn_list.append(decline_btn);

    connect(decline_btn, &QPushButton::clicked, this, [this,product]()
    {
        this->buying_list.buyingListModel->deleteProduct(product);
    });

    ui->buying_tableView->setIndexWidget(buying_list.buyingListModel->index(buying_list.buyingListModel->getProductListSize()-1,1,QModelIndex()), detail_btn);
    ui->buying_tableView->setIndexWidget(buying_list.buyingListModel->index(buying_list.buyingListModel->getProductListSize()-1,2,QModelIndex()), confirm_btn);
    ui->buying_tableView->setIndexWidget(buying_list.buyingListModel->index(buying_list.buyingListModel->getProductListSize()-1,3,QModelIndex()), decline_btn);

}

Admin::~Admin()
{
    delete ui;
}

void Admin::on_actionLogout_triggered()
{
    emit closed();
}


void Admin::on_actionProfile_triggered()
{
    profileDialog = new ProfileDialog(this, current_adminUser.username, current_adminUser.password);

    profileDialog->show();
}

void Admin::on_add_btn_clicked()
{
    productDialog = new ProductDialog(this, "add");

    connect(productDialog, SIGNAL(closed()), this, SLOT(closeProductDialog()));

    connect(productDialog, SIGNAL(added(Product)), this, SLOT(addProduct(Product)));

    productDialog->exec();
}

void Admin::addProduct(Product product)
{
    productListModel->addProduct(product);

    closeProductDialog();
}

void Admin::closeProductDialog()
{
    productDialog->close();

    delete productDialog;

    productDialog = nullptr;
}

void Admin::on_delete_btn_clicked()
{
    ui->statusbar->showMessage("No Item selected",10000);
}

