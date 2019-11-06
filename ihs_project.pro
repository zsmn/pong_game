TEMPLATE = app
QT = core

CONFIG += console
CONFIG -= app_bundle
CONFIG += c++11

LIBS *= -lm -lallegro -lallegro_image -lallegro_primitives -lallegro_font -lallegro_ttf

SOURCES += \
        include/game.cpp \
		main.cpp

HEADERS += \
	include/game.h

DISTFILES += \
	resources/arial.ttf
