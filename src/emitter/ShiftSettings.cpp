#include "ShiftSettings.hpp"

#include <QSettings>
#include <QQmlContext>

Q_GLOBAL_STATIC_WITH_ARGS(QSettings, globalSettings, ("ShiftRay", "ShiftEmitter"))

QLatin1String SIMULATOR_KEY("usedSimulator");

ShiftSettings::ShiftSettings(QObject *parent) : QObject(parent)
{

}

ShiftSettings::~ShiftSettings()
{

}

void ShiftSettings::registerQmlSettings(QQmlContext *ctxt)
{
    ctxt->setContextProperty("ShiftSettings", this);
}

bool ShiftSettings::isSimulatorUsed() const
{
    return globalSettings->value(SIMULATOR_KEY, false).toBool();
}

void ShiftSettings::setIsUsedSimulator(const bool &isUsed)
{
    globalSettings->setValue(SIMULATOR_KEY, isUsed);
    emit usingSimulatorChanged();
}
