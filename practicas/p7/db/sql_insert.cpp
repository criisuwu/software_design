// sql_insert.cpp
#include <iostream>
#include <sqlite3.h>

int main() {
    sqlite3 *db = nullptr;
    char *errMsg = nullptr;
    int rc;

    // Abrir la base de datos
    rc = sqlite3_open("appointment_system.db", &db);
    if (rc) {
        std::cerr << "No se pudo abrir la BD: " << sqlite3_errmsg(db) << "\n";
        if (db) sqlite3_close(db);
        return 1;
    }

    // Insertar usuarios de ejemplo en USER
    const char* userInserts[] = {
        // Administrador
        "INSERT OR IGNORE INTO USER (USERNAME, PASSWORD, ROLE) VALUES "
        "('admin', 'admin123', 'Administrator')",
        
        // Doctores
        "INSERT OR IGNORE INTO USER (USERNAME, PASSWORD, ROLE) VALUES "
        "('drgarcia', 'doctor123', 'Doctor')",
        
        "INSERT OR IGNORE INTO USER (USERNAME, PASSWORD, ROLE) VALUES "
        "('drmartinez', 'doctor123', 'Doctor')",
        
        // Pacientes
        "INSERT OR IGNORE INTO USER (USERNAME, PASSWORD, ROLE) VALUES "
        "('paciente1', 'paciente123', 'Patient')",
        
        "INSERT OR IGNORE INTO USER (USERNAME, PASSWORD, ROLE) VALUES "
        "('paciente2', 'paciente123', 'Patient')"
    };

    int numUserInserts = sizeof(userInserts) / sizeof(userInserts[0]);
    int successfulUserInserts = 0;

    for (int i = 0; i < numUserInserts; i++) {
        rc = sqlite3_exec(db, userInserts[i], nullptr, nullptr, &errMsg);
        if (rc != SQLITE_OK) {
            std::cerr << "Error en inserción de usuario " << i+1 << ": " << errMsg << "\n";
            sqlite3_free(errMsg);
        } else {
            successfulUserInserts++;
        }
    }

    // Insertar detalles de usuarios
    const char* detailInserts[] = {
        // Administrador
        "INSERT OR IGNORE INTO USER_DETAILS (USER_ID, NAME, EMAIL) VALUES "
        "((SELECT ID FROM USER WHERE USERNAME='admin'), 'Administrador Principal', 'admin@hospital.com')",
        
        // Doctores
        "INSERT OR IGNORE INTO USER_DETAILS (USER_ID, NAME, EMAIL, SPECIALTY) VALUES "
        "((SELECT ID FROM USER WHERE USERNAME='drgarcia'), 'Dr. García López', 'garcia@hospital.com', 'Cardiología')",
        
        "INSERT OR IGNORE INTO USER_DETAILS (USER_ID, NAME, EMAIL, SPECIALTY) VALUES "
        "((SELECT ID FROM USER WHERE USERNAME='drmartinez'), 'Dra. Martínez Ruiz', 'martinez@hospital.com', 'Pediatría')",
        
        // Pacientes
        "INSERT OR IGNORE INTO USER_DETAILS (USER_ID, NAME, EMAIL, TELEPHONE) VALUES "
        "((SELECT ID FROM USER WHERE USERNAME='paciente1'), 'Juan Pérez', 'juan@email.com', '123456789')",
        
        "INSERT OR IGNORE INTO USER_DETAILS (USER_ID, NAME, EMAIL, TELEPHONE) VALUES "
        "((SELECT ID FROM USER WHERE USERNAME='paciente2'), 'María López', 'maria@email.com', '987654321')"
    };

    int numDetailInserts = sizeof(detailInserts) / sizeof(detailInserts[0]);
    int successfulDetailInserts = 0;

    for (int i = 0; i < numDetailInserts; i++) {
        rc = sqlite3_exec(db, detailInserts[i], nullptr, nullptr, &errMsg);
        if (rc != SQLITE_OK) {
            std::cerr << "Error en inserción de detalles " << i+1 << ": " << errMsg << "\n";
            sqlite3_free(errMsg);
        } else {
            successfulDetailInserts++;
        }
    }

    std::cout << "Se insertaron " << successfulUserInserts << " usuarios y " 
              << successfulDetailInserts << " detalles correctamente.\n";

    sqlite3_close(db);
    return 0;
}