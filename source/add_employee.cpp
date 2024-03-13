#include "add_employee.h"
#include "ui_add_employee.h"
#include "rsi_login.h"

#include <QMessageBox>

Add_Employee::Add_Employee(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Add_Employee)
{
    ui->setupUi(this);
    //ui->add_pushButton->setEnabled(false);
}

Add_Employee::~Add_Employee()
{
    delete ui;
}

void Add_Employee::on_add_pushButton_clicked()
{
    QString first, last, profile, user_ID, pswrd;
    int age,empid;
    first = ui->first_name_lineEdit->text();
    last = ui->last_name_lineEdit->text();
    profile = ui->profile_lineEdit->text();
    user_ID = ui->user_ID_lineEdit->text();
    pswrd = ui->password_lineEdit->text();
    age = ui->age_lineEdit->text().toInt();
    empid = ui->emp_ID_lineEdit->text().toInt();

    int savingPassword = hashing(pswrd);
    QSqlQuery qry;
    qry.prepare("Insert into details(first_name,last_name,age,profile,user_ID,password,emp_ID)"
                "values (:first, :last, :age, :profile, :user_id, :pswrd, :emp_id)");
    qry.bindValue(":first",first);
    qry.bindValue(":last",last);
    qry.bindValue(":age",age);
    qry.bindValue(":profile",profile);
    qry.bindValue(":user_id",user_ID);
    qry.bindValue(":pswrd",savingPassword);
    qry.bindValue(":emp_id",empid);
    if(qry.exec())
    {
        QMessageBox::information(this,"Succesful","succesfully new employee added!!");
        this->hide();
    }
    else
    {
        QMessageBox::warning(this,"Fail","failed to add new employee!!");
        this->hide();
    }



}

int Add_Employee::hashing(QString str)
{
    const int p =31, m =1e9+7;
    int genratedHashCode = 0;
    long int p_pow = 1;
    for(int i=0;i<str.size();i++)
    {
        genratedHashCode= (genratedHashCode + (str[i].toLatin1() * p_pow))%m;
        p_pow=(p_pow*p)%m;
    }
    qDebug()<<"genrated hashcode is  : " <<genratedHashCode;
    return genratedHashCode;
}
