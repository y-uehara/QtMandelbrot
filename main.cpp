#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "SizeSettings.h"
#include "FractalDrawer.h"
#include "FractalImageProvider.h"

int main(int argc, char *argv[])
{
    //QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    SizeSettings sizeSettings;
    FractalDrawer fractalDrawer(sizeSettings.getCanvasWidth(), sizeSettings.getCanvasHeight());
    auto *fractalImageProvider = new FractalImageProvider(&fractalDrawer, sizeSettings.getCanvasWidth(), sizeSettings.getCanvasHeight());


    QQmlApplicationEngine engine;

    engine.rootContext()->setContextProperty("sizeSettings", &sizeSettings);

    engine.addImageProvider(QLatin1String("fractalDrawer"), fractalImageProvider);
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
