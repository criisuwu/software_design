#include "imports/Speciality.h"

// * constructor
Speciality::Speciality(const std::string& n) {
    this->name = n;
}

// * Recibe la especialidad
std::string Speciality::GetSpeciality() const {
    return name;
}

// * La imprime por pantalla
void Speciality::ShowSpeciality() const {
    std::cout << "Especialidad: " << name << std::endl;
}
