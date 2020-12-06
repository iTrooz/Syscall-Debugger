QT += widgets
requires(qtConfig(listview))

SOURCES   = \
    UI_debugWindow.cpp \
	debugwindow.cpp \
	main.cpp \
    process.cpp \
    utils.cpp
HEADERS   = \
	debugwindow.h \
    process.h \
    utils.h

# install
target.path = $$[QT_INSTALL_EXAMPLES]/widgets/itemviews/addressbook
INSTALLS += target
