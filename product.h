#ifndef PRODUCT_H
#define PRODUCT_H

#include <QString>

/*!
 * \brief The Product class
 * It contain all feilds about product
 */
class Product
{
public:
    Product()
    {
        price = 0;
        count = 0;
        rate = 0.0;
    }


    const QString &getName() const;
    void setName(const QString &newName);

    int getPrice() const;
    void setPrice(int newPrice);

    const int &getCount() const;
    void setCount(const int &newCount);

    const QString &getDescription() const;
    void setDescription(const QString &newDescription);

    double getRate() const;
    void setRate(double newRate);

    const QString &getComments() const;
    void setComments(const QString &newComments);

private:
    QString name;
    int price;
    int count;
    QString description;
    double rate;
    QString comments;
};

inline const QString &Product::getName() const
{
    return name;
}

inline void Product::setName(const QString &newName)
{
    name = newName;
}

inline int Product::getPrice() const
{
    return price;
}

inline void Product::setPrice(int newPrice)
{
    price = newPrice;
}

inline const int &Product::getCount() const
{
    return count;
}

inline void Product::setCount(const int &newCount)
{
    count = newCount;
}

inline const QString &Product::getDescription() const
{
    return description;
}

inline void Product::setDescription(const QString &newDescription)
{
    description = newDescription;
}

inline double Product::getRate() const
{
    return rate;
}

inline void Product::setRate(double newRate)
{
    rate = newRate;
}

inline const QString &Product::getComments() const
{
    return comments;
}

inline void Product::setComments(const QString &newComments)
{
    comments = newComments;
}


#endif // PRODUCT_H
