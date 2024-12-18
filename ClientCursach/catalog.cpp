#include "catalog.h"
#include "ui_catalog.h"
catalog::catalog(Connection *connection, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::catalog)
    , connection(connection)
{
    ui->setupUi(this);
    // Устанавливаем максимальный размер окна
    this->setMaximumSize(1300, 800);

    // Устанавливаем минимальный размер окна (опционально)
    this->setMinimumSize(600, 800);

    QPixmap pix(":/resur/mg/овощи.png");
    int w= ui->vag->width();
    int h= ui->vag->height();
    ui->vag->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));

     QPixmap pix2(":/resur/mg/png.png");
    int wFrut= ui->frut->width();
    int hFrut= ui->frut->height();
    ui->frut->setPixmap(pix2.scaled(wFrut, hFrut, Qt::KeepAspectRatio));

    QPixmap pix3(":/resur/mg/сухо.png");
    int wSuho= ui->suho->width();
    int hSuho= ui->suho->height();
    ui->suho->setPixmap(pix3.scaled(wSuho, hSuho, Qt::KeepAspectRatio));

    QPixmap pix4(":/resur/mg/мясо.png");
    int wMeet= ui->meet->width();
    int hMeet= ui->meet->height();
    ui->meet->setPixmap(pix4.scaled(wMeet, hMeet, Qt::KeepAspectRatio));

    QPixmap pix5(":/resur/mg/молок.png");
    int wMilk= ui->milk->width();
    int hMilk= ui->milk->height();
    ui->milk->setPixmap(pix5.scaled(wMilk, hMilk, Qt::KeepAspectRatio));

    QPixmap pix6(":/resur/mg/сыр.png");
    int wCh= ui->ches->width();
    int hCh= ui->ches->height();
    ui->ches->setPixmap(pix6.scaled(wCh, hCh, Qt::KeepAspectRatio));

    QPixmap pix7(":/resur/mg/крупы.png");
    int wMu= ui->muck->width();
    int hMu= ui->muck->height();
    ui->muck->setPixmap(pix7.scaled(wMu, hMu, Qt::KeepAspectRatio));
    //
    QPixmap pix8(":/resur/mg/хлеб.png");
    int wBr= ui->bread->width();
    int hBr= ui->bread->height();
    ui->bread->setPixmap(pix8.scaled(wBr, hBr, Qt::KeepAspectRatio));

    QPixmap pix9(":/resur/mg/напит.png");
    int wDr= ui->drink->width();
    int hDr= ui->drink->height();
    ui->drink->setPixmap(pix9.scaled(wDr, hDr, Qt::KeepAspectRatio));

    QPixmap pix10(":/resur/mg/шок.png");
    int wSw= ui->sweet->width();
    int hSw= ui->sweet->height();
    ui->sweet->setPixmap(pix10.scaled(wSw, hSw, Qt::KeepAspectRatio));
}

catalog::~catalog()
{
    delete ui;
}

void catalog::on_pushButton_clicked()
{
    QString text = ui->lineEdit->text();
    if(text.length()<50&& text.length()>0&& checkingInjections(text.toStdString())){
    string meseg = connection->sendMessage(3, text);
    ui->textBrowser->setText(QString::fromStdString(meseg));
    }else{
        ui->textBrowser->setText(QString::fromStdString("Ничего не найдено"));
    }
}


void catalog::on_pushButton_2_clicked()
{
    close();
}

