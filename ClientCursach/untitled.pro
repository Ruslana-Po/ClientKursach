QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
    basketss.cpp \
    catalog.cpp \
    check.cpp \
    connection.cpp \
    kol.cpp \
    main.cpp \
    mainwindow.cpp \
    maps.cpp \
    message.cpp \
    numbercard.cpp \
    payment.cpp \
    product.cpp \
    qrcode.cpp

HEADERS += \
    basketss.h \
    catalog.h \
    check.h \
    connection.h \
    header.h \
    kol.h \
    mainwindow.h \
    maps.h \
    message.h \
    numbercard.h \
    payment.h \
    product.h \
    qrcode.h

FORMS += \
    basketss.ui \
    catalog.ui \
    check.ui \
    kol.ui \
    mainwindow.ui \
    maps.ui \
    message.ui \
    numbercard.ui \
    payment.ui \
    product.ui \
    qrcode.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resurs.qrc
