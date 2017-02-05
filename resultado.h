#ifndef RESULTADO_H
#define RESULTADO_H

#include <QMainWindow>
#include <QSqlQuery>
#include <QString>
#include <QListWidget>
#include <filedownloader.h>
#include <imagen.h>


namespace Ui {
class resultado;
}

class resultado : public QMainWindow
{
    Q_OBJECT

public:
    explicit resultado(QWidget *parent = 0);
    ~resultado();

//protected slots:
    void llenarTabla(QString tbuscar);
    void buscar(QString queryText, QListWidget *tabla);
    //void cargarImagen();

//protected:
    //void agregaItem(QString valor, int row, int column);

private slots:
    void on_tabla_itemDoubleClicked(QListWidgetItem *item);
    void on_tabla2_itemDoubleClicked(QListWidgetItem *item);
    void dataInTheHouse(QByteArray data);

private:
    Ui::resultado *ui;
    FileDownloader * m_pImgCtrl;
    Imagen im;
};

#endif // RESULTADO_H
