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

QDataStream& operator<<(QDataStream& out, const Product& product)
{
    out << product.getComments() << QString::number(product.getCount()) << product.getDescription()
    << product.getName() << QString::number(product.getPrice()) << QString::number(product.getRate()) << QString::number((int)product.getStatus());

    return out;
}

QDataStream& operator>>(QDataStream& in, Product& product)
{
    QString comments;
    QString count;
    QString description;
    QString name;
    QString price;
    QString rate;
    QString status;

    in >> comments;
    in >> count;
    in >> description;
    in >> name;
    in >> price;
    in >> rate;
    in >> status;

    product.setComments(comments);
    product.setCount(count.toUInt());
    product.setDescription(description);
    product.setName(name);
    product.setPrice(price.toInt());
    product.setRate(rate.toDouble());
    product.setStatus((Product::Status)status.toInt());

    return in;
}

QDataStream& operator<<(QDataStream& out, const QList<Product>& productList)
{
    for(const auto &product : productList)
        out << product;

    return out;
}

QDataStream& operator>>(QDataStream& in, QList<Product>& productList)
{
    while(!in.atEnd())
    {
        Product product;

        in >> product;

        productList.append(product);
    }

    return in;
}

QDataStream& operator<<(QDataStream& out, const Global::Discount& discount)
{
    out << QString::number(discount.amount) << QString::number(discount.id);

    return out;
}

QDataStream& operator>>(QDataStream& in, Global::Discount& discount)
{
    QString strAmount;
    QString strId;

    in >> strAmount;
    in >> strId;

    discount.amount = strAmount.toInt();
    discount.id = strId.toInt();

    return in;
}

QDataStream& operator<<(QDataStream& out, const QList<Global::Discount>& discountList)
{
    for(const auto &discount : discountList)
        out << discount;

    return out;
}

QDataStream& operator>>(QDataStream& in, QList<Global::Discount>& discountList)
{
    while(!in.atEnd())
    {
        Global::Discount discount;

        in >> discount;

        discountList.append(discount);
    }

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

QDataStream& operator<<(QDataStream& out, const QList<Global::Admin>& adminList)
{
    for(const Global::Admin &admin : adminList)
        out << admin;

    return out;
}

QDataStream& operator>>(QDataStream& in, QList<Global::Admin>& adminList)
{
    while(!in.atEnd())
    {
        Global::Admin admin;

        in >> admin;

        adminList.append(admin);
    }

    return in;
}

QDataStream& operator<<(QDataStream& out, const Global::Seller& seller)
{
    out << seller.name << seller.username << seller.password
    << seller.products << seller.telephone << QString::number(seller.wallet);

    return out;
}

QDataStream& operator>>(QDataStream& in, Global::Seller& seller)
{
    QString strWallet;

    in >> seller.name;
    in >> seller.username;
    in >> seller.password;
    in >> seller.products;
    in >> seller.telephone;
    in >> strWallet;

    seller.wallet = strWallet.toInt();

    return in;
}

QDataStream& operator<<(QDataStream& out, const QList<Global::Seller>& sellerList)
{
    for(const auto &seller : sellerList)
        out << seller;

    return out;
}

QDataStream& operator>>(QDataStream& in, QList<Global::Seller>& sellerList)
{
    while(!in.atEnd())
    {
        Global::Seller seller;

        in >> seller;

        sellerList.append(seller);
    }

    return in;
}

QDataStream& operator<<(QDataStream& out, const Global::Buyer& buyer)
{
    out << buyer.username << buyer.password << buyer.address
    << buyer.orders << buyer.telephone << QString::number(buyer.wallet);

    return out;
}

QDataStream& operator>>(QDataStream& in, Global::Buyer& buyer)
{
    QString strWallet;

    in >> buyer.username;
    in >> buyer.password;
    in >> buyer.address;
    in >> buyer.orders;
    in >> buyer.telephone;
    in >> strWallet;

    buyer.wallet = strWallet.toInt();

    return in;
}

QDataStream& operator<<(QDataStream& out, const QList<Global::Buyer>& buyerList)
{
    for(const auto &buyer : buyerList)
        out << buyer;

    return out;
}

QDataStream& operator>>(QDataStream& in, QList<Global::Buyer>& buyerList)
{
    while(!in.atEnd())
    {
        Global::Buyer buyer;

        in >> buyer;

        buyerList.append(buyer);
    }

    return in;
}


GlobalSettings::GlobalSettings(QObject *parent) : QObject(parent)
{
    settings = new QSettings("DigikalaSoft", "DigikalaCompany");

    qRegisterMethod();

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
