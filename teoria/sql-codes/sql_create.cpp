#include <iostream>
#include <sqlite3.h>

int main() {
    sqlite3* db;
    int exit = 0;

    // Abrir la base de datos (si no existe, la crea)
    exit = sqlite3_open("mi_base_de_datos.db", &db);

    if (exit) {
        std::cerr << "No se pudo abrir la base de datos: " << sqlite3_errmsg(db) << std::endl;
        return -1;
    } else {
        std::cout << "Base de datos abierta correctamente." << std::endl;
    }

    // IMPORTANTE: Activar las foreign keys en SQLite (están desactivadas por defecto)
    std::string enableFK = "PRAGMA foreign_keys = ON;";
    char* mensajeError;
    exit = sqlite3_exec(db, enableFK.c_str(), NULL, 0, &mensajeError);

    if (exit != SQLITE_OK) {
        std::cerr << "Error al activar foreign keys: " << mensajeError << std::endl;
        sqlite3_free(mensajeError);
    }

    /* // Crear la tabla PERSONAS (igual que tu código original)
    std::string sqlPersonas = "CREATE TABLE IF NOT EXISTS PERSONAS("
                              "ID INTEGER PRIMARY KEY AUTOINCREMENT, "
                              "NOMBRE TEXT NOT NULL, "
                              "EDAD INT NOT NULL);";

    exit = sqlite3_exec(db, sqlPersonas.c_str(), NULL, 0, &mensajeError);

    if (exit != SQLITE_OK) {
        std::cerr << "Error al crear la tabla PERSONAS: " << mensajeError << std::endl;
        sqlite3_free(mensajeError);
    } else {
        std::cout << "Tabla PERSONAS creada correctamente." << std::endl;
    }

    // Crear una nueva tabla PEDIDOS con Foreign Key a PERSONAS
    std::string sqlPedidos = "CREATE TABLE IF NOT EXISTS PEDIDOS("
                             "ID INTEGER PRIMARY KEY AUTOINCREMENT, "
                             "DESCRIPCION TEXT NOT NULL, "
                             "PRECIO REAL NOT NULL, "
                             "PERSONA_ID INTEGER NOT NULL, "
                             "FOREIGN KEY (PERSONA_ID) REFERENCES PERSONAS(ID) "
                             "ON DELETE CASCADE "
                             "ON UPDATE CASCADE);";

    exit = sqlite3_exec(db, sqlPedidos.c_str(), NULL, 0, &mensajeError);

    if (exit != SQLITE_OK) {
        std::cerr << "Error al crear la tabla PEDIDOS: " << mensajeError << std::endl;
        sqlite3_free(mensajeError);
    } else {
        std::cout << "Tabla PEDIDOS creada correctamente con Foreign Key a PERSONAS." << std::endl;
    } */

    // Cerrar la base de datos
    sqlite3_close(db);

    return 0;
}





//tabla 4 col: id(int), user(str), contraseña(str), otro (str)