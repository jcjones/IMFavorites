//
// C++ Implementation: mainWindow
//
// Description:
//  GTK2 front-end for IMFavorites. Uses SVG. :)
//
// Author: James Pug Jones <pug AT ufl DOT edu>, (C) 2004
//
// Copyright: See COPYING file that comes with this distribution
//
//
#include "config.h"
#include "mainWindow.h"
#include "fileSelection.h"

#define cd_image "cdrom_umount.svgz"
#define dvd_image "dvd_umount.svgz"
#define number_image "poundsign.svgz"
#define portableaudio_image "cdrom_umount.svgz"

extern mainWindow *mainWindow;

static void progress_callback(imfavorites_engine* engine, int songs) {
    double fraction;
    string text = "Running";

    if (engine->isLimitedByNumber()) {
        // We're limiting by number
        fraction = double(engine->getCollectedFiles())/double(engine->getTargetCollectedFiles());
    } else {
        // We're limiting by size
        fraction = double (engine->getCollectedSizeMB())/double(engine->getTargetSizeMB());
    }

    if (fraction > 1) fraction = 1;

    mainWindow->setProgressBar(fraction);
    mainWindow->setProgressBar(text);

    mainWindow->update();
}

mainWindow::mainWindow() {
    directoryEntry->set_text(string(getenv("HOME")).append("/"));
}


void mainWindow::update() {
    //this->mainWindow->
}

void mainWindow::setProgressBar(double progress) {
    progressbar1->set_fraction(progress);
}

void mainWindow::setProgressBar(string text) {
    progressbar1->set_text(text);
}

void mainWindow::on_browseButton_activate()
{
    struct stat dir;
    int statreturn = 0;
    fileSelection *fileSelection = new class fileSelection();

    fileSelection->set_filename(directoryEntry->get_text());

    // Hide the file list portion to make this into a directory browser.
    fileSelection->get_file_list()->get_parent()->hide();

    fileSelection->run();

    string pathName = fileSelection->get_filename();

    // if this is a directory, add a trailing
    // slash. If not, then axe the filename.
    statreturn = stat(pathName.c_str(),&dir);

    /* Get the stat structure of the directory, then check
       using the POSIX macro whether it's a dir */

    if ( S_ISDIR (dir.st_mode) ) {
        pathName = pathName.append("/");
    }

    if (pathName.find_last_of("/") != pathName.length() ) {
        pathName.erase(pathName.find_last_of("/")+1,pathName.length());
    }

    directoryEntry->set_text(pathName);

    delete fileSelection;
}

void mainWindow::on_SizeCDRadio_toggled()
{
    image1->set(this->findPixmap(cd_image));
}

void mainWindow::on_sizeCD2Radio_toggled()
{
    image1->set(this->findPixmap(cd_image));
}

void mainWindow::on_sizeDVDRadio_toggled()
{
    image1->set(this->findPixmap(dvd_image));
}

void mainWindow::on_sizeOtherRadio_toggled()
{
    image1->set(this->findPixmap(portableaudio_image));

}

void mainWindow::on_limitRadio_toggled()
{
    if (sizeDVDRadio->get_active()) image1->set(this->findPixmap(dvd_image));
    else image1->set(this->findPixmap(cd_image));

    numSongsSpinButton->set_sensitive(false);
    sizeCDRadio->set_sensitive(true);
    sizeCD2Radio->set_sensitive(true);
    sizeOtherRadio->set_sensitive(true);
    sizeDVDRadio->set_sensitive(true);
    cramCheckBox->set_sensitive(true);
}

void mainWindow::on_numSongsSpinButton_changed()
{
}

void mainWindow::on_limitNumberRadio_toggled()
{
    image1->set(this->findPixmap(number_image));
    numSongsSpinButton->set_sensitive(true);
    sizeCDRadio->set_sensitive(false);
    sizeCD2Radio->set_sensitive(false);
    sizeOtherRadio->set_sensitive(false);
    sizeDVDRadio->set_sensitive(false);
    cramCheckBox->set_sensitive(false);
}

void mainWindow::on_cramCheckBox_toggled()
{  
}

void mainWindow::on_startButton_activate()
{
    //this->printValues();

    progressbar1->set_fraction(0);
    progressbar1->set_text("Running...");

    imfavorites_engine *program = new imfavorites_engine();
    program->setTargetDir(directoryEntry->get_text());

    if (limitSizeRadio->get_active())
        program->setTargetSize(this->getSize());
    else
        program->setNumFiles(numSongsSpinButton->get_value_as_int());

    program->setPretend(0);
    program->setCram(cramCheckBox->get_active());
    program->setVerbose(0);

    program->setCallback(progress_callback);

    program->run();

    //progressbar1->set_fraction(1);
    progressbar1->set_text("Done!");
}

unsigned long mainWindow::getSize() {
    if (sizeCDRadio->get_active()) return 700;
    if (sizeCD2Radio->get_active()) return 650;
    if (sizeDVDRadio->get_active()) return 4700;
    if (sizeOtherRadio->get_active()) return otherSizeSpinButton->get_value_as_int();

    // should not get here...
    return 0;
}

void mainWindow::printValues() {
    cout << " Dir: " << directoryEntry->get_text() << endl;
    cout << " SizeOn?: " << limitSizeRadio->get_active() << endl;
    cout << " NumOn?: " << limitNumberRadio->get_active() << endl;
    cout << " Size: " << this->getSize() << endl;
    cout << " NumSongs: " << numSongsSpinButton->get_value_as_int() << endl;
    cout << " Cram: " << cramCheckBox->get_active() << endl;
}

string mainWindow::findPixmap(string pixmap_filename) {
    string pathName;
    struct stat file;
    int statreturn = 0;

    // look for pixmap in the following places...
    string locations[6] = { "", // Current working directory
        "pixmaps/",
        "/usr/share/pixmaps/imfavorites/",
        "/usr/share/pixmaps/",
        "/usr/local/share/pixmaps/imfavorites/",
        "/usr/local/share/pixmaps/"
        };

    for(int i = 0; i < 6; i++) {
        pathName = string(locations[i]).append(pixmap_filename);

        statreturn = stat(pathName.c_str(),&file);
        // Return the full path if the file exists.
        if (S_ISREG(file.st_mode)) return pathName;

    }

    cerr << "Could not find " << pixmap_filename << endl;
    return pixmap_filename;
}
