#ifndef SELLER_H
#define SELLER_H

#include <QMainWindow>
#include "globalsettings.h"
#include "productlistmodel.h"

namespace Ui {
class Seller;
}

class Seller : public QMainWindow
{   
    Q_OBJECT

public:
    explicit Seller(QWidget *parent = nullptr, Global::Seller seller = Global::Seller());
    ~Seller();

private slots:
    void on_actionLogout_triggered();

signals:
    void closed();

private:
    Ui::Seller *ui;
    ProductListModel* productListModel;
};

#endif // SELLER_H
