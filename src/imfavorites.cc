/***************************************************************************
*   Copyright (C) 2004 by James 'Pug' Jones                               *
*   <jcjones AT ufl DOT edu>                                              *
*                                                                         *
*   This program is free software; you can redistribute it and/or modify  *
*   it under the terms of the GNU General Public License as published by  *
*   the Free Software Foundation; either version 2 of the License, or     *
*   (at your option) any later version.                                   *
*                                                                         *
*   This program is distributed in the hope that it will be useful,       *
*   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
*   GNU General Public License for more details.                          *
*                                                                         *
*   You should have received a copy of the GNU General Public License     *
*   along with this program; if not, write to the                         *
*   Free Software Foundation, Inc.,                                       *
*   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
***************************************************************************/

#include <iostream.h>

#include "options.h"
#include "imfavorites_engine.h"

#undef ENABLE_NLS

using namespace std;

int main(int argc, char **argv)
{
#if defined(ENABLE_NLS)
   bindtextdomain (GETTEXT_PACKAGE, PACKAGE_LOCALE_DIR);
   bind_textdomain_codeset(GETTEXT_PACKAGE, "UTF-8");
   textdomain (GETTEXT_PACKAGE);
#endif //ENABLE_NLS

    const char * optv[] = {
        "s:maxsize SIZE",
        "n:maxnum NUMBER",
        "\05|cd \b",
        "\06|dvd \b",
        "c|cram \b",
        "l|list \b",          /* This is such a hack -- to make sure the option looks */
        "v|verbose", /* like the others, we use an esacped backspace... man I'm bad! */
        "?|help",
        " |version",
        NULL
    } ;

    Options opts(*argv, optv);
    OptArgvIter iter(--argc, ++argv);
    opts.ctrls(Options::PARSE_POS); /* the target path argument is "Positional" */
    const char *optarg, *str = NULL;
    int verbose=0, errors=0, pretend=0;

    imfavorites_engine* program = new imfavorites_engine();

    /* Parse our options */

    while( char optchar = opts(iter, optarg) ) {
      switch (optchar) {
        case 's' :
            if (optarg == NULL)  ++errors;
            program->setTargetSize(atoi(optarg));
            break;
        case '\05' :
            /* 700 meg CD size - max size is 737280000 bytes. We come up just short of that with this option. */
            program->setTargetSize(700);
            break;
        case '\06' :
            /* DVD size */
            program->setTargetSize(4700);
            break;
        case 'n' :
            if (optarg == NULL)  ++errors;
            program->setNumFiles(atoi(optarg));
            break;
        case 'v' :
            ++verbose;
            program->setVerbose(verbose);
            break;
        case 'l' :
            pretend=1;
            program->setPretend(1);
            program->setCallback(NULL); // Stop progress outputs
            break;
        case 'c' :
            program->setCram(1);
            break;
        case ' ' :
            cout << "Version " << program->getVersion() << endl;
            exit(1);
            break;
        case '?' :
            cout << opts.name() << " [OPTIONS] TARGET_PATH" << endl << endl;

            cout << "Limiting Options: (Whichever is reached first, size or number)" << endl;
            cout << "\t-s|--maxsize\t<size>\t Maximum size (MB) of resulting collection" << endl;
            cout << "\t\t\tDefault: 650 MB (74-min CD-R)" << endl;
            cout << "\t   --cd\t\t\t Set the size to 700 MB (80-min CD-R)" << endl;
            cout << "\t   --dvd\t\t Set the size to 4.7 GB (120-min DVD)" << endl;
            cout << "\t-c|--cram\t\t Cram some small files into leftover space." << endl;
            cout << "\t-n|--maxnum\t<num>\t Maximum number of songs to copy" << endl << endl;

            cout << "Location Options: ()" << endl;
            cout << "\tTARGET_PATH\t\t Path in which to put all the symbolic links" << endl;

            cout << "Alternative Modes:" << endl;
            cout << "\t-l|--list\t\t \"Pretend\" mode. Only prints the filenames" << endl << endl;

            cout << "Other:" << endl;
            cout << "\t-v|--verbose\t\t Increases the verbosity level (-vv for more)" << endl;
            cout << "\t   --version\t\t Displays the version" << endl;
            cout << "\t-?|--help\t\t What you're seeing" << endl << endl;

            cout << "Examples:" << endl;
            cout << "\t" << opts.name() << " --dvd --cram ~/mp3/favoritesDVD/" << endl;
            cout << "\t\tCram enough music to fill a 4.7 GB DVD with your favorites" << endl;
            cout << "\t\t(assuming you have that many!) to ~/mp3/favoritesDVD/" << endl << endl;

            cout << "\t" << opts.name() << " -n 10 ~/mp3/topten" << endl;
            cout << "\t\tCopy your top 10 pieces to ~/mp3/topten" << endl;

            cout << endl;

            exit(1);
            break;
        case Options::POSITIONAL :
            /* This option sets the target directory -- it's "Positional" */
            if (optarg == NULL)  ++errors;
            program->setTargetDir(optarg);
            break;
        default :
            ++errors;
            break;
      } //switch
    }

    // Print an error message if bad syntax was used, or if no
    // paths were specified on the command-line.
    if ( (errors) || ( !program->isReady() ) ) {
      opts.usage(cout, " TARGET_PATH...");
      exit(1);
    }

    if (!pretend) program->printSummary();

    program->run();

    if (!pretend) program->printOutSummary();

    return 0;
}

