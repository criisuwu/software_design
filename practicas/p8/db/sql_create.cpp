#include <iostream>
#include <sqlite3.h>

int main() {
    sqlite3 *db = nullptr;
    char *errMsg = nullptr;
    int rc;

    // Abrir (o crear) la base de datos
    rc = sqlite3_open("appointment_system.db", &db);
    if (rc) {
        std::cerr << "No se pudo abrir/crear la BD: " << sqlite3_errmsg(db) << "\n";
        if (db) sqlite3_close(db);
        return 1;
    }

    // Activar foreign keys
    rc = sqlite3_exec(db, "PRAGMA foreign_keys = ON;", nullptr, nullptr, &errMsg);
    if (rc != SQLITE_OK) {
        std::cerr << "Error activando foreign_keys: " << errMsg << "\n";
        sqlite3_free(errMsg);
        sqlite3_close(db);
        return 1;
    }

    // Sentencia para crear la tabla USER (solo campos básicos)
    const char *sqlCreateUser =
        "CREATE TABLE IF NOT EXISTS USER ("
        "ID INTEGER PRIMARY KEY AUTOINCREMENT, "
        "USERNAME TEXT NOT NULL UNIQUE, "
        "PASSWORD TEXT NOT NULL, "
        "ROLE TEXT NOT NULL CHECK(ROLE IN ('Doctor','Patient','Administrator')), "
        "NAME TEXT NOT NULL, "
        "EMAIL TEXT, "
        "SPECIALTY TEXT, "
        "TELEPHONE TEXT"
        ");";

    rc = sqlite3_exec(db, sqlCreateUser, nullptr, nullptr, &errMsg);
    if (rc != SQLITE_OK) {
        std::cerr << "Error creando la tabla USER: " << errMsg << "\n";
        sqlite3_free(errMsg);
        sqlite3_close(db);
        return 1;
    }

    // Sentencia para crear la tabla SCHEDULE
    const char *sqlCreateSchedule =
        "CREATE TABLE IF NOT EXISTS SCHEDULE ("
        "ID INTEGER PRIMARY KEY AUTOINCREMENT, "
        "ID_DOCTOR INTEGER NOT NULL, "
        "DAY TEXT NOT NULL, "
        "START_TIME TEXT NOT NULL, "
        "END_TIME TEXT NOT NULL, "
        "FOREIGN KEY(ID_DOCTOR) REFERENCES USER(ID)"
        ");";

    rc = sqlite3_exec(db, sqlCreateSchedule, nullptr, nullptr, &errMsg);
    if (rc != SQLITE_OK) {
        std::cerr << "Error creando la tabla SCHEDULE: " << errMsg << "\n";
        sqlite3_free(errMsg);
        sqlite3_close(db);
        return 1;
    }

    // Sentencia para crear la tabla APPOINTMENT
    const char *sqlCreateAppointment =
        "CREATE TABLE IF NOT EXISTS APPOINTMENT ("
        "ID INTEGER PRIMARY KEY AUTOINCREMENT, "
        "ID_PATIENT INTEGER NOT NULL, "
        "ID_DOCTOR INTEGER NOT NULL, "
        "DATE TEXT NOT NULL, "
        "TIME TEXT NOT NULL, "
        "STATUS TEXT DEFAULT 'Pendiente', "
        "NOTES TEXT, "
        "FOREIGN KEY(ID_PATIENT) REFERENCES USER(ID), "
        "FOREIGN KEY(ID_DOCTOR) REFERENCES USER(ID)"
        ");";

    rc = sqlite3_exec(db, sqlCreateAppointment, nullptr, nullptr, &errMsg);
    if (rc != SQLITE_OK) {
        std::cerr << "Error creando la tabla APPOINTMENT: " << errMsg << "\n";
        sqlite3_free(errMsg);
        sqlite3_close(db);
        return 1;
    }

    std::cout << "Tablas creadas correctamente en appointment_system.db\n";

    sqlite3_close(db);
    return 0;
}