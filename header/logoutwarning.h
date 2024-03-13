#ifndef LOGOUTWARNING_H
#define LOGOUTWARNING_H

#include <QDialog>

namespace Ui {
class LogOutWarning;
}

class LogOutWarning : public QDialog
{
    Q_OBJECT

public:
    explicit LogOutWarning(QWidget *parent = 0);
    ~LogOutWarning();

private slots:
    void on_ok_Push_Button_clicked();

    void on_cacel_Push_Button_clicked();

private:
    Ui::LogOutWarning *ui;
};

#endif // LOGOUTWARNING_H
