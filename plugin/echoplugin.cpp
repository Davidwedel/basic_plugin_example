
#include "echoplugin.h"

//! [0]
QString EchoPlugin::echo(const QString &message)
{
    qDebug() << "recd echo";
    return "hello";
}
//! [0]

