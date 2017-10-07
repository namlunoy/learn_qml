#ifndef ANSWER_H
#define ANSWER_H

#include <QObject>

class Answer : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString content READ content WRITE setContent  )
    Q_PROPERTY(bool isCorrect READ isCorrect WRITE setIsCorrect  )
public:
    explicit Answer(QObject *parent = nullptr);

    QString content() const;
    void setContent(const QString &content);

    bool isCorrect() const;
    void setIsCorrect(bool isCorrect);

signals:

public slots:

private:
    QString m_content;
    bool    m_isCorrect;
};

#endif // ANSWER_H
