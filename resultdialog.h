#ifndef RESULTDIALOG_H
#define RESULTDIALOG_H

#include <QDialog>

namespace Ui{
class Dialog;
}


class ResultDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ResultDialog(QWidget *parent = 0);
    ~ResultDialog();
    void setResult(float);

private:
    Ui::Dialog *ui;

};

#endif // RESULTDIALOG_H
