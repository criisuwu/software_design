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
