#ifndef SIMULATOR_HPP
#define SIMULATOR_HPP

#include <QObject>

class Simulator : public QObject
{
     Q_OBJECT
public:
    explicit Simulator(QObject *parent = nullptr);

signals:

public slots:
};

#endif // SIMULATOR_HPP
