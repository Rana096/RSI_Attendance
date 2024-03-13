#include "update_password.h"
#include "ui_update_password.h"
#include "rsi_login.h"
#include <QMessageBox>

Update_Password::Update_Password(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Update_Password)
{
    ui->setupUi(this);
    ui->user_id_lineEdit->setText(guserID);
    ui->user_id_lineEdit->setReadOnly(true);
}

Update_Password::~Update_Password()
{
    delete ui;
}

void Update_Password::on_update_pushButton_clicked()
{
    qDebug()<<"update clicked";
    rsi_login rsi;
    QString oldPassword =ui->old_password_lineEdit->text();
    QString newPassword =ui->new_password_lineEdit->text();
    rsi.read_from_xml_file();
    if(oldPassword!=password)
    {
        QMessageBox::warning(this,"Wrong Password","Old Password is wrong");
    }
    else
    {
        password = newPassword;
        int retpswd = rsi.hashing(newPassword);
        QSqlQuery qry;
        qry.prepare("update details set password = :retpswd where user_ID = '"+guserID+"'");
        qry.bindValue(":retpswd",retpswd);
        qry.exec();
        QMessageBox::information(this,"Password updation","New Password Update");
        this->hide();
    }

}
