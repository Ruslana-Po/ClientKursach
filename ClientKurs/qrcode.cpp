#include "qrcode.h"
#include "ui_qrcode.h"
#include <QTimer>
#include "message.h"

QrCode::QrCode(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::QrCode)
{
    ui->setupUi(this);
    QPixmap pix(":/resur/mg/QR.png");
    int w= ui->QR->width();
    int h= ui->QR->height();
    ui->QR->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));
    // Устанавливаем максимальный размер окна
    this->setMaximumSize(500, 500);

    // Устанавливаем минимальный размер окна (опционально)
    this->setMinimumSize(500, 500);
    // Таймер на 10 секунд для автоматического закрытия
    QTimer::singleShot(10000, [=]() {
        close();
        Message window;
        window.setModal(true);
        window.exec();
    });
    // Устанавливаем цвет фона окна
    this->setStyleSheet("background-color: lightblue;");
}

QrCode::~QrCode()
{
    delete ui;
}
