#ifndef GLOBALSETTINGS_H
#define GLOBALSETTINGS_H

#include <QObject>
#include <QSettings>
#include <QDebug>
#include <QMetaType>
#include <QList>
#include <QVariant>
#include <product.h>

namespace Global
{
struct Admin
{
    QString username;
    QString password;
};

struct Seller
{
    QString username;
    QString password;
    QString name;
    QString telephone;

    int wallet;

    QList<Product>products;
};

struct Buyer
{
    QString username;
    QString password;
    QString address;
    QString telephone;

    int wallet;

    QList<Product> orders;
};

struct Discount
{
    int id;
    int amount;
};

}
class GlobalSettings : public QObject
{
    Q_OBJECT
public:
    static GlobalSettings* getInstance()
    {
        if(m_instance == nullptr)
        {
            m_instance = new GlobalSettings();
        }

        return m_instance;
    }

    QList<Global::Admin> getAdmins();
    void addAdmin(const Global::Admin &admin);

    QList<Global::Buyer> getBuyers();
    void addBuyer(const Global::Buyer &buyer);

    QList<Global::Seller> getSellers();
    void addSeller(const Global::Seller &seller);

    QList<Product> getProducts();
    void addProduct(const Product &product);

    QList<Global::Discount> getDiscounts();
    void addDiscount(const Global::Discount &discount);

protected:
        static GlobalSettings* m_instance;

private:
    QSettings *settings = nullptr;
    explicit GlobalSettings(QObject *parent = nullptr);

    QList<Global::Admin> admins;
    QList<Global::Buyer> buyers;
    QList<Global::Seller> sellers;

    QList<Product> products;

    QList<Global::Discount> discounts;



    void qRegisterMethod();
};

#endif // GLOBALSETTINGS_H
