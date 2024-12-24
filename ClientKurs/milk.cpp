#include "milk.h"
#include "ui_milk.h"
#include "catalog.h"

milk::milk(Connection *connection, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::milk)
    , connection(connection)
{
    ui->setupUi(this);
    // Устанавливаем максимальный размер окна
    this->setMaximumSize(726, 488);

    // Устанавливаем минимальный размер окна (опционально)
    this->setMinimumSize(726, 488);
    // Устанавливаем цвет фона окна
    this->setStyleSheet("background-color: lightblue;");
}

milk::~milk()
{
    delete ui;
}

void milk::on_pushButton_clicked()
{
    this->close();
    catalog window(connection);
    window.setModal(true);
    window.exec();
}


void milk::on_pushButton_3_clicked()
{
    int number = 7;
    QString frut=ui->pushButton_3->text();
    string messeg = connection->sendMessage(number, frut);
    if(messeg != "Ничего не найдено\n"){
        parseAndAdd(messeg);
    }
    this->close();
}


void milk::on_pushButton_9_clicked()
{
    int number = 7;
    QString frut=ui->pushButton_9->text();
    string messeg = connection->sendMessage(number, frut);
    if(messeg != "Ничего не найдено\n"){
        parseAndAdd(messeg);
    }
    this->close();
}


void milk::on_pushButton_10_clicked()
{
    int number = 7;
    QString frut=ui->pushButton_10->text();
    string messeg = connection->sendMessage(number, frut);
    if(messeg != "Ничего не найдено\n"){
        parseAndAdd(messeg);
    }
    this->close();
}


void milk::on_pushButton_5_clicked()
{
    int number = 7;
    QString frut=ui->pushButton_5->text();
    string messeg = connection->sendMessage(number, frut);
    if(messeg != "Ничего не найдено\n"){
        parseAndAdd(messeg);
    }
    this->close();
}


void milk::on_pushButton_8_clicked()
{
    int number = 7;
    QString frut=ui->pushButton_8->text();
    string messeg = connection->sendMessage(number, frut);
    if(messeg != "Ничего не найдено\n"){
        parseAndAdd(messeg);
    }
    this->close();
}


void milk::on_pushButton_2_clicked()
{
    int number = 7;
    QString frut=ui->pushButton_2->text();
    string messeg = connection->sendMessage(number, frut);
    if(messeg != "Ничего не найдено\n"){
        parseAndAdd(messeg);
    }
    this->close();
}


void milk::on_pushButton_6_clicked()
{
    int number = 7;
    QString frut=ui->pushButton_6->text();
    string messeg = connection->sendMessage(number, frut);
    if(messeg != "Ничего не найдено\n"){
        parseAndAdd(messeg);
    }
    this->close();
}


void milk::on_pushButton_7_clicked()
{
    int number = 7;
    QString frut=ui->pushButton_7->text();
    string messeg = connection->sendMessage(number, frut);
    if(messeg != "Ничего не найдено\n"){
        parseAndAdd(messeg);
    }
    this->close();
}


void milk::on_pushButton_11_clicked()
{
    int number = 7;
    QString frut=ui->pushButton_11->text();
    string messeg = connection->sendMessage(number, frut);
    if(messeg != "Ничего не найдено\n"){
        parseAndAdd(messeg);
    }
    this->close();
}


void milk::on_pushButton_12_clicked()
{
    int number = 7;
    QString frut=ui->pushButton_12->text();
    string messeg = connection->sendMessage(number, frut);
    if(messeg != "Ничего не найдено\n"){
        parseAndAdd(messeg);
    }
    this->close();
}


void milk::on_pushButton_13_clicked()
{
    int number = 7;
    QString frut=ui->pushButton_13->text();
    string messeg = connection->sendMessage(number, frut);
    if(messeg != "Ничего не найдено\n"){
        parseAndAdd(messeg);
    }
    this->close();
}


void milk::on_pushButton_4_clicked()
{
    int number = 7;
    QString frut=ui->pushButton_4->text();
    string messeg = connection->sendMessage(number, frut);
    if(messeg != "Ничего не найдено\n"){
        parseAndAdd(messeg);
    }
    this->close();
}


void milk::on_pushButton_14_clicked()
{
    int number = 7;
    QString frut=ui->pushButton_14->text();
    string messeg = connection->sendMessage(number, frut);
    if(messeg != "Ничего не найдено\n"){
        parseAndAdd(messeg);
    }
    this->close();
}


void milk::on_pushButton_15_clicked()
{
    int number = 7;
    QString frut=ui->pushButton_15->text();
    string messeg = connection->sendMessage(number, frut);
    if(messeg != "Ничего не найдено\n"){
        parseAndAdd(messeg);
    }
    this->close();
}

