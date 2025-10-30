#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include <string>
#include <iostream>

class Administrator {
public:
    // Constructor
    Administrator(const std::string& id, const std::string& user, const std::string& pass,
                  const std::string& tel, const std::string& email, const std::string& name);

    std::string getIdAdministrator() const;
    std::string getUser() const;
    std::string getName() const;
    void assignSpeciality(const std::string& speciality);
    void manageSchedule();
    void manageCensus();
    void displayInfo() const;
    
private:
    std::string IdAdministrator;
    std::string User;           //Esto y la password creo que lo podria sacar anidandolo con login
    std::string Password;
    std::string Telephone;
    std::string Email;
    std::string Name;
};

#endif
