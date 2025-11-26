#include "../import/Sistema.h"
#include <iostream>
#include <sqlite3.h>

Sistema::Sistema() : db(nullptr) {
    connectDatabase();
}

Sistema::~Sistema() {
    if (db) {
        sqlite3_close(db);
    }
}

bool Sistema::connectDatabase() {
    int rc = sqlite3_open("appointment_system.db", &db);
    if (rc) {
        std::cerr << "No se pudo abrir la BD: " << sqlite3_errmsg(db) << std::endl;
        return false;
    }
    
    // Activar claves foráneas
    sqlite3_exec(db, "PRAGMA foreign_keys = ON;", nullptr, nullptr, nullptr);
    return true;
}

bool Sistema::registerUser(const std::string& username, const std::string& password, const std::string& role,
                          const std::string& name, const std::string& email, 
                          const std::string& specialty, const std::string& telephone) {
    sqlite3_stmt* stmt;
    const char* sql = "INSERT INTO USER (USERNAME, PASSWORD, ROLE, NAME, EMAIL, SPECIALTY, TELEPHONE) "
                      "VALUES (?, ?, ?, ?, ?, ?, ?)";
    
    int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);
    if (rc != SQLITE_OK) {
        std::cerr << "Error preparando sentencia: " << sqlite3_errmsg(db) << std::endl;
        return false;
    }
    
    sqlite3_bind_text(stmt, 1, username.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, password.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 3, role.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 4, name.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 5, email.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 6, specialty.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 7, telephone.c_str(), -1, SQLITE_STATIC);
    
    rc = sqlite3_step(stmt);
    sqlite3_finalize(stmt);
    
    if (rc != SQLITE_DONE) {
        std::cerr << "Error insertando usuario: " << sqlite3_errmsg(db) << std::endl;
        return false;
    }
    
    return true;
}

std::unique_ptr<User> Sistema::loginUser(const std::string& username, const std::string& password) {
    sqlite3_stmt* stmt;
    const char* sql = "SELECT ID, USERNAME, PASSWORD, ROLE, NAME, EMAIL, SPECIALTY, TELEPHONE "
                      "FROM USER WHERE USERNAME = ? AND PASSWORD = ?";
    
    int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);
    if (rc != SQLITE_OK) {
        std::cerr << "Error preparando sentencia: " << sqlite3_errmsg(db) << std::endl;
        return nullptr;
    }
    
    sqlite3_bind_text(stmt, 1, username.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, password.c_str(), -1, SQLITE_STATIC);
    
    rc = sqlite3_step(stmt);
    if (rc == SQLITE_ROW) {
        int id = sqlite3_column_int(stmt, 0);
        std::string db_username = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
        std::string db_password = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2));
        std::string role = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3));
        std::string name = sqlite3_column_text(stmt, 4) ? 
                          reinterpret_cast<const char*>(sqlite3_column_text(stmt, 4)) : "";
        std::string email = sqlite3_column_text(stmt, 5) ? 
                           reinterpret_cast<const char*>(sqlite3_column_text(stmt, 5)) : "";
        std::string specialty = sqlite3_column_text(stmt, 6) ? 
                               reinterpret_cast<const char*>(sqlite3_column_text(stmt, 6)) : "";
        std::string telephone = sqlite3_column_text(stmt, 7) ? 
                               reinterpret_cast<const char*>(sqlite3_column_text(stmt, 7)) : "";
        
        sqlite3_finalize(stmt);
        
        // Crear el objeto correspondiente según el rol
        if (role == "Patient") {
            return std::make_unique<Patient>(id, db_username, db_password, name, email, telephone);
        } else if (role == "Doctor") {
            return std::make_unique<Doctor>(id, db_username, db_password, name, email, specialty);
        } else if (role == "Administrator") {
            return std::make_unique<Admin>(id, db_username, db_password, name, email);
        }
    }
    
    sqlite3_finalize(stmt);
    return nullptr;
}

void Sistema::initializeRobots(int count) {
    robots.clear();
    for (int i = 1; i <= count; ++i) {
        robots.push_back(std::make_shared<Robot>(i));
    }
    std::cout << "Sistema de robots inicializado con " << count << " robots.\n";
}

void Sistema::showRobotsStatus() const {
    std::cout << "\n=== ESTADO DE LOS ROBOTS ===\n";
    for (const auto& robot : robots) {
        std::cout << "Robot " << robot->getId() << " | Estado: " << robot->getState() << std::endl;
    }
}

void Sistema::assignRobotTask(int robotId, int seconds, const std::string& taskType) {
    auto it = std::find_if(robots.begin(), robots.end(),
        [robotId](const std::shared_ptr<Robot>& r) { return r->getId() == robotId; });
    
    if (it != robots.end()) {
        if ((*it)->getState() == "Libre") {
            (*it)->assignTask(seconds, taskType);
        } else {
            std::cout << "El robot " << robotId << " está ocupado.\n";
        }
    } else {
        std::cout << "No existe el robot con ID " << robotId << ".\n";
    }
}

void Sistema::assignAnyRobot(int seconds, const std::string& taskType) {
    auto it = std::find_if(robots.begin(), robots.end(),
        [](const std::shared_ptr<Robot>& r) { return r->getState() == "Libre"; });
    
    if (it != robots.end()) {
        std::cout << "Asignando tarea al robot " << (*it)->getId() << "...\n";
        (*it)->assignTask(seconds, taskType);
    } else {
        std::cout << "No hay robots disponibles.\n";
    }
}

void Sistema::freeRobot(int robotId) {
    auto it = std::find_if(robots.begin(), robots.end(),
        [robotId](const std::shared_ptr<Robot>& r) { return r->getId() == robotId; });
    
    if (it != robots.end()) {
        std::cout << "Liberando robot " << robotId << " manualmente.\n";
        // En una implementación real, aquí se forzaría la liberación
    } else {
        std::cout << "Robot no encontrado.\n";
    }
}

std::vector<std::shared_ptr<User>> Sistema::getDoctorsList() const {
    // Implementación para obtener lista de doctores
    return std::vector<std::shared_ptr<User>>();
}

std::vector<std::shared_ptr<User>> Sistema::getAllUsers() const {
    // Implementación para obtener todos los usuarios
    return std::vector<std::shared_ptr<User>>();
}