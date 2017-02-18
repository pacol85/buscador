#include "imagen.h"
#include "ui_imagen.h"
#include "filedownloader.h"

Imagen::Imagen(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::Imagen)
{
    ui->setupUi(this);
}

Imagen::~Imagen()
{
    delete ui;
}

void Imagen::imagenes(QString urlImagen, QString bodega, QString pasillo, QString caja, QString codigo){
    //cargar ubicación para imagen
    QString ubicacion = "Bodega: ";
    ubicacion += bodega;
    ubicacion += "\nPasillo: ";
    ubicacion += pasillo;
    ubicacion += "\nCaja: ";
    ubicacion += caja;
    ui->lbl_ubicacion->setText(ubicacion);
    ui->lbl_estilo->setText(codigo);

    //cargar imagen en im
    QUrl imageUrl(urlImagen);
    m_pImgCtrl = new FileDownloader(imageUrl, this);
    connect(m_pImgCtrl, SIGNAL (downloaded()), this, SLOT (loadImage()));
}

void Imagen::loadImage()
{
    QPixmap buttonImage;
    buttonImage.loadFromData(m_pImgCtrl->downloadedData());
    ui->lbl_imagen->setPixmap(buttonImage);
}

void Imagen::on_Imagen_resized(bool )
{

}
