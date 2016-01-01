#include "listcar.h"
#include "ui_listcar.h"
#include "QStringList"
#include "QStringListModel"
#include "QEventLoop"
#include "QNetworkAccessManager"
#include "QObject"
#include "QNetworkReply"
#include "QJsonDocument"
#include "QJsonArray"
#include "QJsonValue"
#include "QJsonObject"

listcar::listcar(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::listcar)
{
    ui->setupUi(this);
    // Create model
        model = new QStringListModel(this);

        // Make data
        QStringList List = sendrequest();
        // Populate our model
        model->setStringList(List);

        // Glue model and view together
        ui->listView->setModel(model);

        // Add additional feature so that
        // we can manually modify the data in ListView
        // It may be triggered by hitting any key or double-click etc.
        ui->listView->
                setEditTriggers(QAbstractItemView::AnyKeyPressed |
                                QAbstractItemView::DoubleClicked);

}

listcar::~listcar()
{
    delete ui;
}
QStringList listcar::sendrequest()
{
        // create custom temporary event loop on stack
        QEventLoop eventLoop;

        // "quit()" the event-loop, when the network request "finished()"

        QNetworkAccessManager mgr;
        QObject::connect(&mgr, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));

        // the HTTP request
        QNetworkRequest req( QUrl( QString("http://mongoservices-kaihatsudo.rhcloud.com/") ) );
        QNetworkReply *reply = mgr.get(req);
        eventLoop.exec(); // blocks stack until "finished()" has been called

        QStringList List;
        List << "test";
        if (reply->error() == QNetworkReply::NoError) {
            //success

            //QString strReply = (QString) reply->readAll();
            QByteArray strReply = reply->readAll();

            // Make data

                    QJsonDocument jsonResponse = QJsonDocument::fromJson(strReply);
                    QJsonArray jsonArray = jsonResponse.array();

                    foreach (const QJsonValue & value, jsonArray)
                    {
                        if(value.isObject())
                        {
                            QJsonObject obj = value.toObject();qDebug() << obj["mark"].toString();
                            List.append(obj["mark"].toString());
                        }
                        else if(value.isString())
                        {
                            qDebug() << value;


                        }
                    }

        }
        else {
            //failure
            qDebug() << "Failure" <<reply->errorString();
            delete reply;
        }
        return List;
}
