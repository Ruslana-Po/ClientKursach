#ifndef SWEETS_H
#define SWEETS_H

#include <QDialog>
#include "connection.h"
namespace Ui {
class sweets;
}

class sweets : public QDialog
{
    Q_OBJECT

public:
    explicit sweets(Connection *connection, QWidget *parent = nullptr);
    ~sweets();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::sweets *ui;
    Connection *connection;
};

#endif // SWEETS_H
