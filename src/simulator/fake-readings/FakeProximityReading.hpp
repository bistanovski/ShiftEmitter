#ifndef FAKEPROXIMITYREADING_HPP
#define FAKEPROXIMITYREADING_HPP

#include <QObject>

class QTimer;
class QRandomGenerator;

class FakeProximityReading : public QObject
{
    Q_OBJECT
public:
    explicit FakeProximityReading(QObject *parent = nullptr);
    virtual ~FakeProximityReading();

public slots:
    virtual void startGeneratingData();
    virtual void stopGeneratingData();

protected:
    virtual void generateReadingsData();

signals:
    void readingChanged(const bool somethingClose);

private:
    QScopedPointer<QTimer> m_timer;
    QScopedPointer<QRandomGenerator> m_randomGenerator;
};

#endif // FAKEPROXIMITYREADING_HPP
