#include "digikala.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Digikala w;
    w.show();
    return a.exec();
}
