QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
    basketss.cpp \
    bread.cpp \
    catalog.cpp \
    cereals.cpp \
    check.cpp \
    cheese.cpp \
    connection.cpp \
    drinks.cpp \
    fruct.cpp \
    fruitssecs.cpp \
    kol.cpp \
    main.cpp \
    mainwindow.cpp \
    maps.cpp \
    meat.cpp \
    message.cpp \
    milk.cpp \
    numbercard.cpp \
    payment.cpp \
    product.cpp \
    qrcode.cpp \
    sweets.cpp \
    vegetables.cpp

HEADERS += \
    basketss.h \
    bread.h \
    catalog.h \
    cereals.h \
    check.h \
    cheese.h \
    connection.h \
    drinks.h \
    fruct.h \
    fruitssecs.h \
    header.h \
    kol.h \
    mainwindow.h \
    maps.h \
    meat.h \
    message.h \
    milk.h \
    numbercard.h \
    payment.h \
    product.h \
    qrcode.h \
    sweets.h \
    vegetables.h

FORMS += \
    basketss.ui \
    bread.ui \
    catalog.ui \
    cereals.ui \
    check.ui \
    cheese.ui \
    drinks.ui \
    fruct.ui \
    fruitssecs.ui \
    kol.ui \
    mainwindow.ui \
    maps.ui \
    meat.ui \
    message.ui \
    milk.ui \
    numbercard.ui \
    payment.ui \
    product.ui \
    qrcode.ui \
    sweets.ui \
    vegetables.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resurs.qrc
