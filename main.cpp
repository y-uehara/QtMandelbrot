#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "SizeSettings.h"
#include "FractalDrawer.h"

int main(int argc, char *argv[])
{
    //QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    SizeSettings sizeSettings;
    auto *fractalDrawer = new FractalDrawer(sizeSettings.getCanvasWidth(), sizeSettings.getCanvasHeight());

    QQmlApplicationEngine engine;

    engine.rootContext()->setContextProperty("sizeSettings", &sizeSettings);

    engine.addImageProvider(QLatin1String("fractalDrawer"), fractalDrawer);
    engine.rootContext()->setContextProperty("fractalDrawer", fractalDrawer);

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);

    engine.load(url);

    return app.exec();
}
