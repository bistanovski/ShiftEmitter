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
    static void registerQuickComponents();

private:
    // This method simplifies registering, but QtCreator is not aware of the registered types
    // Disabled for now
    // template<class T> static int qmlRegisterReceptor();
};

#endif // RECEPTORBRIDGE_HPP
