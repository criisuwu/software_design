#include "../import/Admin.h"
#include "../import/Sistema.h"
#include <iostream>

void Admin::displayInfo() const {
    std::cout << "\n=== INFORMACIÓN DEL ADMINISTRADOR ===\n";
    User::displayInfo();
}

void Admin::createDoctor() {
    std::cout << "\n--- Crear Doctor ---\n";

    std::string username, password, name, email, specialty, telephone;

    std::cout << "Usuario: ";
    std::cin >> username;
    std::cout << "Contraseña: ";
    std::cin >> password;
    std::cout << "Nombre: ";
    std::cin.ignore();
    std::getline(std::cin, name);
    std::cout << "Correo: ";
    std::cin >> email;
    std::cout << "Especialidad: ";
    std::cin.ignore();
    std::getline(std::cin, specialty);
    std::cout << "Teléfono: ";
    std::cin >> telephone;

    Sistema& sys = Sistema::getInstance();

    bool ok = sys.registerUser(username, password, "Doctor",
                               name, email, specialty, telephone);

    if (ok)
        std::cout << "Doctor creado exitosamente.\n";
    else
        std::cout << "Error al crear doctor.\n";
}

void Admin::viewAllUsers() {
    std::cout << "\n--- Todos los Usuarios ---\n";

    Sistema& sys = Sistema::getInstance();
    auto users = sys.getAllUsers();

    if (users.empty()) {
        std::cout << "No hay usuarios registrados.\n";
        return;
    }

    for (const auto& u : users) {
        std::cout << "\nID: " << u->getId()
                  << "\nUsuario: " << u->getUsername()
                  << "\nRol: " << u->getRole()
                  << "\nNombre: " << u->getName()
                  << "\nEmail: " << u->getEmail()
                  << "\n------------------------\n";
    }
}

void Admin::assignSchedule() {      //Me falla esto
    std::cout << "\n--- Asignar Agenda a Doctor ---\n";

    int idDoctor;
    std::string day, start, end;

    std::cout << "ID del Doctor: ";
    std::cin >> idDoctor;
    std::cout << "Día (Ej: Lunes): ";
    std::cin >> day;
    std::cout << "Hora inicio (HH:MM): ";
    std::cin >> start;
    std::cout << "Hora fin (HH:MM): ";
    std::cin >> end;

    Sistema& sys = Sistema::getInstance();

    bool ok = sys.assignScheduleToDoctor(idDoctor, day, start, end);

    if (ok)
        std::cout << "Agenda asignada correctamente.\n";
    else
        std::cout << "Error asignando agenda.\n";
}

void Admin::viewDoctorsList() {
    Sistema& sys = Sistema::getInstance();
    auto doctors = sys.getDoctorsList();

    if (doctors.empty()) {
        std::cout << "No hay doctores registrados.\n";
        return;
    }

    for (auto& d : doctors) {
        std::cout << "\nID: " << d->getId()
                  << "\nNombre: " << d->getName()
                  << "\n-----------------------\n";
    }
}