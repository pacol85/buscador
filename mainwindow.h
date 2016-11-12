#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMouseEvent>
#include <QObject>
#include <QSqlQuery>
#include "resultado.h"
#include <QScrollArea>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void mouseMoveEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    void mousePressEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    void returnPressed();


protected slots:
    void buscar();

signals:
    void on_texto_returnPressed();
    void nuevaTabla();

private slots:
    void on_clear_pressed();

private:
    QPoint dragPosition;
    resultado res;

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
