#ifndef SELLER_H
#define SELLER_H

#include <QMainWindow>

namespace Ui {
class Seller;
}

class Seller : public QMainWindow
{
    Q_OBJECT

public:
    explicit Seller(QWidget *parent = nullptr);
    ~Seller();

private:
    Ui::Seller *ui;
};

#endif // SELLER_H
