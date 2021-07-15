#ifndef ITEMLISTMODEL_H
#define ITEMLISTMODEL_H

#include <QAbstractListModel>
#include <QList>

#include "product.h"

#include <QAbstractItemModel>

class ItemListModel : public QAbstractListModel
{
    Q_OBJECT

public:
    explicit ItemListModel(QObject *parent = nullptr);

    // Header:
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    void addProduct(Product& product);

    int getProductListSize();

    int getHeaderSize();

private:
    QList<Product> productList;

    QStringList header;
};

#endif // ITEMLISTMODEL_H
