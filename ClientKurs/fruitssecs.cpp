#include "fruitssecs.h"
#include "ui_fruitssecs.h"
#include "catalog.h"


fruitsSecs::fruitsSecs(Connection *connection, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::fruitsSecs)
    , connection(connection)

{
    ui->setupUi(this);
    // Устанавливаем максимальный размер окна
    this->setMaximumSize(530, 393);

    // Устанавливаем минимальный размер окна (опционально)
    this->setMinimumSize(530, 393);
    // Устанавливаем цвет фона окна
    this->setStyleSheet("background-color: lightblue;");
}

fruitsSecs::~fruitsSecs()
{
    delete ui;
}

void fruitsSecs::on_pushButton_clicked()
{
    this->close();
    catalog window(connection);
    window.setModal(true);
    window.exec();
}


void fruitsSecs::on_pushButton_2_clicked()
{
    int number = 7;
    QString frut=ui->pushButton_2->text();
    string messeg = connection->sendMessage(number, frut);
    if(messeg != "Ничего не найдено\n"){
        parseAndAdd(messeg);
    }
    this->close();
}


void fruitsSecs::on_pushButton_3_clicked()
{
    int number = 7;
    QString frut=ui->pushButton_3->text();
    string messeg = connection->sendMessage(number, frut);
    if(messeg != "Ничего не найдено\n"){
        parseAndAdd(messeg);
    }
    this->close();
}


void fruitsSecs::on_pushButton_5_clicked()
{
    int number = 7;
    QString frut=ui->pushButton_5->text();
    string messeg = connection->sendMessage(number, frut);
    if(messeg != "Ничего не найдено\n"){
        parseAndAdd(messeg);
    }
    this->close();
}


void fruitsSecs::on_pushButton_6_clicked()
{
    int number = 7;
    QString frut=ui->pushButton_6->text();
    string messeg = connection->sendMessage(number, frut);
    if(messeg != "Ничего не найдено\n"){
        parseAndAdd(messeg);
    }
    this->close();
}


void fruitsSecs::on_pushButton_4_clicked()
{
    int number = 7;
    QString frut=ui->pushButton_4->text();
    string messeg = connection->sendMessage(number, frut);
    if(messeg != "Ничего не найдено\n"){
        parseAndAdd(messeg);
    }
    this->close();
}

