#ifndef ADMIN_H
#define ADMIN_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QTableView>
#include <QPushButton>

#include "product.h"
#include "itemlistmodel.h"
#include "productdialog.h"

namespace Ui {
class Admin;
}

class Admin : public QMainWindow
{
    Q_OBJECT

public:
    explicit Admin(QWidget *parent = nullptr);
    ~Admin();

private slots:

private:
    struct Submiting_list
    {
        QList<QPushButton*> detail_btn_list;
        QList<QPushButton*> confirm_btn_list;
        QList<QPushButton*> decline_btn_list;

        ItemListModel* submitingListModel;
    }submiting_list;

    struct Canceling_list
    {
        QList<QPushButton*> detail_btn_list;
        QList<QPushButton*> confirm_btn_list;
        QList<QPushButton*> decline_btn_list;

        ItemListModel* cancelingListModel;
    }canceling_list;

    struct Buying_list
    {
        QList<QPushButton*> detail_btn_list;
        QList<QPushButton*> confirm_btn_list;
        QList<QPushButton*> decline_btn_list;

        ItemListModel* buyingListModel;
    }buying_list;

    Ui::Admin *ui;
    Product p2,p1,p3,p4,p5,p6;
    ProductDialog* productDialog  = nullptr;

    QList<Product> productList;

    void add_new_submiting_product(Product& product);
    void add_new_canceling_product(Product& product);
    void add_new_buying_product(Product& product);

    void show_productDialog(const Product &product);

    void add_to_productList(const Product &product);

};

#endif // ADMIN_H
