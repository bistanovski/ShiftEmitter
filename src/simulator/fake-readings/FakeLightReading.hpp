#ifndef FAKELIGHTREADING_HPP
#define FAKELIGHTREADING_HPP

#include <QObject>

class QTimer;
class QRandomGenerator;

class FakeLightReading : public QObject
{
    Q_OBJECT
public:
    explicit FakeLightReading(QObject *parent = nullptr);
    virtual ~FakeLightReading();

public slots:
    virtual void startGeneratingData();
    virtual void stopGeneratingData();

protected:
    virtual void generateReadingsData();

signals:
    void readingChanged(const qreal lux);

private:
    QScopedPointer<QTimer> m_timer;
    QScopedPointer<QRandomGenerator> m_randomGenerator;
};

#endif // FAKELIGHTREADING_HPP
