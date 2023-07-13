#include <QtNetwork/QNetworkAccessManager>
#include <QtSql/QSqlDatabase>
#include <iostream>

int main(int argc, char *argv[])
{
    QNetworkAccessManager networkManager;

    QSqlDatabase database = QSqlDatabase::addDatabase("QSQL");

    std::cout << "object created" << std::endl;
    return 0;
}
