#include "question.h"

Question::Question(QObject *parent) : QObject(parent)
{

}

QString Question::content() const
{
    return m_content;
}

void Question::setContent(const QString &content)
{
    m_content = content;
}

QString Question::id() const
{
    return m_id;
}

void Question::setId(const QString &id)
{
    m_id = id;
}

QString Question::explain() const
{
    return m_explain;
}

void Question::setExplain(const QString &explain)
{
    m_explain = explain;
}
