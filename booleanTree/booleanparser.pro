

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TEMPLATE      = app
HEADERS       = booleanmodel.h \
                booleanparser.h \
                booleanwindow.h \
                node.h
SOURCES       = booleanmodel.cpp \
                booleanparser.cpp \
                booleanwindow.cpp \
                main.cpp \
                node.cpp
