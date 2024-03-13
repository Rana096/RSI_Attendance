#include "childwindow.h"
#include "ui_childwindow.h"

childwindow::childwindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::childwindow)
{
    ui->setupUi(this);
}

childwindow::~childwindow()
{
    delete ui;
}
