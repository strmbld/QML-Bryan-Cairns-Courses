#include "user.h"


User::User(QObject *parent)
    : QObject{parent}
{
    create();
}


bool User::insert()
{
    qInfo() << "Inserting...";

    QSqlQuery query;
    QString cmd = "INSERT INTO `qt6db`.`users` (`name`,`age`) VALUES(:name,:age);";
    query.prepare(cmd);
    query.bindValue(":name", name);
    query.bindValue(":age", age);

    bool ok = exec(query);

    if(ok) {
        id = query.lastInsertId().toInt();
        qInfo() << "Inserted " << id;

        return ok;
    }

    id = 0;

    return ok;
}

bool User::update()
{
    qInfo() << "Updating record#" << id;

    QSqlQuery query;
    QString cmd = "UPDATE `qt6db`.`users` SET `name`=:name, `age`=:age WHERE `idusers`=:id;";
    query.prepare(cmd);
    query.bindValue(":id", id);
    query.bindValue(":name", name);
    query.bindValue(":age", age);

    bool ok = exec(query);

    ok ? qInfo() << "Updated record#" << id : qInfo() << "Failed to update record#" << id;

    return ok;
}

bool User::exec(QSqlQuery &query)
{
    QSqlDatabase db = QSqlDatabase::database();
    if(!db.isOpen()) {
        qInfo() << "Connection is not open!";

        return false;
    }

    qInfo() << "Exec: " << query.executedQuery();
    bool ok = query.exec();

    if(!ok) {
        qInfo() << db.lastError().text();
        qInfo() << query.lastError().text();
    }

    return ok;
}

void User::begin()
{
    QSqlDatabase::database().transaction();
}

void User::commit()
{
    QSqlDatabase::database().commit();
}

void User::rollback()
{
    QSqlDatabase::database().rollback();
}

bool User::open()
{
    QSqlDatabase db = QSqlDatabase::database();
    bool isOpen = db.isOpen();

    qInfo() << "isOpen: " << isOpen;

    return isOpen;
}

void User::create()
{
    id = 0;
    age = 0;
    name = "";
}

void User::load(int id)
{
    qInfo() << "Loading user with id: " << id;
    QSqlQuery query;
    QString cmd = "SELECT idusers, age, name FROM qt6db.users WHERE idusers =:id;";
    query.prepare(cmd);
    query.bindValue(":id", id);

    bool ok = exec(query);

    if(ok) {
        while (query.next()) {
            QSqlRecord record = query.record();
            id = record.value(0).toInt();
            age = record.value(1).toInt();
            name = record.value(2).toString();

            return;
        }
    }

    qInfo() << "Failed to load. Error: " << query.lastError().text();
}

void User::save()
{
    id > 0 ? update() : insert();
}

void User::remove()
{
    QSqlQuery query;
    QString cmd = "DELETE FROM qt6db.users WHERE idusers = :id";
    query.prepare(cmd);
    query.bindValue(":id", id);

    exec(query);
}

