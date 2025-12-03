#include <iostream>
#include <sqlite3.h>

int main() {
    sqlite3* db;
    int rc;
    char *errMsg = 0;

    // Abrir la base de datos
    rc = sqlite3_open("mi_base_de_datos.db", &db);
    if (rc) {
        std::cerr << "No se pudo abrir la base de datos: " << sqlite3_errmsg(db) << std::endl;
        return 1;
    }

    std::string calle, ciudad, id_persona;

    std::cout << "Introduce la calle: ";
    std::getline(std::cin, calle);

    std::cout << "Introduce la ciudad: ";
    std::getline(std::cin, ciudad);

    std::cout << "Introduce el id_persona: ";
    std::cin >> id_persona;

    // Sentencia preparada con parámetros
    const char* sql = "INSERT INTO DIRECCIONES (CALLE, CIUDAD, PERSONA_ID) VALUES (?, ?, ?);";
    sqlite3_stmt* stmt;

    rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
    if (rc != SQLITE_OK) {
        std::cerr << "Error al preparar la sentencia: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return 1;
    }

    // Enlazar los valores
    sqlite3_bind_text(stmt, 1, calle.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 2, ciudad.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 3, id_persona.c_str(), -1, SQLITE_TRANSIENT);

    // Ejecutar
    rc = sqlite3_step(stmt);
    if (rc != SQLITE_DONE) {
        std::cerr << "Error al insertar datos: " << sqlite3_errmsg(db) << std::endl;
    } else {
        std::cout << "Datos insertados correctamente.\n";
    }

    // Liberar
    sqlite3_finalize(stmt);
    sqlite3_close(db);

    return 0;
}
