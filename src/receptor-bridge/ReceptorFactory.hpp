#ifndef RECEPTORFACTORY_HPP
#define RECEPTORFACTORY_HPP

#include <QScopedPointer>

class Receptor;
class ReceptorInfo;
class QByteArray;
enum class ReceptorType;

namespace ReceptorFactory {
//    Receptor *createReceptor(const QByteArray &type, const QByteArray &identifier, QObject *targetParent = nullptr);
    ReceptorInfo *createReceptorInfo(const QByteArray &type, const QByteArray &identifier, QObject *targetParent = nullptr);
}

//ReceptorType sensorTypeToReceptorType(const QByteArray &type);

#endif // RECEPTORFACTORY_HPP
