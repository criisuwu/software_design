#include <iostream>
#include <vector>
#include <string>
#include <sqlite3.h>
#ifdef _WIN32
    #include <windows.h>
#endif

void configUTF8() {
    #ifdef _WIN32
        // Windows: configurar consola para UTF-8
        SetConsoleOutputCP(CP_UTF8);
        SetConsoleCP(CP_UTF8);
    #else
        // Linux/Ubuntu: intentar configurar locale
        try {
            std::locale::global(std::locale("es_ES.UTF-8"));
        } catch (...) {
            // Si falla, intentar con el locale del sistema
            try {
                std::locale::global(std::locale(""));
            } catch (...) {
                // Si también falla, continuar sin configuración
            }
        }
    #endif
}

struct Pedido {
    int id;
    std::string descripcion;
    double precio;
    int personaId;
    std::string nombrePersona;  // Para mostrar el nombre de la persona asociada
};

int main() {

    sqlite3* db;
    int rc;
    configUTF8();
    // Abrir la base de datos
    rc = sqlite3_open("mi_base_de_datos.db", &db);
    if (rc) {
        std::cerr << "No se pudo abrir la base de datos: " << sqlite3_errmsg(db) << std::endl;
        return 1;
    }
    std::cout << "Base de datos abierta correctamente.\n";

    // Consulta con JOIN para obtener también el nombre de la persona
    const char* sql = "SELECT P.ID, P.DESCRIPCION, P.PRECIO, P.PERSONA_ID, PE.NOMBRE "
                      "FROM PEDIDOS P "
                      "INNER JOIN PERSONAS PE ON P.PERSONA_ID = PE.ID;";
    
    sqlite3_stmt* stmt;
    rc = sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);
    if (rc != SQLITE_OK) {
        std::cerr << "Error al preparar la consulta: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return 1;
    }

    std::vector<Pedido> pedidos;  // Aquí guardaremos los datos

    while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
        Pedido p;
        p.id = sqlite3_column_int(stmt, 0);
        p.descripcion = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
        p.precio = sqlite3_column_double(stmt, 2);
        p.personaId = sqlite3_column_int(stmt, 3);
        p.nombrePersona = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 4));

        pedidos.push_back(p);
    }

    sqlite3_finalize(stmt);
    sqlite3_close(db);

    // Mostrar datos desde el vector
    std::cout << "\n--- Datos de Pedidos almacenados en std::vector ---\n";
    if (pedidos.empty()) {
        std::cout << "No hay pedidos registrados.\n";
    } else {
        for (const auto& p : pedidos) {
            std::cout << "ID = " << p.id 
                      << " | Descripción = " << p.descripcion 
                      << " | Precio = " << p.precio << "€"
                      << " | Persona = " << p.nombrePersona 
                      << " (ID: " << p.personaId << ")" 
                      << std::endl;
        }
    }

    return 0;
}