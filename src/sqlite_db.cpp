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
}


sqlite_db::~sqlite_db()
{
    if (vm != 0)
        sqlite_finalize( vm, &errmsg );

    if (p_db != 0)
        sqlite_close(p_db);
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
    p_db = sqlite_open(pathToDB.c_str(), 0777, 0);
    return this->isOpen();
}

int sqlite_db::execute(string query) {
    if (!this->isOpen()) return -1;

    if (vm != 0)
        sqlite_finalize( vm, &errmsg );

    /* Retrieve a single song from the DB for initial path name! */
    sqlite_compile( p_db, query.c_str(), &pzTail, &vm, &errmsg );

    queryDone = 0;

    if (errmsg != NULL) {
        sqlite_freemem(errmsg);
        return -1;
    }

    return this->next();
}

int sqlite_db::next() {
    if (!this->isOpen() || queryDone) return 0;

    int retval = sqlite_step( vm, &nrecs, &p_fields, &p_col_names );

    while (retval == SQLITE_BUSY) {
        // busy, try your call again later.
        usleep(500);
        retval = sqlite_step( vm, &nrecs, &p_fields, &p_col_names );
    }

    if ( retval != SQLITE_ROW) {
        queryDone = 1;
        return 0;
    }
    return nrecs;
}

int sqlite_db::getNumResults() {
    if (!this->isOpen() || queryDone) return -1;

    return nrecs;
}

const char * sqlite_db::getFieldPChar(int i) {
    if (!this->isOpen() || queryDone) return "";

    return p_fields[i];
}

string sqlite_db::getField(int i) {
    if (!this->isOpen() || queryDone) return "";

    return string(p_fields[i]);
}




