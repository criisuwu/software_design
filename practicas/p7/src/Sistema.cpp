#include "../import/Sistema.h"
#include <iostream>
#include <algorithm>
#include <chrono>
#include <thread>

//  "Crea" o mejor dicho define la cantidad de robots que dice el usuario
Sistema::Sistema(int cantidadRobots) {
    for (int i = 1; i <= cantidadRobots; ++i) {
        robots.insert(std::make_shared<Robot>(i));
    }
}

//  Muestra los estados de los robots
void Sistema::showState() const {
    std::cout << "\n=== ESTADO DE LOS ROBOTS ===\n";
    for (const auto& r : robots) {
        std::cout << "Robot " << r->getId()
                  << " | Estado: " << r->getState() << std::endl;
    }
    std::cout << "=============================\n";
}

//  Le asigna las tareas al robot y les cambia el estado dependiendo de si esta ocupado o si esta libre y si se le asigna una tarea o si se le libera de ella.
//  Lo que la diferencia de la otra funcion es que esta es "automatica", es decir el usuario no escoge a que robot se le pone la tarea
void Sistema::assingRobot(int segundos) {
    // Buscar el primer robot libre (el que lleva más tiempo sin actividad)
    auto it = std::find_if(robots.begin(), robots.end(),
        [](const std::shared_ptr<Robot>& r) { return r->getState() == "Libre"; });

    if (it != robots.end()) {
        std::cout << "\nAsignando tarea al robot " << (*it)->getId() << "...\n";
        (*it)->dummy(segundos);
    } else {
        std::cout << "No hay robots disponibles.\n";
    }
}

//  Le asigna las tareas al robot y les cambia el estado dependiendo de si esta ocupado o si esta libre y si se le asigna una tarea o si se le libera de ella
void Sistema::assingRobot(int segundos, int idRobot) {
    auto it = std::find_if(robots.begin(), robots.end(),
        [idRobot](const std::shared_ptr<Robot>& r) { return r->getId() == idRobot; });

    if (it != robots.end()) {
        if ((*it)->getState() == "Libre") {
            std::cout << "[Manual] Asignando tarea al robot " << idRobot << "...\n";
            (*it)->dummy(segundos);
        } else {
            std::cout << "El robot " << idRobot << " está ocupado.\n";
        }
    } else {
        std::cout << "No existe el robot con ID " << idRobot << ".\n";
    }
}

//  Libera al robot, es decir si esta ocupado/atendiendo a alguien, lo pone en default otra vez
void Sistema::freeRobot(int idRobot) {
    auto it = std::find_if(robots.begin(), robots.end(),
        [idRobot](const std::shared_ptr<Robot>& r) { return r->getId() == idRobot; });

    if (it != robots.end()) {
        //Este cambio fuerza el estado, solo para simulación
        std::cout << "[Manual] Forzando estado libre para robot " << idRobot << ".\n";
        (*it)->dummy(0); // lo “resetea” al instante
    } else {
        std::cout << "Robot no encontrado.\n";
    }
}