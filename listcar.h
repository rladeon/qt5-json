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
    QStringList sendmark(QStringList l);

    QStringList sendmodel(QStringList l);
    QStringList sendserie(QStringList l);


private slots:
    void on_listView_clicked();

    void on_listView_2_clicked();

    void on_listView_3_clicked();

private:
    Ui::listcar *ui;
    QStringListModel *model, *model2, *model3;
    ShowCar *showcar;
    listcar *listm;
};

#endif // LISTCAR_H
