#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPair>

namespace Ui {
class MainWindow;
}

class ResultDialog;

class MainWindow : public QMainWindow
{
    Q_OBJECT

    typedef QPair<float, float> Arguments;

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    Arguments arguments();

signals:
    void computed(float f);

public slots:
    void aboutClicked();
    void plusClicked();
    void minusClicked();
    void timesClicked();
    void divideClicked();

    void showResult(float r);

private:
    Ui::MainWindow *ui;
    ResultDialog* results;
};

#endif // MAINWINDOW_H
