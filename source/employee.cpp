#include "employee.h"
#include "ui_employee.h"
#include "rsi_login.h"
#include "update_password.h"
#include "add_employee.h"
#include "privelleges_checkbox.h"
#include "edit_employee.h"
#include <SDL2/SDL.h>               //testing
#include "mysdl.h"
#include "childwindow.h"
#include <QAbstractItemModel>
#include <QMessageBox>

QSettings rememberLastgeometry;

Employee::Employee(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Employee)
{

    /*setting last window size*/
    rememberLastgeometry.beginGroup("employee");
//    restoreGeometry(rememberLastgeometry.value("geometry").toByteArray());
//    restoreState(rememberLastgeometry.value("savestate").toByteArray());
    resize(rememberLastgeometry.value("size",QSize()).toSize());
    move(rememberLastgeometry.value("pos").toPoint());
    if(rememberLastgeometry.value("maximized").toBool())
    {
        showMaximized();
    }
    rememberLastgeometry.endGroup();

    ui->setupUi(this);
    ui->treeWidget->setHeaderLabel("RSI");

    item->setText(0,"Employees");
    ui->treeWidget->addTopLevelItem(item);

    item1->setText(0,"Edit");
    ui->treeWidget->addTopLevelItem(item1);

    QSqlQuery qry;
    QSqlQueryModel *comb = new QSqlQueryModel();
    qry.prepare("select profile from role");
    qry.exec();
    comb->setQuery(qry);
    ui->profile_comboBox->setModel(comb);

    ui->actionAdd_Employee->setEnabled(false);
    ui->actionEdit_Employee->setEnabled(false);
    ui->actionDelete_Employee->setEnabled(false);
    ui->actionLoad->setEnabled(false);

    for(int i=1;i<=5;i++)
    {
        ui->tabWidget->removeTab(1);
    }

    qry.prepare("select profile from details where user_ID = '"+guserID+"'");
    if(qry.exec())
    {
        while(qry.next())
        {
            if(qry.value(0).toString()=="HR")
            {
                //Removing privellege tab
                //ui->tabWidget->removeTab(1);
                ischeckedAdd = rememberLast.value("HRadd").toBool();
                ischeckedEDIT = rememberLast.value("HRedit").toBool();
                ischeckedDELETE= rememberLast.value("HRdelete").toBool();
                ischeckedSEARCH = rememberLast.value("HRsearch").toBool();
                ischeckedLOAD = rememberLast.value("HRload").toBool();
                if(ischeckedAdd){
                    AddRoot0("Add Employee");
                    ui->actionAdd_Employee->setEnabled(true);
                }
                if(ischeckedEDIT){
                    AddRoot1("Edit Employee");
                    ui->actionEdit_Employee->setEnabled(true);
                }
                if(ischeckedDELETE){
                    AddRoot2("Delete Employee");
                    ui->actionDelete_Employee->setEnabled(true);
                }
                if(ischeckedSEARCH){
                    //AddRoot3("Seach Employee");
                }
                if(ischeckedLOAD){
                    AddRoot4("Load");
                    ui->actionLoad->setEnabled(true);
                }
                /*ui->add_Employee_Push_Button->setEnabled(ischeckedAdd);
                ui->edit_Employee_Push_Button->setEnabled(ischeckedEDIT);
                ui->delete_Employee_Push_Button->setEnabled(ischeckedDELETE);
                ui->search_Push_Button->setEnabled(ischeckedSEARCH);
                ui->load_Push_Button->setEnabled(ischeckedLOAD);*/
            }
            else if(qry.value(0).toString()=="Graphic Designer")
            {
                //Removing privellege tab
//                ui->tabWidget->removeTab(1);
                ischeckedAdd = rememberLast.value("GDadd").toBool();
                ischeckedEDIT = rememberLast.value("GDedit").toBool();
                ischeckedDELETE= rememberLast.value("GDdelete").toBool();
                ischeckedSEARCH = rememberLast.value("GDsearch").toBool();
                ischeckedLOAD = rememberLast.value("GDload").toBool();
                if(ischeckedAdd){
                    AddRoot0("Add Employee");
                    ui->actionAdd_Employee->setEnabled(true);
                }
                if(ischeckedEDIT){
                    AddRoot1("Edit Employee");
                    ui->actionEdit_Employee->setEnabled(true);
                }
                if(ischeckedDELETE){
                    AddRoot2("Delete Employee");
                    ui->actionDelete_Employee->setEnabled(true);
                }
                if(ischeckedSEARCH){
                    //AddRoot3("Seach Employee");
                }
                if(ischeckedLOAD){
                    AddRoot4("Load");
                    ui->actionLoad->setEnabled(true);
                }
                /*ui->add_Employee_Push_Button->setEnabled(ischeckedAdd);
                ui->edit_Employee_Push_Button->setEnabled(ischeckedEDIT);
                ui->delete_Employee_Push_Button->setEnabled(ischeckedDELETE);
                ui->search_Push_Button->setEnabled(ischeckedSEARCH);
                ui->load_Push_Button->setEnabled(ischeckedLOAD);*/
            }
            else if(qry.value(0).toString()=="Senior Software Engineer")
            {
                //Removing privellege tab
//                ui->tabWidget->removeTab(1);
                ischeckedAdd = rememberLast.value("SSEadd").toBool();
                ischeckedEDIT = rememberLast.value("SSEedit").toBool();
                ischeckedDELETE= rememberLast.value("SSEdelete").toBool();
                ischeckedSEARCH = rememberLast.value("SSEsearch").toBool();
                ischeckedLOAD = rememberLast.value("SSEload").toBool();
                if(ischeckedAdd){
                    AddRoot0("Add Employee");
                    ui->actionAdd_Employee->setEnabled(true);
                }
                if(ischeckedEDIT){
                    AddRoot1("Edit Employee");
                    ui->actionEdit_Employee->setEnabled(true);
                }
                if(ischeckedDELETE){
                    AddRoot2("Delete Employee");
                    ui->actionDelete_Employee->setEnabled(true);
                }
                if(ischeckedSEARCH){
                    //AddRoot3("Seach Employee");
                }
                if(ischeckedLOAD){
                    AddRoot4("Load");
                    ui->actionLoad->setEnabled(true);
                }
                /*ui->add_Employee_Push_Button->setEnabled(ischeckedAdd);
                ui->edit_Employee_Push_Button->setEnabled(ischeckedEDIT);
                ui->delete_Employee_Push_Button->setEnabled(ischeckedDELETE);
                ui->search_Push_Button->setEnabled(ischeckedSEARCH);
                ui->load_Push_Button->setEnabled(ischeckedLOAD);*/
            }
            else if(qry.value(0).toString()=="Software Engineer")
            {
                //Removing privellege tab
//                ui->tabWidget->removeTab(1);
                ischeckedAdd = rememberLast.value("SEadd").toBool();
                ischeckedEDIT = rememberLast.value("SEedit").toBool();
                ischeckedDELETE= rememberLast.value("SEdelete").toBool();
                ischeckedSEARCH = rememberLast.value("SEsearch").toBool();
                ischeckedLOAD = rememberLast.value("SEload").toBool();
                if(ischeckedAdd){
                    AddRoot0("Add Employee");
                    ui->actionAdd_Employee->setEnabled(true);
                }
                if(ischeckedEDIT){
                    AddRoot1("Edit Employee");
                    ui->actionEdit_Employee->setEnabled(true);
                }
                if(ischeckedDELETE){
                    AddRoot2("Delete Employee");
                    ui->actionDelete_Employee->setEnabled(true);
                }
                if(ischeckedSEARCH){
                    //AddRoot3("Seach Employee");
                }
                if(ischeckedLOAD){
                    AddRoot4("Load");
                    ui->actionLoad->setEnabled(true);
                }
                /*ui->add_Employee_Push_Button->setEnabled(ischeckedAdd);
                ui->edit_Employee_Push_Button->setEnabled(ischeckedEDIT);
                ui->delete_Employee_Push_Button->setEnabled(ischeckedDELETE);
                ui->search_Push_Button->setEnabled(ischeckedSEARCH);
                ui->load_Push_Button->setEnabled(ischeckedLOAD);*/
            }
            else if(qry.value(0).toString()=="Admin")
            {
                AddRoot5("Functionality");
                AddRoot7("Add Role");
                QSqlQuery qry;
                qry.prepare("select first_name from details");
                if(qry.exec())
                {
                    while(qry.next())
                    {
                        AddRoot6(qry.value(0).toString());
                    }
                }
                ischeckedAdd = rememberLast.value("ADadd").toBool();
                ischeckedEDIT = rememberLast.value("ADedit").toBool();
                ischeckedDELETE= rememberLast.value("ADdelete").toBool();
                ischeckedSEARCH = rememberLast.value("ADsearch").toBool();
                ischeckedLOAD = rememberLast.value("ADload").toBool();
                if(ischeckedAdd){
                    AddRoot0("Add Employee");
                    ui->actionAdd_Employee->setEnabled(true);
                }
                if(ischeckedEDIT){
                    AddRoot1("Edit Employee");
                    ui->actionEdit_Employee->setEnabled(true);
                }
                if(ischeckedDELETE){
                    AddRoot2("Delete Employee");
                    ui->actionDelete_Employee->setEnabled(true);
                }
                if(ischeckedSEARCH){
                    //AddRoot3("Seach Employee");
                }
                if(ischeckedLOAD){
                    //AddRoot4("Load");
                    ui->actionLoad->setEnabled(true);
                }
                /*ui->add_Employee_Push_Button->setEnabled(ischeckedAdd);
                ui->edit_Employee_Push_Button->setEnabled(ischeckedEDIT);
                ui->delete_Employee_Push_Button->setEnabled(ischeckedDELETE);
                ui->search_Push_Button->setEnabled(ischeckedSEARCH);
                ui->load_Push_Button->setEnabled(ischeckedLOAD);*/
            }
        }
    }
}

Employee::~Employee()
{
    delete ui;
}

void Employee::on_search_Push_Button_clicked()
{
    bool flag =  false;
    QSqlTableModel *modal = new QSqlTableModel();
    modal->setTable("details");

    switch (ui->search_comboBox->currentIndex()) {
    case Employee_empty:
        break;
    case Employee_id:{
            qDebug()<<"search combobox emp_id index is : "<<ui->search_comboBox->currentIndex();
            int emp_id = ui->search_lineEdit->text().toInt();
            QString whereid = "emp_ID LIKE '%\%1%' ";
            modal->setFilter(whereid.arg(emp_id));
            modal->select();
            flag = true;
        }
        break;
    case Employee_name:{
            qDebug()<<"search combobox emp_name index is : "<<ui->search_comboBox->currentIndex();
            QString emp_name = ui->search_lineEdit->text();
            QString wherename = "concat(first_name,' ',last_name) LIKE '%\%1%' ";
            modal->setFilter(wherename.arg(emp_name));
            modal->select();
            flag = true;
            }
        break;
    case Employee_age:{
            qDebug()<<"search combobox emp_age index is : "<<ui->search_comboBox->currentIndex();
            int emp_age = ui->search_lineEdit->text().toInt();
            QString whereage = "age LIKE '%\%1%' ";
            modal->setFilter(whereage.arg(emp_age));
            modal->select();
            flag = true;
            }
        break;
    case Employee_profile:{
            qDebug()<<"search combobox emp_profile index is : "<<ui->search_comboBox->currentIndex();
            QString emp_profile = ui->search_lineEdit->text();
            QString whereprofile = "profile LIKE '%\%1%' ";
            modal->setFilter(whereprofile.arg(emp_profile));
            modal->select();
            flag = true;
            }
        break;
    case Employee_user_id:{
            qDebug()<<"search combobox emp_user_id index is : "<<ui->search_comboBox->currentIndex();
            QString emp_user_id = ui->search_lineEdit->text();
            QString whereuserid = "user_ID LIKE '%\%1%' ";
            modal->setFilter(whereuserid.arg(emp_user_id));
            modal->select();
            flag = true;
            }
        break;
    default:
        break;
    }
    if(flag)
    {
        ui->tableView->setColumnHidden(6,true);
        ui->tableView->setModel(modal);
    }
}

void Employee::on_ok_pushButton_clicked()
{
    qDebug()<<"OK clicked";
    profile = ui->profile_comboBox->currentText();
    privellegeCheckbox = new Privelleges_Checkbox(this);
    privellegeCheckbox->setWindowTitle(QString("%1 privelleges").arg(profile));
    privellegeCheckbox->show();
}

void Employee::on_actionLog_Out_triggered()
{
    lastLogOutWarning = new LogOutWarning(this);
    lastLogOutWarning->setWindowTitle("logout");
    lastLogOutWarning->show();
}

void Employee::on_actionUpdate_Password_triggered()
{
    qDebug()<<"update password clicked";
    updatePassword = new Update_Password(this);
    updatePassword->setWindowTitle("Password Update");
    updatePassword->show();
}

void Employee::on_actionSelf_Detail_triggered()
{
    qDebug()<<"self detail clicked : "<<guserID;

    ui->tabWidget->insertTab(0,ui->tab,"Details");
    ui->tabWidget->removeTab(1);

    QSqlTableModel *modal = new QSqlTableModel();
    modal->setTable("details");
    modal->setEditStrategy(QSqlTableModel::OnManualSubmit);
    modal->setFilter("user_ID = '"+guserID+"'");
    modal->select();

    ui->tableView->setModel(modal);

    modal->setHeaderData(0,Qt::Horizontal,QObject::tr("EMP_ID"));
    modal->setHeaderData(1,Qt::Horizontal,QObject::tr("First Name"));
    modal->setHeaderData(2,Qt::Horizontal,QObject::tr("Last Name"));
    modal->setHeaderData(3,Qt::Horizontal,QObject::tr("Age"));
    modal->setHeaderData(4,Qt::Horizontal,QObject::tr("Profile"));
    modal->setHeaderData(5,Qt::Horizontal,QObject::tr("USER_ID"));

    QObject::connect(ui->save_Push_Button,&QPushButton::clicked,modal,&QSqlTableModel::submitAll);
    QObject::connect(ui->reset_Push_Button,&QPushButton::clicked,modal,&QSqlTableModel::revertAll);
}

void Employee::on_actionHoliday_List_triggered()
{
    qDebug()<<"holiday list clicked";
    rsi_login conn;
    QSqlQueryModel *modal = new QSqlQueryModel();
    conn.connOpen();
    QSqlQuery *qry = new QSqlQuery(conn.myDb);
    qry->prepare("select Holiday, date_format(Date,'%d-%b-%Y') as Date, "
                 "dayname(Date) as Day_of_Week from holiday_list");
    qry->exec();
    ui->tableView->setModel(modal);
    modal->setQuery(*qry);

    qDebug()<<"Number of holiday in a calender year : "<<(modal->rowCount());
}

void Employee::on_actionFeedback_triggered()
{
    qDebug()<<"employee feedback clicked";
    feedback = new Feedback(this);
    feedback->setWindowTitle("employee feedback");
    feedback->show();
}

void Employee::on_actionLoad_triggered()
{
    ui->tabWidget->removeTab(0);
    ui->tabWidget->insertTab(1,ui->tab,"Details");
    on_load_employee();
}

void Employee::on_actionEdit_Employee_triggered()
{
    ui->tabWidget->removeTab(0);
    ui->tabWidget->insertTab(1,ui->tab_4,"Edit Employee");
}

void Employee::on_actionDelete_Employee_triggered()
{
    ui->tabWidget->removeTab(0);
    ui->tabWidget->insertTab(1,ui->tab_5,"Delete Employee");
}

void Employee::on_actionAdd_Employee_triggered()
{
    ui->tabWidget->removeTab(0);
    ui->tabWidget->insertTab(1,ui->tab_3,"Add Employee");
}

void Employee::on_actionMark_Attendance_triggered()
{
    qDebug()<<"mark attendance clicked";
    attendace = new Attendance(this);
    attendace->setWindowTitle(guserID);
    attendace->show();
}

void Employee::on_ser_employee_pushbutton_clicked()
{
    qDebug()<<"vikas testing : "<<ui->search_comboBox->currentIndex();
}

void Employee::on_load_employee()
{
    QSqlTableModel *tableModel = new QSqlTableModel(this);
    tableModel->setTable("details");
    tableModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
    tableModel->setHeaderData(0,Qt::Horizontal,QObject::tr("EMP_ID"));
    tableModel->setHeaderData(1,Qt::Horizontal,QObject::tr("First Name"));
    tableModel->setHeaderData(2,Qt::Horizontal,QObject::tr("Last Name"));
    tableModel->setHeaderData(3,Qt::Horizontal,QObject::tr("Age"));
    tableModel->setHeaderData(4,Qt::Horizontal,QObject::tr("Profile"));
    tableModel->setHeaderData(5,Qt::Horizontal,QObject::tr("USER_ID"));
    tableModel->select();

    ui->tableView->setModel(tableModel);
    //to hide password column
    ui->tableView->setColumnHidden(6,true);
    ui->tableView->

    QObject::connect(ui->save_Push_Button,&QPushButton::clicked,tableModel,&QSqlTableModel::submitAll);
    QObject::connect(ui->reset_Push_Button,&QPushButton::clicked,tableModel,&QSqlTableModel::revertAll);
}

void Employee::closeEvent(QCloseEvent *evt)
{
    /*remember last window size*/
    rememberLastgeometry.beginGroup("employee");
    rememberLastgeometry.setValue("geometry",saveGeometry());
    rememberLastgeometry.setValue("savestate",saveState());
    rememberLastgeometry.setValue("maximized",isMaximized());
    if(!isMaximized())
    {
        rememberLastgeometry.setValue("pos",pos());
        rememberLastgeometry.setValue("size",size());
    }
    rememberLastgeometry.endGroup();
    rememberLastgeometry.sync();
    qDebug()<<"vikas employee close event";
    evt->accept();
}

void Employee::AddRoot0(QString name)
{
    QTreeWidgetItem *itm = new QTreeWidgetItem();
    //QTreeWidgetItem *add_emp_itm = new QTreeWidgetItem();
    itm->setText(0,name);
    //ui->treeWidget->addTopLevelItem(item);
    //QPushButton *add_employee_pushbutton = new QPushButton("Add Employee");
    item1->addChild(itm);
    //ui->treeWidget->setItemWidget(add_emp_itm,0,add_employee_pushbutton);
    //connect(add_employee_pushbutton,SIGNAL(clicked(bool)),this,SLOT(on_add_employee_pushbutton_clicked()));
}


void Employee::AddRoot1(QString name)
{
    QTreeWidgetItem *itm = new QTreeWidgetItem();
    //QTreeWidgetItem *edit_emp_itm = new QTreeWidgetItem();
    itm->setText(0,name);
    //ui->treeWidget->addTopLevelItem(itm);
    //QPushButton *edit_employee_pushbutton = new QPushButton("Edit Employee");
    item1->addChild(itm);
    //ui->treeWidget->setItemWidget(edit_emp_itm,0,edit_employee_pushbutton);
    //connect(edit_employee_pushbutton,SIGNAL(clicked(bool)),this,SLOT(on_edit_employee_pushbutton_clicked()));
}

void Employee::AddRoot2(QString name)
{
    QTreeWidgetItem *itm = new QTreeWidgetItem();
    //QTreeWidgetItem *del_emp_itm = new QTreeWidgetItem();
    itm->setText(0,name);
    //ui->treeWidget->addTopLevelItem(itm);
    //QPushButton *del_employee_pushbutton = new QPushButton("Delete Employee");
    item1->addChild(itm);
    //ui->treeWidget->setItemWidget(del_emp_itm,0,del_employee_pushbutton);
    //connect(del_employee_pushbutton,SIGNAL(clicked(bool)),this,SLOT(on_del_employee_pushbutton_clicked()));
}

void Employee::AddRoot3(QString name)
{
    QTreeWidgetItem *itm = new QTreeWidgetItem();
    QTreeWidgetItem *ser_emp_itm = new QTreeWidgetItem();
    itm->setText(0,name);
    ui->treeWidget->addTopLevelItem(itm);
    QPushButton *ser_employee_pushbutton = new QPushButton("Search Employee");
    itm->addChild(ser_emp_itm);
    ui->treeWidget->setItemWidget(ser_emp_itm,0,ser_employee_pushbutton);
    connect(ser_employee_pushbutton,SIGNAL(clicked(bool)),this,SLOT(on_ser_employee_pushbutton_clicked()));
}

void Employee::AddRoot4(QString name)
{
    QTreeWidgetItem *itm = new QTreeWidgetItem();
    //QTreeWidgetItem *load_emp_itm = new QTreeWidgetItem();
    itm->setText(0,name);
    ui->treeWidget->addTopLevelItem(itm);
    //QPushButton *load_employee_pushbutton = new QPushButton("Load Employee");
    //itm->addChild(load_emp_itm);
    //ui->treeWidget->setItemWidget(load_emp_itm,0,load_employee_pushbutton);
    //connect(load_employee_pushbutton,SIGNAL(clicked(bool)),this,SLOT(on_load_employee_pushbutton_clicked()));
    //connect(itm,SIGNAL(clicked(bool)),this,SLOT(on_load_employee_pushbutton_clicked()));
}

void Employee::AddRoot5(QString name)
{
    QTreeWidgetItem *itm = new QTreeWidgetItem();
    itm->setText(0,name);
    ui->treeWidget->addTopLevelItem(itm);
}

void Employee::AddRoot6(QString name)
{
    QTreeWidgetItem *itm = new QTreeWidgetItem();
    itm->setText(0,name);
    item->addChild(itm);
}

void Employee::AddRoot7(QString name)
{
    QTreeWidgetItem *itm = new QTreeWidgetItem();
    itm->setText(0,name);
    item1->addChild(itm);
}

void Employee::on_treeWidget_itemClicked(QTreeWidgetItem *item, int column)
{
    QString selectedName;
    QSqlQuery qry;
    qry.prepare("select first_name from details ");
    if(qry.exec())
    {
        while(qry.next())
        {
            if(qry.value(0).toString()==item->text(column))
            {
//                ui->tabWidget->insertTab(0,ui->tab,"Details");
//                ui->tabWidget->removeTab(1);
//                selectedName = item->text(column);

//                QSqlTableModel *modal = new QSqlTableModel();
//                modal->setTable("details");
//                modal->setEditStrategy(QSqlTableModel::OnManualSubmit);
//                modal->setFilter("first_name = '"+selectedName+"'");
//                modal->select();

//                ui->tableView->setModel(modal);

//                modal->setHeaderData(0,Qt::Horizontal,QObject::tr("EMP_ID"));
//                modal->setHeaderData(1,Qt::Horizontal,QObject::tr("First Name"));
//                modal->setHeaderData(2,Qt::Horizontal,QObject::tr("Last Name"));
//                modal->setHeaderData(3,Qt::Horizontal,QObject::tr("Age"));
//                modal->setHeaderData(4,Qt::Horizontal,QObject::tr("Profile"));
//                modal->setHeaderData(5,Qt::Horizontal,QObject::tr("USER_ID"));

//                ui->tableView->hideColumn(6);

//                QObject::connect(ui->save_Push_Button,&QPushButton::clicked,modal,&QSqlTableModel::submitAll);
//                QObject::connect(ui->reset_Push_Button,&QPushButton::clicked,modal,&QSqlTableModel::revertAll);

//                break;
                if(ischldwdw)
                {
                    chldwnd->hide();
                }
                chldwnd = new childwindow(this);
                chldwnd->setParent(this);
                ui->tabWidget->removeTab(0);
                chldwnd->move(350,40);
                chldwnd->show();
                ischldwdw = true;
            }
        }
    }
    if(item->text(column) == "Functionality")
    {
        if(ischldwdw)
        {
            chldwnd->hide();
        }
          ui->tabWidget->removeTab(0);
          ui->tabWidget->insertTab(1,ui->tab_2,"Functionality");
    }
    else if(item->text(column) == "Add Employee")
    {
        if(ischldwdw)
        {
            chldwnd->hide();
        }
          ui->tabWidget->removeTab(0);
          ui->tabWidget->insertTab(1,ui->tab_3,"Add Employee");
    }
    else if(item->text(column) == "Edit Employee")
    {
        if(ischldwdw)
        {
            chldwnd->hide();
        }
          ui->tabWidget->removeTab(0);
          ui->tabWidget->insertTab(1,ui->tab_4,"Edit Employee");
    }
    else if(item->text(column) == "Delete Employee")
    {
        if(ischldwdw)
        {
            chldwnd->hide();
        }
          ui->tabWidget->removeTab(0);
          ui->tabWidget->insertTab(1,ui->tab_5,"Delete Employee");
    }
    else if(item->text(column) == "Add Role")
    {
        if(ischldwdw)
        {
            chldwnd->hide();
        }
          ui->tabWidget->removeTab(0);
          ui->tabWidget->insertTab(1,ui->tab_6,"Add Role");
    }
    else if (item->text(column) == "Employees")
    {
        if(ischldwdw)
        {
            chldwnd->hide();
        }
        qDebug()<<"Employess treewideget clicked";
        on_actionLoad_triggered();
    }
}

void Employee::on_actionsdl_triggered()
{
    qDebug()<<"sdl clicked";
    mysdl = new MYSDL();
    qDebug()<<"vikas in employee.cpp";
}

void Employee::on_add_pushButton_clicked()
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
        ui->tabWidget->removeTab(0);
        ui->tabWidget->insertTab(1,ui->tab,"Details");
    }
    else
    {
        QMessageBox::warning(this,"Fail","failed to add new employee!!");
    }
}


int Employee::hashing(QString str)
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

void Employee::on_update_pushButton_clicked()
{
    qDebug()<<"update clicked";
    QString user_id =ui->user_ID_lineEdit->text();
    QString pswrd =ui->new_password_lineEdit->text();

    int retpswrd = hashing(pswrd);

    QSqlQuery qry;
    qry.prepare("update details set password = :retpswd where user_ID = '"+user_id+"'");
    qry.bindValue(":retpswd",retpswrd);
    if(qry.exec())
    {
        if(qry.numRowsAffected() > 0)
        {
            QMessageBox::information(this,"Succesful","Password updated!!");
            ui->tabWidget->removeTab(0);
            ui->tabWidget->insertTab(1,ui->tab,"Details");
        }
        else
        {
            QMessageBox::warning(this,"Fail","user_ID not present in database");
        }
    }
}

void Employee::on_delete_pushButton_clicked()
{
    QString user_id = ui->user_ID_lineedit->text();
    QSqlQuery qry;
    qry.prepare("delete from details where user_ID = '"+user_id+"'");
    if(qry.exec())
    {
        if(qry.numRowsAffected() > 0)
        {
            QMessageBox::information(this,"Succesful","Delete operation succesfull!!");
            ui->tabWidget->removeTab(0);
            ui->tabWidget->insertTab(1,ui->tab,"Details");
        }
        else
        {
            QMessageBox::warning(this,"Fail","user_ID not present in database");
        }
    }
}

void Employee::on_add_role_pushButton_clicked()
{
    QString role = ui->new_role_lineEdit->text();
    QSqlQuery qry;
    qry.prepare("Insert into role(profile)"
                "values (:first)");
    qry.bindValue(":first",role);
    if(qry.exec())
    {
        QMessageBox::information(this,"Succesful","succesfully new role added!!");
        ui->tabWidget->removeTab(0);
        ui->tabWidget->insertTab(1,ui->tab,"Details");
    }
    else
    {
        QMessageBox::warning(this,"Fail","Entered Role already present in database!!");
    }

}
