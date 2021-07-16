#ifndef SELLER_H
#define SELLER_H

#include <QMainWindow>
#include "globalsettings.h"

namespace Ui {
class Seller;
}

class Seller : public QMainWindow
{
    Q_OBJECT

public:
    explicit Seller(QWidget *parent = nullptr, Global::Seller seller = Global::Seller());
    ~Seller();

private:
    Ui::Seller *ui;
};

#endif // SELLER_H
