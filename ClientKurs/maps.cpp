#include "maps.h"
#include "ui_maps.h"
#include "payment.h"
#include "header.h"
#include <QDebug>
Maps::Maps(Connection *connections, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Maps)
    , connections(connections)
{
    ui->setupUi(this);
    // Устанавливаем максимальный размер окна
    this->setMaximumSize(650, 350);

    // Устанавливаем минимальный размер окна (опционально)
    this->setMinimumSize(600, 300);
    // Устанавливаем цвет фона окна
    this->setStyleSheet("background-color: lightblue;");
    // Устанавливаем другой цвет
    ui->lineEdit->setStyleSheet("background-color: white; color: black;");
}

Maps::~Maps()
{
    delete ui;
}

void NewWindow(){
    DeletOld();
    payment window;
    window.setModal(true);
    window.exec();
}
bool checkYesOrNo;

bool YesOrNo(){
    return checkYesOrNo;
}

//Добавляю
void Maps::on_pushButton_2_clicked()
{
    string mes;
    QString text = ui->lineEdit->text();
    if(text.length()==11){
        string number = text.toStdString();
        bool onlyNum=CheckNumber(number);
        if(onlyNum&&number[0]=='8'){
            int actions = 5;
            mes = connections->sendMessage(actions,text);
            if(mes=="Добавил"){
                //выведет чек
                QString toStr = TotalAmount(true);
                QMessageBox::StandardButton reply = QMessageBox::question(this,"Оплата", "C вас "+toStr +" \nВам нужен чек?", QMessageBox::Yes | QMessageBox::No);
                if(reply == QMessageBox::Yes){
                    makingFile("cheque.txt",true);
                    checkYesOrNo=true;
                    close();
                     NewWindow();
                }else{
                    checkYesOrNo=false;
                    close();
                     NewWindow();

                }
            }else if(mes=="Уже существует"){
                QMessageBox::warning(this, "Запись","Такой номер уже добавлен!");
            }
        }else{
            QMessageBox::warning(this, "Номер","Номер должен начинаться с 8 и не иметь лишних символов");
        }
    }else if(text.length()>11){
        QMessageBox::warning(this, "Номер","Слишком много символов. Должно быть 11 цифр");
    }else if(text.length()<11){
        QMessageBox::warning(this, "Номер","Слишком мало символов. Должно быть 11 цифр");
    }

}

//Воспользоваться
void Maps::on_pushButton_clicked()
{
    string mes;
    QString text = ui->lineEdit->text();
    if(text.length()==11){
        string number = text.toStdString();
        bool onlyNum=CheckNumber(number);
        if(onlyNum&&number[0]=='8'){
            int actions = 6;
            mes = connections->sendMessage(actions,text);
            if(mes=="Уже существует"){
                //вывести сколько с человека
                QString toStr = TotalAmount(true);
                QMessageBox::StandardButton reply = QMessageBox::question(this,"Оплата", "C вас "+toStr +" \nВам нужен чек?", QMessageBox::Yes | QMessageBox::No);
                if(reply == QMessageBox::Yes){
                    makingFile("cheque.txt",true);
                    checkYesOrNo=true;
                    close();
                    NewWindow();
                }else{
                    checkYesOrNo=false;
                    close();
                    NewWindow();
                }
            }else if(mes=="Такого номера нету"){
                QMessageBox::warning(this, "Поиск","Такого номера нету");
            }
        }else{
            QMessageBox::warning(this, "Номер","Номер должен начинаться с 8 и не иметь лишних символов");
        }
    }else if(text.length()>11){
        QMessageBox::warning(this, "Номер","Слишком много символов. Должно быть 11 цифр");
    }else if(text.length()<11){
        QMessageBox::warning(this, "Номер","Слишком мало символов. Должно быть 11 цифр");
    }
}

//Вывести чек
void Maps::on_pushButton_3_clicked()
{
    //вывести сколько с человека
    QString toStr = TotalAmount(false);
    QMessageBox::StandardButton reply = QMessageBox::question(this,"Оплата", "C вас "+toStr +" \nВам нужен чек?", QMessageBox::Yes | QMessageBox::No);
    if(reply == QMessageBox::Yes){
        makingFile("cheque.txt",false);
        checkYesOrNo=true;
        close();
        NewWindow();

    }else{
        checkYesOrNo=false;
        close();
        NewWindow();

    }
}

