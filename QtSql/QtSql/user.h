
#ifndef USER_H
#define USER_H


#include <QObject>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlError>


class User : public QObject
{
private:
    Q_OBJECT

    bool insert();
    bool update();
    bool exec(QSqlQuery& query);

public:
    explicit User(QObject *parent = nullptr);

    int id;
    int age;
    QString name;

    void begin();
    void commit();
    void rollback();
    bool open();
    void create();
    void load(int id);
    void save();
    void remove();

signals:

};

#endif // USER_H
