#ifndef BUYER_H
#define BUYER_H

#include <QMainWindow>
#include "globalsettings.h"
#include "productlistmodel.h"

namespace Ui {
class Buyer;
}

class Buyer : public QMainWindow
{
    Q_OBJECT

public:
    explicit Buyer(QWidget *parent = nullptr, Global::Buyer buyer = Global::Buyer());
    ~Buyer();

private slots:
    void on_actionLogout_triggered();

signals:
    void closed();

private:
    Ui::Buyer *ui;
    ProductListModel* productListModel;
};

#endif // BUYER_H
