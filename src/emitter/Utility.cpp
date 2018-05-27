#include <Utility.hpp>

#include <QDebug>
#include <QNetworkInterface>
#include <QCryptographicHash>
#include <QOperatingSystemVersion>

namespace ShiftUtils {
    QByteArray generateDeviceUUID()
    {
        const auto interfaces = QNetworkInterface::allInterfaces();
        const auto interfaceIterator = std::find_if(interfaces.cbegin(), interfaces.cend(), [](const QNetworkInterface &interface){
            return (!interface.flags().testFlag(QNetworkInterface::IsPointToPoint) && !interface.flags().testFlag(QNetworkInterface::IsLoopBack));
        });

        if(interfaces.cend() != interfaceIterator)
        {
            const auto macAddress = interfaceIterator->hardwareAddress().toUpper().trimmed();
            const auto nameSpace = QString("SHIFT_EMITTER_UNIQUE_CLIENT_NS");

            QCryptographicHash hash(QCryptographicHash::Sha1);
            hash.addData(macAddress.toUtf8());
            hash.addData(nameSpace.toUtf8());

            return hash.result().toHex().toUpper();
        }
        else
        {
            qWarning() << "Required network interface could not be found";
        }

        return QByteArray();
    }

    QString operatingSystemName()
    {
        #if defined(SHIFT_LINUX)
            return QLatin1String("Linux");
        #else
            return QOperatingSystemVersion::current().name();
        #endif
    }

    QString operatingSystemVersion()
    {
        #if defined(SHIFT_LINUX)
            return QLatin1String("16.04");
        #else
            const auto osv = QOperatingSystemVersion::current();
            return QString::number(osv.majorVersion()) + QString::number(osv.minorVersion()) + QString::number(osv.microVersion());
        #endif
    }
}
