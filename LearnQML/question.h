#ifndef QUESTION_H
#define QUESTION_H

#include <QObject>
#include "answer.h"

class Question : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString content READ content WRITE setContent)
    Q_PROPERTY(QString id READ id WRITE setId)
    Q_PROPERTY(QString explain READ explain WRITE setExplain)

   // Q_PROPERTY(QVariantList answers READ answers WRITE setAnswers  )

public:
    explicit Question(QObject *parent = nullptr);


    QString content() const;
    void setContent(const QString &content);

    QString id() const;
    void setId(const QString &id);

    QString explain() const;
    void setExplain(const QString &explain);

signals:

public slots:

private:
    QString         m_id;
    QString         m_content;
    QString         m_explain;
};

#endif // QUESTION_H
