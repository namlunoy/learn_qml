#ifndef MYFIRSTQOBJECT_H
#define MYFIRSTQOBJECT_H

#include <QObject>

class MyFirstQObject : public QObject
{
    Q_OBJECT
public:
    explicit MyFirstQObject(QObject *parent = nullptr);

signals:

public slots:
};

#endif // MYFIRSTQOBJECT_H