/****************************************************************************
**
** Copyright (C) 2017 The Qt Company Ltd.
** Contact: http://www.qt.io/licensing/
**
****************************************************************************/

#pragma once

#include <QtKnx/qknxnetip.h>
#include <QtKnx/qknxnetipframe.h>
#include <QtKnx/qknxglobal.h>

QT_BEGIN_NAMESPACE

class Q_KNX_EXPORT QKnxNetIpConnectionStateResponse final : private QKnxNetIpFrame
{
public:
    QKnxNetIpConnectionStateResponse() = default;
    ~QKnxNetIpConnectionStateResponse() override = default;

    QKnxNetIpConnectionStateResponse(quint8 channelId, QKnxNetIp::Error status);

    quint8 channelId() const;
    QKnxNetIp::Error status() const;

    bool isValid() const override;

    using QKnxNetIpFrame::size;
    using QKnxNetIpFrame::bytes;
    using QKnxNetIpFrame::payload;
    using QKnxNetIpFrame::toString;
};

QT_END_NAMESPACE