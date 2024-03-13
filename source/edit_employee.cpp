#include "edit_employee.h"
#include "ui_edit_employee.h"
#include "rsi_login.h"

#include <QMessageBox>

Edit_Employee::Edit_Employee(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Edit_Employee)
{
    ui->setupUi(this);
}

Edit_Employee::~Edit_Employee()
{
    delete ui;
}

void Edit_Employee::on_update_pushButton_clicked()
{
    rsi_login rsi;
    qDebug()<<"update clicked";
    QString user_id =ui->user_ID_lineEdit->text();
    QString pswrd =ui->new_password_lineEdit->text();

    int retpswrd = rsi.hashing(pswrd);

    QSqlQuery qry;
    qry.prepare("update details set password = :retpswd where user_ID = '"+user_id+"'");
    qry.bindValue(":retpswd",retpswrd);
    if(qry.exec())
    {
        if(qry.numRowsAffected() > 0)
        {
            QMessageBox::information(this,"Succesful","Password updated!!");
            this->hide();
        }
        else
        {
            QMessageBox::warning(this,"Fail","user_ID not present in database");
        }
    }
}
