#ifndef BUYER_H
#define BUYER_H

#include <QMainWindow>

namespace Ui {
class Buyer;
}

class Buyer : public QMainWindow
{
    Q_OBJECT

public:
    explicit Buyer(QWidget *parent = nullptr);
    ~Buyer();

private:
    Ui::Buyer *ui;
};

#endif // BUYER_H
