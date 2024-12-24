#ifndef VEGETABLES_H
#define VEGETABLES_H

#include <QDialog>
#include "connection.h"

namespace Ui {
class vegetables;
}

class vegetables : public QDialog
{
    Q_OBJECT

public:
    explicit vegetables(Connection *connection, QWidget *parent = nullptr);
    ~vegetables();

private slots:
    void on_pushButton_11_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::vegetables *ui;
    Connection *connection;
};

#endif // VEGETABLES_H
