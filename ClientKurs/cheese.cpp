#include "cheese.h"
#include "ui_cheese.h"
#include "catalog.h"

cheese::cheese(Connection *connection, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::cheese)
    , connection(connection)
{
    ui->setupUi(this);
    // Устанавливаем максимальный размер окна
    this->setMaximumSize(493, 409);

    // Устанавливаем минимальный размер окна (опционально)
    this->setMinimumSize(493, 409);
    // Устанавливаем цвет фона окна
    this->setStyleSheet("background-color: lightblue;");
}

cheese::~cheese()
{
    delete ui;
}

void cheese::on_pushButton_clicked()
{
    this->close();
    catalog window(connection);
    window.setModal(true);
    window.exec();
}


void cheese::on_pushButton_2_clicked()
{
    int number = 7;
    QString frut=ui->pushButton_2->text();
    string messeg = connection->sendMessage(number, frut);
    if(messeg != "Ничего не найдено\n"){
        parseAndAdd(messeg);
    }
    this->close();
}


void cheese::on_pushButton_3_clicked()
{
    int number = 7;
    QString frut=ui->pushButton_3->text();
    string messeg = connection->sendMessage(number, frut);
    if(messeg != "Ничего не найдено\n"){
        parseAndAdd(messeg);
    }
    this->close();
}


void cheese::on_pushButton_6_clicked()
{
    int number = 7;
    QString frut=ui->pushButton_6->text();
    string messeg = connection->sendMessage(number, frut);
    if(messeg != "Ничего не найдено\n"){
        parseAndAdd(messeg);
    }
    this->close();
}


void cheese::on_pushButton_4_clicked()
{
    int number = 7;
    QString frut=ui->pushButton_4->text();
    string messeg = connection->sendMessage(number, frut);
    if(messeg != "Ничего не найдено\n"){
        parseAndAdd(messeg);
    }
    this->close();
}


void cheese::on_pushButton_5_clicked()
{
    int number = 7;
    QString frut=ui->pushButton_5->text();
    string messeg = connection->sendMessage(number, frut);
    if(messeg != "Ничего не найдено\n"){
        parseAndAdd(messeg);
    }
    this->close();
}

