#include "imports/Robot.h"

// * Constructor
Robot::Robot(const std::string& id, int pos, double spd, bool st, int dim) {
    idRobot = id;
    position = pos;
    speed = spd;
    state = st;
    dimensions = dim;
}

// * Movimiento del robot (Los prints son para el main)
void Robot::Move(int newPos) {
    std::cout << "Robot " << idRobot << " moviéndose de posición " << position
              << " a " << newPos << "..." << std::endl;
    position = newPos;
}

// * Informacion del ticket
void Robot::PrintTicket(const std::string& ticketInfo) {
    std::cout << "Imprimiendo ticket: " << ticketInfo << std::endl;
}

//
bool Robot::CheckList(const Appointment& appointment, const Login& userLogin) {
    std::cout << "Revisando las citas: " << std::endl;
    return true;
}

void Robot::Talk(const std::string& phrase) {
    std::cout << "Robot dice: " << phrase << std::endl;
}

bool Robot::ScanSpace() {
    std::cout << "Escaneando el entorno..." << std::endl;
    return true;
}

bool Robot::CheckCredential(const std::string& credential) {
    std::cout << "Verificando credencial: " << credential << " -> válida ✅" << std::endl;
    return true;
}

bool Robot::ChangeState(bool newState) {
    state = newState;
    std::cout << "El robot ahora está " << (state ? "activo" : "inactivo") << std::endl;
    return state;
}

void Robot::ShowInfo() const {
    std::cout << "Robot ID: " << idRobot
              << "\nPosición: " << position
              << "\nVelocidad: " << speed
              << "\nEstado: " << (state ? "Activo" : "Inactivo")
              << "\nDimensiones: " << dimensions << std::endl;
}
