#include "A.h"
#include <vector>


A::A(int id) {
    this->id = id;
    if (sqlite3_open("mi_base_de_datos2.db", &db) != SQLITE_OK) {
        std::cerr << "No se pudo abrir la base de datos\n";
        throw std::runtime_error("Database error.");
    }
}

    void A::getPerson(){
        struct Persona {
        int id;
        std::string nombre;
        int edad;
    };
    const char* sql = "SELECT ID, NOMBRE, EDAD FROM PERSONAS WHERE NOMBRE=?;";
    sqlite3_stmt* stmt;
    int rc;
    rc = sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);
    if (rc != SQLITE_OK) {
        std::cerr << "Error al preparar la consulta: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        throw std::runtime_error("Error with the DB.");
    }
    std::string nombre = "";
    std::cout << "¿Qué nombre quieres buscar?: ";
    std::getline(std::cin, nombre);
    sqlite3_bind_text(stmt, 1, nombre.c_str(), -1, SQLITE_TRANSIENT);

    std::vector<Persona> personas;  // Aquí guardaremos los datos

    while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
        Persona p;
        p.id = sqlite3_column_int(stmt, 0);
        p.nombre = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
        p.edad = sqlite3_column_int(stmt, 2);

        personas.push_back(p);
    }

    sqlite3_finalize(stmt);
    sqlite3_close(db);

    // Mostrar datos desde el vector
    std::cout << "\n--- Datos almacenados en std::vector ---\n";
    for (const auto& p : personas) {
        std::cout << "ID = " << p.id << " | Nombre = " << p.nombre << " | Edad = " << p.edad << std::endl;
    }
}