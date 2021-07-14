#ifndef DIGIKALA_H
#define DIGIKALA_H

#include <QMainWindow>

#include "seller.h"
#include "admin.h"
#include "buyer.h"
#include "product.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Digikala; }
QT_END_NAMESPACE

class Digikala : public QMainWindow
{
    Q_OBJECT

public:
    Digikala(QWidget *parent = nullptr);
    ~Digikala();

private:
    Ui::Digikala *ui;
    void setStyleSheet();
    void initialize();
};
#endif // DIGIKALA_H
