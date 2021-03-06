#ifndef RECEPTORBRIDGE_HPP
#define RECEPTORBRIDGE_HPP

#include <QObject>

class Receptor;

namespace ReceptorBridge
{
    QObjectList fetchReceptorInfos(QObject *targetParent);
    void registerQuickComponents();

    // This method simplifies registering, but QtCreator is not aware of the registered types
    // Disabled for now
    // template<class T> static int qmlRegisterReceptor();
}

#endif // RECEPTORBRIDGE_HPP
