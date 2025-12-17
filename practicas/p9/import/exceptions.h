#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <stdexcept>
#include <string>

class DatabaseError : public std::runtime_error {
public:
    DatabaseError(const std::string& msg)
        : std::runtime_error("DatabaseError: " + msg) {}
};

class InvalidCredentialsError : public std::runtime_error {
public:
    InvalidCredentialsError(const std::string& msg = "Usuario o contraseña incorrectos.")
        : std::runtime_error("InvalidCredentialsError: " + msg) {}
};

#endif