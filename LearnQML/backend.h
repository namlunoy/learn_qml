#ifndef BACKEND_H
#define BACKEND_H

#include <QObject>
#include <QString>
#include <QSqlDatabase>
#include <QtDebug>
#include <QSqlQuery>

class Backend : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString userName READ userName WRITE setUserName NOTIFY userNameChanged)
    // marco này dùng để chỉ ra những thuộc tính nào có thể truy cập được từ QML

public:
    explicit    Backend(QObject *parent = nullptr);

    QString     userName();
    void        setUserName(const QString& userName);
    void        readDatabase();

signals:
    void        userNameChanged();

public slots:

private:
    QString         m_userName;
    QSqlDatabase    m_db;

    static const QString DB_DRIVER;
    static const QString DB_PATH;
    static const QString DB_NAME;
};

#endif // BACKEND_H
