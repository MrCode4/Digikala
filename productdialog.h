#ifndef PRODUCTDIALOG_H
#define PRODUCTDIALOG_H

#include <QDialog>

#include <product.h>

namespace Ui {
class ProductDialog;
}

class ProductDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ProductDialog(QWidget *parent = nullptr);

    void insert_information(const Product& product);

    ~ProductDialog();

private:
    Ui::ProductDialog *ui;

};

#endif // PRODUCTDIALOG_H
