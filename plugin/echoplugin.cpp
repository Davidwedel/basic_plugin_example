
#include "echoplugin.h"

EchoPlugin::EchoPlugin(){
    qDebug() << "ctor";
}
//! [0]
QString EchoPlugin::echo(const QString &message)
{
    qDebug() << "recd echo";
    return "hello";
}
//! [0]

