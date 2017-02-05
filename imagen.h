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
    void imagenes(QString urlImagen);

private slots:
    void loadImage();


private:
    Ui::Imagen *ui;
    FileDownloader * m_pImgCtrl;

};

#endif // IMAGEN_H
