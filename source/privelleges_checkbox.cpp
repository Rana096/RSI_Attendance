#include "privelleges_checkbox.h"
#include "ui_privelleges_checkbox.h"
#include "rsi_login.h"

bool ad,ed,de,se,lo;
bool ischeckedAdd,ischeckedEDIT,ischeckedDELETE,ischeckedSEARCH,ischeckedLOAD;
prof HR,GD,SSE,SE,AD;

Privelleges_Checkbox::Privelleges_Checkbox(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Privelleges_Checkbox)
{
    ui->setupUi(this);
    ui->profile_label->setText(profile);



    if(profile=="HR")
    {
        qDebug()<<"HR";
        ischeckedAdd = rememberLast.value("HRadd").toBool();
        ischeckedEDIT = rememberLast.value("HRedit").toBool();
        ischeckedDELETE= rememberLast.value("HRdelete").toBool();
        ischeckedSEARCH = rememberLast.value("HRsearch").toBool();
        ischeckedLOAD = rememberLast.value("HRload").toBool();
        ui->add_checkBox->setChecked(ischeckedAdd);
        ui->edit_checkBox->setChecked(ischeckedEDIT);
        ui->delete_checkBox->setChecked(ischeckedDELETE);
        ui->search_checkBox->setChecked(ischeckedSEARCH);
        ui->load_checkBox->setChecked(ischeckedLOAD);
    }
    else if(profile=="Graphic Designer")
    {
        qDebug()<<"GD";
        ischeckedAdd = rememberLast.value("GDadd").toBool();
        ischeckedEDIT = rememberLast.value("GDedit").toBool();
        ischeckedDELETE= rememberLast.value("GDdelete").toBool();
        ischeckedSEARCH = rememberLast.value("GDsearch").toBool();
        ischeckedLOAD = rememberLast.value("GDload").toBool();
        ui->add_checkBox->setChecked(ischeckedAdd);
        ui->edit_checkBox->setChecked(ischeckedEDIT);
        ui->delete_checkBox->setChecked(ischeckedDELETE);
        ui->search_checkBox->setChecked(ischeckedSEARCH);
        ui->load_checkBox->setChecked(ischeckedLOAD);
    }
    else if(profile=="Senior Software Engineer")
    {
        qDebug()<<"SSE";
        ischeckedAdd = rememberLast.value("SSEadd").toBool();
        ischeckedEDIT = rememberLast.value("SSEedit").toBool();
        ischeckedDELETE= rememberLast.value("SSEdelete").toBool();
        ischeckedSEARCH = rememberLast.value("SSEsearch").toBool();
        ischeckedLOAD = rememberLast.value("SSEload").toBool();
        ui->add_checkBox->setChecked(ischeckedAdd);
        ui->edit_checkBox->setChecked(ischeckedEDIT);
        ui->delete_checkBox->setChecked(ischeckedDELETE);
        ui->search_checkBox->setChecked(ischeckedSEARCH);
        ui->load_checkBox->setChecked(ischeckedLOAD);
    }
    else if(profile=="Software Engineer")
    {
        qDebug()<<"SE";
        ischeckedAdd = rememberLast.value("SEadd").toBool();
        ischeckedEDIT = rememberLast.value("SEedit").toBool();
        ischeckedDELETE= rememberLast.value("SEdelete").toBool();
        ischeckedSEARCH = rememberLast.value("SEsearch").toBool();
        ischeckedLOAD = rememberLast.value("SEload").toBool();
        ui->add_checkBox->setChecked(ischeckedAdd);
        ui->edit_checkBox->setChecked(ischeckedEDIT);
        ui->delete_checkBox->setChecked(ischeckedDELETE);
        ui->search_checkBox->setChecked(ischeckedSEARCH);
        ui->load_checkBox->setChecked(ischeckedLOAD);
    }
    else if(profile=="Admin")
    {
        qDebug()<<"Admin";
        ischeckedAdd = rememberLast.value("ADadd").toBool();
        ischeckedEDIT = rememberLast.value("ADedit").toBool();
        ischeckedDELETE= rememberLast.value("ADdelete").toBool();
        ischeckedSEARCH = rememberLast.value("ADsearch").toBool();
        ischeckedLOAD = rememberLast.value("ADload").toBool();
        ui->add_checkBox->setChecked(ischeckedAdd);
        ui->edit_checkBox->setChecked(ischeckedEDIT);
        ui->delete_checkBox->setChecked(ischeckedDELETE);
        ui->search_checkBox->setChecked(ischeckedSEARCH);
        ui->load_checkBox->setChecked(ischeckedLOAD);
    }
}

Privelleges_Checkbox::~Privelleges_Checkbox()
{
    delete ui;
}

void Privelleges_Checkbox::on_ok_pushButton_clicked()
{
    qDebug()<<"ok clicked"<<profile;
    ad = ui->add_checkBox->isChecked();
    ed = ui->edit_checkBox->isChecked();
    de = ui->delete_checkBox->isChecked();
    se = ui->search_checkBox->isChecked();
    lo = ui->load_checkBox->isChecked();
    qDebug()<< "checkbox status after giving functionality "<<ad<<ed<<de<<se<<lo;

    save_privelleges();
}

void Privelleges_Checkbox::save_privelleges()
{
    qDebug()<<"save privellege function called";
    if(profile == "HR")
    {
        qDebug()<<"HR";
        HR.add=ad;
        HR.edit=ed;
        HR.delet=de;
        HR.search=se;
        HR.load=lo;
        qDebug()<<"saving privelleges in HR "<<HR.add<<HR.edit<<HR.delet<<HR.search<<HR.load;
        rememberLast.setValue("HRadd",HR.add);
        rememberLast.setValue("HRedit",HR.edit);
        rememberLast.setValue("HRdelete",HR.delet);
        rememberLast.setValue("HRsearch",HR.search);
        rememberLast.setValue("HRload",HR.load);
    }
    else if(profile == "Graphic Designer")
    {
        qDebug()<<"Graphic Designer";
        GD.add=ad;
        GD.edit=ed;
        GD.delet=de;
        GD.search=se;
        GD.load=lo;
        qDebug()<<"saving privelleges in Graphic Designer "<<GD.add<<GD.edit<<GD.delet<<GD.search<<GD.load;
        rememberLast.setValue("GDadd",GD.add);
        rememberLast.setValue("GDedit",GD.edit);
        rememberLast.setValue("GDdelete",GD.delet);
        rememberLast.setValue("GDsearch",GD.search);
        rememberLast.setValue("GDload",GD.load);
    }
    else if(profile == "Senior Software Engineer")
    {
        qDebug()<<"Senior Software Engineer";
        SSE.add=ad;
        SSE.edit=ed;
        SSE.delet=de;
        SSE.search=se;
        SSE.load=lo;
        qDebug()<<"saving privelleges in Senior Software Engineer "<<SSE.add<<SSE.edit<<SSE.delet<<SSE.search<<SSE.load;
        rememberLast.setValue("SSEadd",SSE.add);
        rememberLast.setValue("SSEedit",SSE.edit);
        rememberLast.setValue("SSEdelete",SSE.delet);
        rememberLast.setValue("SSEsearch",SSE.search);
        rememberLast.setValue("SSEload",SSE.load);
    }
    else if(profile == "Software Engineer")
    {
        qDebug()<<"Software Engineer";
        SE.add=ad;
        SE.edit=ed;
        SE.delet=de;
        SE.search=se;
        SE.load=lo;
        qDebug()<<"saving privelleges in Software Engineer "<<SE.add<<SE.edit<<SE.delet<<SE.search<<SE.load;
        rememberLast.setValue("SEadd",SE.add);
        rememberLast.setValue("SEedit",SE.edit);
        rememberLast.setValue("SEdelete",SE.delet);
        rememberLast.setValue("SEsearch",SE.search);
        rememberLast.setValue("SEload",SE.load);
    }
    else
    {
        qDebug()<<"Admin";
        AD.add=ad;
        AD.edit=ed;
        AD.delet=de;
        AD.search=se;
        AD.load=lo;
        qDebug()<<"saving privelleges in Admin "<<AD.add<<AD.edit<<AD.delet<<AD.search<<AD.load;
        rememberLast.setValue("ADadd",AD.add);
        rememberLast.setValue("ADedit",AD.edit);
        rememberLast.setValue("ADdelete",AD.delet);
        rememberLast.setValue("ADsearch",AD.search);
        rememberLast.setValue("ADload",AD.load);
    }
}
