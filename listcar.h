#ifndef LISTCAR_H
#define LISTCAR_H

#include <QMainWindow>
#include "QStringListModel"
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

private:
    Ui::listcar *ui;
    QStringListModel *model;
};

#endif // LISTCAR_H
