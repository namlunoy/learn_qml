#ifndef QUESTION_H
#define QUESTION_H

#include <QObject>
#include "answer.h"

class Question : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString content READ content WRITE setContent  )
    Q_PROPERTY(QString id READ id WRITE setId  )
   // Q_PROPERTY(QVariantList answers READ answers WRITE setAnswers  )

public:
    explicit Question(QObject *parent = nullptr);


    QString content() const;
    void setContent(const QString &content);

    QString id() const;
    void setId(const QString &id);

    //QVariantList answers() const;
    //void setAnswers(const QVariantList &answers);

signals:

public slots:

private:
    QString         m_id;
    QString         m_content;
    //QVariantList    m_answers;
};

#endif // QUESTION_H
