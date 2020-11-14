QT += widgets
requires(qtConfig(listview))

SOURCES   = \
    UI_debugWindow.cpp \
	actiontriggers.cpp \
	debugwindow.cpp \
	main.cpp
HEADERS   = \
    actiontriggers.h \
	debugwindow.h \

# install
target.path = $$[QT_INSTALL_EXAMPLES]/widgets/itemviews/addressbook
INSTALLS += target
