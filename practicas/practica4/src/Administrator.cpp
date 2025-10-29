#include "Administrator.h"

// * Constructor
Administrator::Administrator(const std::string& id, const std::string& user, const std::string& pass,
                             const std::string& tel, const std::string& email, const std::string& name)
{
    IdAdministrator = id;
    User = user;
    Password = pass;
    Telephone = tel;
    Email = email;
    Name = name;
}

//TODO Cambiar esto?
std::string Administrator::getIdAdministrator() const { return IdAdministrator; }
std::string Administrator::getUser() const { return User; }
std::string Administrator::getName() const { return Name; }

void Administrator::assignSpeciality(const std::string& speciality) {
    std::cout << "Asignando especialidad: " << speciality << " al personal médico..." << std::endl;
}

void Administrator::manageSchedule() {
    std::cout << "El administrador " << Name << " está gestionando el horario general." << std::endl;
}

void Administrator::manageCensus() {
    std::cout << "El administrador " << Name << " está actualizando el censo de pacientes." << std::endl;
}

void Administrator::displayInfo() const {
    std::cout << "ID: " << IdAdministrator << std::endl;
    std::cout << "Usuario: " << User << std::endl;
    std::cout << "Nombre: " << Name << std::endl;
    std::cout << "Teléfono: " << Telephone << std::endl;
    std::cout << "Email: " << Email << std::endl;
}
