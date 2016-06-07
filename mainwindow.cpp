#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "resultdialog.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QObject::connect(ui->aboutButton,SIGNAL(clicked()),this,SLOT(aboutClicked()));

    QObject::connect(this, SIGNAL(computed(float)),this,SLOT(showResult(float)));

    QObject::connect(ui->plusButton, SIGNAL(clicked()), this, SLOT(plusClicked()));

    QObject::connect(ui->minusButton, SIGNAL(clicked()), this, SLOT(minusClicked()));

    QObject::connect(ui->timesButton, SIGNAL(clicked()), this, SLOT(timesClicked()));

    QObject::connect(ui->divideButton, SIGNAL(clicked()), this, SLOT(divideClicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::aboutClicked()
{
    QMessageBox messageBox;
    messageBox.setIconPixmap(QPixmap(":/noun_459402_cc.svg"));
    messageBox.setText("Lorem ipsum");
    messageBox.setWindowTitle("About");
    messageBox.exec();

}

void MainWindow::showResult(float r)
{
    if(!results)
    {
        results = new ResultDialog();
    }

    results->setResult(r);
    results->exec();
}

void MainWindow::plusClicked()
{
    Arguments a = arguments();

    emit computed(a.first + a.second);
}


void MainWindow::minusClicked()
{
    Arguments a = arguments();

    emit computed(a.first - a.second);
}

void MainWindow::timesClicked()
{
    Arguments a = arguments();

    emit computed(a.first*a.second);
}

void MainWindow::divideClicked()
{
    Arguments a = arguments();

    emit computed(a.first/a.second);
}


MainWindow::Arguments MainWindow::arguments()
{
    bool ok1, ok2;

    float a1 = ui->argument1Input->text().toFloat(&ok1);

    float a2 = ui->argument2Input->text().toFloat(&ok2);

    if(!ok1 || !ok2)
    {
        QMessageBox messageBox;
        messageBox.setIconPixmap(QPixmap(":/noun_459402_cc.svg"));

        messageBox.setText("One of your entries is not a valid number");

        messageBox.setWindowTitle("Error");

        messageBox.exec();
    }

    return Arguments(a1,a2);
}
