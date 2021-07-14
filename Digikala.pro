QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

RESOURCES += qdarkstyle/style.qrc

SOURCES += \
    admin.cpp \
    buyer.cpp \
    itemlistmodel.cpp \
    main.cpp \
    digikala.cpp \
    seller.cpp

HEADERS += \
    admin.h \
    buyer.h \
    digikala.h \
    itemlistmodel.h \
    product.h \
    seller.h

FORMS += \
    admin.ui \
    buyer.ui \
    digikala.ui \
    seller.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

