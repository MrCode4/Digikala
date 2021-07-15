#include "admin.h"
#include "ui_admin.h"
#include <QPixmap>
#include <QDebug>

Admin::Admin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Admin)
{
    ui->setupUi(this);

    submiting_list.submitingListModel = new ItemListModel(this);
    canceling_list.cancelingListModel = new ItemListModel(this);
    buying_list.buyingListModel = new ItemListModel(this);

    ui->submiting_tableView->setModel(submiting_list.submitingListModel);
    ui->cancel_tableView->setModel(canceling_list.cancelingListModel);
    ui->buying_tableView->setModel(buying_list.buyingListModel);

    p1.setName("hassan");
    p2.setName("hosian");

    p3.setName("ali");
    p4.setName("gholi");

    p5.setName("ghasem");
    p6.setName("mohsen");

    add_new_submiting_product(p1);
    add_new_submiting_product(p2);

    add_new_canceling_product(p3);
    add_new_canceling_product(p4);

    add_new_buying_product(p5);
    add_new_buying_product(p6);

}

void Admin::add_new_submiting_product(Product &product)
{
    submiting_list.submitingListModel->addProduct(product);

    QPushButton *detail_btn = new QPushButton();
    detail_btn->setText("more details");
    submiting_list.detail_btn_list.append(detail_btn);

    QPushButton *confirm_btn = new QPushButton();
    confirm_btn->setText("confirm");
    confirm_btn->setStyleSheet("background-color: rgb(0, 99, 0);"
                               "color: rgb(255, 255, 255);");
    submiting_list.confirm_btn_list.append(confirm_btn);

    QPushButton *decline_btn = new QPushButton();
    decline_btn->setText("decline");
    decline_btn->setStyleSheet("background-color: rgb(143, 0, 0);"
                               "color: rgb(255, 255, 255);");
    submiting_list.decline_btn_list.append(decline_btn);

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

    QPushButton *confirm_btn = new QPushButton();
    confirm_btn->setText("confirm");
    confirm_btn->setStyleSheet("background-color: rgb(0, 99, 0);"
                               "color: rgb(255, 255, 255);");
    canceling_list.confirm_btn_list.append(confirm_btn);

    QPushButton *decline_btn = new QPushButton();
    decline_btn->setText("decline");
    decline_btn->setStyleSheet("background-color: rgb(143, 0, 0);"
                               "color: rgb(255, 255, 255);");
    canceling_list.decline_btn_list.append(decline_btn);

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

    QPushButton *confirm_btn = new QPushButton();
    confirm_btn->setText("confirm");
    confirm_btn->setStyleSheet("background-color: rgb(0, 99, 0);"
                               "color: rgb(255, 255, 255);");
    buying_list.confirm_btn_list.append(confirm_btn);

    QPushButton *decline_btn = new QPushButton();
    decline_btn->setText("decline");
    decline_btn->setStyleSheet("background-color: rgb(143, 0, 0);"
                               "color: rgb(255, 255, 255);");
    buying_list.decline_btn_list.append(decline_btn);

    ui->buying_tableView->setIndexWidget(buying_list.buyingListModel->index(buying_list.buyingListModel->getProductListSize()-1,1,QModelIndex()), detail_btn);
    ui->buying_tableView->setIndexWidget(buying_list.buyingListModel->index(buying_list.buyingListModel->getProductListSize()-1,2,QModelIndex()), confirm_btn);
    ui->buying_tableView->setIndexWidget(buying_list.buyingListModel->index(buying_list.buyingListModel->getProductListSize()-1,3,QModelIndex()), decline_btn);

}

Admin::~Admin()
{
    delete ui;
}
