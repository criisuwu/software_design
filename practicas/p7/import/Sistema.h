#ifndef SISTEMA_H
#define SISTEMA_H

#include <set>
#include <vector>
#include <memory>
#include "Robot.h"

// Comparador para ordenar los robots por su última actividad
struct CompararPorActividad {
    bool operator()(const std::shared_ptr<Robot>& a, const std::shared_ptr<Robot>& b) const {
        return a->getUltimaActividad() < b->getUltimaActividad();
    }
};

// Clase Sistema: gestiona los robots del hospitala
class Sistema {
private:
    std::set<std::shared_ptr<Robot>, CompararPorActividad> robots;

public:
    Sistema(int cantidadRobots);

    void showState() const;
    void assingRobot(int segundos);
    void assingRobot(int segundos, int idRobot); // asigna un robot específico
    void freeRobot(int idRobot);                 // libera manualmente un robot

};

#endif
