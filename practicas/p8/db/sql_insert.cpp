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

    // Insertar usuarios de ejemplo en USER con TODOS los campos
    const char* userInserts[] = {
        // Administrador
        "INSERT OR IGNORE INTO USER (USERNAME, PASSWORD, ROLE, NAME, EMAIL) VALUES "
        "('admin', 'admin123', 'Administrator', 'Administrador Principal', 'admin@hospital.com')",
        
        // Doctores
        "INSERT OR IGNORE INTO USER (USERNAME, PASSWORD, ROLE, NAME, EMAIL, SPECIALTY) VALUES "
        "('drgarcia', 'doctor123', 'Doctor', 'Dr. García López', 'garcia@hospital.com', 'Cardiología')",
        
        "INSERT OR IGNORE INTO USER (USERNAME, PASSWORD, ROLE, NAME, EMAIL, SPECIALTY) VALUES "
        "('drmartinez', 'doctor123', 'Doctor', 'Dra. Martínez Ruiz', 'martinez@hospital.com', 'Pediatría')",
        
        // Pacientes
        "INSERT OR IGNORE INTO USER (USERNAME, PASSWORD, ROLE, NAME, EMAIL, TELEPHONE) VALUES "
        "('paciente1', 'paciente123', 'Patient', 'Juan Pérez', 'juan@email.com', '123456789')",
        
        "INSERT OR IGNORE INTO USER (USERNAME, PASSWORD, ROLE, NAME, EMAIL, TELEPHONE) VALUES "
        "('paciente2', 'paciente123', 'Patient', 'María López', 'maria@email.com', '987654321')"
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

    std::cout << "Se insertaron " << successfulUserInserts << " usuarios correctamente.\n";

    sqlite3_close(db);
    return 0;
}