#include <iostream>
#include <memory>
#include <limits>
#include <sqlite3.h>
#include "../import/User.h"
#include "../import/Patient.h"
#include "../import/Doctor.h"
#include "../import/Admin.h"
#include "../import/Sistema.h"

void clearBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void showMainMenu() {
    std::cout << "\n=== PLATAFORMA GESTIÓN DE CITAS ===\n";
    std::cout << "1. Registrar nuevo usuario\n";
    std::cout << "2. Iniciar Sesión\n";
    std::cout << "3. Estado del Sistema de Robots\n";
    std::cout << "4. Salir\n";
    std::cout << "Seleccione una opción: ";
}

void robotManagementMenu(Sistema& system) {
    int option;
    do {
        std::cout << "\n=== GESTIÓN DE ROBOTS ===\n";
        std::cout << "1. Ver estado de robots\n";
        std::cout << "2. Asignar tarea automáticamente\n";
        std::cout << "3. Asignar tarea a robot específico\n";
        std::cout << "4. Volver al menú principal\n";
        std::cout << "Seleccione una opción: ";
        std::cin >> option;
        
        switch(option) {
            case 1:
                system.showRobotsStatus();
                break;
            case 2: {
                int seconds;
                std::cout << "Duración de la tarea (segundos): ";
                std::cin >> seconds;
                system.assignAnyRobot(seconds, "Tarea general");
                break;
            }
            case 3: {
                int robotId, seconds;
                std::cout << "ID del robot: ";
                std::cin >> robotId;
                std::cout << "Duración de la tarea (segundos): ";
                std::cin >> seconds;
                system.assignRobotTask(robotId, seconds, "Tarea específica");
                break;
            }
            case 4:
                std::cout << "Volviendo al menú principal...\n";
                break;
            default:
                std::cout << "Opción no válida\n";
        }
        
        if (option != 4) {
            std::cout << "\nPresione Enter para continuar...";
            clearBuffer();
            std::cin.get();
        }
    } while(option != 4);
}

void registerNewUser(Sistema& system) {
    std::string username, password, role, name, email, specialty, telephone;
    
    std::cout << "\n=== REGISTRO DE NUEVO USUARIO ===\n";
    std::cout << "Nombre de usuario: ";
    std::getline(std::cin, username);
    std::cout << "Contraseña: ";
    std::getline(std::cin, password);
    
    // Validar rol
    do {
        std::cout << "Tipo de usuario (Doctor/Patient/Administrator): ";
        std::getline(std::cin, role);
        if (role != "Doctor" && role != "Patient" && role != "Administrator") {
            std::cout << "Error: Rol debe ser Doctor, Patient o Administrator\n";
        }
    } while (role != "Doctor" && role != "Patient" && role != "Administrator");
    
    std::cout << "Nombre completo: ";
    std::getline(std::cin, name);
    std::cout << "Email: ";
    std::getline(std::cin, email);
    
    if (role == "Doctor") {
        std::cout << "Especialidad: ";
        std::getline(std::cin, specialty);
    } else if (role == "Patient") {
        std::cout << "Teléfono: ";
        std::getline(std::cin, telephone);
    }
    
    if (system.registerUser(username, password, role, name, email, specialty, telephone)) {
        std::cout << "Usuario registrado exitosamente!\n";
    } else {
        std::cout << "Error al registrar usuario (posiblemente el nombre de usuario ya existe)\n";
    }
}

void loginUser(Sistema& system) {
    std::string username, password;
    
    std::cout << "\n=== INICIO DE SESIÓN ===\n";
    std::cout << "Nombre de usuario: ";
    std::getline(std::cin, username);
    std::cout << "Contraseña: ";
    std::getline(std::cin, password);
    
    std::unique_ptr<User> user = system.loginUser(username, password);
    if (user) {
        std::cout << "Login exitoso. Bienvenido ";
        if (!user->getRole().empty()) {
            std::cout << user->getRole();
        }
        std::cout << "!\n";
        
        // Polimorfismo en acción - llama al showMenu() correcto
        user->showMenu();
    } else {
        std::cout << "Usuario o contraseña incorrectos\n";
    }
}

void demonstratePolymorphism() {
    std::cout << "\n=== DEMOSTRACIÓN DE POLIMORFISMO ===\n";
    
    // Crear diferentes tipos de usuarios
    std::unique_ptr<User> patient = std::make_unique<Patient>(
        1, "paciente_ejemplo", "pass123", "Juan Pérez", "juan@email.com", "123456789");
    
    std::unique_ptr<User> doctor = std::make_unique<Doctor>(
        2, "doctor_ejemplo", "pass123", "Dr. García", "garcia@hospital.com", "Cardiología");
    
    std::unique_ptr<User> admin = std::make_unique<Admin>(
        3, "admin_ejemplo", "pass123", "Admin Principal", "admin@hospital.com");
    
    // Array de punteros a User - polimorfismo
    std::vector<std::unique_ptr<User>> users;
    users.push_back(std::move(patient));
    users.push_back(std::move(doctor));
    users.push_back(std::move(admin));
    
    // Mostrar información de cada usuario
    for (const auto& user : users) {
        std::cout << "\n--- Información del Usuario ---\n";
        user->displayInfo();
        std::cout << "Tipo real: " << typeid(*user).name() << "\n";
    }
    
    std::cout << "\nPresione Enter para continuar...";
    clearBuffer();
    std::cin.get();
}

int main() {
    Sistema system;
    
    // Inicializar sistema de robots
    system.initializeRobots(3);
    
    std::cout << "========================================\n";
    std::cout << "   SISTEMA DE GESTIÓN DE CITAS MÉDICAS\n";
    std::cout << "   Con SQLite3, Herencia y Polimorfismo\n";
    std::cout << "========================================\n";
    
    int option;
    
    do {
        showMainMenu();
        std::cin >> option;
        clearBuffer();
        
        switch(option) {
            case 1:
                registerNewUser(system);
                break;
            
            case 2:
                loginUser(system);
                break;
            
            case 3:
                robotManagementMenu(system);
                break;
                
            case 4:
                std::cout << "\n¡Gracias por usar el sistema! Hasta pronto.\n";
                break;
                
            case 99: // Opción secreta para demostración
                demonstratePolymorphism();
                break;
                
            default:
                std::cout << "Opción no válida. Por favor, seleccione 1-4.\n";
        }
        
        if (option != 4 && option != 99) {
            std::cout << "\nPresione Enter para continuar...";
            std::cin.get();
        }
    } while(option != 4);
    
    return 0;
}