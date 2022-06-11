QT       += core gui multimedia

CONFIG += c++11

QMAKE_CXXFLAGS += -std=c++11
QMAKE_LFLAGS += -std=c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QtTicTacToe
TEMPLATE = app

SOURCES += \
    gamemenuwindow.cpp \
    main.cpp \
    mainwindow.cpp \
    o_piece_of_game.cpp \
    piece_of_game.cpp \
    playgroundframe.cpp \
    x_piece_of_game.cpp

HEADERS += \
    gamemenuwindow.h \
    mainwindow.h \
    o_piece_of_game.h \
    piece_of_game.h \
    playgroundframe.h \
    x_piece_of_game.h

FORMS += \
    gamemenuwindow.ui \
    mainwindow.ui \
    playgroundframe.ui

# Default rules for deployment.
#qnx: target.path = /tmp/$${TARGET}/bin
#else: unix:!android: target.path = /opt/$${TARGET}/bin
#!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    images.qrc \
    sounds.qrc
