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

#include "config.h"

#include <sqlite_db.h>

#ifdef HAVE_TAGLIB_TAGLIB_H
#include <taglib/taglib.h>
#include <taglib/fileref.h>
#include <taglib/tfile.h>
#endif // HAVE_TAGLIB_TAGLIB_H

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
    long     numFiles;  /* number of files linked */
    unsigned long long collectedSize; /* size of files collected */
    unsigned long collectedLength;     /* length of files collected */

    long     maxNum;    /* number of files to get */
    long     maxSize;   /* size to get in MB */
    unsigned long long targetSize; /* size to get in bytes - this needs to go */
    unsigned long targetLength; /* length to get in seconds */


    int     limitSetting; /* 0 if we're limiting by size
                             1 if we're limiting by number
                             2 if we're limiting by length */


    int     cram;      /* cram is 0 when disabled,
                          >0 when enabled, and
                          >1 when actively cramming. */
    int     numCrams;  /* number of successful crams made */


    int     verbose;   /* verbosity level (bigger is more verbose) */
    int     pretend;

    int     minScore;  /* Minimum score to copy */

    string  symTargetDir;           /* The actual directory where we place links */
    string  mainMp3MaskDirectory;   /* The mask to subtract from filenames */

    string  filenameMask;           /* The filtering mask for filenames, e.g. *mp3 */

    /* Algorithm to find and return the optimum mask */
    string  findMask();
    int     checkConstraints(void);

    /* Return the filesize in bytes of a file ... this is long, but for huge songs
       it'd need to be long long. ;) */
    unsigned long   getFilesize(const char *);
    unsigned long   getFileLength(const char *);

    int     makeDirectory(string);
    int     makeTargetDirectory(string);

    int     symLinkFavorites(void);
    int     printFavorites(void);
    int     runFavorites(void);

    imCallback  cb;
    sqlite_db*  database;

public:
    imfavorites_engine();

    ~imfavorites_engine();

    bool    run();
    bool    setCram(int);
    bool    setVerbose(int);
    bool    setPretend(int);
    bool    setTargetDir(string);
    bool    setOutStream(void);

    bool    setNumFiles(long);
    bool    setTargetSize(unsigned long);
    bool    setTargetLength(unsigned long);
    bool    setFilenameMask(string);
    bool    setMinScore(int);

    void    printSummary(void);
    void    printOutSummary(void);
    string  getVersion(void);

    unsigned long   getCollectedSizeMB(void);
    unsigned long   getTargetSizeMB(void);
    long    getCollectedFiles(void);
    long    getTargetCollectedFiles(void);
    unsigned long   getCollectedLength(void);
    unsigned long   getTargetLength(void);

    int     isLimitedByNumber(void);
    int     isLimitedByLength(void);
    int     isLimitedBySize(void);

    int     isReady(void);

    void    setCallback (imCallback c) { cb = c ;    }
    imCallback  getCallback (void) const   { return cb ; }
    void    invokeCallback (int delta) { if ( cb != NULL ) (*cb)(this, delta) ; }


};

static void default_progress_cb (imfavorites_engine *, int Param);


#endif
