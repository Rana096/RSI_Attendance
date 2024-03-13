#include "attendance.h"
#include "ui_attendance.h"
#include "rsi_login.h"

Attendance::Attendance(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Attendance)
{
    ui->setupUi(this);
    ui->logout_PushButton->setEnabled(false);
}

Attendance::~Attendance()
{
    delete ui;
}

void Attendance::on_login_PushButton_clicked()
{
    qDebug()<<"login clicked";

    rsi_login conn;
    conn.connOpen();
    QSqlQuery *qry = new QSqlQuery(conn.myDb);
    qry->prepare("update attendance set log_in = now() where user_ID = '"
                 +guserID+"'");
    qry->exec();

    qry->prepare("select log_in from attendance where user_ID = '"
                 +guserID+"'");
    qry->exec();
    while(qry->next())
    {
    QString logintime = qry->value(0).toString();
    ui->login_lineEdit->setText(logintime);
    }
    ui->login_PushButton->setEnabled(false);
    ui->logout_PushButton->setEnabled(true);
}

void Attendance::on_logout_PushButton_clicked()
{
    qDebug()<<"logout clicked";

    rsi_login conn;
    conn.connOpen();
    QSqlQuery *qry = new QSqlQuery(conn.myDb);
    qry->prepare("update attendance set log_out = now() where user_ID = '"
                 +guserID+"'");
    qry->exec();

    qry->prepare("select log_out from attendance where user_ID = '"
                 +guserID+"'");
    qry->exec();
    while(qry->next())
    {
    QString logouttime = qry->value(0).toString();
    ui->logout_lineEdit->setText(logouttime);
    }
    ui->login_PushButton->setEnabled(true);
    ui->logout_PushButton->setEnabled(false);
}
