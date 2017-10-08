#include "backend.h"
#include <QDir>

const QString Backend::DB_PATH = ":/data/basic_english_grammar.db";
const QString Backend::DB_DRIVER = "QSQLITE";
const QString Backend::DB_NAME = "basic_english_grammar.db";

Backend* Backend::_instance = NULL;

Backend::Backend(QObject *parent) : QObject(parent)
{
    if(_instance == NULL){
        qDebug() << "Init";
        QString dbfilepath = QDir::currentPath()+"/"+DB_NAME;
        qDebug() << dbfilepath ;

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

        if(m_db.isOpen()){
            qDebug() << "Open successfull!";
            _instance = this;
        }else qDebug() << "Open DB failed!";
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

QVariantList Backend::getAllLesson()
{
    if(getInstance()->m_lesson.size() <= 0)
    {
        QSqlQuery query;
        query.prepare("select * from lesson");
        if(query.exec() == false)
            qDebug() << "Execure the query failed!";
        else {
            qDebug() << "Execure done ok!" << query.size();

            getInstance()->m_lesson.clear();

            while (query.next()) {
                Lesson *lesson = new Lesson;
                lesson->setId(query.value("id").toInt());
                lesson->setTitle(query.value("text").toString());
                lesson->setContent(query.value("content").toString());
                lesson->setUrl(query.value("url").toString());
                getInstance()->m_lesson.push_back(qVariantFromValue(lesson));
                //qDebug() << lesson->title();
            }
        }
    }

    return getInstance()->m_lesson;
}

QString Backend::getContent(QString id)
{
    QString result;
    QString sql = "select content from Lesson where id = "+id;
    QSqlQuery query;
    query.prepare(sql);
    qDebug() << "SQL: " << sql;
    if(query.exec() == false){
        qDebug() << "Execute the query failed!";
    }else{
        if(query.first())
            result = query.value("content").toString();
    }
    return result;
}

QVariantList Backend::getAllQuestions(QString lessonId)
{
    QVariantList questions;
    QString sql = "select * from Question where Question.lesson_id = " + lessonId;
    QSqlQuery query;
    query.prepare(sql);
    if(query.exec() == false){
        qDebug() << "Execute failed: " + sql;
    }else{
        while(query.next()){
            Question *quest = new Question;
            quest->setId(query.value("id").toString());
            quest->setContent(query.value("text").toString());
            quest->setExplain(query.value("explan").toString());
            questions.push_back(qVariantFromValue(quest));
            //delete quest;
        }
    }

    return questions;
}

QVariantList Backend::getAllAnswers(QString questionId)
{
    QVariantList answers;
    QString sql = "select * from Answer where Answer.question_id = '" + questionId + "'";
    QSqlQuery query;
    query.prepare(sql);
    if(query.exec() == false)
        qDebug() << "Execute failed! " << sql;
    else{
        while(query.next()){
            Answer *answer = new Answer;
            answer->setContent(query.value("text").toString());
            answer->setHint(query.value("hint").toString());
            answer->setId(query.value("id").toString());
            answer->setIsCorrect(query.value("is_correct").toBool());
            answers.push_back(qVariantFromValue(answer));
        }
    }

    return answers;
}

Backend* Backend::getInstance()
{
    if(_instance == NULL)
        _instance = new Backend();
    return _instance;
}
