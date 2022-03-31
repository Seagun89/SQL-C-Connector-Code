// to run code must use g++ main.cpp sql_conn.cpp -L/usr/include/mysql/mysql -lmysqlclient
#include <iostream>
#include <mysql/mysql.h>
#include "sql_conn.h"

using namespace std;

int main(int argc, char const *argv[])
{
    MYSQL *conn;
    MYSQL_RES *res;
    MYSQL_ROW row;

    sql_conn mysqlD;
    mysqlD.server = "localhost";
    mysqlD.user = "seagun";
    mysqlD.password = "Georgekev89@";
    mysqlD.database = "demo";
    mysqlD.sql_query = "select * from clients;";

    conn = mysqlD.mysql_connection_setup(mysqlD.user, mysqlD.password, mysqlD.server, mysqlD.database, mysqlD.connection);
    res = mysqlD.mysql_execute_query(conn, mysqlD.sql_query);

    cout << "Displaying database output: \n"
         << endl;

    while ((row = mysql_fetch_row(res)) != NULL)
    {
        cout << row[0] << " | " << row[1] << " | " << row[2] << " | " << row[3] << endl
             << endl;
    }
    mysql_free_result(res);
    mysql_close(conn);
    return 0;
}
