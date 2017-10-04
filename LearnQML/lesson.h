#ifndef LESSON_H
#define LESSON_H

#include <QObject>

class Lesson : public QObject
{
    Q_OBJECT

public:
    explicit Lesson(QObject *parent = nullptr);
    Lesson(const Lesson& other);

    Q_INVOKABLE int id() const;
    void setId(int id);

    Q_INVOKABLE QString title() const;
    void setTitle(const QString &title);

      QString url() const;
    void setUrl(const QString &url);

    Q_INVOKABLE QString content() const;
    void setContent(const QString &content);

signals:

public slots:

private:
    int         m_id;
    QString     m_title;
    QString     m_url;
    QString     m_content;
};

#endif // LESSON_H
