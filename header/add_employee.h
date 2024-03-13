#ifndef ADD_EMPLOYEE_H
#define ADD_EMPLOYEE_H

#include <QDialog>

namespace Ui {
class Add_Employee;
}

class Add_Employee : public QDialog
{
    Q_OBJECT

public:
    explicit Add_Employee(QWidget *parent = 0);
    ~Add_Employee();

private slots:
    void on_add_pushButton_clicked();

private:
    Ui::Add_Employee *ui;

public:
    int hashing(QString);

};

#endif // ADD_EMPLOYEE_H
