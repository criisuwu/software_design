#include "imports/Robot.h"

// * Constructor
Robot::Robot(const std::string& id, int pos, double spd, bool st, int dim) {
    this->idRobot = id;
    this->position = pos;
    this->speed = spd;
    this->state = st;
    this->dimensions = dim;
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

// * Miara citas
bool Robot::CheckList(const Appointment& appointment, const Login& userLogin) {
    std::cout << "Revisando las citas: " << std::endl;
    return true;
}

// * Modulo de sonido
void Robot::Talk(const std::string& phrase) {
    std::cout << "Robot dice: " << phrase << std::endl;
}

// * Sensor del siguelineas
bool Robot::ScanSpace() {
    std::cout << "Escaneando el entorno..." << std::endl;
    return true;
}

// * Confimar info
bool Robot::CheckCredential(const std::string& credential) {
    std::cout << "Verificando credencial: " << credential << " -> válida ✅" << std::endl;
    return true;
}

// * Verificar si esta ocupado o libre
bool Robot::ChangeState(bool newState) {
    state = newState;
    std::cout << "El robot ahora está " << (state ? "activo" : "inactivo") << std::endl;
    return state;
}

void Robot::ShowInfo() const {
    std::cout << "\t*Info del robot*\t" << std::endl;
    std::cout << "Robot ID: " << idRobot << std::endl;
    std::cout << "Posición: " << position << std::endl;
    std::cout << "Velocidad: " << speed << std::endl;
    std::cout << "Estado: " << (state ? "Activo" : "Inactivo") << std::endl;
    std::cout << "Dimensiones: " << dimensions << std::endl;
}
