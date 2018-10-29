#ifndef FAKEGYROSCOPEREADING_HPP
#define FAKEGYROSCOPEREADING_HPP

#include <QObject>

class QTimer;
class QRandomGenerator;

class FakeGyroscopeReading : public QObject
{
    Q_OBJECT
public:
    explicit FakeGyroscopeReading(QObject *parent = nullptr);
    virtual ~FakeGyroscopeReading();

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

#endif // FAKEGYROSCOPEREADING_HPP
