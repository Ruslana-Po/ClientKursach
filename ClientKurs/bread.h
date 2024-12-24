#ifndef BREAD_H
#define BREAD_H

#include <QDialog>
#include "connection.h"
namespace Ui {
class bread;
}

class bread : public QDialog
{
    Q_OBJECT

public:
    explicit bread(Connection *connection, QWidget *parent = nullptr);
    ~bread();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::bread *ui;
    Connection *connection;
};

#endif // BREAD_H
