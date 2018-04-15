#ifndef RECEPTORBRIDGE_HPP
#define RECEPTORBRIDGE_HPP

#include <QObject>

class Receptor;

class ReceptorBridge: public QObject
{
    Q_OBJECT
public:
    explicit ReceptorBridge(QObject *parent = nullptr);
    virtual ~ReceptorBridge();

    static QObjectList fetchReceptorInfos(QObject *targetParent);
};

#endif // RECEPTORBRIDGE_HPP
