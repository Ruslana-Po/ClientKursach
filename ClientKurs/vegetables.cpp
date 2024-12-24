#include "vegetables.h"
#include "ui_vegetables.h"
#include "catalog.h"

vegetables::vegetables(Connection *connection, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::vegetables)
    , connection(connection)
{
    ui->setupUi(this);
    // Устанавливаем максимальный размер окна
    this->setMaximumSize(646, 499);

    // Устанавливаем минимальный размер окна (опционально)
    this->setMinimumSize(646, 499);
    // Устанавливаем цвет фона окна
    this->setStyleSheet("background-color: lightblue;");
}

vegetables::~vegetables()
{
    delete ui;
}

void vegetables::on_pushButton_11_clicked()
{
    this->close();
    catalog window(connection);
    window.setModal(true);
    window.exec();
}


void vegetables::on_pushButton_clicked()
{
    int number = 7;
    QString frut=ui->pushButton->text();
    string messeg = connection->sendMessage(number, frut);
    if(messeg != "Ничего не найдено\n"){
        parseAndAdd(messeg);
    }
    this->close();
}



void vegetables::on_pushButton_2_clicked()
{
    int number = 7;
    QString frut=ui->pushButton_2->text();
    string messeg = connection->sendMessage(number, frut);
    if(messeg != "Ничего не найдено\n"){
        parseAndAdd(messeg);
    }
    this->close();
}


void vegetables::on_pushButton_3_clicked()
{
    int number = 7;
    QString frut=ui->pushButton_3->text();
    string messeg = connection->sendMessage(number, frut);
    if(messeg != "Ничего не найдено\n"){
        parseAndAdd(messeg);
    }
    this->close();
}


void vegetables::on_pushButton_9_clicked()
{
    int number = 7;
    QString frut=ui->pushButton_9->text();
    string messeg = connection->sendMessage(number, frut);
    if(messeg != "Ничего не найдено\n"){
        parseAndAdd(messeg);
    }
    this->close();
}


void vegetables::on_pushButton_10_clicked()
{
    int number = 7;
    QString frut=ui->pushButton_10->text();
    string messeg = connection->sendMessage(number, frut);
    if(messeg != "Ничего не найдено\n"){
        parseAndAdd(messeg);
    }
    this->close();
}


void vegetables::on_pushButton_5_clicked()
{
    int number = 7;
    QString frut=ui->pushButton_5->text();
    string messeg = connection->sendMessage(number, frut);
    if(messeg != "Ничего не найдено\n"){
        parseAndAdd(messeg);
    }
    this->close();
}


void vegetables::on_pushButton_6_clicked()
{
    int number = 7;
    QString frut=ui->pushButton_6->text();
    string messeg = connection->sendMessage(number, frut);
    if(messeg != "Ничего не найдено\n"){
        parseAndAdd(messeg);
    }
    this->close();
}


void vegetables::on_pushButton_8_clicked()
{
    int number = 7;
    QString frut=ui->pushButton_8->text();
    string messeg = connection->sendMessage(number, frut);
    if(messeg != "Ничего не найдено\n"){
        parseAndAdd(messeg);
    }
    this->close();
}


void vegetables::on_pushButton_7_clicked()
{
    int number = 7;
    QString frut=ui->pushButton_7->text();
    string messeg = connection->sendMessage(number, frut);
    if(messeg != "Ничего не найдено\n"){
        parseAndAdd(messeg);
    }
    this->close();
}


void vegetables::on_pushButton_4_clicked()
{
    int number = 7;
    QString frut=ui->pushButton_4->text();
    string messeg = connection->sendMessage(number, frut);
    if(messeg != "Ничего не найдено\n"){
        parseAndAdd(messeg);
    }
    this->close();
}

