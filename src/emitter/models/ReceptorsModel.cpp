#include "ReceptorsModel.hpp"

#include <QDebug>
#include <QQmlContext>

ReceptorsModel::ReceptorsModel(QObject *parent) : QObject(parent)
{

}

ReceptorsModel::~ReceptorsModel()
{

}

void ReceptorsModel::fillReceptorsData(const QObjectList &receptors)
{
    m_receptorsList = receptors;
}

void ReceptorsModel::registerModel(QQmlContext *ctxt)
{
    ctxt->setContextProperty("receptorsModel", QVariant::fromValue(m_receptorsList));
}
