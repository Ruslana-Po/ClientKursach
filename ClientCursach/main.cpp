#include "mainwindow.h"
#include <QApplication>
//Текстовые надписи
#include <QLabel>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
