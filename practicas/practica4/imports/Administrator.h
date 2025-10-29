#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include <string>
#include <iostream>

class Administrator {
private:
    std::string IdAdministrator;
    std::string User;
    std::string Password;
    std::string Telephone;
    std::string Email;
    std::string Name;

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
};

#endif
