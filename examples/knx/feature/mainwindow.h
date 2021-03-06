/****************************************************************************
**
** Copyright (C) 2019 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the QtKnx module.
**
** $QT_BEGIN_LICENSE:BSD$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** BSD License Usage
** Alternatively, you may use this file under the terms of the BSD license
** as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
******************************************************************************/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtKnx>
#include <QtWidgets>

QT_BEGIN_NAMESPACE

namespace Ui {
    class MainWindow;
}

QT_END_NAMESPACE

class DeviceItem;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void onConnected();
    void onDisconnected();
    void onDeviceDiscovered(QKnxNetIpServerInfo info);
    void onErrorOccurred(QKnxNetIpEndpointConnection::Error error, QString errorString);

    void on_actionImport_triggered();
    void on_devices_currentIndexChanged(int index);
    void on_serviceTypes_currentIndexChanged(int index);

    void on_sendRead_clicked();
    void on_sendWrite_clicked();
    void on_connection_clicked();

private:
    void setupInterfaces();
    void toggleUi(bool enable);
    void populateServiceTypesComboBox();
    void populateInterfaceFeaturesComboBox();

    void setText(QKnx::InterfaceFeature feature, const QKnxByteArray &value);
    void populateFrame(QKnxNetIp::ServiceType type, QKnx::InterfaceFeature feature,
        const QKnxByteArray &value, int returnCode = -1);
    void onFeatureResponseReceived(QKnx::InterfaceFeature feature, QKnx::ReturnCode code,
        const QKnxByteArray &value);
    void onFeatureInfoReceived(QKnx::InterfaceFeature feature, const QKnxByteArray &value);

private:
    Ui::MainWindow *ui { nullptr };

    DeviceItem *m_device { nullptr };
    QTreeWidgetItem *m_last { nullptr };
    QTreeWidgetItem *m_current { nullptr };

    QKnxNetIpTunnel m_tunnel;
    QKnxNetIpServerDiscoveryAgent m_discoveryAgent;
    QVector<QKnxNetIpSecureConfiguration> m_secureConfigs;
};

#endif // MAINWINDOW_H
