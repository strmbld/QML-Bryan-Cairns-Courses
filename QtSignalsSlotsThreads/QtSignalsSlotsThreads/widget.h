#ifndef WIDGET_H
#define WIDGET_H


#include <QObject>
#include <QRunnable>
#include <QThread>
#include <QDebug>


class Widget : public QObject, public QRunnable
{
private:
    Q_OBJECT

    bool m_is_sender;
    bool m_is_active;

public:
    explicit Widget(QObject *parent = nullptr);


    void run() override;

    inline bool is_sender() const { return m_is_sender; }
    inline void set_is_sender(bool is_sender) { m_is_sender = is_sender; }

public slots:
    void work_started();
    void work_finished();
    void work_ready(int i);

signals:
    void started();
    void finished();
    void update(int i);
};

#endif // WIDGET_H
