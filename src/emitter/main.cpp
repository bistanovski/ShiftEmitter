#include <QQmlContext>
#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <QDebug>

#include "receptor-bridge/receptors/Receptor.hpp"
#include "receptor-bridge/ReceptorBridge.hpp"
#include "models/ReceptorsModel.hpp"

int main(int argc, char *argv[])
{
    QGuiApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QLatin1String("qrc:/qml/main.qml")));

    ReceptorsModel receptorsModel;
    receptorsModel.fillReceptorsData(ReceptorBridge::fetchReceptorInfos(&receptorsModel));
    receptorsModel.registerModel(engine.rootContext());

    return app.exec();
}
