// generated 2004/3/30 10:08:39 EST by pug@resmiranda.berthall.com.(none)
// using glademm V2.0.0.1
//
// newer (non customized) versions of this file go to mainWindow.h_new

// you might replace
//    class foo : public foo_glade { ... };
// by
//    typedef foo_glade foo;
// if you didn't make any modifications to the widget

#ifndef _MAINWINDOW_H
#  include "mainWindow_glade.h"
#  define _MAINWINDOW_H

#ifndef GTKMM_IS_PRESENT
#error "Can't compile this without GTKMM, use the --with-gtkmm configure flag."
#endif

#include <imfavorites_engine.h>

static void progress_callback(imfavorites_engine* engine, int songs);

class mainWindow : public mainWindow_glade
{
public:
        mainWindow();
        void setProgressBar(double prog);
        void setProgressBar(string text);
        void update();

private:
        void on_browseButton_activate();
        void on_SizeCDRadio_toggled();
        void on_sizeCD2Radio_toggled();
        void on_sizeDVDRadio_toggled();
        void on_sizeOtherRadio_toggled();
        void on_limitRadio_toggled();
        void on_numSongsSpinButton_changed();
        void on_limitNumberRadio_toggled();
        void on_limitLengthRadio_toggled();
        void on_cramCheckBox_toggled();
        void on_pretendCheckBox_toggled();
        void on_startButton_activate();
        void on_all1_activate();
        void on_mp3_activate();
        void on_ogg_vorbis1_activate();
        void on_windows_media1_activate();
        void on_aac1_activate();


        string findPixmap(string);
        unsigned long getSize();
        void printValues();

};
#endif

