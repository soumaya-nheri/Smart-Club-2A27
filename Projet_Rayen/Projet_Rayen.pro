QT       += core gui sql
QT       += multimedia
QT       +=printsupport
Qt         += charts
QT       += core gui multimedia multimediawidgets
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
QT += charts
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
    abonnement.cpp \
    abonnes.cpp \
    coach.cpp \
    comptabilite.cpp \
    connection.cpp \
    depenses.cpp \
    donutbreakdownchart.cpp \
    equipements.cpp \
    evenement.cpp \
    historique.cpp \
    main.cpp \
    mainslice.cpp \
    mainwindow.cpp \
    modifier.cpp \
    modifier_ab.cpp \
    modifier_abt.cpp \
    modifier_dep.cpp \
    modifier_rev.cpp \
    modifiercoach.cpp \
    modifierprogrammes.cpp \
    modifiers.cpp \
    programs.cpp \
    revenues.cpp \
    services.cpp \
    sponsor.cpp

HEADERS += \
    abonnement.h \
    abonnes.h \
    coach.h \
    comptabilite.h \
    connection.h \
    depenses.h \
    donutbreakdownchart.h \
    equipements.h \
    evenement.h \
    historique.h \
    mainslice.h \
    mainwindow.h \
    modifier.h \
    modifier_ab.h \
    modifier_abt.h \
    modifier_dep.h \
    modifier_rev.h \
    modifiercoach.h \
    modifierprogrammes.h \
    modifiers.h \
    programs.h \
    revenues.h \
    services.h \
    sponsor.h

FORMS += \
    comptabilite.ui \
    mainwindow.ui \
    modifier.ui \
    modifier_ab.ui \
    modifier_abt.ui \
    modifier_dep.ui \
    modifier_rev.ui \
    modifiercoach.ui \
    modifierprogrammes.ui \
    modifiers.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=

RESOURCES += \
    RESS.qrc
