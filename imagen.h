#ifndef IMAGEN_H
#define IMAGEN_H

#include <QFrame>
#include <filedownloader.h>

namespace Ui {
class Imagen;
}

class Imagen : public QFrame
{
    Q_OBJECT

public:
    explicit Imagen(QWidget *parent = 0);
    ~Imagen();
    void imagenes(QString urlImagen, QString bodega, QString pasillo, QString caja, QString codigo);

private slots:
    void loadImage();


    void on_Imagen_resized(bool );

private:
    Ui::Imagen *ui;
    FileDownloader * m_pImgCtrl;

};

#endif // IMAGEN_H
