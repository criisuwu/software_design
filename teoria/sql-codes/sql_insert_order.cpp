#include <iostream>
#include <sqlite3.h>
#include <string>

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

    // Activar foreign keys
    rc = sqlite3_exec(db, "PRAGMA foreign_keys = ON;", NULL, 0, &errMsg);
    if (rc != SQLITE_OK) {
        std::cerr << "Error al activar foreign keys: " << errMsg << std::endl;
        sqlite3_free(errMsg);
    }

    // Primero, mostrar las personas disponibles
    std::cout << "=== PERSONAS DISPONIBLES ===" << std::endl;
    const char* sqlSelect = "SELECT ID, NOMBRE, EDAD FROM PERSONAS;";
    sqlite3_stmt* stmtSelect;

    rc = sqlite3_prepare_v2(db, sqlSelect, -1, &stmtSelect, NULL);
    if (rc == SQLITE_OK) {
        while (sqlite3_step(stmtSelect) == SQLITE_ROW) {
            int id = sqlite3_column_int(stmtSelect, 0);
            const unsigned char* nombre = sqlite3_column_text(stmtSelect, 1);
            int edad = sqlite3_column_int(stmtSelect, 2);
            std::cout << "ID: " << id << " - " << nombre << " (" << edad << " años)" << std::endl;
        }
        sqlite3_finalize(stmtSelect);
    }
    std::cout << "============================\n" << std::endl;

    // Solicitar datos del pedido
    int personaId;
    std::string descripcion;
    double precio;

    std::cout << "Introduce el ID de la persona: ";
    std::cin >> personaId;
    std::cin.ignore(); // Limpiar el buffer

    std::cout << "Introduce la descripción del pedido: ";
    std::getline(std::cin, descripcion);

    std::cout << "Introduce el precio: ";
    std::cin >> precio;

    // Sentencia preparada con parámetros
    const char* sql = "INSERT INTO PEDIDOS (DESCRIPCION, PRECIO, PERSONA_ID) VALUES (?, ?, ?);";
    sqlite3_stmt* stmt;

    rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
    if (rc != SQLITE_OK) {
        std::cerr << "Error al preparar la sentencia: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return 1;
    }

    // Enlazar los valores
    sqlite3_bind_text(stmt, 1, descripcion.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_double(stmt, 2, precio);
    sqlite3_bind_int(stmt, 3, personaId);

    // Ejecutar
    rc = sqlite3_step(stmt);
    if (rc != SQLITE_DONE) {
        std::cerr << "Error al insertar pedido: " << sqlite3_errmsg(db) << std::endl;
        if (std::string(sqlite3_errmsg(db)).find("FOREIGN KEY") != std::string::npos) {
            std::cerr << "La persona con ID " << personaId << " no existe." << std::endl;
        }
    } else {
        std::cout << "Pedido insertado correctamente.\n";
        std::cout << "ID del pedido: " << sqlite3_last_insert_rowid(db) << std::endl;
    }

    // Liberar
    sqlite3_finalize(stmt);
    sqlite3_close(db);

    return 0;
}