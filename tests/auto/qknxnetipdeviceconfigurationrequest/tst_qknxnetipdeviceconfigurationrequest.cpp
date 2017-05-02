/****************************************************************************
**
** Copyright (C) 2017 The Qt Company Ltd.
** Contact: http://www.qt.io/licensing/
**
****************************************************************************/

#include <QtCore/qdebug.h>
#include <QtTest/qtest.h>
#include <QtKnx/qknxnetipdeviceconfigurationrequest.h>

static QString s_msg;
static void myMessageHandler(QtMsgType, const QMessageLogContext &, const QString &msg)
{
    s_msg = msg;
}

class tst_QKnxNetIpDeviceConfigurationRequest: public QObject
{
    Q_OBJECT

private slots:
    void testDefaultConstructor();
    void testConstructor();
    void testDebugStream();
    void testDataStream();
};

void tst_QKnxNetIpDeviceConfigurationRequest::testDefaultConstructor()
{
    QKnxNetIpDeviceConfigurationRequest configuration;
    QCOMPARE(configuration.isValid(), false);
}

void tst_QKnxNetIpDeviceConfigurationRequest::testConstructor()
{
}

void tst_QKnxNetIpDeviceConfigurationRequest::testDebugStream()
{
    struct DebugHandler
    {
        explicit DebugHandler(QtMessageHandler newMessageHandler)
            : oldMessageHandler(qInstallMessageHandler(newMessageHandler)) {}
        ~DebugHandler() {
            qInstallMessageHandler(oldMessageHandler);
        }
        QtMessageHandler oldMessageHandler;
    } _(myMessageHandler);

    //qDebug() << DEFAULTCONSTRUCTOR;
    //QCOMPARE(s_msg, QString::fromLatin1("0x1nv4l1d"));
}

void tst_QKnxNetIpDeviceConfigurationRequest::testDataStream()
{
    {
        //QByteArray byteArray;
        //QDataStream out(&byteArray, QIODevice::WriteOnly);
        //out << CONSTRUCTORWITHARG;
        //QCOMPARE(byteArray, QByteArray::fromHex("1404C0A8020CFFFFFF00C0A80201B48A03020100"));
    }

    {
        //out << OTHERCONSTRUCTOR;
        //QCOMPARE(byteArray, QByteArray::fromHex("1404C0A8020CFFFFFF00C0A80201B48A03020100"));
 }
}

QTEST_APPLESS_MAIN(tst_QKnxNetIpDeviceConfigurationRequest)

#include "tst_qknxnetipdeviceconfigurationrequest.moc"
