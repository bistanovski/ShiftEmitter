#ifndef RECEPTOR_HPP
#define RECEPTOR_HPP

#include <QObject>

class Receptor : public QObject
{
    Q_OBJECT
public:
    explicit Receptor(QObject *parent = nullptr);

signals:

public slots:
};

#endif // RECEPTOR_HPP