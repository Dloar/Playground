TEMPLATE = app

QT += qml quick
CONFIG += c++11

RESOURCES += LearningQt.qrc

qml.files = LearningQt.qml

launch_modeall {
	CONFIG(debug, debug|release) {
	    DESTDIR = debug
	} else {
	    DESTDIR = release
	}
}

SOURCES += LearningQt.cpp
