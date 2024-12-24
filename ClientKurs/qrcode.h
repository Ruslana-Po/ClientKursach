#ifndef QRCODE_H
#define QRCODE_H

#include <QDialog>

namespace Ui {
class QrCode;
}

class QrCode : public QDialog
{
    Q_OBJECT

public:
    explicit QrCode(QWidget *parent = nullptr);
    ~QrCode();

private:
    Ui::QrCode *ui;
};

#endif // QRCODE_H
