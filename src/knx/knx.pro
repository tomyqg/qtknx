TARGET = QtKnx

QT = core
CONFIG += c++11
QT_FOR_PRIVATE += network core-private

QMAKE_DOCS = $$PWD/doc/qtknx.qdocconf

include (core/core.pri)
include(dpt/dpt.pri)
include(knxproj/knxproj.pri)
include(netip/netip.pri)
include(tlstm/tlstm.pri)

DEFINES += QT_NO_CAST_FROM_ASCII

PUBLIC_HEADERS += \
    qknxadditionalinfo.h \
    qknxaddress.h \
    qknxconnectioninfo.h \
    qknxcontrolfield.h \
    qknxdeviceconfiguration.h \
    qknxextendedcontrolfield.h \
    qknxglobal.h \
    qknxinterfaceobjectproperty.h \
    qknxinterfaceobjectpropertydatatype.h \
    qknxinterfaceobjecttype.h \
    qknxlinklayerdevice.h \
    qknxlinklayerframe.h \
    qknxlinklayerframebuilder.h \
    qknxdevicemanagementframe.h \
    qknxdevicemanagementframefactory.h \
    qknxnamespace.h \
    qknxtpdu.h \
    qknxtpdufactory.h \
    qknxtraits.h \
    qknxtransportlayer.h \
    qknxutils.h \
    qknxlinklayerframefactory.h

PRIVATE_HEADERS += \
    qknxlinklayerdevice_p.h \
    qknxtransportlayer_p.h

SOURCES += \
    qknxadditionalinfo.cpp \
    qknxaddress.cpp \
    qknxconnectioninfo.cpp \
    qknxcontrolfield.cpp \
    qknxdeviceconfiguration.cpp \
    qknxextendedcontrolfield.cpp \
    qknxinterfaceobjectproperty.cpp \
    qknxinterfaceobjectpropertydatatype.cpp \
    qknxinterfaceobjecttype.cpp \
    qknxlinklayerdevice.cpp \
    qknxlinklayerframe.cpp \
    qknxdevicemanagementframe.cpp \
    qknxdevicemanagementframefactory.cpp \
    qknxnamespace.cpp \
    qknxtpdu.cpp \
    qknxtpdufactory_broadcast.cpp \
    qknxtpdufactory_multicast.cpp \
    qknxtpdufactory_p2p.cpp \
    qknxtransportlayer.cpp \
    qknxlinklayerframefactory.cpp \
    qknxlinklayerframebuilder.cpp


HEADERS += $$PUBLIC_HEADERS $$PRIVATE_HEADERS

load(qt_module)
