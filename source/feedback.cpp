#include "feedback.h"
#include "ui_feedback.h"
#include "rsi_login.h"

Feedback::Feedback(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Feedback)
{
    ui->setupUi(this);
}

Feedback::~Feedback()
{
    delete ui;
}



void Feedback::on_save_PushButton_clicked()
{
    qDebug()<<"save button clicked";
    rsi_login conn;
    QSqlQueryModel *modal = new QSqlQueryModel();
    conn.connOpen();
    QSqlQuery *qry = new QSqlQuery(conn.myDb);
    qry->prepare("select * from details where user_ID = '"+guserID+"'");
    qry->exec();
    //ui->tableView->setModel(modal);
    modal->setQuery(*qry);

    //this->hide();
}

void Feedback::on_cancel_PushButton_clicked()
{
    qDebug()<<"cancel button clicked";
    this->hide();
}
