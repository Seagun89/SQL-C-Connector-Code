#include <iostream>
#include <mysql/mysql.h>

using namespace std;
class sql_conn
{
public:
    const char *user, *password, *server, *database, *sql_query;
    MYSQL *connection = mysql_init(NULL);
    MYSQL *mysql_connection_setup(const char *user, const char *password, const char *server, const char *database, MYSQL *connection);
    MYSQL_RES *mysql_execute_query(MYSQL *connection, const char *sql_query);
};