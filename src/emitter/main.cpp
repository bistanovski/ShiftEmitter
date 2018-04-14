#include <QQmlContext>
#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <QDebug>

#include "receptor-bridge/Receptor.hpp"
#include "receptor-bridge/ReceptorNetwork.hpp"

int main(int argc, char *argv[])
{
    QGuiApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    ContextData cData;

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextObject(&cData);
    engine.load(QUrl(QLatin1String("qrc:/qml/main.qml")));
    if (engine.rootObjects().isEmpty())
    {
        qWarning() << "Root QML object is not created";
    }

    const auto receptors = ReceptorNetwork::fetchAllReceptors();
    cData.setFoundSensors(static_cast<int>(receptors.size()));

    for(const auto &receptor : receptors)
    {
        cData.appendFoundType(QString(receptor->getType()));
        cData.appendFoundIdentifier(QString(receptor->getIdeintifier()));
    }

    return app.exec();
}
