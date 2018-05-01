#ifndef FAKEACCELEROMETERREADING_HPP
#define FAKEACCELEROMETERREADING_HPP

#include <QObject>

class QTimer;
class QRandomGenerator;

class FakeAccelerometerReading : public QObject
{
    Q_OBJECT

public:
    explicit FakeAccelerometerReading(QObject *parent = nullptr);
    virtual ~FakeAccelerometerReading();

    void startGeneratingData();
    void stopGeneratingData();

private:
    void generateReadingsData();

signals:
    void readingChanged(const qreal x, const qreal y, const qreal z);

private:
    QScopedPointer<QTimer> m_timer;
    QScopedPointer<QRandomGenerator> m_randomGenerator;
};

#endif // FAKEACCELEROMETERREADING_HPP
