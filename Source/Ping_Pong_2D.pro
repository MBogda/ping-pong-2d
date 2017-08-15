TEMPLATE = app
CONFIG += c++14
CONFIG -= app_bundle
CONFIG -= qt

CONFIG(release, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-window -lsfml-system
CONFIG(debug, debug|release): LIBS += -lsfml-audio-d -lsfml-graphics-d -lsfml-network-d -lsfml-window-d -lsfml-system-d
#CONFIG(release, debug|release): LIBS += \
#    /usr/local/lib/libsfml-window.a \
#    /usr/local/lib/libsfml-system.a
#CONFIG(debug, debug|release): LIBS += \
#    /usr/local/lib/libsfml-window-s-d.a \
#    /usr/local/lib/libsfml-system-s-d.a

SOURCES += main.cpp \
    movablegameobject.cpp \
    gameobjects.cpp

HEADERS += \
    movablegameobject.h \
    gameobjects.h
