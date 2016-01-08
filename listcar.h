#ifndef LISTCAR_H
#define LISTCAR_H

#include <QMainWindow>
#include "QStringListModel"
#include "showcar.h"

namespace Ui {
class listcar;
}

class listcar : public QMainWindow
{
    Q_OBJECT

public:
    explicit listcar(QWidget *parent = 0);
    ~listcar();
    QStringList sendrequest();


private slots:
    void on_listView_clicked();

private:
    Ui::listcar *ui;
    QStringListModel *model;
    ShowCar *showcar;
    listcar *listm;
};

#endif // LISTCAR_H
