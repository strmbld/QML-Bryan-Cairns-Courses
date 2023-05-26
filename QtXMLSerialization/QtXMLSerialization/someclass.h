#ifndef SOMECLASS_H
#define SOMECLASS_H


#include <QObject>
#include <QMap>


class SomeClass : public QObject
{
private:
    Q_OBJECT


    QString m_name;
    QMap<QString, QString> m_map;

public:
    explicit SomeClass(QObject *parent = nullptr);


    void fill();
    inline QString name() const { return m_name; }
    inline void set_name(QString value) { m_name = value; }
    inline QMap<QString, QString> map() const { return m_map; }
    inline void set_map(QMap<QString, QString> new_map) { m_map = new_map; }

    friend QDataStream& operator << (QDataStream& out_stream, const SomeClass& obj)
    {
        out_stream << obj.m_name;
        out_stream << obj.m_map;

        return out_stream;
    }

    friend QDataStream& operator >> (QDataStream& in_stream, SomeClass& obj)
    {
        in_stream >> obj.m_name;
        in_stream >> obj.m_map;

        return in_stream;
    }
};

#endif // SOMECLASS_H
