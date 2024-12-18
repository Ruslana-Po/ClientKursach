#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "product.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Cassa)
{
    ui->setupUi(this);
    // Устанавливаем максимальный размер окна
    this->setMaximumSize(600, 440);

    // Устанавливаем минимальный размер окна (опционально)
    this->setMinimumSize(600, 400);
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
    close();
}

