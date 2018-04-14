#ifndef RECEPTORNETWORK_HPP
#define RECEPTORNETWORK_HPP

#include <memory>

#include <QObject>

class Receptor;
typedef std::unique_ptr<Receptor> ReceptorPtr;

class ReceptorNetwork : public QObject
{
    Q_OBJECT
public:
    explicit ReceptorNetwork(QObject *parent = nullptr);
    virtual ~ReceptorNetwork();

    static std::vector<ReceptorPtr> fetchAllReceptors();
};

#endif // RECEPTORNETWORK_HPP
