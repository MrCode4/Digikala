#ifndef BUYER_H
#define BUYER_H

#include <QMainWindow>

namespace Ui {
class buyer;
}

class buyer : public QMainWindow
{
    Q_OBJECT

public:
    explicit buyer(QWidget *parent = nullptr);
    ~buyer();

private:
    Ui::buyer *ui;
};

#endif // BUYER_H
