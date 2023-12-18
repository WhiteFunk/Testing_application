#include "user_db_manager.h"

#include <QtSql>
#include <QString>

User_DB_Manager::User_DB_Manager()
{

    QSqlDatabase dbase = QSqlDatabase::addDatabase("QSQLITE");
    dbase.setDatabaseName("users.sqlite");

    QSqlQuery a_query;

    QString str ="CREATE TABLE Users ("
        "UserId INTEGER PRIMARY KEY AUTOINCREMENT,"
        "Username TEXT,"
       "Salt TEXT,"
        "SaltedPassword TEXT,"
        "Role int"
        ");";
    a_query.exec(str);

}



void User_DB_Manager::insertInTable()
{

}

void User_DB_Manager::selectFromTable()
{

}
