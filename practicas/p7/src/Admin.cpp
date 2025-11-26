#include "../import/Admin.h"
#include <iostream>

Admin::Admin(int id, const std::string& username, const std::string& password, 
             const std::string& name, const std::string& email)
    : User(id, username, password, "Administrator", name, email) {}

void Admin::showMenu() {
    int option;
    do {
        std::cout << "\n=== MENÚ ADMINISTRADOR ===\n";
        std::cout << "1. Crear Doctor\n";
        std::cout << "2. Asignar Agenda a Doctor\n";
        std::cout << "3. Ver Lista de Doctores\n";
        std::cout << "4. Ver Todos los Usuarios\n";
        std::cout << "5. Ver Mi Información\n";
        std::cout << "6. Cerrar Sesión\n";
        std::cout << "Seleccione una opción: ";
        std::cin >> option;
        
        switch(option) {
            case 1:
                createDoctor();
                break;
            case 2:
                assignSchedule();
                break;
            case 3:
                viewDoctorsList();
                break;
            case 4:
                viewAllUsers();
                break;
            case 5:
                displayInfo();
                break;
            case 6:
                std::cout << "Cerrando sesión...\n";
                break;
            default:
                std::cout << "Opción no válida\n";
        }
    } while(option != 6);
}

void Admin::displayInfo() const {
    std::cout << "\n=== INFORMACIÓN DEL ADMINISTRADOR ===\n";
    User::displayInfo();
}

void Admin::createDoctor() {
    std::cout << "\n--- Crear Doctor ---\n";
    std::cout << "Funcionalidad en desarrollo...\n";
}

void Admin::assignSchedule() {
    std::cout << "\n--- Asignar Agenda ---\n";
    std::cout << "Funcionalidad en desarrollo...\n";
}

void Admin::viewDoctorsList() {
    std::cout << "\n--- Lista de Doctores ---\n";
    std::cout << "Funcionalidad en desarrollo...\n";
}

void Admin::viewAllUsers() {
    std::cout << "\n--- Todos los Usuarios ---\n";
    std::cout << "Funcionalidad en desarrollo...\n";
}