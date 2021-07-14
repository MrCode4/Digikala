#include "itemlistmodel.h"
#include <QDebug>
#include <QHeaderView>

ItemListModel::ItemListModel(QObject *parent)
    : QAbstractListModel(parent)
{
}

QVariant ItemListModel::headerData(int section, Qt::Orientation orientation, int role) const
{    

    if(role == Qt::DisplayRole)
    {
        QStringList header;
        if(orientation == Qt::Orientation::Horizontal)
        {
            switch (section)
            {
            case 0:
                return "Product Name";
            case 1:
                return "Confirm";
            case 2:
                return "Decline";
            }
        }
        else
        {
            return QString::number(section);
        }
        return header;
    }

    return QVariant();


}

int ItemListModel::rowCount(const QModelIndex &parent) const
{
    // For list models only the root node (an invalid parent) should return the list's size. For all
    // other (valid) parents, rowCount() should return 0 so that it does not become a tree model.
    if (parent.isValid())
        return 0;

    // FIXME: Implement me!
}

QVariant ItemListModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    // FIXME: Implement me!
    return QVariant();
}
