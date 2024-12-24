#ifndef CHEESE_H
#define CHEESE_H

#include <QDialog>
#include "connection.h"

namespace Ui {
class cheese;
}

class cheese : public QDialog
{
    Q_OBJECT

public:
    explicit cheese(Connection *connection, QWidget *parent = nullptr);
    ~cheese();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::cheese *ui;
    Connection *connection;
};

#endif // CHEESE_H
