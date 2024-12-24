#include "numbercard.h"
#include "ui_numbercard.h"
#include "message.h"
#include "header.h"
numberCard::numberCard(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::numberCard)
{
    ui->setupUi(this);
    // Устанавливаем максимальный размер окна
    this->setMaximumSize(350, 300);

    // Устанавливаем минимальный размер окна (опционально)
    this->setMinimumSize(300, 250);
    // Устанавливаем цвет фона окна
    this->setStyleSheet("background-color: lightblue;");
    // Устанавливаем другой цвет
    ui->lineEdit->setStyleSheet("background-color: white; color: black;");
}

numberCard::~numberCard()
{
    delete ui;
}

void NewWindowTwo(){
    Message window;
    window.setModal(true);
    window.exec();
}

void numberCard::on_pushButton_clicked()
{
    QString text = ui->lineEdit->text();
    if(text.length()==16 && CheckNumber(text.toStdString())){
        close();
        NewWindowTwo();
    }else{
        QMessageBox::warning(this, "Карта","Некорректный номер");
    }
}

