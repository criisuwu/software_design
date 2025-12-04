#ifndef PATIENT_H
#define PATIENT_H

#include "User.h"
#include <iostream>
#include <string>

class Patient : public User {
private:
    std::string telephone;

public:
    Patient(int id = 0, const std::string& username = "", const std::string& password = "", 
            const std::string& name = "", const std::string& email = "", const std::string& telephone = "");
    
    std::string getTelephone() const { return telephone; }
    void setTelephone(const std::string& tel) { telephone = tel; }
    
    void showMenu() override;
    void displayInfo() const override;
    
    // Funcionalidades específicas
    void requestAppointment();
    void viewMyAppointments();
    void cancelAppointment();
};

#endif