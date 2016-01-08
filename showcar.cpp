#include "showcar.h"
#include "ui_showcar.h"

ShowCar::ShowCar(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ShowCar)
{
    ui->setupUi(this);

}

ShowCar::~ShowCar()
{
    delete ui;
}
void ShowCar::SetList(QStringList l)
{
    this->listcar = l;
}
QStringList ShowCar::GetList()
{
    return listcar;
}
