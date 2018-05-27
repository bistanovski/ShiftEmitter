#ifndef RECEPTORSMODEL_HPP
#define RECEPTORSMODEL_HPP

#include <QObject>

class QQmlContext;

class ReceptorsModel : public QObject
{
    Q_OBJECT

public:
    explicit ReceptorsModel(QObject *parent = nullptr);
    virtual ~ReceptorsModel();

    void fillReceptorsData(const QObjectList &receptors);
    void registerQmlModel(QQmlContext *ctxt);

    int numOfReceptors() const;
    const QObjectList &getReceptorsModel();

private:
    QObjectList m_receptorsList;
};

#endif // RECEPTORSMODEL_HPP
