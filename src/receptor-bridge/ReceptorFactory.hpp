#ifndef RECEPTORFACTORY_HPP
#define RECEPTORFACTORY_HPP

#include <QObject>

class Receptor;
class ReceptorInfo;
class QByteArray;
enum class ReceptorType;

namespace ReceptorFactory {
    ReceptorInfo *createReceptorInfo(const QByteArray &type, const QByteArray &identifier, QObject *targetParent = nullptr);
}

#endif // RECEPTORFACTORY_HPP
