#include "Schedule.h"

// * Constructor
Schedule::Schedule(int hour, const std::string& appointment) {
    this->Hour = hour;
    this->Appointment = appointment;
}

// * Get de las citas
int Schedule::getHour() const {
    return Hour;
}

std::string Schedule::getAppointment() const {
    return Appointment;
}

// * Set de las citas
void Schedule::setHour(int hour) {
    Hour = hour;
}

void Schedule::setAppointment(const std::string& appointment) {
    Appointment = appointment;
}

void Schedule::displaySchedule() const {
    std::cout << "Mostrando horario:" << std::endl;
    std::cout << "Hora: " << Hour << ":00" << std::endl;
    std::cout << "Cita: " << Appointment << std::endl;
}

void Schedule::showInfo() const {
    std::cout << "\t*Info del Horario*\t" << std::endl;
    std::cout << "Hora: " << Hour << ":00" << std::endl;
    std::cout << "Cita asociada: " << Appointment << std::endl;
}
