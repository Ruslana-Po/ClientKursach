#ifndef NUMBERCARD_H
#define NUMBERCARD_H

#include <QDialog>

namespace Ui {
class numberCard;
}

class numberCard : public QDialog
{
    Q_OBJECT

public:
    explicit numberCard(QWidget *parent = nullptr);
    ~numberCard();

private slots:
    void on_pushButton_clicked();

private:
    Ui::numberCard *ui;
};

#endif // NUMBERCARD_H
