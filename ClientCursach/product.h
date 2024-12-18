#ifndef PRODUCT_H
#define PRODUCT_H

#include <QDialog>
#include "connection.h"



namespace Ui {
class Product;
}

class Product : public QDialog
{
    Q_OBJECT

public:
    explicit Product(QWidget *parent = nullptr);

    ~Product();


private slots:

    void on_pushButton_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_8_clicked();

private:
    Connection *Connect;
    Ui::Product *ui;
};

#endif // PRODUCT_H
