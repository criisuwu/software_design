#include "imports/Login.h"

// * Constructor
Login::Login(const std::string& user, const std::string& pass) {
    username = user;
    password = pass;
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
    std::cout << "Usuario: " << username << " | Password: " << password << std::endl;
}
