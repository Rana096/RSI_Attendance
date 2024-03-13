#ifndef ATTENDANCE_H
#define ATTENDANCE_H

#include <QDialog>

namespace Ui {
class Attendance;
}

class Attendance : public QDialog
{
    Q_OBJECT

public:
    explicit Attendance(QWidget *parent = 0);
    ~Attendance();

private slots:
    void on_login_PushButton_clicked();

    void on_logout_PushButton_clicked();



private:
    Ui::Attendance *ui;
};

#endif // ATTENDANCE_H
