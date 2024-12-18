#ifndef CATALOG_H
#define CATALOG_H
#include <QDialog>
#include "connection.h"

namespace Ui {
class catalog;
}

class catalog : public QDialog
{
    Q_OBJECT

public:
    explicit catalog(Connection *connection, QWidget *parent = nullptr);
    ~catalog();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::catalog *ui;
    Connection *connection;
};

#endif // CATALOG_H
