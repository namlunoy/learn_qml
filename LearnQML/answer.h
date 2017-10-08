#ifndef ANSWER_H
#define ANSWER_H

#include <QObject>

class Answer : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString id READ id WRITE setId)
    Q_PROPERTY(QString content READ content WRITE setContent)
    Q_PROPERTY(QString hint READ hint WRITE setHint)
    Q_PROPERTY(bool isCorrect READ isCorrect WRITE setIsCorrect)

public:
    explicit Answer(QObject *parent = nullptr);

    QString content() const;
    void setContent(const QString &content);

    bool isCorrect() const;
    void setIsCorrect(bool isCorrect);

    QString id() const;
    void setId(const QString &id);

    QString hint() const;
    void setHint(const QString &hint);

signals:

public slots:

private:
    QString m_id;
    QString m_content;
    QString m_hint;
    bool    m_isCorrect;
};

#endif // ANSWER_H
