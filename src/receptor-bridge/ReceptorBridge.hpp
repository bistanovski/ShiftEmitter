#ifndef RECEPTORBRIDGE_HPP
#define RECEPTORBRIDGE_HPP

#include <memory>

#include <QObject>

class Receptor;
typedef std::unique_ptr<Receptor> ReceptorPtr;

class ReceptorBridge: public QObject
{
    Q_OBJECT
public:
    explicit ReceptorBridge(QObject *parent = nullptr);
    virtual ~ReceptorBridge();

    static std::vector<ReceptorPtr> fetchAllReceptors();
};

#endif // RECEPTORBRIDGE_HPP
