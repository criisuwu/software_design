#include "../imports/Patient.h"

// * Constructor
Patient::Patient(const std::string& name, const std::string& idPatient, 
                 const std::string& email, const std::string& user, 
                 const std::string& pass, int number, int phone) {
    this->name = name;
    this->idPatient = idPatient;
    this->email = email;
    this->user = user;
    this->pwd = pass;
    this->number = number;
    this->phone = phone;
}

// * Cambia principalmente el nombre para ver si funciona, pero deberia cambiar todo
std::string Patient::changeData(std::string newData) {
    std::string oldData = this->name;
    this->name = newData;
    return "Datos cambiados de: " + oldData + " a: " + this->name;
}

// * Los get de la info
std::string Patient::GetName() const { 
    return this->name; 
}

std::string Patient::GetEmail() const { 
    return this->email; 
}

std::string Patient::getUser() const { 
    return this->user; 
}

std::string Patient::getName() const { 
    return this->name; 
}

int Patient::GetNumber() const { 
    return this->number; 
}

void Patient::ShowInfo() const {
    std::cout << "=== Información del Paciente ===" << std::endl;
    std::cout << "Nombre: " << this->name << std::endl;
    std::cout << "ID: " << this->idPatient << std::endl;
    std::cout << "Email: " << this->email << std::endl;
    std::cout << "Usuario: " << this->user << std::endl;
    std::cout << "Número: " << this->number << std::endl;
    std::cout << "Teléfono: " << this->phone << std::endl;
    
    if (this->appointment) {
        std::cout << "Tiene cita programada" << std::endl;
    } else {
        std::cout << "No tiene citas programadas" << std::endl;
    }
}

// * Solicitar la cita
void Patient::RequestAppointment() {
    std::cout << "Paciente " << this->name << " ha solicitado una cita médica." << std::endl;
}

// * Cancelar la cita
void Patient::CancelAppointment() {
    std::cout << "Paciente " << this->name << " ha cancelado su cita médica." << std::endl;
    this->appointment.reset();
}

 // * Confirmar la cita
void Patient::ConfirmAppointment() {
    std::cout << "Paciente " << this->name << " ha confirmado su cita médica." << std::endl;
}

// * Cambiar la cita
void Patient::ChangeAppointment() {
    std::cout << "Paciente " << this->name << " ha solicitado cambiar su cita médica." << std::endl;
}

// * Confirmar la notificacion
bool Patient::ConfirmNotification(bool state) {
    std::cout << "Notificación " << (state ? "confirmada" : "rechazada") 
              << " por el paciente " << this->name << std::endl;
    return state;
}

// ! No se si debria de tener getNotification