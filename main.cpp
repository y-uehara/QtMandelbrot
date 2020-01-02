#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "FractalDrawer.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    FractalDrawer fractalDrawer;
    engine.addImageProvider(QLatin1String("fractalDrawer"), &fractalDrawer);
    engine.rootContext()->setContextProperty("fractalDrawer", &fractalDrawer);

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);

    engine.load(url);

    return app.exec();
}