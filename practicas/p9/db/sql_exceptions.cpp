#include <iostream>
#include <sqlite3.h>
#include <stdexcept>

sqlite3* openDatabase(const std::string& filename) {
    sqlite3* db = nullptr;

    int rc = sqlite3_open(filename.c_str(), &db);
    if (rc != SQLITE_OK) {
        throw std::runtime_error("Error al abrir la BD: " + std::string(sqlite3_errmsg(db)));
    }
    return db;
}

void execSQL(sqlite3* db, const std::string& sql) {
    char* errMsg = nullptr;

    int rc = sqlite3_exec(db, sql.c_str(), nullptr, nullptr, &errMsg);
    if (rc != SQLITE_OK) {
        std::string error = errMsg ? errMsg : "Error SQL desconocido";
        sqlite3_free(errMsg);
        throw std::runtime_error("Error ejecutando SQL -> " + error);
    }
}

void closeDatabase(sqlite3* db) {
    if (db) {
        int rc = sqlite3_close(db);
        if (rc != SQLITE_OK) {
            throw std::runtime_error("Error cerrando la BD.");
        }
    }
}