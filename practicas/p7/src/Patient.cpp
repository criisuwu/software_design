#include "../import/Patient.h"
#include <iostream>

Patient::Patient(int id, const std::string& username, const std::string& password, 
                 const std::string& name, const std::string& email, const std::string& telephone)
    : User(id, username, password, "Patient", name, email), telephone(telephone) {}

void Patient::showMenu() {
    int option;
    do {
        std::cout << "\n=== MENÚ PACIENTE ===\n";
        std::cout << "1. Solicitar Cita\n";
        std::cout << "2. Ver Mis Citas\n";
        std::cout << "3. Cancelar Cita\n";
        std::cout << "4. Ver Mi Información\n";
        std::cout << "5. Cerrar Sesión\n";
        std::cout << "Seleccione una opción: ";
        std::cin >> option;
        
        switch(option) {
            case 1:
                requestAppointment();
                break;
            case 2:
                viewMyAppointments();
                break;
            case 3:
                cancelAppointment();
                break;
            case 4:
                displayInfo();
                break;
            case 5:
                std::cout << "Cerrando sesión...\n";
                break;
            default:
                std::cout << "Opción no válida\n";
        }
    } while(option != 5);
}

void Patient::displayInfo() const {
    std::cout << "\n=== INFORMACIÓN DEL PACIENTE ===\n";
    User::displayInfo();
    std::cout << "Teléfono: " << telephone << "\n";
}

void Patient::requestAppointment() {
    std::cout << "\n--- Solicitar Cita ---\n";
    std::cout << "Funcionalidad en desarrollo...\n";
}

void Patient::viewMyAppointments() {
    std::cout << "\n--- Mis Citas ---\n";
    std::cout << "Funcionalidad en desarrollo...\n";
}

void Patient::cancelAppointment() {
    std::cout << "\n--- Cancelar Cita ---\n";
    std::cout << "Funcionalidad en desarrollo...\n";
}