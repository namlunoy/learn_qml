#include "answer.h"

Answer::Answer(QObject *parent) : QObject(parent)
{

}

QString Answer::content() const
{
    return m_content;
}

void Answer::setContent(const QString &content)
{
    m_content = content;
}

bool Answer::isCorrect() const
{
    return m_isCorrect;
}

void Answer::setIsCorrect(bool isCorrect)
{
    m_isCorrect = isCorrect;
}

QString Answer::id() const
{
    return m_id;
}

void Answer::setId(const QString &id)
{
    m_id = id;
}

QString Answer::hint() const
{
    return m_hint;
}

void Answer::setHint(const QString &hint)
{
    m_hint = hint;
}
