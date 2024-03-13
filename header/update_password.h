#ifndef UPDATE_PASSWORD_H
#define UPDATE_PASSWORD_H

#include <QDialog>

namespace Ui {
class Update_Password;
}

class Update_Password : public QDialog
{
    Q_OBJECT

public:
    explicit Update_Password(QWidget *parent = 0);
    ~Update_Password();

private slots:
    void on_update_pushButton_clicked();

private:
    Ui::Update_Password *ui;
};

#endif // UPDATE_PASSWORD_H
