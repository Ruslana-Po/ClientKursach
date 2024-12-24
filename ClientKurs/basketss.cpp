#include "basketss.h"
#include "ui_basketss.h"
#include "header.h"
Basketss::Basketss(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Basketss)
{
    ui->setupUi(this);
    // Устанавливаем максимальный размер окна
    this->setMaximumSize(350, 250);

    // Устанавливаем минимальный размер окна (опционально)
    this->setMinimumSize(300, 200);
    // Устанавливаем цвет фона окна
    this->setStyleSheet("background-color: lightblue;");
    // Устанавливаем другой цвет
    ui->lineEdit->setStyleSheet("background-color: white; color: black;");
}

Basketss::~Basketss()
{
    delete ui;
}

void Basketss::on_pushButton_clicked()
{

    QString text = ui->lineEdit->text();
     if(text.length()>0){
    string number = text.toStdString();
    bool onlyNum= CheckNumber(number);
    bool check;
    if(onlyNum){
        check=DelBas(number);
        if(check){
             close();
        }else{
            QMessageBox::warning(this, "Код","Товара с таким кодом в корзине нет");
        }

    }else{
        QMessageBox::warning(this, "Код","Товара с таким кодом в корзине нет");
    }
     }

}


