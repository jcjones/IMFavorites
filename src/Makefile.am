if BUILD_GIMFAVORITES 
    bin_PROGRAMS = imfavorites gimfavorites
else
    bin_PROGRAMS = imfavorites
endif

imfavorites_SOURCES = imfavorites.cc imfavorites_engine.cpp sqlite_db.cpp options.cpp

gimfavorites_SOURCES = fileSelection.cc fileSelection_glade.cc imfavorites_engine.cpp mainWindow.cc mainWindow_glade.cc sqlite_db.cpp gimfavorites.cc doneDialog.cc doneDialog_glade.cc

noinst_HEADERS = mainWindow_glade.h mainWindow.h fileSelection_glade.h fileSelection.h imfavorites_engine.h sqlite_db.h options.h doneDialog.h doneDialog_glade.h

AM_CXXFLAGS = -Wno-deprecated @GTKMM_CFLAGS@
AM_CFLAGS = -Wno-deprecated

imfavorites_LDADD = /usr/lib/libsqlite.so @LIBS@ @GTKMM_LIBS@
imfavorites_DEPENDENCIES = /usr/include/sqlite.h

gimfavorites_LDADD = /usr/lib/libsqlite.so @LIBS@ @GTKMM_LIBS@
gimfavorites_DEPENDENCIES = /usr/include/sqlite.h
