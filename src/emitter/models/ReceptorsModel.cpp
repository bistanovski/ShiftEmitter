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
    for(auto r : m_receptorsList)
    {
        r->deleteLater();
    };
    m_receptorsList = receptors;
}

void ReceptorsModel::registerQmlModel(QQmlContext *ctxt)
{
    ctxt->setContextProperty("receptorsModel", QVariant::fromValue(m_receptorsList));
}

int ReceptorsModel::numOfReceptors() const
{
    return m_receptorsList.length();
}

const QObjectList &ReceptorsModel::getReceptorsModel()
{
    return m_receptorsList;
}
