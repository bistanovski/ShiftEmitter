#ifndef FAKEAMBIENTLIGHTREADING_HPP
#define FAKEAMBIENTLIGHTREADING_HPP

#include <QObject>

class QTimer;
class QRandomGenerator;

class FakeAmbientLightReading : public QObject
{
    Q_OBJECT

public:
    explicit FakeAmbientLightReading(QObject *parent = nullptr);
    virtual ~FakeAmbientLightReading();

public slots:
    virtual void startGeneratingData();
    virtual void stopGeneratingData();

protected:
    virtual void generateReadingsData();

signals:
    void readingChanged(const int lightLevel);

private:
    QScopedPointer<QTimer> m_timer;
    QScopedPointer<QRandomGenerator> m_randomGenerator;
};

#endif // FAKEAMBIENTLIGHTREADING_HPP
