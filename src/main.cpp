// main.cpp

#include <iostream>
#include "sqlite3.h"
#include "SQLiteCpp/SQLiteCpp.h"

using namespace std;

int main(void)
{

    cout << "Hello World" << endl;

    // vanilla sqlite3 commands
    // open the database, create it if necessary

    /*
    sqlite3 *db;
    std::string path = "./db/todo.db";
    int rc = sqlite3_open_v2(path.c_str(), &db, SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE, NULL);

    if(rc){
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return(1);
    } else {
        cout << "db connected" << endl;
    }
    */


    // trying SQLiteCPP
    try
    {

        // Open a database file
        SQLite::Database db("db/todo.db3");

        // Compile a SQL query, containing one parameter (index 1)
        SQLite::Statement query(db, "SELECT * FROM todo WHERE id > :id");

        // Bind the integer value 6 to the first parameter of the SQL query
        int64_t minId = 0;
        query.bind(":id", minId);

        // Loop to execute the query step by step, to get rows of result
        while (query.executeStep())
        {
            // Demonstrate how to get some typed column value
            int id = query.getColumn(0);
            const char* title = query.getColumn(1);
            int done = query.getColumn(4);

            std::cout << "row: " << id << ", title: " << title << ", done: " << done << std::endl;
        }
    }
    catch (std::exception& e)
    {
        std::cout << "exception: " << e.what() << std::endl;
        return(EXIT_FAILURE);
    }
    
    return(EXIT_SUCCESS);
}
