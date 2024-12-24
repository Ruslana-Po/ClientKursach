#include "kol.h"
#include "ui_kol.h"
#include "header.h"
kol::kol(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::kol)
{
    ui->setupUi(this);
    // Устанавливаем максимальный размер окна
    this->setMaximumSize(450, 350);

    // Устанавливаем минимальный размер окна (опционально)
    this->setMinimumSize(400, 300);
    // Устанавливаем цвет фона окна
    this->setStyleSheet("background-color: lightblue;");
    // Устанавливаем другой цвет
    ui->lineEdit->setStyleSheet("background-color: white; color: black;");
     ui->doubleSpinBox->setStyleSheet("background-color: white; color: black;");
     ui->spinBox->setStyleSheet("background-color: white; color: black;");
}

kol::~kol()
{
    delete ui;
}

void kol::on_pushButton_clicked()
{

    QString text = ui->lineEdit->text();
    if(text.length()>0){
    string number = text.toStdString();
    bool onlyNum=CheckNumber(number);
    if(onlyNum){
        //Сначало найдем значение
        string result =finds(number);
        if(result=="Весовое"){
            QString kol = ui->doubleSpinBox->text();
            string point=kol.toStdString();
            for(size_t i=0; i<point.length(); i++){
                if(point[i]==','){
                    point[i]='.';
                    break;
                }
            }
            double weight;
            stringstream str;
            str<<point;
            str>>weight;
            if(weight>= 0.01&&weight<=10.00){
                ReKol(number,weight);
                 close();
            }else if(weight>10.00){
                QMessageBox::warning(this, "Кол","Такого количества товара в магазине нету");
            }else{
                QMessageBox::warning(this, "Кол","Количество указано неверно");
            }

         }else if(result=="Упакованный"){
            QString kol = ui->spinBox->text();
             double weight = kol.toDouble();
             if(weight> 0.00&&weight<=10.00){
                 ReKol(number,weight);
                  close();
             }else if(weight>10.00){
                 QMessageBox::warning(this, "Кол","Такого количества товара в магазине нету");
             }else{
                  QMessageBox::warning(this, "Кол","Количество указано неверно");
             }
        }else{
             QMessageBox::warning(this, "Код","Товара с таким кодом в корзине нет");
         }
    }else{
          QMessageBox::warning(this, "Код","Товара с таким кодом в корзине нет");
    }
    }
}




