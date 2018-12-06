#include <QQmlContext>
#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <QDebug>

#include "Utility.hpp"
#include "ShiftSettings.hpp"
#include "network/RestClient.hpp"
#include "network/AmqpClient.hpp"
#include "models/ReceptorsModel.hpp"
#include "receptor-bridge/ReceptorInfo.hpp"
#include "network/TelemetryTransporter.hpp"
#include "receptor-bridge/ReceptorBridge.hpp"
#include "simulator/SimulatedReceptorBridge.hpp"

auto fillReceptorsModel = [](ReceptorsModel &model, QQmlContext *ctxt, const QObjectList &data)
{
    for(const auto d : qAsConst(data))
    {
        const auto info = qobject_cast<const ReceptorInfo*>(d);
        qDebug() << "ReceptorReadings:" << info->getFriendlyName() << info->getReadings();
    }
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

#ifdef SHIFT_ANDROID
    qputenv("QT_SCALE_FACTOR", "0.85");
#endif

    QGuiApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    QQmlContext *rootContext = engine.rootContext();

    ShiftSettings settings;
    settings.registerQmlSettings(rootContext);
    settings.setDeviceUUID(ShiftUtils::generateDeviceUUID());
    settings.setOSName(ShiftUtils::operatingSystemName());
    settings.setOSVersion(ShiftUtils::operatingSystemVersion());

    TelemetryTransporter telTransporter;
    telTransporter.registerQmlTransporter(rootContext);

    AmqpClient amqpClient(settings.getDeviceUUID());
    amqpClient.registerQmlClient(rootContext);

    RestClient restClient;
    restClient.registerQmlRestClient(rootContext);

    ReceptorsModel receptorsModel;
    auto registerComponentsAndModel = [&settings, &receptorsModel, rootContext]() {
        registerQuickComponents(settings.isSimulatorUsed());
        fillReceptorsModel(receptorsModel, rootContext, (settings.isSimulatorUsed() ? SimulatedReceptorBridge::fetchReceptorInfos(&receptorsModel) : ReceptorBridge::fetchReceptorInfos(&receptorsModel)));
    };

    QObject::connect(&settings, &ShiftSettings::usingSimulatorChanged, registerComponentsAndModel);
    registerComponentsAndModel();

    engine.load(QUrl(QLatin1String("qrc:/qml/main.qml")));

    return app.exec();
}
