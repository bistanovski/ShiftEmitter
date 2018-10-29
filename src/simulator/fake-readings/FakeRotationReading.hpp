#ifndef FAKEROTATIONREADING_HPP
#define FAKEROTATIONREADING_HPP

#include <QObject>

class QTimer;
class QRandomGenerator;

class FakeRotationReading : public QObject
{
    Q_OBJECT

public:
    explicit FakeRotationReading(QObject *parent = nullptr);
    virtual ~FakeRotationReading();

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

#endif // FAKEROTATIONREADING_HPP
