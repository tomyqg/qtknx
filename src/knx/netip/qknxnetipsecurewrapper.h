/******************************************************************************
**
** Copyright (C) 2018 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the QtKnx module.
**
** $QT_BEGIN_LICENSE:GPL$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3 or (at your option) any later version
** approved by the KDE Free Qt Foundation. The licenses are as published by
** the Free Software Foundation and appearing in the file LICENSE.GPL3
** included in the packaging of this file. Please review the following
** information to ensure the GNU General Public License requirements will
** be met: https://www.gnu.org/licenses/gpl-3.0.html.
**
** $QT_END_LICENSE$
**
******************************************************************************/

#ifndef QKNXNETIPSECUREWRAPPER_H
#define QKNXNETIPSECUREWRAPPER_H

#include <QtKnx/qknxnetipframe.h>
#include <QtKnx/qtknxglobal.h>

QT_BEGIN_NAMESPACE

class QKnxNetIpSecureWrapperPrivate;
class Q_KNX_EXPORT QKnxNetIpSecureWrapperProxy final
{
public:
    QKnxNetIpSecureWrapperProxy() = delete;
    ~QKnxNetIpSecureWrapperProxy() = default;

    QKnxNetIpSecureWrapperProxy(const QKnxNetIpFrame &&) = delete;
    explicit QKnxNetIpSecureWrapperProxy(const QKnxNetIpFrame &frame);

    bool isValid() const;

    quint16 secureSessionId() const;
    quint48 sequenceNumber() const;
    QKnxByteArray serialNumber() const;
    quint16 messageTag() const;
    QKnxByteArray encapsulatedFrame() const;
    QKnxByteArray messageAuthenticationCode() const;

    class Q_KNX_EXPORT Builder final
    {
    public:
        Builder();
        ~Builder();

        Builder &setSecureSessionId(quint16 sessionId);
        Builder &setSequenceNumber(quint48 seqNumber);
        Builder &setSerialNumber(const QKnxByteArray &serialNumber);
        Builder &setMessageTag(quint16 tag);
        Builder &setEncapsulatedFrame(const QKnxByteArray &frame);
        Builder &setMessageAuthenticationCode(const QKnxByteArray &data);

        QKnxNetIpFrame create() const;

        Builder(const Builder &other);
        Builder &operator=(const Builder &other);

    private:
        QSharedDataPointer<QKnxNetIpSecureWrapperPrivate> d_ptr;
    };
    static QKnxNetIpSecureWrapperProxy::Builder builder();

    class Q_KNX_EXPORT SecureBuilder final
    {
    public:
        SecureBuilder();
        ~SecureBuilder();

        SecureBuilder &setSecureSessionId(quint16 sessionId);
        SecureBuilder &setSequenceNumber(quint48 seqNumber);
        SecureBuilder &setSerialNumber(const QKnxByteArray &serialNumber);
        SecureBuilder &setMessageTag(quint16 tag);
        SecureBuilder &setEncapsulatedFrame(const QKnxNetIpFrame &frame);

        QKnxNetIpFrame create(const QKnxByteArray &sessionKey) const;

        SecureBuilder(const SecureBuilder &other);
        SecureBuilder &operator=(const SecureBuilder &other);

    private:
        QSharedDataPointer<QKnxNetIpSecureWrapperPrivate> d_ptr;
    };
    static QKnxNetIpSecureWrapperProxy::SecureBuilder secureBuilder();

private:
    const QKnxNetIpFrame &m_frame;
};

QT_END_NAMESPACE

#endif
