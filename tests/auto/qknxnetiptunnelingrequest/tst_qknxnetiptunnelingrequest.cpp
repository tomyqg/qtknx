/****************************************************************************
**
** Copyright (C) 2017 The Qt Company Ltd.
** Contact: http://www.qt.io/licensing/
**
****************************************************************************/

#include <QtCore/qdebug.h>
#include <QtTest/qtest.h>
#include <QtKnx/qknxnetiptunnelingrequest.h>

static QString s_msg;
static void myMessageHandler(QtMsgType, const QMessageLogContext &, const QString &msg)
{
    s_msg = msg;
}

class tst_QKnxNetIpTunnelingRequest: public QObject
{
    Q_OBJECT

private slots:
    void testDefaultConstructor();
    void testConstructor(); // to do
    void testDebugStream(); // to do
    void testDataStream(); // to do
};

void tst_QKnxNetIpTunnelingRequest::testDefaultConstructor()
{
    QKnxNetIpTunnelingRequest tunneling;
    QCOMPARE(tunneling.isValid(), false);
}

void tst_QKnxNetIpTunnelingRequest::testConstructor()
{
}

void tst_QKnxNetIpTunnelingRequest::testDebugStream()
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

void tst_QKnxNetIpTunnelingRequest::testDataStream()
{
    //QByteArray byteArray;
    //QDataStream out(&byteArray, QIODevice::WriteOnly);
    //out << OTHERCONSTRUCTOR;
    //QCOMPARE(byteArray, QByteArray::fromHex("1404C0A8020CFFFFFF00C0A80201B48A03020100"));
}

QTEST_APPLESS_MAIN(tst_QKnxNetIpTunnelingRequest)

#include "tst_qknxnetiptunnelingrequest.moc"
