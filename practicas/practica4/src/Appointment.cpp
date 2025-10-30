#include "imports/Appointment.h"

// * Constructor
Appointment::Appointment(const std::string& date, const std::string& place, const std::string& info) {
    this->Date = date;
    this->Place = place;
    this->Info = info;
}

// * Gets de la informacion de las citas
std::string Appointment::getDate() const {
    return Date;
}
std::string Appointment::getPlace() const {
    return Place;
}
std::string Appointment::getInfo() const {
    return Info;
}

// * Set de la info
void Appointment::setDate(const std::string& date) {
    Date = date;
}
void Appointment::setPlace(const std::string& place) {
    Place = place;
}
void Appointment::addInfo(const std::string& info) {
    Info = info;
}

// * Mover la cita
void Appointment::moveAppointment(const std::string& newDate) {
    std::cout << "Moviendo cita de " << Date << " a " << newDate << std::endl;
    Date = newDate;
}

// * Cancelar cita
void Appointment::cancelAppointment() {
    std::cout << "Cita en " << Place << " el " << Date << " ha sido cancelada." << std::endl;
}

// * Mirar cita (Creo que no solo deberia de tener la info y que deberia de tener tambien la fecha y lugar)
void Appointment::seeAppointment() const {
    std::cout << "Cita programada para " << Date << " en " << Place << "." << std::endl;
    std::cout << "Motivo: " << Info << std::endl;
}

// * Confirmar la cita
void Appointment::confirmAppointment() {
    std::cout << "Cita confirmada para el " << Date << " en " << Place << "." << std::endl;
}

// * Cambiar si esta presente el paciente o no
void Appointment::changeStatusAppointment() {
    std::cout << "Estado de la cita actualizado correctamente." << std::endl;
}

void Appointment::displayAppointment() const {
    std::cout << "\t*Info Cita*\t" << std::endl;
    std::cout << "Fecha: " << Date << std::endl;
    std::cout << "Lugar: " << Place << std::endl;
    std::cout << "Información: " << Info << std::endl;
}
