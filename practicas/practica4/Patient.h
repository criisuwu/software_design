#include <iostream>

class Patient {
public:
    Patient ();
    std::string changeData(std::string);
    
private:
    int number;
    std::string user;
    std::string pwd;
    std::string name;
    std::string email;
    std::string idPatient;
};

//puntero a array con citas
//y va tambien relacionado a citas