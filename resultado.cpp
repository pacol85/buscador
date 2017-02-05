#include "resultado.h"
#include "ui_resultado.h"
#include <QListWidget>
#include <QListWidgetItem>
#include <QDebug>
#include <QPixmap>
#include <filedownloader.h>
#include <imagen.h>

resultado::resultado(QWidget *parent) :
    QMainWindow(parent, Qt::FramelessWindowHint | Qt::WindowSystemMenuHint
                | Qt::WindowStaysOnTopHint),

    ui(new Ui::resultado)
{
    ui->setupUi(this);
    //QStringList titulos;

    //ui->tabla->alternatingRowColors() = true;
    //titulos << "Codigo" << "Nombre" << "Ubicacion" << "Color" << "Existencia";

    //ui->tabla->setHorizontalHeaderLabels(titulos);

    connect(this, SIGNAL(on_tabla2_itemDoubleClicked()), this, SLOT(cargarImagen()));
}

resultado::~resultado()
{
    delete ui;
}

void resultado::llenarTabla(QString tbuscar){

    QStringList claves;
    QRegExp reg("\\s");
    claves = tbuscar.split(reg);
    //Query para los que no se encuentran
    QString queryText = "SELECT p.pr_codigo, p.pr_nombre, p.pr_ubicacion, p.pr_existencia, cxp.cp_existencia, col.co_nombre "
                        "FROM cr_productos as p, cr_colorxproducto as cxp, cr_colores as col "
                        "WHERE p.pr_codigo = cxp.pr_codigo and cxp.co_codigo = col.co_codigo "
                        "AND cxp.cp_existencia = 0 ";
    foreach (QString clave, claves) {
        queryText += "AND (p.pr_codigo LIKE '%" + clave + "%' OR p.pr_nombre LIKE '%" + clave + "%' "
                "OR col.co_nombre LIKE '%" + clave + "%' OR col.co_codigo LIKE '%" + clave + "%')";
    }

    //qDebug() << queryText;
    //Query para los que sí se encuentran
    QString queryText2 = "SELECT p.pr_codigo, p.pr_nombre, p.pr_ubicacion, p.pr_existencia, cxp.cp_existencia, col.co_nombre "
                        "FROM cr_productos as p, cr_colorxproducto as cxp, cr_colores as col "
                        "WHERE p.pr_codigo = cxp.pr_codigo and cxp.co_codigo = col.co_codigo "
                        "AND cxp.cp_existencia = 1 ";
    foreach (QString clave, claves) {
        queryText2 += "AND (p.pr_codigo LIKE '%" + clave + "%' OR p.pr_nombre LIKE '%" + clave + "%' "
                "OR col.co_nombre LIKE '%" + clave + "%' OR col.co_codigo LIKE '%" + clave + "%')";
    }

    //qDebug() << queryText2;

    buscar(queryText, ui->tabla);
    buscar(queryText2, ui->tabla2);

}

void resultado::buscar(QString queryText, QListWidget* tabla){
    QSqlQuery query;
    query.exec(queryText);

    int row = 0;
    tabla->clear();
    while (query.next()) {
        QString fila = "";
        fila = fila + query.value(0).toString() + " - " + query.value(1).toString() +
                " - " + query.value(5).toString();
        QListWidgetItem *newItem = new QListWidgetItem;
        newItem->setText(fila);
        tabla->insertItem(row,newItem);
        row++;
        qDebug() << fila;
    }
}

void resultado::on_tabla_itemDoubleClicked(QListWidgetItem *item)
{
    QString texto = item->text();
    QStringList items = texto.split(" - ");
    QString prod = items[0];
    qDebug() << prod;

/*
    QUrl imageUrl("http://farm5.static.flickr.com/4101/4798839454_725882374d_b.jpg");

    m_pImgCtrl = new FileDownloader(imageUrl, this);

    connect(m_pImgCtrl, SIGNAL (downloaded()), this, SLOT (loadImage()));*/
}

void resultado::on_tabla2_itemDoubleClicked(QListWidgetItem *item)
{
    QString texto = item->text();
    QStringList items = texto.split(" - ");
    QString prod = items[0];
    qDebug() << prod;

    QString queryText = "select url, pr_ubicacion from cr_productos where pr_codigo = '" + prod + "'";
    QSqlQuery query;
    query.exec(queryText);

    QString urlImagen = "";
    while (query.next()) {
        QString result = "";
        result = result + query.value(0).toString() + ", " + query.value(1).toString();
        qDebug() << result;

        if(query.value(0).toString() != ""){
            urlImagen = query.value(0).toString();
        }

        //im.loadUrl(query.value(0).toString());
        /*im.makeRequests("https://dl.dropboxusercontent.com/u/4397/albImagenes/lanababy.png");
        //prueba de uso de networkManager
        connect(&im, SIGNAL(dataReadyRead(QByteArray)), this, SLOT(dataInTheHouse(QByteArray)));

        im.loadUbic(query.value(1).toString());
        im.move(pos().x(), pos().y() + ui->tabWidget->height());
        im.show();*/
    }

    //abrir la pantalla de imagen
    if(urlImagen != ""){
        im.show();

        im.imagenes(urlImagen);
    }


}

void resultado::dataInTheHouse(QByteArray data)
{
    QString dataString;
    dataString = data;
    qDebug() << dataString;
}
/*
void resultado::cargarImagen()
{
    //abrir la pantalla de imagen
    im.show();
    //cargar imagen en im
    QUrl imageUrl(urlImagen);

    m_pImgCtrl = new FileDownloader(imageUrl, this);
    im.imagenes(m_pImgCtrl);
    //connect(m_pImgCtrl, SIGNAL (downloaded()), this, SLOT (loadImage()));
}

*/
