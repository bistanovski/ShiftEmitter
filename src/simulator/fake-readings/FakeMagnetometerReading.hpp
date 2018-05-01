#ifndef FAKEMAGNETOMETERREADING_HPP
#define FAKEMAGNETOMETERREADING_HPP

#include <QObject>

class QTimer;
class QRandomGenerator;

class FakeMagnetometerReading : public QObject
{
    Q_OBJECT
public:
    explicit FakeMagnetometerReading(QObject *parent = nullptr);
    virtual ~FakeMagnetometerReading();

public slots:
    virtual void startGeneratingData();
    virtual void stopGeneratingData();

protected:
    virtual void generateReadingsData();

signals:
    void readingChanged(const qreal xFlux, const qreal yFlux, const qreal zFlux, const qreal callibrationLevel);

private:
    QScopedPointer<QTimer> m_timer;
    QScopedPointer<QRandomGenerator> m_randomGenerator;
};

#endif // FAKEMAGNETOMETERREADING_HPP
