#ifndef IMAGEN_H
#define IMAGEN_H

#include <QFrame>
#include <qgraphicsscene.h>
#include <QObject>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>



namespace Ui {
class Imagen;
}

class Imagen : public QFrame
{
    Q_OBJECT

public:
    explicit Imagen(QWidget *parent = 0);
    ~Imagen();
    void loadUbic(QString ubic);
    void loadUrl(QString url);
    void makeRequests(QString endPointRequest);

signals:
    void dataReadyRead(QByteArray);
public slots:
    void readyRead(QNetworkReply *reply);

private slots:
    void on_close_clicked();

private:
    Ui::Imagen *ui;
    QGraphicsScene *scene;
    QNetworkAccessManager *manager = new QNetworkAccessManager();
};

#endif // IMAGEN_H
