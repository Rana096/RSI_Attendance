#ifndef CHILDWINDOW_H
#define CHILDWINDOW_H

#include <QWidget>

namespace Ui {
class childwindow;
}

class childwindow : public QWidget
{
    Q_OBJECT

public:
    explicit childwindow(QWidget *parent = 0);
    ~childwindow();

private:
    Ui::childwindow *ui;
};

#endif // CHILDWINDOW_H
