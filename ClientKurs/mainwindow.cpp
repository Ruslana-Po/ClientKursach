#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "product.h"
#include <QProcess>
#include <QApplication>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::Cassa) // Инициализация ui
{
    ui->setupUi(this);
    // Устанавливаем максимальный размер окна
    this->setMaximumSize(600, 440);

    // Устанавливаем минимальный размер окна (опционально)
    this->setMinimumSize(600, 400);
    // Устанавливаем цвет фона окна
    this->setStyleSheet("background-color: lightblue;");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    Product window;
    window.setModal(true);
    window.exec();
}

