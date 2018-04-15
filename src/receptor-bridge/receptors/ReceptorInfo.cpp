#include "ReceptorInfo.hpp"

ReceptorInfo::ReceptorInfo(const QByteArray &type, const QByteArray &identifier, QObject *parent) : QObject(parent),
    m_type(type),
    m_identifier(identifier)
{
    emit typeChanged();
    emit identifierChanged();
}

ReceptorInfo::~ReceptorInfo()
{

}

QByteArray ReceptorInfo::getType() const
{
    return m_type;
}

QByteArray ReceptorInfo::getIdentifier() const
{
    return m_identifier;
}
