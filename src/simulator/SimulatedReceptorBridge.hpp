#ifndef SIMULATEDRECEPTORBRIDGE_H
#define SIMULATEDRECEPTORBRIDGE_H

#include <QObject>

class Receptor;

namespace SimulatedReceptorBridge
{
    QObjectList fetchReceptorInfos(QObject *targetParent);
    void registerQuickComponents();

    void insertPairOfByteArraysInVector(QVector<QPair<QByteArray, QByteArray>> &targetVector, const QByteArray &first, const QByteArray &second);

    // This method simplifies registering, but QtCreator is not aware of the registered types
    // Disabled for now
    // template<class T> static int qmlRegisterReceptor();
}

#endif // SIMULATEDRECEPTORBRIDGE_H
