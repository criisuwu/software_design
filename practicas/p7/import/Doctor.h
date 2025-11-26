#ifndef DOCTOR_H
#define DOCTOR_H

#include "User.h"
#include <iostream>
#include <string>

class Doctor : public User {
private:
    std::string specialty;

public:
    Doctor(int id = 0, const std::string& username = "", const std::string& password = "", 
           const std::string& name = "", const std::string& email = "", const std::string& specialty = "");
    
    std::string getSpecialty() const { return specialty; }
    void setSpecialty(const std::string& spec) { specialty = spec; }
    
    void showMenu() override;
    void displayInfo() const override;
    
    // Funcionalidades específicas
    void confirmAttendance();
    void modifySchedule();
    void addNotesToAppointment();
    void viewMySchedule();
};

#endif