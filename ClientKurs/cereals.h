#ifndef CEREALS_H
#define CEREALS_H

#include <QDialog>
#include "connection.h"
namespace Ui {
class cereals;
}

class cereals : public QDialog
{
    Q_OBJECT

public:
    explicit cereals(Connection *connection, QWidget *parent = nullptr);
    ~cereals();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_10_clicked();

private:
    Ui::cereals *ui;
    Connection *connection;
};

#endif // CEREALS_H
