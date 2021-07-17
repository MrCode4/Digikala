#ifndef BUYER_H
#define BUYER_H

#include <QMainWindow>
#include "globalsettings.h"
#include "productlistmodel.h"
#include "profiledialog.h"

namespace Ui {
class Buyer;
}

class Buyer : public QMainWindow
{
    Q_OBJECT

public:
    explicit Buyer(QWidget *parent = nullptr, Global::Buyer current_buyerUser = Global::Buyer());
    ~Buyer();

private slots:
    void on_actionLogout_triggered();

    void on_actionProfile_triggered();

    void on_pushButton_5_clicked();

signals:
    void closed();

private:
    Ui::Buyer *ui;
    ProductListModel* productListModel;
    Global::Buyer current_buyerUser;
    ProfileDialog* profileDialog = nullptr;
};

#endif // BUYER_H
