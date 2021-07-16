#include <QFile>
#include <QTextStream>

#include "globalsettings.h"
#include "digikala.h"
#include "ui_digikala.h"

Digikala::Digikala(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Digikala)
{
    ui->setupUi(this);   

    GlobalSettings* global = GlobalSettings::getInstance();

    initialize();

    Admin* admin = new Admin();
    admin->showFullScreen();

    Seller* seller = new Seller();
    seller->showFullScreen();

    Buyer* buyer = new Buyer();
    buyer->showFullScreen();
}

Digikala::~Digikala()
{
    delete ui;
}

void Digikala::setStyleSheet()
{
    QFile f(":/qdarkstyle/dark/style.qss");

    if (!f.exists())
    {
        printf("Unable to set stylesheet, file not found\n");
    }
    else
    {
        f.open(QFile::ReadOnly | QFile::Text);
        QTextStream ts(&f);
        qApp->setStyleSheet(ts.readAll());
    }

}

void Digikala::initialize()
{
    this->setObjectName("Digikala");
    this->setWindowTitle("Digikala");

    this->setWindowState(Qt::WindowFullScreen);

    setStyleSheet();
}

