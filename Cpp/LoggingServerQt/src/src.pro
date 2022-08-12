#-------------------------------------------------
#
# Project created by QtCreator 2014-08-08T13:07:12
#
#-------------------------------------------------

TARGET = LoggingServerQt
TEMPLATE = app

CONFIG += c++11

QT       += core gui widgets

SOURCES += main.cpp\
	TcpIpEdit.cpp \
	Utils.cpp \
	MainWidget.cpp \
	Icons.cpp \
	SettingsWidget.cpp \
	Settings.cpp \
	Controller.cpp \
	TcpIpEndPoint.cpp \
	ControllerWidget.cpp \
	LoggingServer.cpp

HEADERS  += \
	TcpIpEdit.hpp \
	Utils.hpp \
	MainWidget.hpp \
	Icons.hpp \
	SettingsWidget.hpp \
	Settings.hpp \
	Controller.hpp \
	TcpIpEndPoint.hpp \
	ControllerWidget.hpp \
	LoggingServer.hpp

RESOURCES += \
	Icons.qrc

INCLUDEPATH += ../../CppAidKit/headers/
LIBS += -l ../-LAidKit
