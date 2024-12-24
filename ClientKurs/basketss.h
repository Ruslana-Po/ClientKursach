#ifndef BASKETSS_H
#define BASKETSS_H

#include <QDialog>

namespace Ui {
class Basketss;
}

class Basketss : public QDialog
{
    Q_OBJECT

public:
    explicit Basketss(QWidget *parent = nullptr);
    ~Basketss();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Basketss *ui;
};

#endif // BASKETSS_H
