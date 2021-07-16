#include "itemlistmodel.h"
#include <QDebug>
#include <QHeaderView>

ItemListModel::ItemListModel(QObject *parent)
    : QAbstractListModel(parent),
      header{"Product Name", "Details", "Confirm", "Decline"}
{

}

QVariant ItemListModel::headerData(int section, Qt::Orientation orientation, int role) const
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

int ItemListModel::rowCount(const QModelIndex &parent) const
{
    return productList.size();
}

int ItemListModel::columnCount(const QModelIndex &parent) const
{
    return header.size();
}

QVariant ItemListModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || index.row() >= productList.size())
        return QVariant();

    if(role == Qt::DisplayRole)
    {
        if(index.column() == 0)
        {
            return productList[index.row()].getName();
        }

    }

    return QVariant();
}


void ItemListModel::addProduct(Product& product)
{
    beginInsertRows(QModelIndex(), productList.size(), productList.size());

    productList.append(product);

    endInsertRows();
}

void ItemListModel::deleteProduct(const Product& product)
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

int ItemListModel::getProductListSize()
{
    return productList.size();
}

int ItemListModel::getHeaderSize()
{
    return header.size();
}
