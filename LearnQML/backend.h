#ifndef BACKEND_H
#define BACKEND_H

#include <QObject>
#include <QString>
#include <QSqlDatabase>
#include <QtDebug>
#include <QSqlQuery>
#include <QList>
#include <list>
#include <vector>
#include "lesson.h"

class Backend : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString userName READ userName WRITE setUserName NOTIFY userNameChanged)
    // marco này dùng để chỉ ra những thuộc tính nào có thể truy cập được từ QML

public:
    explicit    Backend(QObject *parent = nullptr);

    QString     userName();
    void        setUserName(const QString& userName);
    Backend*     getInstance();

    Q_INVOKABLE QVariantList getAllLesson();

signals:
    void        userNameChanged();

public slots:

private:
    static Backend* _instance;

    QString                 m_userName;
    QSqlDatabase            m_db;
    //std::list<Lesson>       m_lesson;
    //QList<Lesson>       m_lesson;
    QVariantList            m_lesson;

    static const QString DB_DRIVER;
    static const QString DB_PATH;
    static const QString DB_NAME;

};

#endif // BACKEND_H
