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

            QByteArray strReply = reply->readAll();

            // Make data

                    QJsonDocument jsonResponse = QJsonDocument::fromJson(strReply);
                    QJsonArray jsonArray = jsonResponse.array();
                    List.clear();
                    foreach (const QJsonValue & value, jsonArray)
                    {

                        if(value.isObject())
                        {
                            QJsonObject obj = value.toObject();
                            if(!obj.isEmpty())
                            {
                                if(!(obj["mark"].isNull()))
                                {
                                        List.append(obj["mark"].toString());
                                }
                            }

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
QStringList listcar::sendmark(QStringList l)
{
        // create custom temporary event loop on stack
        QEventLoop eventLoop;

        // "quit()" the event-loop, when the network request "finished()"

        QNetworkAccessManager mgr;
        QObject::connect(&mgr, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));
        QString data = l.first();
        // the HTTP request
        QNetworkRequest req( QUrl( QString("http://mongoservices-kaihatsudo.rhcloud.com/crud/querymark/"+data) ) );
        QNetworkReply *reply = mgr.get(req);
        eventLoop.exec(); // blocks stack until "finished()" has been called

        QStringList List;
        List << "test";
        if (reply->error() == QNetworkReply::NoError) {
            //success

            QByteArray strReply = reply->readAll();

            // Make data

                    QJsonDocument jsonResponse = QJsonDocument::fromJson(strReply);
                    QJsonArray jsonArray = jsonResponse.array();
                    List.clear();
                    foreach (const QJsonValue & value, jsonArray)
                    {

                        if(value.isObject())
                        {
                            QJsonObject obj = value.toObject();
                            if(!obj.isEmpty())
                            {
                                if(!(obj["model"].isNull()))
                                {
                                        List.append(obj["model"].toString());
                                }
                            }

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
QStringList listcar::sendmodel(QStringList l)
{
        // create custom temporary event loop on stack
        QEventLoop eventLoop;

        // "quit()" the event-loop, when the network request "finished()"

        QNetworkAccessManager mgr;
        QObject::connect(&mgr, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));
        QString data = l.first();
        // the HTTP request
        QNetworkRequest req( QUrl( QString("http://mongoservices-kaihatsudo.rhcloud.com/crud/querymodel/"+data) ) );
        QNetworkReply *reply = mgr.get(req);
        eventLoop.exec(); // blocks stack until "finished()" has been called

        QStringList List;
        List << "test";
        if (reply->error() == QNetworkReply::NoError) {
            //success

            QByteArray strReply = reply->readAll();

            // Make data

                    QJsonDocument jsonResponse = QJsonDocument::fromJson(strReply);
                    QJsonArray jsonArray = jsonResponse.array();
                    List.clear();
                    foreach (const QJsonValue & value, jsonArray)
                    {

                        if(value.isObject())
                        {
                            QJsonObject obj = value.toObject();
                            if(!obj.isEmpty())
                            {
                                if(!(obj["serie"].isNull()))
                                {
                                        List.append(obj["serie"].toString());
                                }
                            }

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
QStringList listcar::sendserie(QStringList l)
{
        // create custom temporary event loop on stack
        QEventLoop eventLoop;

        // "quit()" the event-loop, when the network request "finished()"

        QNetworkAccessManager mgr;
        QObject::connect(&mgr, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));
        QString data = l.first();
        // the HTTP request
        QNetworkRequest req( QUrl( QString("http://mongoservices-kaihatsudo.rhcloud.com/crud/queryserie/"+data) ) );
        QNetworkReply *reply = mgr.get(req);
        eventLoop.exec(); // blocks stack until "finished()" has been called

        QStringList List;
        List << "test";
        if (reply->error() == QNetworkReply::NoError) {
            //success

            QByteArray strReply = reply->readAll();

            // Make data

                    QJsonDocument jsonResponse = QJsonDocument::fromJson(strReply);
                    QJsonArray jsonArray = jsonResponse.array();
                    List.clear();
                    foreach (const QJsonValue & value, jsonArray)
                    {

                        if(value.isObject())
                        {
                            QJsonObject obj = value.toObject();
                            if(!obj.isEmpty())
                            {
                                if(!(obj["serie"].isNull()))
                                {
                                        List.append(obj["serie"].toString());
                                }
                            }

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
void listcar::on_listView_clicked()
{

    QModelIndexList list = ui->listView->selectionModel()->selectedIndexes();

       QStringList slist;
       foreach(const QModelIndex &index, list)
       {
           slist.append( index.data(Qt::DisplayRole ).toString());
       }

    //ui->listView->hide();
    //listm->hide();
       // Create model
           model2 = new QStringListModel(this);

           // Make data
           QStringList List = sendmark(slist);
           // Populate our model
           model2->setStringList(List);

           // Glue model and view together
           ui->listView_2->setModel(model2);

           // Add additional feature so that
           // we can manually modify the data in ListView
           // It may be triggered by hitting any key or double-click etc.
           ui->listView_2->
                   setEditTriggers(QAbstractItemView::AnyKeyPressed |
                                   QAbstractItemView::DoubleClicked);

}

void listcar::on_listView_2_clicked()
{
    QModelIndexList list = ui->listView_2->selectionModel()->selectedIndexes();

       QStringList slist;
       foreach(const QModelIndex &index, list)
       {
           slist.append( index.data(Qt::DisplayRole ).toString());
       }
    // Create model
        model3 = new QStringListModel(this);

        // Make data
        QStringList List = sendmodel(slist);
        // Populate our model
        model3->setStringList(List);

        // Glue model and view together
        ui->listView_3->setModel(model3);

        // Add additional feature so that
        // we can manually modify the data in ListView
        // It may be triggered by hitting any key or double-click etc.
        ui->listView_3->
                setEditTriggers(QAbstractItemView::AnyKeyPressed |
                                QAbstractItemView::DoubleClicked);
}

void listcar::on_listView_3_clicked()
{
    QModelIndexList list = ui->listView_3->selectionModel()->selectedIndexes();

       QStringList slist;
       foreach(const QModelIndex &index, list)
       {
           slist.append( index.data(Qt::DisplayRole ).toString());
       }

    showcar = new ShowCar(this);
    showcar->SetList(slist);
    showcar->show();
}
