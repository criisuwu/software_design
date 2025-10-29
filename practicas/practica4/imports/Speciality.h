#ifndef SPECIALITY_H
#define SPECIALITY_H

#include <iostream>
#include <string>

class Speciality {
private:
    std::string name;

public:
    Speciality(const std::string& name = "");   //Constructor

    std::string GetSpeciality() const;
    void ShowSpeciality() const;
};

#endif
