//
// C++ Interface: sqlite_db
//
// Description: 
//  A simple C++ interface to SQLite
//
// Author: James Pug Jones <pug AT ufl DOT edu>, (C) 2004
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef SQLITE_DB_H
#define SQLITE_DB_H

#include <iostream>
#include <string>
#include <sqlite3.h>
#include <unistd.h> // for usleep

using namespace std;

/**
@author James Pug Jones
*/
class sqlite_db{
private:
    sqlite3 *p_db;

    char *errmsg;
    const char **p_fields;
    const char **p_col_names;
    const char *pzTail;
    int nrecs;
    int queryDone;

    sqlite3_stmt *vm;

    string pathToDB;

public:
    sqlite_db();
    ~sqlite_db();

    int open(string);
    int isOpen();

    int execute(string);
    int next();
    int getNumResults();

    const char *getFieldPChar(int i);
    string getField(int i);

};

#endif
