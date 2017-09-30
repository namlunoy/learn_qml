#ifndef BACKEND_H
#define BACKEND_H

#include <QObject>
#include <QString>

class BackEnd : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString userName READ userName WRITE setUserName NOTIFY userNameChanged)
    // marco này dùng để chỉ ra những thuộc tính nào có thể truy cập được từ QML

public:
    explicit BackEnd(QObject *parent = nullptr);

    QString userName();
    void setUserName(const QString& userName);

signals:
    void userNameChanged();

public slots:

private:
    QString m_userName;
};

#endif // BACKEND_H
