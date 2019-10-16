QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

VERSION = 0.5.6.0
DEFINES += APP_VERSION=\\\"$$VERSION\\\"

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ArchivoUsuarios.cpp \
    BalaDeCanon.cpp \
    Base.cpp \
    Canon.cpp \
    LanzamientoParabolico.cpp \
    MapaMar.cpp \
    Menu.cpp \
    Oficial.cpp \
    Registo.cpp \
    main.cpp

HEADERS += \
    ArchivoUsuarios.h \
    BalaDeCanon.h \
    Base.h \
    Canon.h \
    Definiciones.h \
    LanzamientoParabolico.h \
    MapaMar.h \
    Menu.h \
    Oficial.h \
    Registo.h


FORMS += \
    Registo.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += recursos/res.qrc

