#ifndef FAKECOMPASSREADING_HPP
#define FAKECOMPASSREADING_HPP

#include <QObject>

class QTimer;
class QRandomGenerator;

class FakeCompassReading : public QObject
{
    Q_OBJECT
public:
    explicit FakeCompassReading(QObject *parent = nullptr);
    virtual ~FakeCompassReading();

public slots:
    virtual void startGeneratingData();
    virtual void stopGeneratingData();

protected:
    virtual void generateReadingsData();

signals:
    void readingChanged(const qreal azimuth, const qreal callibration);

private:
    QScopedPointer<QTimer> m_timer;
    QScopedPointer<QRandomGenerator> m_randomGenerator;
};

#endif // FAKECOMPASSREADING_HPP
