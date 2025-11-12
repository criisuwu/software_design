#include <iostream>
#include <limits>
#include <memory>
#include "../import/Sistema.h"
#include "../import/Robot.h"

void mostrarMenuPrincipal() {
    std::cout << "\n=== SISTEMA DE GESTIÓN DE ROBOTS HOSPITALARIOS ===\n";
    std::cout << "1. Mostrar estado de todos los robots\n";
    std::cout << "2. Asignar tarea automáticamente\n";
    std::cout << "3. Asignar tarea a robot específico\n";
    std::cout << "4. Forzar liberación de robot\n";
    std::cout << "5. Funciones avanzadas del robot\n";
    std::cout << "6. Salir\n";
    std::cout << "Seleccione una opción: ";
}

void mostrarMenuRobot() {
    std::cout << "\n=== FUNCIONES AVANZADAS DEL ROBOT ===\n";
    std::cout << "1. Mover robot\n";
    std::cout << "2. Generar ticket\n";
    std::cout << "3. Verificar cita\n";
    std::cout << "4. Hablar\n";
    std::cout << "5. Escanear espacio\n";
    std::cout << "6. Verificar credencial\n";
    std::cout << "7. Cambiar estado (activo/inactivo)\n";
    std::cout << "8. Mostrar información del robot\n";
    std::cout << "9. Volver al menú principal\n";
    std::cout << "Seleccione una opción: ";
}

void limpiarBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void funcionesAvanzadasRobot() {
    int opcionRobot;
    bool enMenuRobot = true;
    
    while (enMenuRobot) {
        mostrarMenuRobot();
        std::cin >> opcionRobot;
        
        switch (opcionRobot) {
            case 1: {
                int idRobot, nuevaPosicion;
                std::cout << "Ingrese el ID del robot: ";
                std::cin >> idRobot;
                std::cout << "Ingrese la nueva posición: ";
                std::cin >> nuevaPosicion;
                
                Robot robotTemp(idRobot);
                robotTemp.Move(nuevaPosicion);
                break;
            }
            
            case 2: {
                int idRobot;
                std::string ticketInfo;
                std::cout << "Ingrese el ID del robot: ";
                std::cin >> idRobot;
                limpiarBuffer();
                std::cout << "Ingrese la información del ticket: ";
                std::getline(std::cin, ticketInfo);
                
                Robot robotTemp(idRobot);
                robotTemp.PrintTicket(ticketInfo);
                break;
            }
            
            case 3: {
                int idRobot;
                Appointment cita;
                Login login;
                
                std::cout << "Ingrese el ID del robot: ";
                std::cin >> idRobot;
                limpiarBuffer();
                
                std::cout << "Ingrese nombre del paciente: ";
                std::getline(std::cin, cita.patientName);
                std::cout << "Ingrese hora de la cita: ";
                std::getline(std::cin, cita.time);
                std::cout << "Ingrese destino: ";
                std::getline(std::cin, cita.destination);
                std::cout << "Ingrese usuario: ";
                std::getline(std::cin, login.username);
                std::cout << "Ingrese contraseña: ";
                std::getline(std::cin, login.password);
                
                Robot robotTemp(idRobot);
                bool citaValida = robotTemp.CheckList(cita, login);
                std::cout << "Cita " << (citaValida ? "confirmada" : "rechazada") << std::endl;
                break;
            }
            
            case 4: {
                int idRobot;
                std::string frase;
                std::cout << "Ingrese el ID del robot: ";
                std::cin >> idRobot;
                limpiarBuffer();
                std::cout << "Ingrese lo que debe decir el robot: ";
                std::getline(std::cin, frase);
                
                Robot robotTemp(idRobot);
                robotTemp.Talk(frase);
                break;
            }
            
            case 5: {
                int idRobot;
                std::cout << "Ingrese el ID del robot: ";
                std::cin >> idRobot;
                
                Robot robotTemp(idRobot);
                bool espacioLibre = robotTemp.ScanSpace();
                std::cout << "Espacio " << (espacioLibre ? "libre" : "ocupado") << std::endl;
                break;
            }
            
            case 6: {
                int idRobot;
                std::string credencial;
                std::cout << "Ingrese el ID del robot: ";
                std::cin >> idRobot;
                limpiarBuffer();
                std::cout << "Ingrese la credencial a verificar: ";
                std::getline(std::cin, credencial);
                
                Robot robotTemp(idRobot);
                bool credencialValida = robotTemp.CheckCredential(credencial);
                std::cout << "Credencial " << (credencialValida ? "válida" : "inválida") << std::endl;
                break;
            }
            
            case 7: {
                int idRobot, nuevoEstado;
                std::cout << "Ingrese el ID del robot: ";
                std::cin >> idRobot;
                std::cout << "Ingrese el nuevo estado (1=Activo, 0=Inactivo): ";
                std::cin >> nuevoEstado;
                
                Robot robotTemp(idRobot);
                robotTemp.ChangeState(nuevoEstado != 0);
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
        
        if (opcionRobot != 9) {
            std::cout << "\nPresione Enter para continuar...";
            limpiarBuffer();
            std::cin.get();
        }
    }
}

int main() {
    int cantidadRobots;
    std::cout << "=== INICIALIZACIÓN DEL SISTEMA ===\n";
    std::cout << "Ingrese la cantidad de robots a crear: ";
    std::cin >> cantidadRobots;
    
    if (std::cin.fail() || cantidadRobots <= 0) {
        std::cout << "Error: debe ingresar un número válido mayor que 0.\n";
        return 1;
    }
    
    // Crear el sistema con la cantidad especificada de robots
    Sistema sistema(cantidadRobots);
    std::cout << "Sistema inicializado con " << cantidadRobots << " robots.\n";
    
    int opcion;
    bool ejecutando = true;
    
    while (ejecutando) {
        mostrarMenuPrincipal();
        std::cin >> opcion;
        
        if (std::cin.fail()) {
            std::cout << "Error: ingrese un número válido.\n";
            limpiarBuffer();
            continue;
        }
        
        switch (opcion) {
            case 1: {
                sistema.mostrarEstados();
                break;
            }
            
            case 2: {
                int segundos;
                std::cout << "Ingrese la duración de la tarea (segundos): ";
                std::cin >> segundos;
                
                if (std::cin.fail() || segundos < 0) {
                    std::cout << "Error: ingrese un número válido de segundos.\n";
                    limpiarBuffer();
                } else {
                    sistema.asignarRobot(segundos);
                }
                break;
            }
            
            case 3: {
                int idRobot, segundos;
                std::cout << "Ingrese el ID del robot: ";
                std::cin >> idRobot;
                std::cout << "Ingrese la duración de la tarea (segundos): ";
                std::cin >> segundos;
                
                if (std::cin.fail() || segundos < 0 || idRobot <= 0) {
                    std::cout << "Error: ingrese valores válidos.\n";
                    limpiarBuffer();
                } else {
                    sistema.asignarRobot(segundos, idRobot);
                }
                break;
            }
            
            case 4: {
                int idRobot;
                std::cout << "Ingrese el ID del robot a liberar: ";
                std::cin >> idRobot;
                
                if (std::cin.fail() || idRobot <= 0) {
                    std::cout << "Error: ingrese un ID válido.\n";
                    limpiarBuffer();
                } else {
                    sistema.forzarLibre(idRobot);
                }
                break;
            }
            
            case 5: {
                funcionesAvanzadasRobot();
                break;
            }
            
            case 6: {
                ejecutando = false;
                std::cout << "Saliendo del sistema... ¡Hasta pronto!\n";
                break;
            }
            
            default: {
                std::cout << "Opción no válida. Intente nuevamente.\n";
                break;
            }
        }
        
        if (opcion != 6 && opcion != 5) {
            std::cout << "\nPresione Enter para continuar...";
            limpiarBuffer();
            std::cin.get();
        }
    }
    
    return 0;
}