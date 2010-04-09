#include <QtGui/QApplication>
#include "connection.h"

int main(int argc, char *argv[])
{    
    QApplication a(argc, argv);
    Connection w;
    w.show();
    return a.exec();
}
