#include "../imports/Administrator.h"

// * Constructor
Administrator::Administrator(const std::string& id, const std::string& user, const std::string& pass,
                             const std::string& tel, const std::string& email, const std::string& name)
{
    this->IdAdministrator = id;
    this->User = user;
    this->Password = pass;
    this->Telephone = tel;
    this->Email = email;
    this->Name = name;
}

// * Gets de la informacion
std::string Administrator::getIdAdministrator() const { return IdAdministrator; }
std::string Administrator::getUser() const {
    return User;
}
std::string Administrator::getName() const {
    return Name;
}


// * Asignar la especialidad (Solo a los doctores)
void Administrator::assignSpeciality(const std::string& speciality) {
    std::cout << "Asignando especialidad: " << speciality << " al personal médico..." << std::endl;
}

// * Mirar el schedule
void Administrator::manageSchedule() {
    std::cout << "El administrador " << Name << " está gestionando el horario general." << std::endl;
}

// * Gestionar el numero de doctores
void Administrator::manageCensus() {
    std::cout << "El administrador " << Name << " está actualizando el censo de pacientes." << std::endl;
}

void Administrator::displayInfo() const {
    std::cout << "\t*Info del administrador*\t" << std::endl;
    std::cout << "ID: " << IdAdministrator << std::endl;
    std::cout << "Usuario: " << User << std::endl;
    std::cout << "Nombre: " << Name << std::endl;
    std::cout << "Teléfono: " << Telephone << std::endl;
    std::cout << "Email: " << Email << std::endl;
}
