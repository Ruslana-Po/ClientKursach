#ifndef KOL_H
#define KOL_H

#include <QDialog>

namespace Ui {
class kol;
}

class kol : public QDialog
{
    Q_OBJECT

public:
    explicit kol(QWidget *parent = nullptr);
    ~kol();

private slots:
    void on_pushButton_clicked();

private:
    Ui::kol *ui;
};

#endif // KOL_H
