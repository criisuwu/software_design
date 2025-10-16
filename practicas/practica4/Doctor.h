//relacion con agenda
# ifndef DOCTOR.H
# define DOCTOR.H

#include <iostream>
#include <memory>
#include "Appointment.h"

class Doctor {
public:
    Doctor ();
    std::string changeData(std::string);
    
private:
    int number;
    std::string user;
    std::string pwd;
    std::string name;
    std::string email;
    std::string idPatient;
    std::string speciality;
    std::unique_ptr<Appointment> appointment;                           //I relate patient w/ appointment
    std::unique_ptr<int[]> uniqueArray = std::make_unique<int[]>(5);    //I create an array for the multipl
};

# endif