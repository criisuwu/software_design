#ifndef SPECIALITY_H
#define SPECIALITY_H

#include <iostream>
#include <string>

class Speciality {
public:
    //Constructor
    Speciality(const std::string& name = "");

    std::string GetSpeciality() const;  //No estoy segura de si deberia de haber un setSpeciality puesto que eso lo hace el Administrator
    void ShowSpeciality() const;
    
private:
    std::string name;
};

#endif
