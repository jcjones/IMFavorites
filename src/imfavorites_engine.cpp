//
// C++ Implementation: imfavorites_engine
//
// Description:
//  The meat of IMFavorites - you can interface this with anything.
//
// Author: James Pug Jones <pug AT ufl DOT edu>, (C) 2004
//
// Copyright: See COPYING file that comes with this distribution
//
//
#include "imfavorites_engine.h"

#define IMFAVORITES_VERSION "0.4, 17 April 2004"

imfavorites_engine::imfavorites_engine() {
    string pathToDB = string(getenv("HOME")).append("/.imms/imms.db");

    // Variable init
    numFiles    = 0; // number of files linked
    numCrams    = 0; // number of successful crams made
    cram        = 0; // cram is 0 when disabled,
                     //  >0 when enabled, and
                     //  >1 when actively cramming.
    verbose     = 0; // verbosity level (bigger is more verbose)

    collectedSize = 0;

    // Init through helpers
    this->setNumFiles(99999);
    this->setTargetSize(650);

    // Set paths' defaults
    symTargetDir = "";           // The actual directory where we place links
    mainMp3MaskDirectory = "";   // The mask to subtract from filenames

    // Initial callback (can be overridden)
    this->setCallback(default_progress_cb);

    // Start the DB
    database = new sqlite_db();

    if (verbose) cout << "Opening database..." << endl;
    database->open(pathToDB);

    if (!database->isOpen()) cerr << "Failed to open DB at " <<  pathToDB << endl;
    else mainMp3MaskDirectory = this->findMask();
}

imfavorites_engine::~imfavorites_engine() {
    delete database;
}

bool imfavorites_engine::setNumFiles(int in) {
    maxNumSet = 1;
    maxNum = in;
    return true;
}

bool imfavorites_engine::setCram(int in) {
    cram = in;
    return true;
}

bool imfavorites_engine::setVerbose(int in) {
    verbose = in;
    return true;;
}

bool imfavorites_engine::setTargetSize(unsigned long size ) {
    maxNumSet = 0;
    maxSize = size;
    targetSize = (unsigned long long int)size * 1048576 ; // convert megs into bytes
    return true;
}

bool imfavorites_engine::setTargetDir(string in) {
    symTargetDir = in;
    /* Replace ~ with HOME */
    if (symTargetDir.find("~") != string::npos)
        symTargetDir.replace(symTargetDir.find("~"), 1, getenv("HOME"));

    /* Ensure the resultant ends in a / */
    if (symTargetDir.find_last_of("/") != symTargetDir.length())
        symTargetDir.append("/");
    return true;
}

bool imfavorites_engine::setOutStream() {
    return false;
}

bool imfavorites_engine::setPretend(int in) {
    pretend = in;
    return true;
}

int imfavorites_engine::makeDirectory(string thisDirectory) {
    /* Return 0 if we fail, 1 if we succeed, 2 if it already exists */

    struct stat dir;
    int ret = 1, statreturn = 0;

    // just make a directory
    statreturn = stat(thisDirectory.c_str(),&dir);

    /* If this directory already exists, then don't make a new one... */
    /* Get the stat structure of the directory, then check
    using the POSIX macro whether it's a dir */

    if ( (! S_ISDIR (dir.st_mode)) || (statreturn < 0) ) {
        /* Make the dir */
        if (verbose > 1)
            cout << "Making directory "<< thisDirectory << endl ;

        ret = mkdir(thisDirectory.c_str(), 0777);

        if (ret != 0) {
            cerr << "Could not create directory  " << thisDirectory << endl;
            return 0;
        }
    }
    else if (verbose > 2) {
        cout << "Dir already exists "<< thisDirectory << endl ;
        return 2;
    }

    return 1;
}

int imfavorites_engine::makeTargetDirectory(string subDirectoryPath) {
    int ret = 0, slashPos = 0;
    string thisDirectory = symTargetDir;

    /* At this point subDirectoryPath might be something like Albums/Best of Train/ */
    /* So, as long as we still have a slash to kill off, do this...*/

    while ((slashPos = subDirectoryPath.find_first_of("/")) != string::npos) {
        thisDirectory += subDirectoryPath.substr(0, slashPos) + "/";

        ret = this->makeDirectory(thisDirectory);
        if (ret < 1) return 0; // Die.

        /* Erase this part of the path */
        subDirectoryPath.erase(0, slashPos+1);
    }

    return ret;
}

unsigned long imfavorites_engine::getFilesize(const char *FileName)
{
    struct stat file;

    if(!stat(FileName,&file)) {
        return file.st_size;
    }

    // If the file doesn't exist or something strange like that, return 0. We'll skip it...
    return 0;
}

void imfavorites_engine::printOutSummary(void) {
    cout << endl << "Done!";

    if (maxNumSet) {
    cout << "\t Filled " << collectedSize << " bytes (" << collectedSize / 1048576 << " MB)" << endl;
    cout << "\t Linked " << numFiles << " songs. ";

    } else {
    cout << "\t Filled " << collectedSize << " / " << targetSize << " bytes (" << collectedSize / 1048576 << " / " << targetSize / 1048576 << " MB)" << endl;
    cout << "\t Linked " << numFiles << " songs. ";
    }

    if (cram)
        cout << "\t Made " << numCrams << " crams." << endl;
    else
        cout << endl;

}

void imfavorites_engine::printSummary(void) {
    /* Print out option summary */
    if (maxNumSet)
        cout << "Maximum number of files to copy: \t" << maxNum << endl;
    else
        cout << "Size of collection to make: \t\t" << maxSize << " MB, " << targetSize << " b" << endl;

    cout << "Target path for collection: \t\t" << symTargetDir << endl;
    cout << "The root path to your files: \t\t" << mainMp3MaskDirectory << endl << endl;
    if (cram) cout << "Cramming enabled." << endl;
}


int imfavorites_engine::runFavorites(void) {
    unsigned long size = 0;
    int ret = 0;
    int loop_return = 1;

    string::size_type slashPos = 0;
    string thisDirectory = "";
    struct stat dir;

    char maxNum_s[64];
    sprintf(maxNum_s, "%d", maxNum);

    if (!pretend)  {
        if ( this->makeDirectory(symTargetDir) < 1 ) return 0;
    }


    /* Build initial SQL statement */
    string sql_command = string("SELECT Rating.rating, Library.path FROM Library INNER JOIN Rating ON Rating.uid=Library.uid WHERE Rating.rating > 99 ORDER BY Rating.rating DESC ");

    if (maxNumSet) {
        sql_command.append("LIMIT ").append(maxNum_s).append(";");
    } else {
        sql_command.append(";");
    }

    /* Go */

    database->execute(sql_command);

    /* Begin looping and taking care of data */

    /* loop_return is 0 if we need to stop next iteration,
       1 if all is okay, 2 if we need to skip this entry */

    if (pretend) {
        while ( (loop_return > 0) && (database->getNumResults()>0) ) {
            loop_return = this->checkConstraints();
            if (loop_return == 1) this->printFavorites();
            this->invokeCallback(numFiles);
            database->next();
        }
    } else {
        while ( (loop_return > 0) && (database->getNumResults()>0) ) {
            loop_return = this->checkConstraints();
            if (loop_return == 1) this->symLinkFavorites();
            this->invokeCallback(numFiles);
            database->next();
        }
    }

    return 1;
}

int imfavorites_engine::checkConstraints(void) {
    // Return Values:
    //  0 - Fail or Done
    //  1 - All OK (or Cramming)
    //  2 - File too small / Don't copy


    // Format for printing later.
    string baseName = database->getField(1);
    string::size_type lastSlash = baseName.find_last_of("/")+1;
    string fileName = baseName.substr(lastSlash);

    // Check filesize then see if we're over limit.
    unsigned long size = getFilesize(database->getFieldPChar(1));

    // This also takes care of files that don't exist - their size is 0, so just skip...

    if (size < 42) return 2; // 0x2A seems a good number.

    /* Don't check against size if we're only doing numbers. */
    if ((collectedSize + size > targetSize) && (!maxNumSet)) {
        // If this file would put us over the edge, then
        // stop unless cram is true.
        if (!cram) return 0;

        // Note this skip. We don't want to walk the
        // whole bloody list, after all. So we track the
        // cram skips and will halt when it appears we
        // have 300 kilobytes of space to cram, while the
        // user only has 9-meg symphonies...
        ++cram;

        // 98 tries seems good to me (100 - 2). If it's that
        // far down the list, then will the user even want
        // to listen to it? ;)
        if (cram > 100) return 0; /* Abort */

        // This file may have defeated us, but don't stop yet!
        if (verbose) cout << "CRAM: Can't cram " << fileName << " (" << size << " > " << targetSize - collectedSize << ")" << endl;

        return 2;
    }

    if (cram > 1) {
        // Chalk up a cram...
        ++numCrams;
    }

    // Count this file's size in the total
    collectedSize += size;

    // Add another tick to the wall...
    ++numFiles;

    return 1;
}

int imfavorites_engine::printFavorites(void) {
    cout << database->getField(1) << endl;
    return 1;
}

int imfavorites_engine::symLinkFavorites(void) {
    /* Figure out the name of the symlink -- delete
       all the text prior to and including the last slash */
    string baseName = database->getField(1);
    string::size_type lastSlash = baseName.find_last_of("/")+1;
    string fileName = baseName.substr(lastSlash);

    /* Prepare to create any directories we need to create
       We need a string with the path name minus the mask
       directory and minus the filename. That string will be
       subDirectoryPath */

    string subDirectoryPath = baseName;

    /* Apply the mask to figure out the list of directories
       we need to chomp and make */
    subDirectoryPath.erase(subDirectoryPath.find(mainMp3MaskDirectory), mainMp3MaskDirectory.length() );
    string symTarget = symTargetDir + subDirectoryPath;

    /* Axe the filename from subDirectoryPath and then
       make the subdirectory.
    */
    subDirectoryPath.erase(subDirectoryPath.find(fileName), subDirectoryPath.length());

    this->makeTargetDirectory(subDirectoryPath);

    /* Write out the file's info, then symlink it.*/
    if (verbose)  cout << "[" << database->getField(0) << "] " << database->getField(1) << endl;

    int ret = symlink(database->getFieldPChar(1), symTarget.c_str());

    if (ret != 0) {
        cerr << "Could not symlink " << database->getField(1) << " -> " << symTarget << endl;
    }

    /* Progress Dot */
    return 1;
}

string imfavorites_engine::findMask(void) {
    int count = 1, lastcount = 0;

    string query = "SELECT path FROM Library LIMIT 1;";
    string presentMask = "";
    string mangledPath = "";
    string lastMask;

    /* Retrieve a single song from the DB for initial path name! */
    database->execute(query);

    mangledPath = database->getField(0);

    /* We need a string with the path name minus the filename */
    /* Axe the filename and leading / */
    mangledPath.erase(mangledPath.find_last_of("/"), mangledPath.length() );
    mangledPath.erase(0,1);


    /* Algorithm Details:
        (Don't expect much out of this. It's 11:58 at night...
        Maybe I'll write a better one later.)
        Let mangledPath be a full pathname to a single song in the database.
        Let presentMask be the root of the filesystem.
        Let C(presentMask) be the number of files in the database
        that have presentMask in their name.

        While (C(presentMask) >= C`(presentMask))
            Copy the first dir (from 0 to the first '/') from
                mangledPath to presentMask
            Erase that dir from mangledPath

        Halting condition is that we've suddenly come to a directory
            where our count of files drops.
        This means we hit a directory that is NOT common to all of
            the files in the database.

        So stop here and return the values that existed just
            before this condition.
    */

    for( ; (count>=lastcount) && (count > 0) ; ) {
        /* As long as count stays equal to or bigger than the last count,
           move up the mask a directory */
        /* Hold on to old values */
        lastMask = presentMask;
        lastcount = count;

        /* Copy the first directory name left in mangledPath
           onto the end of presentMask. */
        presentMask.append("/").append(mangledPath.substr(0, mangledPath.find_first_of("/")));

        /* Erase the directory name we just copied onto presentMask */
        mangledPath.erase(0, mangledPath.find_first_of("/")+1);

        query = string("SELECT count(path) FROM Library WHERE path LIKE \"").append(presentMask).append("%\"");

        /* Make a SQL call to get the count of like entries in the path database */
        database->execute(query);

        count = atoi(database->getFieldPChar(0));

        if (verbose > 2) {
            cout << "pM: " << presentMask << endl;
            cout << "mP: " << mangledPath << endl;
            cout << "Last Count: " << lastcount << " Count: " << count << endl;
        }

        /* Close that SQL call */

    }

    return lastMask.append("/");
}

bool imfavorites_engine::run() {

    if (!database->isOpen()) cerr << "Database not open." << endl;
    else this->runFavorites();

    return 1;
}

unsigned long imfavorites_engine::getCollectedSizeMB() {
    return (unsigned long)(collectedSize/1048576);
}

unsigned long imfavorites_engine::getTargetSizeMB() {
    return maxSize;
}

long imfavorites_engine::getCollectedFiles() {
    return numFiles;
}

long imfavorites_engine::getTargetCollectedFiles() {
    return maxNum;
}

int imfavorites_engine::isLimitedByNumber() {
    return maxNumSet;
}

int imfavorites_engine::isReady() {
    // We are ready when one of these conditions is true:
    // We've going to a maxNumber of songs and that's >0
    // We're going to a maxSize of songs and that's >0
    // AND
    // We're either pretending, or we have a symTargetDir set
    return ( (maxNumSet && maxNum >0) || (!maxNumSet && maxSize > 0) ) &&
           (symTargetDir.length() > 0 || pretend);
}

string imfavorites_engine::getVersion(void) {
    return IMFAVORITES_VERSION;
}

static void default_progress_cb (imfavorites_engine * engine, int Param) {
    cerr << ".";
}
