#include "imagen.h"
#include "ui_imagen.h"
#include <QtGui>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>

Imagen::Imagen(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::Imagen)
{
    ui->setupUi(this);
    scene = new QGraphicsScene;
    connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(readyRead(QNetworkReply*)));
}

Imagen::~Imagen()
{
    delete ui;
}

void Imagen::on_close_clicked()
{
    this->hide();
}

void Imagen::loadUbic(QString ubic){
    ui->ubicacion->setText(ubic);
}

void Imagen::loadUrl(QString url){
    url = "";
/*
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    connect(manager, SIGNAL(finished(QNetworkReply*)),
            this, SLOT(replyFinished(QNetworkReply*)));

    QNetworkReply *response = manager->get(QNetworkRequest(QUrl(url)));

    qDebug() << response->size();
    QPixmap pixmap(manager);
    scene->addPixmap(pixmap);
    ui->foto->setScene(scene);

    QGraphicsScene scene;
    QPixmap pm;
    pm.load("C:\\Users\\USUARIO\\Dropbox\\Public\\albImagenes\\lanababy.png");
    scene.addPixmap(pm);
    ui->foto->setScene(scene);*/
}

void Imagen::makeRequests(QString endPointRequest){
    manager->get(QNetworkRequest(QUrl(endPointRequest)));//"https://dl.dropboxusercontent.com/u/4397/albImagenes/lanababy.png");
}

void Imagen::readyRead(QNetworkReply *reply){
    QByteArray myData;
    myData = reply->readAll();
    emit(dataReadyRead(myData));
}
