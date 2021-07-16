#include "globalsettings.h"
#include <QDir>
#include <QDebug>

GlobalSettings* GlobalSettings::m_instance = nullptr;

Q_DECLARE_METATYPE(QList<Global::Admin>)
Q_DECLARE_METATYPE(QList<Global::Seller>)
Q_DECLARE_METATYPE(QList<Global::Buyer>)
Q_DECLARE_METATYPE(QList<Global::Discount>)
Q_DECLARE_METATYPE(Global::Discount)
Q_DECLARE_METATYPE(QList<Product>)

QDataStream& operator<<(QDataStream& out, const Global::Discount& discount)
{
    out << discount.amount << discount.id;

    return out;
}

QDataStream& operator>>(QDataStream& in, Global::Discount& discount)
{
    in >> discount.amount;
    in >> discount.id;

    return in;
}

QDataStream& operator<<(QDataStream& out, const Global::Admin& admin)
{
    out << admin.username << admin.password;

    return out;
}

QDataStream& operator>>(QDataStream& in, Global::Admin& admin)
{
    in >> admin.username;
    in >> admin.password;

    return in;
}

QDataStream& operator<<(QDataStream& out, const Global::Seller& seller)
{
    out << seller.name << seller.username << seller.password;
    out << seller.products << seller.telephone << seller.wallet;

    return out;
}

QDataStream& operator>>(QDataStream& in, Global::Seller& seller)
{
    in >> seller.name;
    in >> seller.username;
    in >> seller.password;
    in >> seller.products;
    in >> seller.telephone;
    in >> seller.wallet;

    return in;
}

QDataStream& operator<<(QDataStream& out, const Global::Buyer& buyer)
{
    out << buyer.username << buyer.password << buyer.address;
    out << buyer.orders << buyer.telephone << buyer.wallet;

    return out;
}

QDataStream& operator>>(QDataStream& in, Global::Buyer& buyer)
{
    in >> buyer.username;
    in >> buyer.password;
    in >> buyer.address;
    in >> buyer.orders;
    in >> buyer.telephone;
    in >> buyer.wallet;

    return in;
}

QDataStream& operator<<(QDataStream& out, const Product& product)
{
    out << product.getComments() << product.getCount() << product.getDescription();
    out << product.getName() << product.getPrice() << product.getRate() << (int)product.getStatus();

    return out;
}

QDataStream& operator>>(QDataStream& in, Product& product)
{
    QString comments;
    int count;
    QString description;
    QString name;
    int price;
    double rate;
    int status;

    in >> comments;
    in >> count;
    in >> description;
    in >> name;
    in >> price;
    in >> rate;
    in >> status;

    product.setComments(comments);
    product.setCount(count);
    product.setDescription(description);
    product.setName(name);
    product.setPrice(price);
    product.setRate(rate);
    product.setStatus((Product::Status)status);

    return in;
}


GlobalSettings::GlobalSettings(QObject *parent) : QObject(parent)
{
    settings = new QSettings("MySoft", "Star Runner");

    qRegisterMethod();


    //settings->value("discount_list").value<QList<Global::Discount> >();

}

void GlobalSettings::qRegisterMethod()
{
    qRegisterMetaTypeStreamOperators<QList<Global::Admin> >("QList<Global::Admin>");
    qRegisterMetaTypeStreamOperators<Global::Admin>("Global::Admin");

    qRegisterMetaTypeStreamOperators<QList<Global::Buyer> >("QList<Global::Buyer>");
    qRegisterMetaTypeStreamOperators<Global::Buyer>("Global::Buyer");

    qRegisterMetaTypeStreamOperators<QList<Global::Seller> >("QList<Global::Seller>");
    qRegisterMetaTypeStreamOperators<Global::Seller>("Global::Seller");

    qRegisterMetaTypeStreamOperators<QList<Global::Discount> >("QList<Global::Discount>");
    qRegisterMetaTypeStreamOperators<Global::Discount >("Global::Discount");

    qRegisterMetaTypeStreamOperators<QList<Product> >("QList<Product>");
}

QList<Global::Discount> GlobalSettings::getDiscounts()
{
    return settings->value("discount_list").value<QList<Global::Discount> >();
}

void GlobalSettings::addDiscount(const Global::Discount &discount)
{
    QList<Global::Discount> list = settings->value("discount_list").value<QList<Global::Discount> >();
    list.append(discount);

    settings->setValue("discount_list", QVariant::fromValue(list));
}

QList<Product> GlobalSettings::getProducts()
{
    return settings->value("product_list").value<QList<Product> >();
}

void GlobalSettings::addProduct(const Product &product)
{
    QList<Product> list = settings->value("product_list").value<QList<Product> >();
    list.append(product);

    settings->setValue("product_list", QVariant::fromValue(list));
}


QList<Global::Seller> GlobalSettings::getSellers()
{
    return settings->value("seller_list").value<QList<Global::Seller> >();
}

void GlobalSettings::addSeller(const Global::Seller &seller)
{
    QList<Global::Seller> list = settings->value("seller_list").value<QList<Global::Seller> >();
    list.append(seller);

    settings->setValue("seller_list", QVariant::fromValue(list));
}

QList<Global::Buyer> GlobalSettings::getBuyers()
{
    return settings->value("buyer_list").value<QList<Global::Buyer> >();
}

void GlobalSettings::addBuyer(const Global::Buyer &buyer)
{
    QList<Global::Buyer> list = settings->value("buyer_list").value<QList<Global::Buyer> >();
    list.append(buyer);

    settings->setValue("buyer_list", QVariant::fromValue(list));
}

QList<Global::Admin> GlobalSettings::getAdmins()
{
   return settings->value("admin_list").value<QList<Global::Admin> >();
}

void GlobalSettings::addAdmin(const Global::Admin &admin)
{
    QList<Global::Admin> list = settings->value("admin_list").value<QList<Global::Admin> >();
    list.append(admin);

    settings->setValue("admin_list", QVariant::fromValue(list));
}


