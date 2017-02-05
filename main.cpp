#include "mainwindow.h"
#include <QApplication>
#include <QtSql/QSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlDriver>
#include <QtSql/QSqlQuery>
#include <QDebug>
#include <QWidget>

bool createConnection();

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    if (!createConnection()){

        qDebug() << "Not connected!";
        //return 1;
    }
    else{

        qDebug() << "Connected!";
 /*
        QSqlQuery query;
        query.exec("SELECT name FROM student");

        while (query.next()) {
            QString name = query.value(0).toString();
            qDebug() << "name:" << name;
        }
 */
        //return 0;
    }

    return a.exec();
}

bool createConnection(){
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("jupiter.whfweb.com");//("node02.facesharedus1.com");
    //db.setPort(2083);
    db.setDatabaseName("nllsxjwy_controlruta");
    db.setUserName("nllsxjwy_cr");
    db.setPassword("L1b3rt4d#");
    /*db.setHostName("localhost");
    db.setDatabaseName("controlruta");
    db.setUserName("root");
    db.setPassword("");*/
    if (!db.open()) {
        printf("Database error occurred");
        return false;
    }else{
        printf("Coneccion exitosa");
    }
    return true;
}
