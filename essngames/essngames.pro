QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    cexceptie.cpp \
    cuser.cpp \
    gamesw.cpp \
    iexceptie.cpp \
    iuser.cpp \
    loginw.cpp \
    main.cpp \
    mainwindow.cpp \
    normaluser.cpp \
    refistereduser.cpp \
    registerw.cpp

HEADERS += \
    cexceptie.h \
    cuser.h \
    gamesw.h \
    iexceptie.h \
    iuser.h \
    loginw.h \
    mainwindow.h \
    normaluser.h \
    refistereduser.h \
    registerw.h

FORMS += \
    gamesw.ui \
    loginw.ui \
    mainwindow.ui \
    registerw.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resurse.qrc