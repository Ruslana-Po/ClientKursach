#include "catalog.h"
#include "fruct.h"
#include "vegetables.h"
#include "fruitssecs.h"
#include "cheese.h"
#include "meat.h"
#include "milk.h"
#include "drinks.h"
#include "bread.h"
#include "sweets.h"
#include "cereals.h"
#include "ui_catalog.h"
catalog::catalog(Connection *connection, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::catalog)
    , connection(connection)
{
    ui->setupUi(this);
    // Устанавливаем максимальный размер окна
    this->setMaximumSize(1300, 800);

    // Устанавливаем минимальный размер окна (опционально)
    this->setMinimumSize(600, 800);
    // Устанавливаем цвет фона окна
    this->setStyleSheet("background-color: lightblue;");
    // Устанавливаем другой цвет
    ui->pushButton->setStyleSheet("background-color: white; color: black;");
    ui->pushButton_2->setStyleSheet("background-color: white; color: black;");
    ui->pushButton_3->setStyleSheet("background-color: white; color: black;");
    ui->pushButton_4->setStyleSheet("background-color: white; color: black;");
    ui->pushButton_5->setStyleSheet("background-color: white; color: black;");
    ui->pushButton_6->setStyleSheet("background-color: white; color: black;");
    ui->pushButton_7->setStyleSheet("background-color: white; color: black;");
    ui->pushButton_8->setStyleSheet("background-color: white; color: black;");
    ui->pushButton_9->setStyleSheet("background-color: white; color: black;");
    ui->pushButton_10->setStyleSheet("background-color: white; color: black;");

  }

catalog::~catalog()
{
    delete ui;
}




void catalog::on_pushButton_3_clicked()
{
    this->close();
    fruct window(connection);
    window.setModal(true);
    window.exec();
}


void catalog::on_pushButton_4_clicked()
{
    this->close();
    vegetables window(connection);
    window.setModal(true);
    window.exec();
}


void catalog::on_pushButton_5_clicked()
{
    this->close();
    fruitsSecs window(connection);
    window.setModal(true);
    window.exec();
}


void catalog::on_pushButton_clicked()
{
    this->close();
    cheese window(connection);
    window.setModal(true);
    window.exec();
}


void catalog::on_pushButton_2_clicked()
{
    this->close();
    meat window(connection);
    window.setModal(true);
    window.exec();
}


void catalog::on_pushButton_6_clicked()
{
    this->close();
    milk window(connection);
    window.setModal(true);
    window.exec();
}


void catalog::on_pushButton_7_clicked()
{
    this->close();
    cereals window(connection);
    window.setModal(true);
    window.exec();
}


void catalog::on_pushButton_8_clicked()
{
    this->close();
    sweets window(connection);
    window.setModal(true);
    window.exec();
}


void catalog::on_pushButton_9_clicked()
{
    this->close();
    bread window(connection);
    window.setModal(true);
    window.exec();
}


void catalog::on_pushButton_10_clicked()
{
    this->close();
    drinks window(connection);
    window.setModal(true);
    window.exec();
}

