#ifndef PRODUCTDIALOG_H
#define PRODUCTDIALOG_H

#include <QDialog>

namespace Ui {
class productDialog;
}

class productDialog : public QDialog
{
    Q_OBJECT

public:
    explicit productDialog(QWidget *parent = nullptr);
    ~productDialog();

private:
    Ui::productDialog *ui;
};

#endif // PRODUCTDIALOG_H
