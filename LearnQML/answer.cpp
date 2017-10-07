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
