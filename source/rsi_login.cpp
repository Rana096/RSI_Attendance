#include "rsi_login.h"
#include "ui_rsi_login.h"
#include <QMessageBox>
#include <QDebug>
#include <QtXml/QDomDocument>
#include <QtCore>
#include <QXmlStreamReader>
#include <semaphore.h>

#define ONLY_ONE_INSTANCE "1_Single_instance_1"
extern const QString str;

QString guserID;
bool isguserAdmin;
QString username,password;
QString profile;
QSettings rememberLast;
extern sem_t *semmem;

rsi_login::rsi_login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::rsi_login)
{
    ui->setupUi(this);

    ischecked = rememberLast.value("lastUsedCredentials").toBool();
    ui->rememberMe_CheckBox->setChecked(ischecked);
    if(ischecked)
    {
        read_from_xml_file();
    }

    issqlconnect = connOpen();
    qDebug()<<"Connection to database !!!"<< issqlconnect;
    if(issqlconnect)
        ui->sql_db_connection_label->setText("Connected to database!!!");
    else
        ui->sql_db_connection_label->setText("Failed to connect database!!!");

}

rsi_login::~rsi_login()
{
    delete ui;
}

void rsi_login::on_logIn_PushButton_clicked()
{
    username = ui->userID_Line_Edit->text();
    password = ui->password_LineEdit->text();

   QString retPassword = QString :: number( hashing(password));
    qDebug()<<"return hash code value is : "<<retPassword;

    if(!myDb.isOpen())
    { 
        qDebug()<<"No connection to database";
        return;
    }
    QSqlQuery qry;
    int flag = 0;

    qry.prepare("select user_ID, password, profile from details where user_ID = '"
                +username+ "' and password = '"+retPassword+"'");
    if(qry.exec())
    {
        while(qry.next())
        {
            flag = 1;
            guserID = username;
            if(qry.value(2).toString()=="Admin"||
                    qry.value(2).toString()=="admin")
            {
                isguserAdmin = true;
            }
            qDebug()<<"in login page guserid : "<<guserID;
            break;
        }

        if(flag == 1)
        {
            qDebug()<<"Login succesfull!!";

            if(ischecked)
            {
                write_on_xml_file();
            }

            this -> hide();
            employee = new Employee (this);
            employee->setWindowTitle(username);
            employee->show();
        }
        else
        {
            ui->sql_db_connection_label->setText("Wrong Id and password!!!");
        }

    }
}

void rsi_login::on_rememberMe_CheckBox_clicked(bool checked)
{
    ischecked = checked;
    rememberLast.setValue("lastUsedCredentials",ischecked);
}

void rsi_login::write_on_xml_file()
{
    //Write xml
    QDomDocument document;
    //Make root element
    QDomElement root = document.createElement("User_LogIn");
    //Add it to the document
    document.appendChild(root);
    //Add it to the document
    QDomElement loginCredential = document.createElement("Lastloginattempt");
    //username = ui->userID_Line_Edit->text();
    //password = ui->password_LineEdit->text();
    loginCredential.setAttribute("UserID",username);
    loginCredential.setAttribute("Password",password);
    root.appendChild(loginCredential);
    //Write to File
    QFile file("/home/kodiak/Desktop/Vikas/documents/logincredential.xml");
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        qDebug()<<"Failed to open file to write login credentials";
        return;
    }
    else
    {
        QTextStream stream(&file);
        stream<<document.toString();
        file.close();
    }
}

void rsi_login::read_from_xml_file()
{
    QDomDocument document;
    QFile file("/home/kodiak/Desktop/Vikas/documents/logincredential.xml");
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug()<<"Failed to open file";
        return;
    }
    else
    {
        if(!document.setContent(&file))
        {
            qDebug()<<"Failed to load document";
        }
        file.close();
    }
    QDomElement rootElement = document.firstChildElement();
    QDomElement user = rootElement.firstChildElement();
    username = user.attribute("UserID");
    password = user.attribute("Password");
    ui->userID_Line_Edit->setText(username);
    ui->password_LineEdit->setText(password);
}

int rsi_login::hashing(QString str)
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

void rsi_login::closeEvent(QCloseEvent *evt)
{
    qDebug()<<"vikas, rsi_login file  : ";
//    sem_post(semmem);
    evt->accept();
}
