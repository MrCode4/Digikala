#ifndef DIGIKALA_H
#define DIGIKALA_H

#include <QMainWindow>

#include "seller.h"
#include "admin.h"
#include "buyer.h"
#include "product.h"
#include "signuppage.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Digikala; }
QT_END_NAMESPACE

class Digikala : public QMainWindow
{
    Q_OBJECT

public:
    Digikala(QWidget *parent = nullptr);
    ~Digikala();

private slots:
    void on_actionExit_triggered();
    void requestLogin();
    void signup();

    void signUpPageClosed();
    void adminClosed();
    void buyerClosed();
    void sellerClosed();

private:
    Ui::Digikala *ui;
    void setStyleSheet();
    void initialize();
    Admin* admin = nullptr;
    Buyer* buyer = nullptr;
    Seller* seller = nullptr;
    SignUpPage* signUpPage = nullptr;
};
#endif // DIGIKALA_H
