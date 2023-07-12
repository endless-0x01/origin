#include <QApplication>
#include <QtNetwork/QNetworkAccessManager>
#include <QtSql/QSqlDatabase>
#include <iostream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QNetworkAccessManager networkManager;

    QSqlDatabase database = QSqlDatabase::addDatabase("QSQL");

    std::cout << "object created" << std::endl;
    return a.exec();
}
