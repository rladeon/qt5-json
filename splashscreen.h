#ifndef SPLASHSCREEN
#define SPLASHSCREEN
#include "QLabel"
#include "QString"
#include "QPixmap"
#include "QDesktopWidget"
#include "QRect"
#include "QBitmap"

class SplashScreen : public QLabel
{

public:
    SplashScreen::SplashScreen( const QString& img )
    : QLabel( NULL, Qt::Tool | Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint )
    {
        QPixmap pixmap(img);

        setPixmap( pixmap );
        setMask( pixmap.mask() );
        setAttribute( Qt::WA_TranslucentBackground );

        QDesktopWidget screen;
        QRect screenGeom = screen.screenGeometry(this);
        move( screenGeom.center().x() - width () / 2,
            screenGeom.center().y() - height() / 2 );
    }

};
#endif // SPLASHSCREEN

