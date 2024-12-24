#include "check.h"
#include "ui_check.h"
#include "header.h"
#include <fstream>
#include <QApplication>
#include "mainwindow.h"


Check::Check(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Check)
{
    ui->setupUi(this);
    // Устанавливаем максимальный размер окна
    this->setMaximumSize(400, 440);

    // Устанавливаем минимальный размер окна (опционально)
    this->setMinimumSize(400, 400);
    // Открываем файл для чтения
    string line;
    ifstream in("cheque.txt"); // окрываем файл для чтения
    if (!in.is_open()) {
        cerr << "Ошибка открытия файла: " << endl;
        return;
    }
    string content((istreambuf_iterator<char>(in)), istreambuf_iterator<char>());
    in.close();     // закрываем файл
    ui->textBrowser->setText(QString::fromStdString(content));
    // Устанавливаем цвет фона окна
    this->setStyleSheet("background-color: lightblue;");
     ui->textBrowser->setStyleSheet("background-color: white; color: black;");

}

Check::~Check()
{
    delete ui;
}




void Check::on_pushButton_clicked()
{
    // Создаем экземпляр MainWindow
    MainWindow *mainWindow = new MainWindow();
    mainWindow->show();

    // Закрываем текущее окно
    this->close();
}

