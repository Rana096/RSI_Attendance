#ifndef RSI_LOGIN_H
#define RSI_LOGIN_H

#include <QDialog>
#include <QtSql>
#include <QFileInfo>
#include "employee.h"
#include <QMutex>

extern QString guserID;
extern bool isguserAdmin;
extern QString username,password;
extern QString profile;
extern QSettings rememberLast;
extern QSharedMemory shrdmem;

namespace Ui {
class rsi_login;
}

class rsi_login : public QDialog
{
    Q_OBJECT

public:
    explicit rsi_login(QWidget *parent = 0);
    ~rsi_login();


    void write_on_xml_file();
    void read_from_xml_file();

private slots:
    void on_logIn_PushButton_clicked();

    void on_rememberMe_CheckBox_clicked(bool checked);

private:
    Ui::rsi_login *ui;
    Employee *employee;    

public:
    bool ischecked = false;
    bool issqlconnect = false;
    QSqlDatabase myDb;    
    bool connOpen()
    {
        myDb = QSqlDatabase::addDatabase("QMYSQL");
        myDb.setHostName("10.131.83.88");
        myDb.setUserName("kodiak");
        myDb.setPassword("K1o2d3i4a5k$");
        myDb.setDatabaseName("employee_db");

        if(!myDb.open())
        {
            qDebug()<<"Connection to database failed !!!";
            return false;
        }
        else
        {
            qDebug()<<"Connection to database succesful !!!";
            return true;
        }
    }

    void connClose()
    {
        myDb.close();
        myDb.removeDatabase(QSqlDatabase::defaultConnection);
    }

    int hashing(QString);
    void closeEvent(QCloseEvent *evt);

};



#endif // RSI_LOGIN_H
