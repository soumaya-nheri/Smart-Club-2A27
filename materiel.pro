QT       += core gui sql
QT       += printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

QT       += charts


QT += network
QT += multimedia multimediawidgets


CONFIG += c++11

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
    connection.cpp \
    dialog.cpp \
    equipements.cpp \
    main.cpp \
    mainwindow.cpp \
    modifier.cpp \
    modifiers.cpp \
    qcustomplot.cpp \
    services.cpp

HEADERS += \
    connection.h \
    dialog.h \
    equipements.h \
    mainwindow.h \
    modifier.h \
    modifiers.h \
    qcustomplot.h \
    services.h

FORMS += \
    dialog.ui \
    mainwindow.ui \
    modifier.ui \
    modifiers.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc

DISTFILES += \
    ../../Desktop/projet photos/stats.png \
    ../../Desktop/projet photos/white.png \
    images/2.png \
    images/4.png \
    images/act.png \
    images/ajout.png \
    images/modif.png \
    images/pdf.png \
    images/stats.png \
    images/supp.png \
    images/white.png
