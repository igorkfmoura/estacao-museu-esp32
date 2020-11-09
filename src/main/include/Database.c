#include <sqlite3.h>

char *zErrMsg = 0;
int rc;
char *sql;
sqlite3_stmt *res;
const char *tail;
const char *data = "Callback function called";

static int callback(void *data, int argc, char **argv, char **azColName)
{
    return 0;
}

static int readDataHandler(void *data, int argc, char **argv, char **azColName)
{
    int i;
    Serial.printf("%s: ", (const char *)data);
    for (i = 0; i < argc; i++)
    {
        Serial.printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    Serial.printf("\n");
    return 0;
}

int openDb(char *filename, sqlite3 **db)
{
    int rc = sqlite3_open(filename, db);
    if (rc)
    {
        Serial.printf("Can't open database: %s\n", sqlite3_errmsg(*db));
        return rc;
    }
    else
    {
        Serial.printf("Opened database successfully\n");
    }
    return rc;
}

int dbClear(sqlite3 *db)
{
    int rc = sqlite3_exec(db, "DROP TABLE museu", callback, (void *)data, &zErrMsg);
    if (rc != SQLITE_OK)
    {
        sqlite3_close(db);
        Serial.println("Table already exists or  Error on creating 'museu' table");
    }
}

int dbSetup(sqlite3 *db)
{
    int rc = sqlite3_exec(db, "CREATE TABLE IF NOT EXISTS museu (Hora_UTC varchar(20),Temperatura float,Humidade float,Pressão float,Luminosidade float, Co2 float, Poeira float)", callback, (void *)data, &zErrMsg);
    if (rc != SQLITE_OK)
    {
        sqlite3_close(db);
        Serial.println("Table already exists or  Error on creating 'museu' table");
    }

    return rc;
}

//  Main functions

//  Test functions
int writeOnDB(const char *date, float data_list[], sqlite3 *db)
{
    char *sql = "INSERT INTO museu VALUES(?, ?, ?, ?, ?, ?, ?)";
    rc = sqlite3_prepare_v2(db, sql, strlen(sql), &res, &tail);
    if (rc != SQLITE_OK)
    {
        String resp = "Failed to fetch data: ";
        resp += sqlite3_errmsg(db);
        sqlite3_close(db);
        Serial.println(resp.c_str());
        return 0;
    }

    // date
    sqlite3_bind_text(res, 1, date, strlen(date), SQLITE_STATIC);

    // Float data
    int i;
    for (i = 0; i < sizeof(data_list); i++)
    {
        sqlite3_bind_double(res, i + 2, data_list[i]);
    }

    if (sqlite3_step(res) != SQLITE_DONE)
    {
        Serial.printf("ERROR executing stmt: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 0;
    }

    sqlite3_finalize(res);

    if (rc != SQLITE_OK)
    {
        Serial.printf("SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    }
    else
    {
        Serial.printf("Data was successfully storaged\n");
    }
    return rc;
}

int readDB(sqlite3 *db)
{
    int rc = sqlite3_exec(db, "SELECT * FROM museu", readDataHandler, (void *)data, &zErrMsg);
    if (rc != SQLITE_OK)
    {
        Serial.printf("SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    }
    else
    {
        Serial.printf("DB was successfully read\n");
    }

    return rc;
}
