QT += widgets
requires(qtConfig(listview))

SOURCES   = \
    actiontriggers.cpp \
    creatorDialog/dialog.cpp \
			debugWindow/window.cpp \
			main.cpp \
			newaddresstab.cpp
HEADERS   = \
    actiontriggers.h \
    creatorDialog/dialog.h \
			debugWindow/window.h \
			newaddresstab.h

# install
target.path = $$[QT_INSTALL_EXAMPLES]/widgets/itemviews/addressbook
INSTALLS += target
