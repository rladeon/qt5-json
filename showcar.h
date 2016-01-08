#ifndef SHOWCAR_H
#define SHOWCAR_H

#include <QMainWindow>

namespace Ui {
class ShowCar;
}

class ShowCar : public QMainWindow
{
    Q_OBJECT

public:
    explicit ShowCar(QWidget *parent = 0);
    ~ShowCar();
     void SetList(QStringList l);
     QStringList GetList();
private:
    Ui::ShowCar *ui;
    QStringList listcar;
};

#endif // SHOWCAR_H
