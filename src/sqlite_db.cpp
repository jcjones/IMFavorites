//
// C++ Implementation: sqlite_db
//
// Description: 
//  A simple C++ interface to SQLite
//
// Author: James Pug Jones <pug AT ufl DOT edu>, (C) 2004
//
// Copyright: See COPYING file that comes with this distribution
//
//
#include "sqlite_db.h"

sqlite_db::sqlite_db()
{
    char *errmsg = 0;
    const char **p_fields;
    const char **p_col_names;
    const char *pzTail = 0;
    int nrecs = 0;
    int queryDone = 0;
    pathToDB = "";
    vm = 0;
    p_db = 0;
}


sqlite_db::~sqlite_db()
{
    if (vm != 0)
        sqlite3_finalize( vm );

    if (p_db != 0)
        sqlite3_close(p_db);
}

int sqlite_db::isOpen() {
    if(p_db == 0) {
        cerr << "Could not open database at: " << pathToDB << endl;
        return 0;
    }
    return 1;
}

int sqlite_db::open(string in) {
    pathToDB = in;
    return sqlite3_open(pathToDB.c_str(), &p_db) == SQLITE_OK;
}

int sqlite_db::execute(string query) {
    if (!this->isOpen()) return -1;

//    if (vm != 0)
//        sqlite3_finalize( vm );

    /* Retrieve a single song from the DB for initial path name! */
    int retval = sqlite3_prepare( p_db, query.c_str(), query.length(), &vm, &pzTail ); 

    if (retval != SQLITE_OK) { 
        // Something is horribly wrong
        cout << "Critical failure while attempting to compile statement: " << query << endl;
        cout << "Exiting..." << endl;
        exit(0);
    }

    queryDone = 0;

    if (errmsg != NULL) {
        sqlite3_free(errmsg);
        return -1;
    }

    return this->next();
}

int sqlite_db::next() {
    if (!this->isOpen() || queryDone) return 0;

    int retval = sqlite3_step( vm );

    while (retval == SQLITE_BUSY) {
        // busy, try your call again later.
        usleep(500);
        retval = sqlite3_step( vm );
    }

    if ( retval != SQLITE_ROW) {
        queryDone = 1;
        return 0;
    }
    return getNumResults();
}

int sqlite_db::getNumResults() {
    if (!this->isOpen() || queryDone) return -1;
    nrecs = sqlite3_data_count( vm );
    return nrecs;
}

const char * sqlite_db::getFieldPChar(int i) {
    if (!this->isOpen() || queryDone || i < sqlite3_column_count( vm ) ) return "";

    return (const char *)sqlite3_column_text(vm, i);
}

string sqlite_db::getField(int i) {
    if (!this->isOpen() || queryDone || i < sqlite3_column_count( vm ) ) return "";

    return string((const char *)sqlite3_column_text(vm, i));
}




