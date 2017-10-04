#include "lesson.h"

Lesson::Lesson(QObject *parent) : QObject(parent)
{

}

Lesson::Lesson(const Lesson &other)
{
    m_id = other.m_id;;
    m_title = other.m_title;;
    m_url = other.m_url;;
    m_content = other.m_content;;
}

int Lesson::id() const
{
    return m_id;
}

void Lesson::setId(int id)
{
    m_id = id;
}

QString Lesson::title() const
{
    return m_title;
}

void Lesson::setTitle(const QString &title)
{
    m_title = title;
}

QString Lesson::url() const
{
    return m_url;
}

void Lesson::setUrl(const QString &url)
{
    m_url = url;
}

QString Lesson::content() const
{
    return m_content;
}

void Lesson::setContent(const QString &content)
{
    m_content = content;
}
