#ifndef DRINKS_H
#define DRINKS_H

#include <QDialog>
#include "connection.h"
namespace Ui {
class drinks;
}

class drinks : public QDialog
{
    Q_OBJECT

public:
    explicit drinks(Connection *connection, QWidget *parent = nullptr);
    ~drinks();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::drinks *ui;
    Connection *connection;
};

#endif // DRINKS_H
