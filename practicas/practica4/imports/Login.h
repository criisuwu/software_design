#ifndef LOGIN_H
#define LOGIN_H

#include <iostream>
#include <string>

class Login {
private:
    std::string username;
    std::string password;

public:
    Login(const std::string& user = "", const std::string& pass = ""); //Constructor

    std::string GetUsername() const;
    std::string GetPassword() const;
    void ShowLoginInfo() const;
};

#endif
