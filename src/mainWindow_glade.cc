// generated 2004/4/5 14:56:36 EDT by pug@resmiranda.berthall.com.(none)
// using glademm V2.0.0.1
//
// DO NOT EDIT THIS FILE ! It was created using
// glade-- imfavorites.glade --header-suffix .h
// for gtk 2.2.4 and gtkmm 2.2.0
//
// Please modify the corresponding derived classes in ./src/mainWindow.cc


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
#include "mainWindow_glade.h"
#include <gdk/gdkkeysyms.h>
#include <gtkmm/accelgroup.h>
#include <gtkmm/label.h>
#include <gdkmm/pixbufloader.h>

static const unsigned char cdrom_umount_svgz_data[] = 
{       	31,139,8,8,38,19,110,61,0,3,99,114,115,99,45,100,
	101,118,105,99,101,45,99,100,114,111,109,95,117,109,111,117,
	110,116,0,237,90,107,111,27,71,18,252,236,0,249,15,27,
	6,56,36,192,206,114,222,15,89,74,32,146,162,207,128,146,
	24,177,156,32,56,28,2,102,69,75,68,104,82,32,233,135,
	242,235,175,106,118,41,83,22,73,73,135,59,92,14,136,1,
	137,218,71,247,244,244,84,87,215,12,125,248,237,135,55,211,
	226,221,120,177,156,204,103,71,29,85,201,78,49,158,213,243,
	243,201,236,226,168,51,89,206,69,140,46,9,213,249,246,155,
	207,63,59,252,66,136,162,63,191,186,94,76,46,46,87,7,
	69,127,113,189,92,141,166,197,243,122,62,91,22,95,245,191,
	254,248,176,208,82,234,226,183,235,226,4,190,71,211,243,57,
	30,141,167,151,243,226,112,220,222,168,234,249,155,111,138,209,
	236,188,56,155,47,150,171,241,172,248,113,116,57,43,14,87,
	163,250,247,209,42,63,253,236,73,113,58,169,199,179,229,248,
	160,56,125,246,226,20,215,207,198,51,152,175,230,139,131,226,
	248,124,254,219,184,120,62,157,190,93,174,242,173,34,85,178,
	44,94,254,244,172,56,249,112,53,95,172,138,23,211,183,23,
	226,249,172,40,132,200,209,15,126,232,159,253,242,226,164,88,
	190,187,40,94,188,234,157,62,239,23,29,209,237,254,108,250,
	221,238,224,108,144,77,17,183,148,70,154,226,229,234,122,58,
	250,109,58,238,118,79,190,239,20,69,209,185,92,173,174,14,
	186,221,247,239,223,87,239,77,53,95,92,116,207,126,236,242,
	245,174,52,221,159,7,2,214,98,109,77,119,93,12,115,115,
	67,44,91,119,213,249,234,188,83,252,227,243,207,158,28,126,
	113,242,253,217,243,179,95,138,229,74,22,157,249,213,168,158,
	172,174,15,100,229,158,190,158,76,167,7,111,23,211,175,190,
	28,77,46,22,231,241,235,167,152,225,252,247,241,193,108,62,
	27,63,237,124,115,219,88,21,157,79,12,252,126,3,125,199,
	192,236,55,48,155,225,233,79,195,83,251,141,237,166,113,188,
	243,216,109,62,78,119,30,251,59,177,186,253,195,133,77,127,
	118,239,171,241,142,111,189,223,119,218,146,135,47,101,254,183,
	127,133,100,59,82,126,186,247,205,118,49,197,226,237,52,191,
	242,199,120,49,127,90,79,39,87,183,239,52,67,15,243,191,
	181,195,219,151,226,253,228,124,117,121,176,14,76,188,153,172,
	198,139,233,4,31,7,246,238,176,119,33,17,238,1,29,48,
	177,247,249,173,101,247,113,191,51,119,103,120,123,119,248,127,
	178,134,89,186,69,158,26,200,202,218,171,85,167,184,28,147,
	112,110,46,223,77,198,239,123,243,15,71,29,89,200,2,247,
	248,211,41,192,114,7,75,196,51,62,234,92,45,198,203,241,
	226,221,184,137,226,162,152,156,31,117,78,71,215,227,197,175,
	31,192,89,242,87,213,41,88,172,120,243,111,92,144,38,218,
	39,135,87,163,213,229,230,3,249,180,83,192,242,59,184,47,
	241,243,119,249,147,188,196,231,59,252,252,209,233,110,181,73,
	107,19,105,170,148,92,169,180,174,98,242,181,44,99,229,141,
	23,218,84,42,224,182,195,149,21,78,85,193,235,246,170,22,
	58,86,46,198,82,54,247,173,240,112,145,214,23,237,75,82,
	208,145,41,27,71,205,93,83,110,190,99,234,236,39,148,178,
	108,253,135,114,115,32,115,19,251,116,50,27,143,22,207,22,
	163,243,201,120,182,202,89,106,202,189,83,92,180,55,95,205,
	38,171,229,81,231,45,210,249,146,185,253,97,246,106,57,70,
	174,21,22,195,85,42,233,212,41,174,113,17,66,101,148,193,
	3,141,7,26,44,224,28,30,232,155,7,121,192,39,135,203,
	213,252,170,40,230,175,95,47,199,88,78,121,179,12,188,47,
	234,249,20,164,223,98,188,141,241,83,19,181,213,164,41,208,
	245,180,186,183,231,181,117,157,76,187,78,198,85,73,186,82,
	187,42,168,154,171,163,181,199,90,87,214,97,173,66,229,131,
	47,109,170,116,136,34,85,201,248,18,211,9,177,86,248,109,
	98,201,60,151,14,156,102,93,105,82,21,163,41,131,197,178,
	24,250,179,218,215,217,95,20,217,31,94,167,191,32,178,63,
	95,210,95,20,244,23,226,75,151,42,101,0,50,85,105,167,
	203,205,160,254,40,190,11,186,210,49,149,17,174,189,171,133,
	169,100,196,171,85,82,73,132,202,38,91,130,5,165,67,128,
	209,70,60,53,193,231,204,97,58,149,113,6,119,66,52,130,
	0,80,192,142,149,6,182,70,11,37,241,91,215,217,27,158,
	38,192,4,206,4,124,169,146,174,48,37,184,178,53,157,216,
	50,59,41,233,196,151,116,226,97,98,84,40,179,23,119,47,
	162,244,131,16,101,36,178,32,91,68,41,100,77,135,92,216,
	196,148,196,120,209,180,160,66,178,149,87,59,64,85,73,165,
	244,86,152,164,120,60,28,234,29,200,130,93,114,113,187,221,
	160,103,134,102,167,157,74,209,109,181,59,238,247,134,67,183,
	211,206,40,105,183,218,245,237,64,15,227,78,59,171,227,246,
	249,157,248,147,254,176,191,211,110,123,144,123,203,13,70,42,
	134,237,118,97,152,134,39,59,237,188,146,219,199,27,184,193,
	201,240,120,167,93,144,118,123,141,247,142,251,199,67,191,219,
	46,165,237,73,57,14,189,222,208,238,180,3,57,111,159,95,
	234,247,244,78,176,108,15,241,22,190,30,68,67,113,77,67,
	166,242,50,177,226,149,141,45,15,197,134,135,98,195,67,49,
	243,80,67,67,105,147,134,2,105,200,166,208,16,81,104,136,
	200,54,68,228,110,17,81,104,136,200,111,18,81,84,153,136,
	82,75,68,253,132,50,64,233,163,107,73,88,59,95,161,230,
	88,228,62,149,183,98,4,45,121,24,146,150,112,187,33,37,
	147,73,41,102,82,210,153,148,98,38,165,144,73,201,110,144,
	146,221,32,37,157,73,41,110,144,146,203,164,100,62,146,146,
	18,217,89,166,37,159,105,41,108,208,146,202,180,100,50,45,
	209,200,232,134,149,244,189,172,100,30,214,231,164,71,18,141,
	212,13,47,37,7,130,145,161,165,37,229,34,46,67,108,120,
	73,35,217,102,163,123,158,45,70,179,229,235,249,226,205,81,
	231,205,104,181,152,124,248,10,128,179,169,192,124,156,142,182,
	184,249,200,55,19,194,150,65,135,194,171,88,5,109,213,215,
	143,102,184,158,66,145,236,46,102,165,228,118,134,235,249,254,
	96,143,29,38,181,189,152,251,110,16,247,216,25,111,182,87,
	202,96,112,178,207,238,223,99,42,237,183,39,101,24,135,251,
	146,226,77,242,187,130,244,123,236,130,115,59,232,251,120,111,
	82,98,216,197,112,195,129,124,164,240,233,245,54,214,237,65,
	140,163,91,198,241,64,131,213,101,148,84,60,53,0,169,21,
	155,191,113,154,191,83,20,164,98,222,113,1,101,73,92,78,
	5,250,179,9,144,39,10,93,65,213,44,50,138,9,93,121,
	72,6,48,76,194,21,164,95,128,76,50,161,114,46,53,34,
	117,10,115,167,29,233,198,59,83,179,172,45,253,66,13,155,
	42,42,199,27,96,10,148,85,194,141,228,252,189,117,107,31,
	88,183,1,195,187,16,90,61,33,53,24,142,56,110,10,215,
	91,244,168,182,110,21,197,140,210,127,21,238,95,133,251,167,
	45,92,229,214,149,27,81,171,104,140,20,158,211,92,146,208,
	248,44,73,219,143,232,129,172,69,244,36,25,202,224,170,168,
	75,13,108,163,109,123,40,0,52,118,149,208,202,212,148,21,
	153,119,54,222,233,90,81,76,163,95,75,52,81,180,85,155,
	123,119,214,255,116,134,167,50,220,148,228,197,102,68,230,233,
	26,231,159,196,106,255,127,72,102,119,236,255,203,52,119,47,
	238,166,59,220,155,109,132,128,17,162,66,101,132,156,237,72,
	229,100,114,30,152,107,159,115,29,130,195,239,100,166,130,251,
	116,169,75,75,181,84,171,44,94,168,6,161,37,53,133,95,
	35,64,161,252,240,130,196,126,84,25,166,66,224,197,168,153,
	104,40,231,156,104,197,76,131,217,152,88,207,191,99,12,200,
	180,71,190,177,108,202,222,159,106,95,57,105,75,8,74,109,
	220,148,81,9,219,8,65,1,102,142,192,12,50,141,25,104,
	74,47,203,123,198,67,84,134,74,186,188,237,85,246,20,121,
	199,82,192,131,116,30,153,150,136,0,243,135,66,196,222,153,
	127,170,24,153,104,195,205,178,138,123,243,172,236,174,68,223,
	84,96,200,178,19,202,23,248,98,162,77,246,11,248,50,201,
	208,205,24,131,112,86,158,127,41,53,213,22,59,121,83,90,
	15,197,28,152,105,147,66,198,98,36,110,192,237,60,185,137,
	26,40,194,139,17,19,101,38,252,105,192,228,129,47,100,154,
	144,166,8,135,180,101,242,117,165,52,129,163,168,226,49,89,
	206,205,69,179,51,209,235,192,93,66,225,88,98,26,91,200,
	83,195,116,70,214,143,142,169,166,246,246,64,171,203,138,29,
	91,139,196,83,6,143,49,16,143,106,118,5,17,33,196,169,
	181,140,159,145,3,190,53,243,201,226,213,64,63,60,184,128,
	232,116,34,160,141,119,130,29,248,78,182,119,245,117,247,160,
	190,142,122,51,46,181,167,4,9,185,212,65,181,77,29,11,
	227,115,51,201,98,220,162,252,36,182,202,255,221,179,167,164,
	146,123,220,166,207,183,171,161,185,69,227,17,10,171,68,115,
	55,199,109,28,146,172,128,21,199,38,28,185,155,51,60,86,
	226,26,229,173,151,214,53,54,103,216,18,241,120,132,236,199,
	243,53,47,44,132,135,201,7,55,60,21,66,245,90,208,20,
	86,59,36,238,229,248,129,189,92,146,249,136,201,201,188,153,
	75,201,230,35,38,31,251,138,21,147,137,64,106,112,88,133,
	129,177,127,116,229,237,8,177,231,83,18,0,197,43,14,100,
	177,62,102,2,70,60,136,3,148,17,80,130,153,169,241,2,
	226,214,30,117,27,29,16,140,8,192,229,188,2,169,56,4,
	128,240,17,106,224,246,78,38,71,94,149,228,153,202,102,32,
	2,151,249,36,203,73,205,51,209,196,157,43,226,181,216,54,
	130,8,66,226,77,12,130,55,243,208,162,25,154,196,4,196,
	53,35,151,28,217,139,118,100,205,73,123,58,49,209,49,120,
	208,50,96,234,108,166,12,133,120,57,83,175,238,85,158,254,
	97,202,19,206,98,43,59,177,22,62,153,245,41,22,214,88,
	187,96,219,163,209,246,209,35,240,153,142,123,234,145,248,180,
	22,168,50,143,82,26,155,29,16,189,23,69,149,84,94,102,
	158,77,98,217,28,187,115,178,134,231,201,216,109,163,206,146,
	203,29,219,74,188,199,230,8,172,162,233,161,197,33,229,14,
	224,0,195,43,172,13,40,38,1,138,232,80,86,129,56,145,
	116,39,179,23,237,20,23,142,134,48,176,134,199,17,17,250,
	0,43,11,146,172,5,64,142,155,128,105,72,158,31,42,233,
	220,13,172,94,95,161,27,68,3,54,2,31,122,75,222,117,
	249,244,1,2,24,76,228,44,215,222,251,208,32,22,245,67,
	55,154,138,174,57,43,48,60,114,177,164,99,202,74,77,2,
	70,91,107,212,71,16,158,225,146,39,201,240,72,74,74,249,
	136,214,2,108,84,39,168,139,4,28,7,202,148,128,226,205,
	21,234,33,70,148,205,167,34,152,68,2,137,162,68,149,73,
	40,81,15,242,15,60,226,69,10,8,136,104,121,196,19,124,
	98,83,13,158,32,79,68,174,65,19,67,138,160,94,144,42,
	120,228,84,232,209,51,45,9,142,179,71,206,18,172,92,54,
	30,219,146,164,87,93,102,175,89,127,4,84,33,221,74,85,
	102,199,177,108,28,223,11,248,240,32,192,59,40,49,233,210,
	13,226,131,147,237,62,43,176,110,163,190,1,124,126,242,167,
	3,188,254,216,31,149,49,212,171,160,173,154,188,233,73,74,
	160,217,144,233,210,67,220,37,82,40,215,2,51,139,190,54,
	205,215,58,149,134,170,67,95,196,223,33,139,83,128,206,43,
	98,76,165,192,67,47,80,176,160,154,210,130,174,34,48,165,
	93,70,180,55,236,146,137,196,151,125,81,177,64,69,217,44,
	42,178,47,74,91,231,201,172,164,96,79,66,204,252,28,92,
	170,249,8,61,131,84,137,33,173,14,160,87,159,21,143,6,
	113,147,201,99,123,238,134,218,161,134,3,209,42,56,119,158,
	34,80,75,131,64,208,83,24,160,204,26,35,240,8,77,5,
	126,37,0,181,8,154,143,190,249,19,193,185,136,250,226,1,
	27,21,142,229,172,65,160,235,62,47,13,234,133,199,183,34,
	143,81,114,12,214,161,198,168,62,235,21,142,17,238,69,92,
	124,16,226,40,63,53,143,235,111,16,215,106,128,152,53,119,
	218,0,220,174,239,9,254,83,120,131,226,56,62,182,143,193,
	219,250,123,69,135,172,57,197,47,118,64,149,53,184,4,221,
	49,98,47,148,191,31,100,247,199,146,67,240,178,131,27,0,
	0,60,236,77,205,47,5,185,130,198,225,93,99,178,16,136,
	158,176,1,66,51,141,217,154,188,100,130,160,175,32,178,47,
	39,178,175,40,116,115,254,74,95,192,37,157,17,182,142,188,
	102,0,125,58,11,74,100,134,44,179,51,7,204,81,59,128,
	84,35,16,168,98,198,41,191,151,196,189,12,28,16,151,226,
	249,50,186,40,89,144,93,89,219,246,184,23,238,44,191,130,
	146,108,36,164,111,202,216,76,249,54,82,10,24,101,88,66,
	137,127,83,143,192,91,40,179,55,39,232,45,75,80,109,80,
	28,217,83,105,214,59,128,144,143,152,61,231,79,95,33,83,
	241,90,216,55,74,243,144,255,61,3,159,255,2,120,145,140,
	137,1,35,0,0,

};

#include <gtkmm/box.h>
#include <gtkmm/radiobutton.h>
#include <gtkmm/adjustment.h>
#include <gtkmm/table.h>
#include <gtkmm/image.h>
#include <gtkmm/alignment.h>
#include <gtkmm/button.h>

mainWindow_glade::mainWindow_glade(
) : Gtk::Window(Gtk::WINDOW_TOPLEVEL)
{  mainWindow = this;
   gmm_data = new GlademmData(get_accel_group());
   
   Gtk::Label *label1 = Gtk::manage(new class Gtk::Label(_("Select your limiting\n"
		"options and press\n"
		"<span weight=\"bold\">Start</span> to link your \n"
		"favorite songs into\n"
		"your Target Directory.")));
   Glib::RefPtr<Gdk::PixbufLoader> _image1_loader=Gdk::PixbufLoader::create();
   _image1_loader->write(cdrom_umount_svgz_data, sizeof cdrom_umount_svgz_data);
   _image1_loader->close();
   image1 = Gtk::manage(new class Gtk::Image(_image1_loader->get_pixbuf()));
   
   Gtk::VBox *vbox2 = Gtk::manage(new class Gtk::VBox(false, 0));
   Gtk::RadioButton::Group _RadioBGroup_sizeOtherRadio;
   sizeOtherRadio = Gtk::manage(new class Gtk::RadioButton(_RadioBGroup_sizeOtherRadio, _("_Other size (MB)"), true));
   
   Gtk::RadioButton::Group _RadioBGroup_limitSizeRadio;
   limitSizeRadio = Gtk::manage(new class Gtk::RadioButton(_RadioBGroup_limitSizeRadio, _("_Fit collection to a size"), true));
   sizeCDRadio = Gtk::manage(new class Gtk::RadioButton(_RadioBGroup_sizeOtherRadio, _("_CD (700 MB)"), true));
   sizeCD2Radio = Gtk::manage(new class Gtk::RadioButton(_RadioBGroup_sizeOtherRadio, _("CD (650 _MB)"), true));
   sizeDVDRadio = Gtk::manage(new class Gtk::RadioButton(_RadioBGroup_sizeOtherRadio, _("_DVD (4.7 GB)"), true));
   cramCheckBox = Gtk::manage(new class Gtk::CheckButton(_("C_ram in as many songs\n"
		"as possible"), true));
   limitNumberRadio = Gtk::manage(new class Gtk::RadioButton(_RadioBGroup_limitSizeRadio, _("Pick a certain _number of songs"), true));
   
   Gtk::Adjustment *numSongsSpinButton_adj = Gtk::manage(new class Gtk::Adjustment(10, 1, 9999, 1, 10, 10));
   numSongsSpinButton = Gtk::manage(new class Gtk::SpinButton(*numSongsSpinButton_adj, 1, 0));
   
   Gtk::Label *label6 = Gtk::manage(new class Gtk::Label(_("<span weight=\"bold\">Limting Options</span>")));
   Gtk::Label *label5 = Gtk::manage(new class Gtk::Label(_("<span weight=\"bold\">Target Directory</span>")));
   directoryEntry = Gtk::manage(new class Gtk::Entry());
   
   Gtk::Adjustment *otherSizeSpinButton_adj = Gtk::manage(new class Gtk::Adjustment(180, 1, 9999, 10, 100, 10));
   otherSizeSpinButton = Gtk::manage(new class Gtk::SpinButton(*otherSizeSpinButton_adj, 1, 0));
   browseButton = Gtk::manage(new class Gtk::Button(_("_Browse"), true));
   
   Gtk::Label *label16 = Gtk::manage(new class Gtk::Label(_("")));
   Gtk::Label *label18 = Gtk::manage(new class Gtk::Label(_("Place symbolic links in...")));
   Gtk::Label *label19 = Gtk::manage(new class Gtk::Label(_("")));
   Gtk::Table *table2 = Gtk::manage(new class Gtk::Table(2, 2, false));
   Gtk::HBox *hbox1 = Gtk::manage(new class Gtk::HBox(false, 0));
   Gtk::Image *image2 = Gtk::manage(new class Gtk::Image(Gtk::StockID("gtk-apply"), Gtk::IconSize(4)));
   Gtk::Label *label4 = Gtk::manage(new class Gtk::Label(_("_Start"), true));
   Gtk::HBox *hbox4 = Gtk::manage(new class Gtk::HBox(false, 2));
   Gtk::Alignment *alignment1 = Gtk::manage(new class Gtk::Alignment(0.5, 0.5, 0, 0));
   Gtk::Button *startButton = Gtk::manage(new class Gtk::Button());
   progressbar1 = Gtk::manage(new class Gtk::ProgressBar());
   
   Gtk::VBox *vbox1 = Gtk::manage(new class Gtk::VBox(false, 0));
   label1->set_alignment(0.5,0.5);
   label1->set_padding(12,12);
   label1->set_justify(Gtk::JUSTIFY_FILL);
   label1->set_line_wrap(true);
   label1->set_use_markup(true);
   label1->set_selectable(false);
   image1->set_alignment(0.5,0.5);
   image1->set_padding(0,0);
   vbox2->pack_start(*label1, Gtk::PACK_SHRINK, 0);
   vbox2->pack_start(*image1);
   sizeOtherRadio->set_flags(Gtk::CAN_FOCUS);
   _tooltips.set_tip(*sizeOtherRadio, _("Enter another size (in Megabytes)"), "");
   sizeOtherRadio->set_border_width(4);
   sizeOtherRadio->set_relief(Gtk::RELIEF_NORMAL);
   sizeOtherRadio->set_mode(true);
   sizeOtherRadio->set_active(false);
   limitSizeRadio->set_flags(Gtk::CAN_FOCUS);
   _tooltips.set_tip(*limitSizeRadio, _("If you want to fit songs into a particular amount of space, use this option"), "");
   limitSizeRadio->set_relief(Gtk::RELIEF_NORMAL);
   limitSizeRadio->set_mode(true);
   limitSizeRadio->set_active(true);
   sizeCDRadio->set_flags(Gtk::CAN_FOCUS);
   _tooltips.set_tip(*sizeCDRadio, _("Fill a 80-minute CD-R"), "");
   sizeCDRadio->set_border_width(4);
   sizeCDRadio->set_relief(Gtk::RELIEF_NORMAL);
   sizeCDRadio->set_mode(true);
   sizeCDRadio->set_active(true);
   sizeCD2Radio->set_flags(Gtk::CAN_FOCUS);
   _tooltips.set_tip(*sizeCD2Radio, _("Fill a 74-minute CD-R"), "");
   sizeCD2Radio->set_border_width(4);
   sizeCD2Radio->set_relief(Gtk::RELIEF_NORMAL);
   sizeCD2Radio->set_mode(true);
   sizeCD2Radio->set_active(false);
   sizeDVDRadio->set_flags(Gtk::CAN_FOCUS);
   _tooltips.set_tip(*sizeDVDRadio, _("Fill a 120-minute DVD-R"), "");
   sizeDVDRadio->set_border_width(4);
   sizeDVDRadio->set_relief(Gtk::RELIEF_NORMAL);
   sizeDVDRadio->set_mode(true);
   sizeDVDRadio->set_active(false);
   cramCheckBox->set_flags(Gtk::CAN_FOCUS);
   _tooltips.set_tip(*cramCheckBox, _("Cram some small files into leftover space; with this enabled, some less-liked but shorter songs will be added to fill up remaining space in the collection"), "");
   cramCheckBox->set_border_width(4);
   cramCheckBox->set_relief(Gtk::RELIEF_NORMAL);
   cramCheckBox->set_mode(true);
   cramCheckBox->set_active(true);
   limitNumberRadio->set_flags(Gtk::CAN_FOCUS);
   _tooltips.set_tip(*limitNumberRadio, _("If you only want your favorite 10, 15, or other number of songs, then use this option"), "");
   limitNumberRadio->set_relief(Gtk::RELIEF_NORMAL);
   limitNumberRadio->set_mode(true);
   limitNumberRadio->set_active(false);
   numSongsSpinButton->set_flags(Gtk::CAN_FOCUS);
   _tooltips.set_tip(*numSongsSpinButton, _("Number of songs in resulting collection"), "");
   numSongsSpinButton->set_update_policy(Gtk::UPDATE_ALWAYS);
   numSongsSpinButton->set_numeric(true);
   numSongsSpinButton->set_digits(0);
   numSongsSpinButton->set_wrap(false);
   label6->set_alignment(0,0.5);
   label6->set_padding(0,0);
   label6->set_justify(Gtk::JUSTIFY_LEFT);
   label6->set_line_wrap(false);
   label6->set_use_markup(true);
   label6->set_selectable(false);
   label5->set_alignment(0,0.5);
   label5->set_padding(0,0);
   label5->set_justify(Gtk::JUSTIFY_LEFT);
   label5->set_line_wrap(false);
   label5->set_use_markup(true);
   label5->set_selectable(false);
   directoryEntry->set_flags(Gtk::CAN_FOCUS);
   _tooltips.set_tip(*directoryEntry, _("The directory where all song symbolic links will be placed"), "");
   directoryEntry->set_visibility(true);
   directoryEntry->set_editable(true);
   directoryEntry->set_max_length(0);
   directoryEntry->set_text(_("~/mp3/favorites/"));
   directoryEntry->set_has_frame(true);
   directoryEntry->set_activates_default(false);
   otherSizeSpinButton->set_flags(Gtk::CAN_FOCUS);
   _tooltips.set_tip(*otherSizeSpinButton, _("Size in Megabytes of resulting collection"), "");
   otherSizeSpinButton->set_update_policy(Gtk::UPDATE_ALWAYS);
   otherSizeSpinButton->set_numeric(true);
   otherSizeSpinButton->set_digits(0);
   otherSizeSpinButton->set_wrap(false);
   browseButton->set_flags(Gtk::CAN_FOCUS);
   _tooltips.set_tip(*browseButton, _("Browse for a target directory"), "");
   browseButton->set_relief(Gtk::RELIEF_NORMAL);
   label16->set_size_request(20,-1);
   label16->set_alignment(0,0.5);
   label16->set_padding(0,0);
   label16->set_justify(Gtk::JUSTIFY_LEFT);
   label16->set_line_wrap(false);
   label16->set_use_markup(false);
   label16->set_selectable(false);
   label18->set_alignment(0,0.5);
   label18->set_padding(0,0);
   label18->set_justify(Gtk::JUSTIFY_LEFT);
   label18->set_line_wrap(false);
   label18->set_use_markup(false);
   label18->set_selectable(false);
   label19->set_size_request(20,-1);
   label19->set_alignment(0,0.5);
   label19->set_padding(0,0);
   label19->set_justify(Gtk::JUSTIFY_LEFT);
   label19->set_line_wrap(false);
   label19->set_use_markup(false);
   label19->set_selectable(false);
   table2->set_row_spacings(0);
   table2->set_col_spacings(0);
   table2->attach(*sizeOtherRadio, 2, 3, 9, 10, Gtk::FILL, Gtk::AttachOptions(), 0, 0);
   table2->attach(*limitSizeRadio, 1, 4, 5, 6, Gtk::FILL, Gtk::AttachOptions(), 0, 0);
   table2->attach(*sizeCDRadio, 2, 4, 6, 7, Gtk::FILL, Gtk::AttachOptions(), 0, 0);
   table2->attach(*sizeCD2Radio, 2, 4, 7, 8, Gtk::FILL, Gtk::AttachOptions(), 0, 0);
   table2->attach(*sizeDVDRadio, 2, 4, 8, 9, Gtk::FILL, Gtk::AttachOptions(), 0, 0);
   table2->attach(*cramCheckBox, 2, 4, 10, 11, Gtk::FILL, Gtk::AttachOptions(), 0, 0);
   table2->attach(*limitNumberRadio, 1, 4, 12, 13, Gtk::FILL, Gtk::AttachOptions(), 0, 0);
   table2->attach(*numSongsSpinButton, 2, 4, 13, 14, Gtk::EXPAND|Gtk::FILL, Gtk::AttachOptions(), 0, 0);
   table2->attach(*label6, 0, 4, 4, 5, Gtk::FILL, Gtk::AttachOptions(), 0, 0);
   table2->attach(*label5, 0, 4, 0, 1, Gtk::FILL, Gtk::AttachOptions(), 0, 0);
   table2->attach(*directoryEntry, 1, 3, 2, 3, Gtk::EXPAND|Gtk::FILL, Gtk::AttachOptions(), 0, 0);
   table2->attach(*otherSizeSpinButton, 3, 4, 9, 10, Gtk::EXPAND|Gtk::FILL, Gtk::AttachOptions(), 0, 0);
   table2->attach(*browseButton, 3, 4, 2, 3, Gtk::FILL, Gtk::AttachOptions(), 0, 0);
   table2->attach(*label16, 1, 2, 3, 4, Gtk::FILL, Gtk::AttachOptions(), 0, 0);
   table2->attach(*label18, 1, 4, 1, 2, Gtk::FILL, Gtk::AttachOptions(), 0, 0);
   table2->attach(*label19, 0, 1, 3, 4, Gtk::FILL, Gtk::AttachOptions(), 0, 0);
   hbox1->pack_start(*vbox2);
   hbox1->pack_start(*table2, Gtk::PACK_EXPAND_WIDGET, 5);
   image2->set_alignment(0.5,0.5);
   image2->set_padding(0,0);
   label4->set_alignment(0.5,0.5);
   label4->set_padding(0,0);
   label4->set_justify(Gtk::JUSTIFY_LEFT);
   label4->set_line_wrap(false);
   label4->set_use_markup(false);
   label4->set_selectable(false);
   hbox4->pack_start(*image2, Gtk::PACK_SHRINK, 0);
   hbox4->pack_start(*label4, Gtk::PACK_SHRINK, 0);
   alignment1->add(*hbox4);
   startButton->set_flags(Gtk::CAN_FOCUS);
   _tooltips.set_tip(*startButton, _("Start symbolically linking"), "");
   startButton->set_border_width(4);
   startButton->set_relief(Gtk::RELIEF_NORMAL);
   startButton->add(*alignment1);
   _tooltips.set_tip(*progressbar1, _("Current progress"), "");
   vbox1->pack_start(*hbox1);
   vbox1->pack_start(*startButton, Gtk::PACK_SHRINK, 0);
   vbox1->pack_start(*progressbar1, Gtk::PACK_SHRINK, 0);
   mainWindow->set_border_width(2);
   mainWindow->set_title(_("IMMS Magical Favorites Collector"));
   mainWindow->set_modal(false);
   mainWindow->property_window_position().set_value(Gtk::WIN_POS_NONE);
   mainWindow->set_resizable(true);
   mainWindow->property_destroy_with_parent().set_value(false);
   mainWindow->add(*vbox1);
   label1->show();
   image1->show();
   vbox2->show();
   sizeOtherRadio->show();
   limitSizeRadio->show();
   sizeCDRadio->show();
   sizeCD2Radio->show();
   sizeDVDRadio->show();
   cramCheckBox->show();
   limitNumberRadio->show();
   numSongsSpinButton->show();
   label6->show();
   label5->show();
   directoryEntry->show();
   otherSizeSpinButton->show();
   browseButton->show();
   label16->show();
   label18->show();
   label19->show();
   table2->show();
   hbox1->show();
   image2->show();
   label4->show();
   hbox4->show();
   alignment1->show();
   startButton->show();
   progressbar1->show();
   vbox1->show();
   mainWindow->show();
   sizeOtherRadio->signal_toggled().connect(SigC::slot(*this, &mainWindow_glade::on_sizeOtherRadio_toggled));
   limitSizeRadio->signal_toggled().connect(SigC::slot(*this, &mainWindow_glade::on_limitRadio_toggled));
   sizeCDRadio->signal_toggled().connect(SigC::slot(*this, &mainWindow_glade::on_SizeCDRadio_toggled));
   sizeCD2Radio->signal_toggled().connect(SigC::slot(*this, &mainWindow_glade::on_sizeCD2Radio_toggled));
   sizeDVDRadio->signal_toggled().connect(SigC::slot(*this, &mainWindow_glade::on_sizeDVDRadio_toggled));
   cramCheckBox->signal_toggled().connect(SigC::slot(*this, &mainWindow_glade::on_cramCheckBox_toggled));
   limitNumberRadio->signal_toggled().connect(SigC::slot(*this, &mainWindow_glade::on_limitNumberRadio_toggled));
   numSongsSpinButton->signal_changed().connect(SigC::slot(*this, &mainWindow_glade::on_numSongsSpinButton_changed));
   browseButton->signal_activate().connect(SigC::slot(*this, &mainWindow_glade::on_browseButton_activate));
   browseButton->signal_clicked().connect(SigC::slot(*this, &mainWindow_glade::on_browseButton_activate));
   startButton->signal_activate().connect(SigC::slot(*this, &mainWindow_glade::on_startButton_activate));
   startButton->signal_clicked().connect(SigC::slot(*this, &mainWindow_glade::on_startButton_activate));
}

mainWindow_glade::~mainWindow_glade()
{  delete gmm_data;
}
