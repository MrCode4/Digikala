#ifndef SELLER_H
#define SELLER_H

#include <QMainWindow>
#include "globalsettings.h"
#include "productlistmodel.h"
#include "profiledialog.h"

namespace Ui {
class Seller;
}

class Seller : public QMainWindow
{   
    Q_OBJECT

public:
    explicit Seller(QWidget *parent = nullptr, Global::Seller sellerUser = Global::Seller());
    ~Seller();

private slots:
    void on_actionLogout_triggered();

    void on_actionProfile_triggered();

signals:
    void closed();

private:
    Ui::Seller *ui;
    ProductListModel* productListModel;
    Global::Seller current_sellerUser;
    ProfileDialog* profileDialog = nullptr;
};

#endif // SELLER_H
