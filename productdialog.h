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
    explicit ProductDialog(QWidget *parent = nullptr, QString mode = "read_only");

    void insert_information(const Product& product);

    ~ProductDialog();

signals:
    void added(Product);
    void closed();

private slots:
    void on_addBtn_clicked();

    void on_cancelBtn_clicked();



private:
    Ui::ProductDialog *ui;


};

#endif // PRODUCTDIALOG_H
