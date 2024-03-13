#-------------------------------------------------
#
# Project created by QtCreator 2022-09-29T04:22:17
#
#-------------------------------------------------

QT       += core gui sql
QT	 += xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = RSIAttendance
TEMPLATE = app

LIBS += -lSDL2 -lSDL2_image
LIBS += /home/kodiak/build-MyStaticLib-Release-Debug/libMyStaticLib.a

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        rsi_login.cpp \
    employee.cpp \
    logoutwarning.cpp \
    feedback.cpp \
    attendance.cpp \
    update_password.cpp \
    add_employee.cpp \
    privelleges_checkbox.cpp \
    edit_employee.cpp \
    mysdl.cpp \
    childwindow.cpp

HEADERS += \
        rsi_login.h \
    employee.h \
    logoutwarning.h \
    feedback.h \
    attendance.h \
    update_password.h \
    add_employee.h \
    privelleges_checkbox.h \
    edit_employee.h \
    mysdl.h \
    childwindow.h \
    mydll.h \
    mydll_global.h \
    mystaticlib.h

FORMS += \
        rsi_login.ui \
    employee.ui \
    logoutwarning.ui \
    feedback.ui \
    attendance.ui \
    update_password.ui \
    add_employee.ui \
    privelleges_checkbox.ui \
    edit_employee.ui \
    childwindow.ui
