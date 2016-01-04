#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "listcar.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    MainWindow *m;
    listcar *Listcar;

};

#endif // MAINWINDOW_H
