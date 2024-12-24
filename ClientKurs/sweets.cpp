#include "sweets.h"
#include "ui_sweets.h"
#include "catalog.h"
sweets::sweets(Connection *connection, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::sweets)
    , connection(connection)
{
    ui->setupUi(this);
    // Устанавливаем максимальный размер окна
    this->setMaximumSize(539, 431);

    // Устанавливаем минимальный размер окна (опционально)
    this->setMinimumSize(539, 431);
    // Устанавливаем цвет фона окна
    this->setStyleSheet("background-color: lightblue;");
}

sweets::~sweets()
{
    delete ui;
}

void sweets::on_pushButton_clicked()
{
    this->close();
    catalog window(connection);
    window.setModal(true);
    window.exec();
}


void sweets::on_pushButton_2_clicked()
{
    int number = 7;
    QString frut=ui->pushButton_2->text();
    string messeg = connection->sendMessage(number, frut);
    if(messeg != "Ничего не найдено\n"){
        parseAndAdd(messeg);
    }
    this->close();
}


void sweets::on_pushButton_6_clicked()
{
    int number = 7;
    QString frut=ui->pushButton_6->text();
    string messeg = connection->sendMessage(number, frut);
    if(messeg != "Ничего не найдено\n"){
        parseAndAdd(messeg);
    }
    this->close();
}


void sweets::on_pushButton_7_clicked()
{
    int number = 7;
    QString frut=ui->pushButton_7->text();
    string messeg = connection->sendMessage(number, frut);
    if(messeg != "Ничего не найдено\n"){
        parseAndAdd(messeg);
    }
    this->close();
}


void sweets::on_pushButton_8_clicked()
{
    int number = 7;
    QString frut=ui->pushButton_8->text();
    string messeg = connection->sendMessage(number, frut);
    if(messeg != "Ничего не найдено\n"){
        parseAndAdd(messeg);
    }
    this->close();
}


void sweets::on_pushButton_5_clicked()
{
    int number = 7;
    QString frut=ui->pushButton_5->text();
    string messeg = connection->sendMessage(number, frut);
    if(messeg != "Ничего не найдено\n"){
        parseAndAdd(messeg);
    }
    this->close();
}


void sweets::on_pushButton_3_clicked()
{
    int number = 7;
    QString frut=ui->pushButton_3->text();
    string messeg = connection->sendMessage(number, frut);
    if(messeg != "Ничего не найдено\n"){
        parseAndAdd(messeg);
    }
    this->close();
}


void sweets::on_pushButton_4_clicked()
{
    int number = 7;
    QString frut=ui->pushButton_4->text();
    string messeg = connection->sendMessage(number, frut);
    if(messeg != "Ничего не найдено\n"){
        parseAndAdd(messeg);
    }
    this->close();
}

