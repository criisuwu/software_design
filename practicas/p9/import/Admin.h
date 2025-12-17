#ifndef ADMIN_H
#define ADMIN_H

#include "User.h"
#include <iostream>
#include <string>

class Admin : public User {
public:
    Admin(int id = 0, const std::string& username = "", const std::string& password = "", 
          const std::string& name = "", const std::string& email = "");
    
    void showMenu() override;
    void displayInfo() const override;
    
    // Funcionalidades específicas del administrador
    void createDoctor();
    void assignSchedule();
    void viewDoctorsList();
    void viewAllUsers();
};

#endif