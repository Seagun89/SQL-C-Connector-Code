#include <iostream>
#include <mysql/mysql.h>
#include "sql_conn.h"

using namespace std;

MYSQL *sql_conn::mysql_connection_setup(const char *user, const char *password, const char *server, const char *database, MYSQL *connection)
{

    if (!mysql_real_connect(connection, server, user, password, database, 0, NULL, 0))
    {
        cout << "Connection Error: " << mysql_error(connection) << endl;
        exit(1);
    }
    return connection;
}

MYSQL_RES *sql_conn::mysql_execute_query(MYSQL *connection, const char *sql_query)
{
    if (mysql_query(connection, sql_query))
    {
        cout << "MYSQL Query Connection: " << mysql_error(connection) << endl;
        exit(1);
    }
    return mysql_use_result(connection);
}