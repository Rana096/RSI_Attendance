#ifndef PRIVELLEGES_CHECKBOX_H
#define PRIVELLEGES_CHECKBOX_H

#include <QDialog>

extern bool ischeckedAdd,ischeckedEDIT,ischeckedDELETE,ischeckedSEARCH,ischeckedLOAD;

struct prof{
    bool add;
    bool edit;
    bool delet;
    bool search;
    bool load;
};


namespace Ui {
class Privelleges_Checkbox;
}

class Privelleges_Checkbox : public QDialog
{
    Q_OBJECT

public:
    explicit Privelleges_Checkbox(QWidget *parent = 0);
    ~Privelleges_Checkbox();

private slots:
    void on_ok_pushButton_clicked();

private:
    Ui::Privelleges_Checkbox *ui;

public:
    void save_privelleges();
};

#endif // PRIVELLEGES_CHECKBOX_H
