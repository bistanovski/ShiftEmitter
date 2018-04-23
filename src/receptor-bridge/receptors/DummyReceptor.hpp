#ifndef DUMMYRECEPTOR_HPP
#define DUMMYRECEPTOR_HPP

#include <QSensor>
#include "Receptor.hpp"

class DummyReceptor : public Receptor
{
    Q_OBJECT

public:
    explicit DummyReceptor(QObject *parent = nullptr);
    virtual ~DummyReceptor();

    virtual void connectReceptor() override;
    virtual void startListening() override;

private slots:
    virtual void onReadingChanged() override;

private:
    QSensor m_dummySensor;
    const QByteArray m_dummyType = "DUMMY";
};

#endif // DUMMYRECEPTOR_HPP
