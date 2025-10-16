# ifndef PATIENT.H
# define PATIENT.H

#include <iostream>
#include <memory>
#include "Appointment.h"

class Patient {
public:
    Patient ();
    std::string changeData(std::string); //Seria un array de cosas (?)
    // ? Faltan metodos todavia
private:
    int number;
    std::string user;
    std::string pwd;
    std::string name;
    std::string email;
    std::string idPatient;
    std::unique_ptr<Appointment> appointment;                           //I relate patient w/ appointment
    std::unique_ptr<int[]> uniqueArray = std::make_unique<int[]>(5);    //I create an array for the multiple appointments a patient can get.
                                                                        // TODO check if it's okay the variable
};

# endif