#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "backend.h"
#include "question.h"
#include "answer.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    //Register class Backend as QML type

    qmlRegisterType<Backend>("CongLibs", 1, 0, "Backend");
    qmlRegisterType<Lesson>("CongLibs", 1, 0, "Lesson");
    qmlRegisterType<Question>("CongLibs", 1, 0, "Question");
    qmlRegisterType<Answer>("CongLibs", 1, 0, "Answer");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QLatin1String("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
