#include "backend.h"
#include <QDir>

const QString Backend::DB_PATH = ":/data/basic_english_grammar.db";
const QString Backend::DB_DRIVER = "QSQLITE";
const QString Backend::DB_NAME = "basic_english_grammar.db";

Backend::Backend(QObject *parent) : QObject(parent)
{
    m_userName = "xxx";

    QString dbfilepath = QDir::currentPath()+"/"+DB_NAME;
    qDebug() << dbfilepath ;
    m_userName = dbfilepath;

    if(QFile::exists(dbfilepath) == false){
        qDebug()  << "Copying database ... ";
        QFile::copy(DB_PATH,dbfilepath);
        QFile::setPermissions(dbfilepath, QFile::ReadOwner | QFile::WriteOwner);
    }else{
        qDebug() << "database already exist!";
    }


    if(QSqlDatabase::isDriverAvailable(DB_DRIVER))
        qDebug() << "Driver ok!";
    else qDebug() << "Doesnt has driver!";
    m_db = QSqlDatabase::addDatabase(DB_DRIVER);

    m_db.setDatabaseName(DB_NAME);
    m_db.open();

    if(m_db.isOpen())
        qDebug() << "Open successfull!";
    else qDebug() << "Open DB failed!";

    QSqlQuery query;
    query.prepare("select * from lesson");
    if(query.exec() == false)
        qDebug() << "Execure the query failed!";
    else {
        qDebug() << "Execure done ok!" << query.size();
        while (query.next()) {
                QString country = query.value(0).toString();
                qDebug() << country;
                //m_userName += (" " + country);
            }
    }



}

QString Backend::userName()
{
    return m_userName;
}

void Backend::setUserName(const QString &userName)
{
    if(m_userName == userName)
        return;
    m_userName = userName;
    emit userNameChanged(); //rase event
}

void Backend::readDatabase()
{

}
