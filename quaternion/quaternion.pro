TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    operators.cpp \
    quaternion.cpp

HEADERS += \
    operators.h \
    quaternion.h
