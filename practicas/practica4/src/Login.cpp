#include "imports/Login.h"

// * Constructor
Login::Login(const std::string& user, const std::string& pass) {
    this->username = user;
    this->password = pass;
}

// * Recibe el usuario
std::string Login::GetUsername() const {
    return username;
}

// * Recibe la contraseña
std::string Login::GetPassword() const {
    return password;
}

// * Devuelve el inicio de sesion (Para probar el main)
void Login::ShowLoginInfo() const {
    std::cout << "\t*Info de login*\t" << std::endl;
    std::cout << "Usuario: " << username << std::endl;
    std::cout << "Password: " << password << std::endl;
}
