#ifndef FAKEORIENTATIONREADING_HPP
#define FAKEORIENTATIONREADING_HPP

#include <QObject>

class QTimer;
class QRandomGenerator;

class FakeOrientationReading : public QObject
{
    Q_OBJECT
public:
    explicit FakeOrientationReading(QObject *parent = nullptr);
    virtual ~FakeOrientationReading();

public slots:
    virtual void startGeneratingData();
    virtual void stopGeneratingData();

protected:
    virtual void generateReadingsData();

signals:
    void readingChanged(const int orientation);

private:
    QScopedPointer<QTimer> m_timer;
    QScopedPointer<QRandomGenerator> m_randomGenerator;
};

#endif // FAKEORIENTATIONREADING_HPP
