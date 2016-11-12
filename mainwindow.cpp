#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtSql/QSqlQuery>
#include <QDebug>
#include <QString>
#include <QKeyEvent>
#include <resultado.h>

//QString tBuscar = "";

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent, Qt::FramelessWindowHint | Qt::WindowSystemMenuHint
                | Qt::WindowStaysOnTopHint),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QAction *quitAction = new QAction(tr("S&alir"), this);
    quitAction->setShortcut(tr("Ctrl+Q"));
    connect(quitAction, SIGNAL(triggered()), qApp, SLOT(quit()));
    addAction(quitAction);

    //QAction *enterAction = new QAction(tr("Enter"), this);
    //quitAction->setShortcut(Qt::Key_Enter);
    connect(this, SIGNAL(on_texto_returnPressed()), this, SLOT(buscar()));


    //connect(this, SIGNAL(nuevaTabla()), &res, SLOT(&res.llenarTabla(tbuscar);));

    setContextMenuPolicy(Qt::ActionsContextMenu);
    setToolTip(tr("Arrastra la ventana con el click izquierdo.\n"
                  "Usa click derecho para abrir el menú."));
    setWindowTitle(tr("Buscador de inventario"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        dragPosition = event->globalPos();//event->globalPos();
        event->accept();
    }
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    if (event->buttons() & Qt::LeftButton) {
        move(event->globalPos());// - dragPosition);
        event->accept();
    }
}


void MainWindow::buscar()
{
    QString text = ui->texto->text();

    if (text.isEmpty())
            return;

    //tBuscar = text;

    //emit nuevaTabla();
    //resultado res;
    res.llenarTabla(text);
    res.move(pos().x(), pos().y() + ui->texto->height());//res.move());
    res.show();

    //int r = res.exec();
    return;
}


void MainWindow::on_clear_pressed()
{
    ui->texto->setText("");

    res.hide();
}
