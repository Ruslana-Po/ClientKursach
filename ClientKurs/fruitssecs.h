#ifndef FRUITSSECS_H
#define FRUITSSECS_H

#include <QDialog>
#include "connection.h"

namespace Ui {
class fruitsSecs;
}

class fruitsSecs : public QDialog
{
    Q_OBJECT

public:
    explicit fruitsSecs(Connection *connection, QWidget *parent = nullptr);
    ~fruitsSecs();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::fruitsSecs *ui;
    Connection *connection;
};

#endif // FRUITSSECS_H
