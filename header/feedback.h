#ifndef FEEDBACK_H
#define FEEDBACK_H

#include <QDialog>

namespace Ui {
class Feedback;
}

class Feedback : public QDialog
{
    Q_OBJECT

public:
    explicit Feedback(QWidget *parent = 0);
    ~Feedback();

private slots:

    void on_save_PushButton_clicked();

    void on_cancel_PushButton_clicked();

private:
    Ui::Feedback *ui;
};

#endif // FEEDBACK_H
