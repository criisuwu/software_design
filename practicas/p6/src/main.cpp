#include <iostream>
#include <limits>
#include <memory>
#include "../import/Sistema.h"
#include "../import/Robot.h"

//  Muestra el menu principal
void showMainMenu() {
    std::cout << "\n=== SISTEMA DE GESTIÓN DE ROBOTS HOSPITALARIOS ===\n";
    std::cout << "1. Mostrar estado de todos los robots\n";
    std::cout << "2. Asignar tarea automáticamente\n";
    std::cout << "3. Asignar tarea a robot específico\n";
    std::cout << "4. Forzar liberación de robot\n";
    std::cout << "5. Funciones avanzadas del robot\n";
    std::cout << "6. Salir\n";
    std::cout << "Seleccione una opción: ";
}

//  Como en mi codigo robot de la practica 4 tenia muchos metodos he decidido implementarlos de forma basica. Y este es el menu de esos metodos
void showMenuRobot() {
    std::cout << "\n=== FUNCIONES AVANZADAS DEL ROBOT ===\n";
    std::cout << "1. Mover robot\n";
    std::cout << "2. Generar ticket\n";
    std::cout << "3. Verificar appointment\n";
    std::cout << "4. Hablar\n";
    std::cout << "5. Escanear espacio\n";
    std::cout << "6. Verificar info\n";
    std::cout << "7. Cambiar estado (activo/inactivo)\n";
    std::cout << "8. Mostrar información del robot\n";
    std::cout << "9. Volver al menú principal\n";
    std::cout << "Seleccione una opción: ";
}

//  Limpia el buffer
void clearBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

//  Los casos para el menu de los metodos extra que tenia en el codigo de la practica 4
void advancedRobot() {
    int optionRobot;
    bool enMenuRobot = true;
    
    while (enMenuRobot) {
        showMenuRobot();
        std::cin >> optionRobot;
        
        switch (optionRobot) {
            case 1: {
                int idRobot, newPosition;
                std::cout << "Ingrese el ID del robot: ";
                std::cin >> idRobot;
                std::cout << "Ingrese la nueva posición: ";
                std::cin >> newPosition;
                
                Robot robotTemp(idRobot);
                robotTemp.Move(newPosition);
                break;
            }
            
            case 2: {
                int idRobot;
                std::string ticketInfo;
                std::cout << "Ingrese el ID del robot: ";
                std::cin >> idRobot;
                clearBuffer();
                std::cout << "Ingrese la información del ticket: ";
                std::getline(std::cin, ticketInfo);
                
                Robot robotTemp(idRobot);
                robotTemp.PrintTicket(ticketInfo);
                break;
            }
            
            case 3: {
                int idRobot;
                Appointment appointment;
                Login login;
                
                std::cout << "Ingrese el ID del robot: ";
                std::cin >> idRobot;
                clearBuffer();
                
                std::cout << "Ingrese nombre del paciente: ";
                std::getline(std::cin, appointment.patientName);
                std::cout << "Ingrese hora de la appointment: ";
                std::getline(std::cin, appointment.time);
                std::cout << "Ingrese destino: ";
                std::getline(std::cin, appointment.destination);
                std::cout << "Ingrese usuario: ";
                std::getline(std::cin, login.username);
                std::cout << "Ingrese contraseña: ";
                std::getline(std::cin, login.password);
                
                Robot robotTemp(idRobot);
                bool validAppointment = robotTemp.CheckList(appointment, login);
                std::cout << "Cita " << (validAppointment ? "confirmada" : "rechazada") << std::endl;
                break;
            }
            
            case 4: {
                int idRobot;
                std::string words;
                std::cout << "Ingrese el ID del robot: ";
                std::cin >> idRobot;
                clearBuffer();
                std::cout << "Ingrese lo que debe decir el robot: ";
                std::getline(std::cin, words);
                
                Robot robotTemp(idRobot);
                robotTemp.Talk(words);
                break;
            }
            
            case 5: {
                int idRobot;
                std::cout << "Ingrese el ID del robot: ";
                std::cin >> idRobot;
                
                Robot robotTemp(idRobot);
                bool freeSpace = robotTemp.ScanSpace();
                std::cout << "Espacio " << (freeSpace ? "libre" : "ocupado") << std::endl;
                break;
            }
            
            case 6: {
                int idRobot;
                std::string info;
                std::cout << "Ingrese el ID del robot: ";
                std::cin >> idRobot;
                clearBuffer();
                std::cout << "Ingrese la info a verificar: ";
                std::getline(std::cin, info);
                
                Robot robotTemp(idRobot);
                bool validInfo = robotTemp.CheckCredential(info);
                std::cout << "Credencial " << (validInfo ? "válida" : "inválida") << std::endl;
                break;
            }
            
            case 7: {
                int idRobot, newState;
                std::cout << "Ingrese el ID del robot: ";
                std::cin >> idRobot;
                std::cout << "Ingrese el nuevo estado (1=Activo, 0=Inactivo): ";
                std::cin >> newState;
                
                Robot robotTemp(idRobot);
                robotTemp.ChangeState(newState != 0);
                break;
            }
            
            case 8: {
                int idRobot;
                std::cout << "Ingrese el ID del robot: ";
                std::cin >> idRobot;
                
                Robot robotTemp(idRobot);
                robotTemp.ShowInfo();
                break;
            }
            
            case 9: {
                enMenuRobot = false;
                std::cout << "Volviendo al menú principal...\n";
                break;
            }
            
            default: {
                std::cout << "Opción no válida. Intente nuevamente.\n";
                break;
            }
        }
        
        if (optionRobot != 9) {
            std::cout << "\nPresione Enter para continuar...";
            clearBuffer();
            std::cin.get();
        }
    }
}

//  El main con el menu principal y sus condiciones principales (Lo pedido para esta practica)
int main() {
    int numberRobots;
    std::cout << "=== INICIALIZACIÓN DEL SISTEMA ===\n";
    std::cout << "Ingrese la cantidad de robots a crear: ";
    std::cin >> numberRobots;
    
    if (std::cin.fail() || numberRobots <= 0) {
        std::cout << "Error: debe ingresar un número válido mayor que 0.\n";
        return 1;
    }
    
    // Crear el system con la cantidad especificada de robots
    Sistema system(numberRobots);
    std::cout << "Sistema inicializado con " << numberRobots << " robots.\n";
    
    int option;
    bool program = true;
    
    while (program) {
        showMainMenu();
        std::cin >> option;
        
        if (std::cin.fail()) {
            std::cout << "Error: ingrese un número válido.\n";
            clearBuffer();
            continue;
        }
        
        switch (option) {
            case 1: {
                system.showState();
                break;
            }
            
            case 2: {
                int seconds;
                std::cout << "Ingrese la duración de la tarea (seconds): ";
                std::cin >> seconds;
                
                if (std::cin.fail() || seconds < 0) {
                    std::cout << "Error: ingrese un número válido de seconds.\n";
                    clearBuffer();
                } else {
                    system.assingRobot(seconds);
                }
                break;
            }
            
            case 3: {
                int idRobot, seconds;
                std::cout << "Ingrese el ID del robot: ";
                std::cin >> idRobot;
                std::cout << "Ingrese la duración de la tarea (seconds): ";
                std::cin >> seconds;
                
                if (std::cin.fail() || seconds < 0 || idRobot <= 0) {
                    std::cout << "Error: ingrese valores válidos.\n";
                    clearBuffer();
                } else {
                    system.assingRobot(seconds, idRobot);
                }
                break;
            }
            
            case 4: {
                int idRobot;
                std::cout << "Ingrese el ID del robot a liberar: ";
                std::cin >> idRobot;
                
                if (std::cin.fail() || idRobot <= 0) {
                    std::cout << "Error: ingrese un ID válido.\n";
                    clearBuffer();
                } else {
                    system.freeRobot(idRobot);
                }
                break;
            }
            
            case 5: {
                advancedRobot();
                break;
            }
            
            case 6: {
                program = false;
                std::cout << "Saliendo del system... ¡Hasta pronto!\n";
                break;
            }
            
            default: {
                std::cout << "Opción no válida. Intente nuevamente.\n";
                break;
            }
        }
        
        if (option != 6 && option != 5) {
            std::cout << "\nPresione Enter para continuar...";
            clearBuffer();
            std::cin.get();
        }
    }
    
    return 0;
}