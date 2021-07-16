#ifndef PRODUCTLISTMODEL_H
#define PRODUCTLISTMODEL_H

#include <QAbstractListModel>
#include <QList>

#include "product.h"

class ProductListModel : public QAbstractListModel
{
    Q_OBJECT

public:
    explicit ProductListModel(QObject *parent = nullptr);

    // Header:
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;    

    void addProduct(const Product &product);
    void deleteProduct(const Product &product);

    int getProductListSize();

    int getHeaderSize();

private:
    QList<Product> productList;

    QStringList header;
};

#endif // PRODUCTLISTMODEL_H
