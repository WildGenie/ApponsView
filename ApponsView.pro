#-------------------------------------------------
#
# Project created by QtCreator 2014-01-02T23:30:54
#
#-------------------------------------------------

QT       += core gui axcontainer

qtHaveModule(opengl): QT += opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ApponsView
TEMPLATE = app


SOURCES += main.cpp \
    mainwindow.cpp \
    view.cpp \
    dtcontrol.cpp \
    filestoreserver.cpp \
    QLogger.cpp \
    pixelorderconverter.cpp \
    digitalclock.cpp \
    settingdialog.cpp \
    apponssetting.cpp

HEADERS  += \
    mainwindow.h \
    view.h \
    dtcontrol.h \
    QLogger.h \
    filestoreserver.h \
    pixelorderconverter.h \
    digitalclock.h \
    settingdialog.h \
    apponssetting.h

OTHER_FILES +=

RESOURCES += \
    Appons.qrc

INCLUDEPATH += $$PWD/
DEPENDPATH += $$PWD/

FORMS += \
    aboutDlg.ui \
    settingdialog.ui
