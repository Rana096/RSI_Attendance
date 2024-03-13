#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <QMainWindow>
#include "logoutwarning.h"
#include "feedback.h"
#include "attendance.h"
#include "update_password.h"
#include "add_employee.h"
#include "privelleges_checkbox.h"
#include "edit_employee.h"
#include "mysdl.h"
#include "childwindow.h"
#include <QMouseEvent>
#include <QtCore>
#include <QtGui>
#include <QTreeWidgetItem>

extern struct prof HR,GD,SSE,SE,AD;

namespace Ui {
class Employee;
}

class Employee : public QMainWindow
{
    Q_OBJECT

public:
    explicit Employee(QWidget *parent = 0);
    ~Employee();

private slots:
    void on_search_Push_Button_clicked();

    void on_ok_pushButton_clicked();

    void on_actionLog_Out_triggered();

    void on_actionUpdate_Password_triggered();

    void on_actionSelf_Detail_triggered();

    void on_actionHoliday_List_triggered();

    void on_actionFeedback_triggered();

    void on_actionLoad_triggered();

    void on_actionEdit_Employee_triggered();

    void on_actionDelete_Employee_triggered();

    void on_actionAdd_Employee_triggered();

    void on_actionMark_Attendance_triggered();

    void on_ser_employee_pushbutton_clicked();

    void on_treeWidget_itemClicked(QTreeWidgetItem *item, int column);

    void on_actionsdl_triggered();

    void on_add_pushButton_clicked();

    void on_update_pushButton_clicked();

    void on_delete_pushButton_clicked();

    void on_add_role_pushButton_clicked();

private:
    Ui::Employee *ui;
    LogOutWarning *lastLogOutWarning;
    Feedback *feedback;
    Attendance *attendace;
    Update_Password *updatePassword;
    Add_Employee *addEmployee;
    Privelleges_Checkbox *privellegeCheckbox;
    Edit_Employee *editEmp;
    MYSDL *mysdl;
    childwindow *chldwnd;

    QTreeWidgetItem *item = new QTreeWidgetItem();
    QTreeWidgetItem *item1 = new QTreeWidgetItem();

    void AddRoot0(QString name);
    void AddRoot1(QString name);
    void AddRoot2(QString name);
    void AddRoot3(QString name);
    void AddRoot4(QString name);
    void AddRoot5(QString name);
    void AddRoot6(QString name);
    void AddRoot7(QString name);

    void on_load_employee();

    enum Employee_combobox{
        Employee_empty,
        Employee_id,
        Employee_name,
        Employee_age,
        Employee_profile,
        Employee_user_id
    };

public:
    int hashing(QString);
    bool ischldwdw = false;
    void closeEvent(QCloseEvent *evt);
};

#endif // EMPLOYEE_H
