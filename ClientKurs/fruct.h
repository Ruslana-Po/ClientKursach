#ifndef FRUCT_H
#define FRUCT_H

#include <QDialog>
#include "connection.h"

namespace Ui {
class fruct;
}

class fruct : public QDialog
{
    Q_OBJECT

public:
    explicit fruct(Connection *connection, QWidget *parent = nullptr);
    ~fruct();

private slots:
    void on_pushButton_14_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_9_clicked();

private:
    Ui::fruct *ui;
    Connection *connection;
};

#endif // FRUCT_H
