#ifndef MAPS_H
#define MAPS_H

#include <QDialog>
#include "connection.h"
namespace Ui {
class Maps;
}

class Maps : public QDialog
{
    Q_OBJECT

public:
    explicit Maps(Connection *connections,QWidget *parent = nullptr);
    ~Maps();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::Maps *ui;
    Connection *connections;
};

#endif // MAPS_H
