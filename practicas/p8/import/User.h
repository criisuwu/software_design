// User.h
#ifndef USER_H
#define USER_H

#include <string>
#include <iostream>
#include <memory>

class User {
protected:
    int id;
    std::string username;
    std::string password;
    std::string role;
    std::string name;
    std::string email;

public:
    User(int id = 0, const std::string &username = "", const std::string &password = "", 
         const std::string &role = "", const std::string &name = "", const std::string &email = "")
        : id(id), username(username), password(password), role(role), name(name), email(email) {}

    virtual ~User() = default;

    // Getters
    int getId() const { return id; }
    std::string getUsername() const { return username; }
    std::string getPassword() const { return password; }
    std::string getRole() const { return role; }
    std::string getName() const { return name; }
    std::string getEmail() const { return email; }

    // Setters
    void setId(int newId) { id = newId; }
    void setName(const std::string& newName) { name = newName; }
    void setEmail(const std::string& newEmail) { email = newEmail; }

    // Método virtual para mostrar menú
    virtual void showMenu() = 0;

    // Método virtual para mostrar información
    virtual void displayInfo() const {
        std::cout << "ID: " << id << "\n";
        std::cout << "Usuario: " << username << "\n";
        std::cout << "Rol: " << role << "\n";
        std::cout << "Nombre: " << name << "\n";
        std::cout << "Email: " << email << "\n";
    }
};

#endif // USER_H