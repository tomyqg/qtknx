/****************************************************************************
**
** Copyright (C) 2017 The Qt Company Ltd.
** Contact: http://www.qt.io/licensing/
**
****************************************************************************/

#include "qknxnetipdeviceconfigurationrequest.h"

QT_BEGIN_NAMESPACE

QKnxNetIpDeviceConfigurationRequest::QKnxNetIpDeviceConfigurationRequest(quint8 id,
        quint8 sequenceCounter, const QKnxCemiFrame &cemi)
    : QKnxNetIpConnectionHeaderFrame(QKnxNetIp::ServiceType::DeviceConfigurationRequest)
{
    setConnectionHeader({ id, sequenceCounter });
    setPayload({ cemi.ref().bytes(), cemi.ref().size() });
}

QKnxNetIpDeviceConfigurationRequest::QKnxNetIpDeviceConfigurationRequest(
        const QKnxNetIpConnectionHeaderFrame &other)
    : QKnxNetIpConnectionHeaderFrame(other)
{}

quint8 QKnxNetIpDeviceConfigurationRequest::channelId() const
{
    return connectionHeader().channelId();
}

quint8 QKnxNetIpDeviceConfigurationRequest::sequenceCounter() const
{
    return connectionHeader().sequenceCounter();
}

QKnxCemiFrame QKnxNetIpDeviceConfigurationRequest::cemi() const
{
    auto ref = payloadRef(connectionHeaderSize());
    return QKnxCemiFrame::fromBytes(ref.bytes<std::vector<quint8>>(), 0, ref.size());
}

bool QKnxNetIpDeviceConfigurationRequest::isValid() const
{
    // TODO: fix size check once the minimum CEMI frame size is known
    return QKnxNetIpConnectionHeaderFrame::isValid() && size() >= 12
        && code() == QKnxNetIp::ServiceType::DeviceConfigurationRequest;
}

QT_END_NAMESPACE
