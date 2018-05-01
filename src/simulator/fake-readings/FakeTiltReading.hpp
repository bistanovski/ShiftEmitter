#ifndef FAKETILTREADING_HPP
#define FAKETILTREADING_HPP

#include <QObject>

class QTimer;
class QRandomGenerator;

class FakeTiltReading : public QObject
{
    Q_OBJECT
public:
    explicit FakeTiltReading(QObject *parent = nullptr);
    virtual ~FakeTiltReading();

public slots:
    virtual void startGeneratingData();
    virtual void stopGeneratingData();

protected:
    virtual void generateReadingsData();

signals:
    void readingChanged(const qreal xRotation, const qreal yRotation);

private:
    QScopedPointer<QTimer> m_timer;
    QScopedPointer<QRandomGenerator> m_randomGenerator;
};

#endif // FAKETILTREADING_HPP
