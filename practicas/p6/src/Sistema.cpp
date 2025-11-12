#include "../import/Sistema.h"
#include <iostream>
#include <algorithm>
#include <chrono>
#include <thread>

Sistema::Sistema(int cantidadRobots) {
    for (int i = 1; i <= cantidadRobots; ++i) {
        robots.insert(std::make_shared<Robot>(i));
    }
}

void Sistema::mostrarEstados() const {
    std::cout << "\n=== ESTADO DE LOS ROBOTS ===\n";
    for (const auto& r : robots) {
        std::cout << "Robot " << r->getId()
                  << " | Estado: " << r->getState() << std::endl;
    }
    std::cout << "=============================\n";
}

void Sistema::asignarRobot(int segundos) {
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

void Sistema::asignarRobot(int segundos, int idRobot) {
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

void Sistema::forzarLibre(int idRobot) {
    auto it = std::find_if(robots.begin(), robots.end(),
        [idRobot](const std::shared_ptr<Robot>& r) { return r->getId() == idRobot; });

    if (it != robots.end()) {
        // ⚠️ Este cambio fuerza el estado, solo para simulación
        std::cout << "[Manual] Forzando estado libre para robot " << idRobot << ".\n";
        (*it)->dummy(0); // lo “resetea” al instante
    } else {
        std::cout << "Robot no encontrado.\n";
    }
}

