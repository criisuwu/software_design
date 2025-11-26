#include "../import/Doctor.h"
#include <iostream>

Doctor::Doctor(int id, const std::string& username, const std::string& password, 
               const std::string& name, const std::string& email, const std::string& specialty)
    : User(id, username, password, "Doctor", name, email), specialty(specialty) {}

void Doctor::showMenu() {
    int option;
    do {
        std::cout << "\n=== MENÚ DOCTOR ===\n";
        std::cout << "1. Confirmar Asistencia\n";
        std::cout << "2. Modificar Agenda\n";
        std::cout << "3. Añadir Notas a Cita\n";
        std::cout << "4. Ver Mi Agenda\n";
        std::cout << "5. Ver Mi Información\n";
        std::cout << "6. Cerrar Sesión\n";
        std::cout << "Seleccione una opción: ";
        std::cin >> option;
        
        switch(option) {
            case 1:
                confirmAttendance();
                break;
            case 2:
                modifySchedule();
                break;
            case 3:
                addNotesToAppointment();
                break;
            case 4:
                viewMySchedule();
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

void Doctor::displayInfo() const {
    std::cout << "\n=== INFORMACIÓN DEL DOCTOR ===\n";
    User::displayInfo();
    std::cout << "Especialidad: " << specialty << "\n";
}

void Doctor::confirmAttendance() {
    std::cout << "\n--- Confirmar Asistencia ---\n";
    std::cout << "Funcionalidad en desarrollo...\n";
}

void Doctor::modifySchedule() {
    std::cout << "\n--- Modificar Agenda ---\n";
    std::cout << "Funcionalidad en desarrollo...\n";
}

void Doctor::addNotesToAppointment() {
    std::cout << "\n--- Añadir Notas a Cita ---\n";
    std::cout << "Funcionalidad en desarrollo...\n";
}

void Doctor::viewMySchedule() {
    std::cout << "\n--- Mi Agenda ---\n";
    std::cout << "Funcionalidad en desarrollo...\n";
}