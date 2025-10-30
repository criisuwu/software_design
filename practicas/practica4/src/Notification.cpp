#include "../imports/Notification.h"

// * Constructor
Notification::Notification(const std::string& info, bool state) {
    this->InfoAppointment = info;
    this->State = state;
}

// * Get de los atributos
std::string Notification::getInfoAppointment() const {
    return InfoAppointment;
}

bool Notification::getState() const {
    return State;
}

// * Set del estado
void Notification::setState(bool state) {
    State = state;
}

// * Mandar noti
void Notification::sendNotification() {
    std::cout << "Enviando notificación: " << InfoAppointment << std::endl;
    std::cout << "Estado actual: " << (State ? "Activa" : "Inactiva") << std::endl;
}

// * Cambiar el estado
bool Notification::changeState(bool newState) {
    if (State == newState) {
        std::cout << "El estado ya es " << (State ? "activo" : "inactivo") << "." << std::endl;
        return false;
    }
    State = newState;
    std::cout << "Estado cambiado a: " << (State ? "activo" : "inactivo") << std::endl;
    return true;
}

void Notification::displayNotification() const {
    std::cout << "\t*Info de notificacion*\t" << std::endl;
    std::cout << "Información: " << InfoAppointment << std::endl;
    std::cout << "Estado: " << (State ? "Activo" : "Inactivo") << std::endl;;
}
