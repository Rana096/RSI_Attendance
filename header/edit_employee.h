#ifndef EDIT_EMPLOYEE_H
#define EDIT_EMPLOYEE_H

#include <QDialog>

namespace Ui {
class Edit_Employee;
}

class Edit_Employee : public QDialog
{
    Q_OBJECT

public:
    explicit Edit_Employee(QWidget *parent = 0);
    ~Edit_Employee();

private slots:
    void on_update_pushButton_clicked();

private:
    Ui::Edit_Employee *ui;
};

#endif // EDIT_EMPLOYEE_H
