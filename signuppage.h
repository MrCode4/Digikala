#ifndef SIGNUPPAGE_H
#define SIGNUPPAGE_H

#include <QMainWindow>

namespace Ui {
class SignUpPage;
}

class SignUpPage : public QMainWindow
{
    Q_OBJECT

public:
    explicit SignUpPage(QWidget *parent = nullptr);
    ~SignUpPage();

private:
    Ui::SignUpPage *ui;
};

#endif // SIGNUPPAGE_H
