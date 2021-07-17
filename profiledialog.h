#ifndef PROFILEDIALOG_H
#define PROFILEDIALOG_H

#include <QDialog>

namespace Ui {
class ProfileDialog;
}

class ProfileDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ProfileDialog(QWidget *parent = nullptr, QString username = "", QString password = "");
    ~ProfileDialog();

private:
    Ui::ProfileDialog *ui;
};

#endif // PROFILEDIALOG_H
