#include "../imports/Doctor.h"

// * Constructor
Doctor::Doctor(const std::string& name, const std::string& idDoctor, 
               const std::string& email, const std::string& user, 
               const std::string& pass, int number, 
               std::unique_ptr<Speciality> speciality) {
    this->name = name;
    this->idDoctor = idDoctor;
    this->email = email;
    this->username = user;
    this->password = pass;
    this->number = number;
    this->speciality = std::move(speciality);
}

// Cambiar datos básicos
std::string Doctor::changeData(std::string newEmail) {
    email = newEmail;
    return email;
}

// Getters
std::string Doctor::GetName() const { return name; }
std::string Doctor::GetEmail() const { return email; }
int Doctor::GetNumber() const { return number; }

// Mostrar información
void Doctor::ShowInfo() const {
    std::cout << "Doctor: " << name << std::endl;
    std::cout << "ID: " << idDoctor << std::endl;
    std::cout << "Email: " << email << std::endl;
    std::cout << "Número: " << number << std::endl;
}

// Métodos placeholder (para ampliar después)
void Doctor::ConfirmAppointment() {
    std::cout << "Confirmando cita..." << std::endl;
}

void Doctor::CancelAppointment() {
    std::cout << "Cancelando cita..." << std::endl;
}

void Doctor::DiagnosePatient(const std::string& patientName) {
    std::cout << "Diagnosticando al paciente: " << patientName << std::endl;
}
