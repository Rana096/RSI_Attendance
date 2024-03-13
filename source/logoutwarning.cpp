#include "logoutwarning.h"
#include "ui_logoutwarning.h"
#include "rsi_login.h"
#include "employee.h"

LogOutWarning::LogOutWarning(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LogOutWarning)
{
    ui->setupUi(this);
}

LogOutWarning::~LogOutWarning()
{
    delete ui;
}

void LogOutWarning::on_ok_Push_Button_clicked()
{
    qDebug()<<"logout action confirmed";
    QApplication::quit();
}

void LogOutWarning::on_cacel_Push_Button_clicked()
{
    qDebug()<<"logout action canceled";
    this->hide();
}
