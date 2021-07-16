#ifndef BUYER_H
#define BUYER_H

#include <QMainWindow>
#include "globalsettings.h"

namespace Ui {
class Buyer;
}

class Buyer : public QMainWindow
{
    Q_OBJECT

public:
    explicit Buyer(QWidget *parent = nullptr, Global::Buyer buyer = Global::Buyer());
    ~Buyer();

private:
    Ui::Buyer *ui;
};

#endif // BUYER_H
