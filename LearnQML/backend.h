#ifndef BACKEND_H
#define BACKEND_H

#include <QObject>
#include <QString>
#include <QSqlDatabase>
#include <QtDebug>
#include <QSqlQuery>
#include "lesson.h"
#include "question.h"
#include "answer.h"

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

    Q_INVOKABLE QVariantList    getAllLesson();
    Q_INVOKABLE QString         getContent(QString id);
    Q_INVOKABLE QVariantList    getAllQuestions(QString lessonId);
    Q_INVOKABLE QVariantList    getAllAnswers(QString questionId);


signals:
    void        userNameChanged();

public slots:

private:
    static Backend* _instance;

    QString                 m_userName;
    QSqlDatabase            m_db;
    QVariantList            m_lesson;

    static const QString DB_DRIVER;
    static const QString DB_PATH;
    static const QString DB_NAME;

};

#endif // BACKEND_H
