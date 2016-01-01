#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    Listcar = new listcar(this);
    Listcar->show();
    m->hide();

}

void MainWindow::on_pushButton_2_clicked()
{
    qApp->quit();
}
