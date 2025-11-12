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
                  << " | Estado: " << r->getEstado() << std::endl;
    }
    std::cout << "=============================\n";
}

void Sistema::asignarRobot(int segundos) {
    // Buscar el primer robot libre (el que lleva más tiempo sin actividad)
    auto it = std::find_if(robots.begin(), robots.end(),
        [](const std::shared_ptr<Robot>& r) { return r->getEstado() == "Libre"; });

    if (it != robots.end()) {
        std::cout << "\nAsignando tarea al robot " << (*it)->getId() << "...\n";
        (*it)->dummy(segundos);
    } else {
        std::cout << "No hay robots disponibles.\n";
    }
}
