#ifndef SIGNUPPAGE_H
#define SIGNUPPAGE_H

#include <QMainWindow>
#include <QPixmap>
#include <globalsettings.h>

namespace Ui {
class SignUpPage;
}

class SignUpPage : public QMainWindow
{
    Q_OBJECT

public:
    explicit SignUpPage(QWidget *parent = nullptr);
    ~SignUpPage();

private slots:
    void on_signin_pushBtn_clicked();

    void on_signup_pushBtn_clicked();

    void on_userMode_comboBox_currentTextChanged(const QString &text);

signals:
    void closed();

private:
    Ui::SignUpPage *ui;

    QPixmap backImage;
};

#endif // SIGNUPPAGE_H
