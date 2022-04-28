QT       += core gui
QT       += multimedia multimediawidgets

QT       += network
   #aici am modificat


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    aboutus.cpp \
    cexceptie.cpp \
    contactinfo.cpp \
    cuser.cpp \
    gamesw.cpp \
    iexceptie.cpp \
    irequest.cpp \
    iuser.cpp \
    loginw.cpp \
    main.cpp \
    mainwindow.cpp \
    normaluser.cpp \
    refistereduser.cpp \
    registerw.cpp \
    requestaddfriend.cpp \
    requestdeletefriend.cpp \
    requestgamedescription.cpp \
    requestlogin.cpp \
    requestmyfriends.cpp \
    requestregister.cpp \
    requestsendscore.cpp \
    requesttop.cpp \
    sendmessage.cpp \
    tcpclient.cpp

HEADERS += \
    aboutus.h \
    cexceptie.h \
    contactinfo.h \
    cuser.h \
    gamesw.h \
    iexceptie.h \
    irequest.h \
    iuser.h \
    loginw.h \
    mainwindow.h \
    normaluser.h \
    refistereduser.h \
    registerw.h \
    requestaddfriend.h \
    requestdeletefriend.h \
    requestgamedescription.h \
    requestlogin.h \
    requestmyfriends.h \
    requestregister.h \
    requestsendscore.h \
    requesttop.h \
    sendmessage.h \
    tcpclient.h

FORMS += \
    aboutus.ui \
    chat.ui \
    contactinfo.ui \
    gamesw.ui \
    loginw.ui \
    mainwindow.ui \
    registerw.ui \
    sendmessage.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resurse.qrc

DISTFILES +=
