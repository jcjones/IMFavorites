# generated 2004/3/30 9:46:59 EST by pug@resmiranda.berthall.com.(none)
# using glademm V2.0.0.1
#
# newer (non customized) versions of this file go to Makefile.am_new
bin_PROGRAMS = imfavorites

imfavorites_SOURCES = imfavorites.cc	mainWindow_glade.cc 	mainWindow.cc 	fileSelection_glade.cc 	fileSelection.cc imfavorites_engine.cpp sqlite_db.cpp

noinst_HEADERS = mainWindow_glade.h mainWindow.h fileSelection_glade.h fileSelection.h imfavorites_engine.h sqlite_db.h

AM_CXXFLAGS = -Wno-deprecated @GTKMM_CFLAGS@

imfavorites_LDADD = /usr/lib/libsqlite.so @LIBS@ @GTKMM_LIBS@
imfavorites_DEPENDENCIES = /usr/include/sqlite.h


AM_CFLAGS = -Wno-deprecated
