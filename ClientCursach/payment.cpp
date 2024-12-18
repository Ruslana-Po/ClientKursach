#include "payment.h"
#include "ui_payment.h"
#include "numbercard.h"
#include "header.h"
#include "qrcode.h"

payment::payment(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::payment)
{
    ui->setupUi(this);
    // Устанавливаем максимальный размер окна
    this->setMaximumSize(350, 300);

    // Устанавливаем минимальный размер окна (опционально)
    this->setMinimumSize(300, 250);
}

payment::~payment()
{
    delete ui;
}
string pay;

//Чтобы другое окно получило
string Pay(){
    return pay;
}

//Картой
void payment::on_pushButton_clicked()
{

    pay ="Оплата картой";
    close();
    numberCard window;
    window.setModal(true);
    window.exec();

}

//Спб
void payment::on_pushButton_3_clicked()
{
    pay = "Оплата через спб";
    close();
    QrCode window;
    window.setModal(true);
    window.exec();
}

