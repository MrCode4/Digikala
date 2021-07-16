#include "productlistmodel.h"
#include <QDebug>

ProductListModel::ProductListModel(QObject *parent)
    : QAbstractListModel(parent),
    header{"Product Name", "Price", "Count", "Description", "Rate", "Comments"}
{
}

QVariant ProductListModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if(role == Qt::DisplayRole)
    {
        if(orientation == Qt::Orientation::Horizontal)
        {
            if(section < header.size())
            {
                return header[section];
            }
            else
                return QVariant();
        }
        else
        {
            return QString::number(section+1);
        }
    }

    return QVariant();

}

int ProductListModel::rowCount(const QModelIndex &parent) const
{
     return productList.size();
}

int ProductListModel::columnCount(const QModelIndex &parent) const
{
    return header.size();
}

QVariant ProductListModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || index.row() >= productList.size())
        return QVariant();

    if(role == Qt::DisplayRole)
    {
        if(index.column() == 0)//Name
        {
            return productList[index.row()].getName();
        }
        else if(index.column() == 1)//Price
        {
            return productList[index.row()].getPrice();
        }
        else if(index.column() == 2)//Count
        {
            return productList[index.row()].getCount();
        }
        else if(index.column() == 3)//Description
        {
            return productList[index.row()].getDescription();
        }
    }

    return QVariant();
}

void ProductListModel::addProduct(const Product& product)
{
    bool isExist = false;

    for(const auto &p : qAsConst(productList))
    {
        if(p.getName() == product.getName())
        {
            isExist = true;

            break;
        }
    }

    if(!isExist)
    {
        beginInsertRows(QModelIndex(), productList.size(), productList.size());

        productList.append(product);

        endInsertRows();
    }
}

void ProductListModel::deleteProduct(const Product& product)
{
    for(int i = 0 ; i < productList.size() ; i++)
    {
        if(productList[i].getName() == product.getName())
        {
            beginRemoveRows(QModelIndex(), i, i);

            productList.removeAt(i);

            endRemoveRows();

            return;
        }
    }
}

int ProductListModel::getProductListSize()
{
    return productList.size();
}

int ProductListModel::getHeaderSize()
{
    return header.size();
}
