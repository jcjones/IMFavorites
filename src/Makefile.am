if BUILD_GIMFAVORITES
    bin_PROGRAMS = imfavorites gimfavorites
else
    bin_PROGRAMS = imfavorites
endif

imfavorites_SOURCES = imfavorites.cc imfavorites_engine.cpp sqlite_db.cpp options.cpp

gimfavorites_SOURCES = gimfavorites.cc fileSelection.cc fileSelection_glade.cc imfavorites_engine.cpp mainWindow.cc mainWindow_glade.cc sqlite_db.cpp doneDialog.cc doneDialog_glade.cc

noinst_HEADERS = mainWindow_glade.h mainWindow.h fileSelection_glade.h fileSelection.h imfavorites_engine.h sqlite_db.h options.h doneDialog.h doneDialog_glade.h

AM_CXXFLAGS = -Wno-deprecated @GTKMM_CFLAGS@
AM_CFLAGS = -Wno-deprecated

if WITH_TAGLIB
    imfavorites_LDADD = /usr/lib/libtag.so /usr/lib/libsqlite3.so @LIBS@
    gimfavorites_LDADD = /usr/lib/libtag.so /usr/lib/libsqlite3.so @LIBS@ @GTKMM_LIBS@
else
    imfavorites_LDADD = /usr/lib/libsqlite3.so @LIBS@
    gimfavorites_LDADD = /usr/lib/libsqlite3.so @LIBS@ @GTKMM_LIBS@
endif

imfavorites_DEPENDENCIES = /usr/include/sqlite3.h
gimfavorites_DEPENDENCIES = /usr/include/sqlite3.h

