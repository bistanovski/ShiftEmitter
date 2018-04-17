#include "ReceptorFactory.hpp"

#include "ReceptorInfo.hpp"

ReceptorInfo *ReceptorFactory::createReceptorInfo(const QByteArray &type, const QByteArray &identifier, QObject *targetParent)
{
    return std::move(new ReceptorInfo(type, identifier, targetParent));
}
