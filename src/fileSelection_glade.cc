// generated 2004/3/31 16:44:04 EST by pug@resmiranda.berthall.com.(none)
// using glademm V2.0.0.1
//
// DO NOT EDIT THIS FILE ! It was created using
// glade-- imfavorites.glade --header-suffix .h
// for gtk 2.2.4 and gtkmm 2.2.0
//
// Please modify the corresponding derived classes in ./src/fileSelection.cc


#if defined __GNUC__ && __GNUC__ < 3
#error This program will crash if compiled with g++ 2.x
// see the dynamic_cast bug in the gtkmm FAQ
#endif //
#include "config.h"
/*
 * Standard gettext macros.
 */
#ifdef ENABLE_NLS
#  include <libintl.h>
#  undef _
#  define _(String) dgettext (GETTEXT_PACKAGE, String)
#  ifdef gettext_noop
#    define N_(String) gettext_noop (String)
#  else
#    define N_(String) (String)
#  endif
#else
#  define textdomain(String) (String)
#  define gettext(String) (String)
#  define dgettext(Domain,Message) (Message)
#  define dcgettext(Domain,Message,Type) (Message)
#  define bindtextdomain(Domain,Directory) (Domain)
#  define _(String) (String)
#  define N_(String) (String)
#endif
#include "fileSelection_glade.h"
#include <gdk/gdkkeysyms.h>
#include <gtkmm/accelgroup.h>
#include <gtkmm/button.h>

fileSelection_glade::fileSelection_glade(
) : Gtk::FileSelection(_("Select Directory"))
{  fileSelection = this;
   gmm_data = new GlademmData(get_accel_group());
   fileSelection->get_cancel_button()->set_flags(Gtk::CAN_FOCUS);
   fileSelection->get_cancel_button()->set_relief(Gtk::RELIEF_NORMAL);
   fileSelection->get_ok_button()->set_flags(Gtk::CAN_FOCUS);
   fileSelection->get_ok_button()->set_relief(Gtk::RELIEF_NORMAL);
   fileSelection->set_border_width(10);
   fileSelection->set_title(_("Select Directory"));
   fileSelection->set_modal(false);
   fileSelection->property_window_position().set_value(Gtk::WIN_POS_NONE);
   fileSelection->set_resizable(true);
   fileSelection->property_destroy_with_parent().set_value(true);
   fileSelection->show_fileop_buttons();
   fileSelection->show();
   fileSelection->signal_close().connect(SigC::slot(*this, &fileSelection_glade::on_fileSelection_close));
}

fileSelection_glade::~fileSelection_glade()
{  delete gmm_data;
}