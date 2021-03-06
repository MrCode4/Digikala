#include <QFile>
#include <QTextStream>

#include "globalsettings.h"
#include "digikala.h"
#include "ui_digikala.h"

/*!
 * \brief Digikala::Digikala
 * login page
 * \param parent
 */
Digikala::Digikala(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Digikala)
{
    ui->setupUi(this);   

    initialize();

}

Digikala::~Digikala()
{
    delete ui;
}

/*!
 * \brief Digikala::setStyleSheet
 * set style
 */
void Digikala::setStyleSheet()
{
    QFile f(":/qdarkstyle/dark/style.qss");

    if (!f.exists())
    {
        printf("Unable to set stylesheet, file not found\n");
    }
    else
    {
        f.open(QFile::ReadOnly | QFile::Text);
        QTextStream ts(&f);
        qApp->setStyleSheet(ts.readAll());
    }

}

/*!
 * \brief Digikala::initialize
 */
void Digikala::initialize()
{
    this->setObjectName("Digikala");
    this->setWindowTitle("Digikala");

    this->setWindowState(Qt::WindowFullScreen);

    setStyleSheet();
}

/*!
 * \brief Digikala::on_actionExit_triggered
 * when user clicked on exit button
 */
void Digikala::on_actionExit_triggered()
{
    close();
}

/*!
 * \brief Digikala::requestLogin
 * when user clicked on login button
 */
void Digikala::requestLogin()
{
    QList<Global::Admin> adminList = GlobalSettings::getInstance()->getAdmins();

    bool isItExist = false;

    Global::Admin adminUser;

    for(const auto &ad : qAsConst(adminList))
    {
        if(ad.username == ui->username_lineEdit->text() &&
           ad.password == ui->passowrd_lineEdit->text())
        {
            isItExist = true;
            adminUser = ad;

            break;
        }
    }

    if(isItExist)
    {
        admin = new Admin(this, adminUser);
        admin->showFullScreen();

        connect(admin,SIGNAL(closed()),this,SLOT(adminClosed()));

        return;
    }



    Global::Seller sellerUser;
    QList<Global::Seller> sellerList = GlobalSettings::getInstance()->getSellers();

    for(const auto &se : qAsConst(sellerList))
        if(se.username == ui->username_lineEdit->text() &&
           se.password == ui->passowrd_lineEdit->text())
        {
            isItExist = true;
            sellerUser = se;

            break;
        }

    if(isItExist)
    {
        seller = new Seller(this, sellerUser);
        seller->showFullScreen();

        connect(seller,SIGNAL(closed()),this,SLOT(sellerClosed()));

        return;
    }

    Global::Buyer buyerUser;
    QList<Global::Buyer> buyerList = GlobalSettings::getInstance()->getBuyers();

    for(const auto &bu : qAsConst(buyerList))
        if(bu.username == ui->username_lineEdit->text() &&
           bu.password == ui->passowrd_lineEdit->text())
        {
            isItExist = true;
            buyerUser = bu;

            break;
        }

    if(isItExist)
    {
        buyer = new Buyer(this, buyerUser);
        buyer->showFullScreen();

        connect(buyer,SIGNAL(closed()),this,SLOT(buyerClosed()));

        return;
    }

    ui->statusBar->showMessage("Invalid Username or Password!",10000);

}

/*!
 * \brief Digikala::signUpPageClosed
 * when user clicked on signup
 */
void Digikala::signUpPageClosed()
{
    this->show();

    signUpPage->close();

    delete signUpPage;

    signUpPage = nullptr;
}

/*!
 * \brief Digikala::adminClosed
 * when admin loggedout
 */
void Digikala::adminClosed()
{
    this->show();

    admin->close();

    delete admin;

    admin = nullptr;
}

/*!
 * \brief Digikala::buyerClosed
 * whem buyer logged out
 */
void Digikala::buyerClosed()
{
    this->show();

    buyer->close();

    delete buyer;

    buyer = nullptr;
}

/*!
 * \brief Digikala::sellerClosed
 * when seller logged out
 */
void Digikala::sellerClosed()
{
    this->show();

    seller->close();

    delete seller;

    seller = nullptr;
}

/*!
 * \brief Digikala::signup
 * when user clicked on signup
 */
void Digikala::signup()
{
    signUpPage = new SignUpPage();

    signUpPage->showFullScreen();

    connect(signUpPage, SIGNAL(closed()), this, SLOT(signUpPageClosed()));

    this->hide();
}

