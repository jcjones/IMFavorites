//
// C++ Interface: imfavorites_engine
//
// Description:
//      The meat of IMFavorites - you can interface this with anything.
//
// Author: James Pug Jones <pug AT ufl DOT edu>, (C) 2004
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef IMFAVORITES_ENGINE_H
#define IMFAVORITES_ENGINE_H

#include <iostream.h>
#include <string>

#include <sqlite_db.h>

#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

using namespace std;

/**
@author James Pug Jones
*/

typedef void (*imCallback)(class imfavorites_engine *, int delta) ;

class imfavorites_engine{
private:
    int     numFiles; /* number of files linked */
    int     numCrams; /* number of successful crams made */
    int     maxNum;   /* number of files to get */
    int     maxNumSet; /* True if we're going by number, false if going by size */
    int     maxSize;

    int     cram;     /* cram is 0 when disabled,
                     >0 when enabled, and
                     >1 when actively cramming. */
    int     verbose;  /* verbosity level (bigger is more verbose) */
    int     pretend;

    /* I feel special.. I need 64 bit computing for this!
    4.7 gigs in bytes is 4,928,307,200 > 4,294,967,294, which is the max
    for unsigned long int. */
    unsigned long long int  collectedSize;
    unsigned long long int  targetSize;

    string  symTargetDir;           /* The actual directory where we place links */
    string  mainMp3MaskDirectory;   /* The mask to subtract from filenames */

    /* Algorithm to find and return the optimum mask */
    string  findMask(sqlite_db*);
    int     checkConstraints(sqlite_db*);

    /* Return the filesize in bytes of a file ... this is long, but for huge songs
       it'd need to be long long. ;) */
    unsigned long   getFilesize(const char *);

    int     makeDirectory(string);
    int     makeTargetDirectory(string);

    int     symLinkFavorites(sqlite_db*);
    int     printFavorites(sqlite_db*);
    int     runFavorites(sqlite_db*);

    imCallback  cb;

public:
    imfavorites_engine();

    ~imfavorites_engine();

    bool    run();
    bool    setNumFiles(int);
    bool    setCram(int);
    bool    setVerbose(int);
    bool    setPretend(int);
    bool    setTargetSize(unsigned long);
    bool    setTargetDir(string);
    bool    setOutStream(void);

    void    printSummary(void);
    void    printOutSummary(void);
    unsigned long   getCollectedSizeMB();
    unsigned long   getTargetSizeMB();
    long    getCollectedFiles();
    long    getTargetCollectedFiles();
    int     isLimitedByNumber();

    void    setCallback ( imCallback c ) { cb = c ;    }
    imCallback  getCallback ( void ) const   { return cb ; }
    void    invokeCallback ( int delta ) { if ( cb != NULL ) (*cb)(this, delta) ; }


};

static void default_progress_cb (imfavorites_engine *, int Param);

#endif
