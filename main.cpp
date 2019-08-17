#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickStyle>
#include <QIcon>

#include "root.h"

int main(int argc, char *argv[])
{
    qmlRegisterType<Calculator::Root>("Calculator", 1, 0, "Root");

    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);
    //app.setWindowIcon(QIcon("/Zer0Black.png"));
    QQmlApplicationEngine engine;

    QQuickStyle::setStyle("Universal");

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
