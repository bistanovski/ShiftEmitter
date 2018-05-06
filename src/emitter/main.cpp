#include <QQmlContext>
#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <QDebug>

#include "Utility.hpp"
#include "ShiftSettings.hpp"
#include "receptor-bridge/ReceptorBridge.hpp"
#include "simulator/SimulatedReceptorBridge.hpp"
#include "models/ReceptorsModel.hpp"

auto fillReceptorsModel = [](ReceptorsModel &model, QQmlContext *ctxt, const QObjectList &data)
{
    model.fillReceptorsData(data);
    model.registerQmlModel(ctxt);
};

auto registerQuickComponents = [](const bool &isSimulatorUsed)
{
    if(isSimulatorUsed) {
        SimulatedReceptorBridge::registerQuickComponents();
    }
    else {
        ReceptorBridge::registerQuickComponents();
    }
};

int main(int argc, char *argv[])
{
    QGuiApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    const auto deviceUUID = ShiftUtils::generateDeviceUUID();
    qDebug() << "Device UUID: " << deviceUUID;

    QQmlApplicationEngine engine;
    QQmlContext *rootContext = engine.rootContext();

    ReceptorsModel receptorsModel;
    ShiftSettings settings;
    settings.registerQmlSettings(rootContext);
    settings.setDeviceUUID(deviceUUID);

    auto registerComponentsAndModel = [&settings, &receptorsModel, rootContext]() {
        registerQuickComponents(settings.isSimulatorUsed());
        fillReceptorsModel(receptorsModel, rootContext, (settings.isSimulatorUsed() ? SimulatedReceptorBridge::fetchReceptorInfos(&receptorsModel) : ReceptorBridge::fetchReceptorInfos(&receptorsModel)));
    };

    QObject::connect(&settings, &ShiftSettings::usingSimulatorChanged, registerComponentsAndModel);
    registerComponentsAndModel();

    engine.load(QUrl(QLatin1String("qrc:/qml/main.qml")));

    return app.exec();
}
