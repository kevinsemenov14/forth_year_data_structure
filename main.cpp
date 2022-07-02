#include "headers\mainwindow.h"
#include "headers\database.h" // **testing**
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    // Will test the database and see if it opens or not.
    Database::getInstance();

    w.show();

    return a.exec();
}
