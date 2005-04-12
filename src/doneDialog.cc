// generated 2004/4/17 21:33:30 EDT by pug@resmiranda.berthall.com.(none)
// using glademm V2.0.0.1
//
// newer (non customized) versions of this file go to doneDialog.cc_new

// This file is for your program, I won't touch it again!

#include "config.h"
#include "doneDialog.h"
#include <gtkmm/main.h>

void doneDialog::on_doneDialog_close_clicked()
{
    Gtk::Main::instance()->quit();
}

void doneDialog::on_doneDialog_ok_clicked()
{
    this->signal_close();
}
