#include "mainwindow.h"
#include <QApplication>
//Текстовые надписи
#include <QLabel>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // Создаем первое окно
    MainWindow *mainWindow = new MainWindow();
    mainWindow->show();

    return app.exec();
}
