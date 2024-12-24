#ifndef MEAT_H
#define MEAT_H

#include <QDialog>
#include "connection.h"
namespace Ui {
class meat;
}

class meat : public QDialog
{
    Q_OBJECT

public:
    explicit meat(Connection *connection, QWidget *parent = nullptr);
    ~meat();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_9_clicked();

private:
    Ui::meat *ui;
    Connection *connection;
};

#endif // MEAT_H
