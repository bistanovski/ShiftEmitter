#ifndef UTILITY_HPP
#define UTILITY_HPP

#include <QString>
#include <QByteArray>

namespace ShiftUtils
{
    QByteArray generateDeviceUUID();
    QString operatingSystemName();
    QString operatingSystemVersion();
}

#endif // UTILITY_HPP
