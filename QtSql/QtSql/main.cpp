#include <QCoreApplication>
#include <QDebug>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QPluginLoader>
#include <QVariant>
#include <QDateTime>
#include <QRandomGenerator>

#include "user.h"


int createUser()
{
    qInfo() << "Creating new user";

    User user;
    int id = 0;
    if(user.open()) {
        user.begin();
        user.name = "New User " + QDateTime::currentDateTime().toString();
        user.age = QRandomGenerator::global()->bounded(1, 100);

        user.save();
        user.commit();

        id = user.id;
    }

    return id;
}

void loadUser(int id)
{
    qInfo() << "Loading record: " << id;

    User user;
    if(user.open()) {
        user.load(id);
        qInfo() << "Loaded: " << user.name;
    }
}

void do_something()
{
    QSqlQuery query;
    QString cmd = "SELECT idusers, name, age FROM qt6db.users";

    if(!query.exec(cmd)) {
        qInfo() << QSqlDatabase::database().lastError().text();
        qInfo() << query.lastError().text();

        return;
    }

    qInfo() << "query.size(): " << query.size();

    while (query.next()) {
        int id = query.value(0).toInt();
        QString name = query.value(1).toString();
        int age = query.value(2).toInt();

        qInfo() << id << " " << name << " " << age;
    }

    int id = createUser();
    qInfo() << "Created: " << id;

    if(id > 0) {
        loadUser(id);
    }
}

void connectDB()
{
    qInfo() << "Connecting to db";

    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("127.0.0.1");
    db.setPort(3306);
    db.setDatabaseName("qt6db");
    db.setUserName("root");
    db.setPassword("$It#543$never#925$ends");

    if(!db.open()) {
        qInfo() << "Failed to connect to db!";
        qInfo() << db.lastError().text();

        return;
    }

    qInfo() << "Connected!";

    do_something();

    db.close();
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qInfo() << "Inspecting db drivers";

    foreach (QString driverName, QSqlDatabase::drivers()) {
        qInfo() << driverName;

        QSqlDatabase db = QSqlDatabase::addDatabase(driverName);
        QSqlDriver* obj = db.driver();

        qInfo() << "Transactions: " << obj->hasFeature(QSqlDriver::DriverFeature::Transactions);
        qInfo() << "QuerySize: " << obj->hasFeature(QSqlDriver::DriverFeature::QuerySize);
        qInfo() << "BLOB: " << obj->hasFeature(QSqlDriver::DriverFeature::BLOB);
        qInfo() << "Unicode: " << obj->hasFeature(QSqlDriver::DriverFeature::Unicode);
        qInfo() << "PreparedQueries: " << obj->hasFeature(QSqlDriver::DriverFeature::PreparedQueries);
        qInfo() << "NamedPlaceholders: " << obj->hasFeature(QSqlDriver::DriverFeature::NamedPlaceholders);
        qInfo() << "PositionalPlaceholders: " << obj->hasFeature(QSqlDriver::DriverFeature::PositionalPlaceholders);
        qInfo() << "LastInsertId: " << obj->hasFeature(QSqlDriver::DriverFeature::LastInsertId);
        qInfo() << "BatchOperations: " << obj->hasFeature(QSqlDriver::DriverFeature::BatchOperations);
        qInfo() << "SimpleLocking: " << obj->hasFeature(QSqlDriver::DriverFeature::SimpleLocking);
        qInfo() << "LowPrecisionNumbers: " << obj->hasFeature(QSqlDriver::DriverFeature::LowPrecisionNumbers);
        qInfo() << "EventNotifications: " << obj->hasFeature(QSqlDriver::DriverFeature::EventNotifications);
        qInfo() << "FinishQuery: " << obj->hasFeature(QSqlDriver::DriverFeature::FinishQuery);
        qInfo() << "MultipleResultSets: " << obj->hasFeature(QSqlDriver::DriverFeature::MultipleResultSets);
        qInfo() << "CancelQuery: " << obj->hasFeature(QSqlDriver::DriverFeature::CancelQuery);
    }

    connectDB();

    return a.exec();
}
