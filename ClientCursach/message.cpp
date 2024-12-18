#include "message.h"
#include "ui_message.h"
#include "header.h"
#include "check.h"

Message::Message(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Message)
{
    ui->setupUi(this);
    // Устанавливаем максимальный размер окна
    this->setMaximumSize(350, 350);

    // Устанавливаем минимальный размер окна (опционально)
    this->setMinimumSize(300, 250);
    string pay=Pay();
    if(pay=="Оплата картой"|| pay=="Оплата через спб"){
        string meseg = pay+" прошла успешно";
        ui->textBrowser->setText(QString::fromStdString(meseg));
    }else{
        ui->textBrowser->setText(QString::fromStdString("Оплата не прошла"));
    }
}

Message::~Message()
{
    delete ui;
}

void Message::on_pushButton_clicked()
{
    bool check = YesOrNo();
    close();
    // Открываем текстовый файл с помощью системной команды
    if(check){
        Check window;
        window.setModal(true);
        window.exec();
    }

}

