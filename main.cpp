#include "mainwindow.h"
#include <QApplication>
#include "QPixmap"
#include "QSplashScreen"
#include "Windows.h"
#include "QThread"
#include "splashscreen.h"
#include "QPainter"
#include "QTimer"
class I : public QThread

{

public:

        static void sleep(unsigned long secs) {

                QThread::sleep(secs);

        }

};

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QImage splashScrImage ("C:/developpement/qt/greencar/asset/introd_diagnostique.png");
    QSize screenSize = QApplication::desktop()->geometry().size()/2;

    QImage splashScr (screenSize, QImage::Format_ARGB32_Premultiplied);
    QPainter painter (&splashScr);
    painter.fillRect(splashScr.rect(), Qt::transparent);
    QImage scaled = splashScrImage.scaled(screenSize, Qt::KeepAspectRatio);
    QRect scaledRect = scaled.rect();
    scaledRect.moveCenter(splashScr.rect().center());
    painter.drawImage(scaledRect, scaled);
    QPixmap Logo;
    Logo.convertFromImage(splashScr);
    QSplashScreen splashScrWindow (&w, Logo, Qt::WindowStaysOnTopHint);

    splashScrWindow.move(  QApplication::desktop()->width() / 3,
        QApplication::desktop()->height() / 3 );

    splashScrWindow.show();
    I::sleep(3);

    w.show();
    splashScrWindow.finish(&w);
    return a.exec();
}
