//relacion con agenda
# ifndef DOCTOR.H
# define DOCTOR.H

#include <iostream>
#include <memory>
#include "imports/Appointment.h"
#include "imports/Speciality.h"

class Doctor {
public:
    Doctor (const std::string& name = "",
           const std::string& idDoctor = "",
           const std::string& email = "",
           const std::string& user,
           const std::string& pass,
           int number = 0,
           std::unique_ptr<Speciality> speciality = nullptr);
    std::string changeData(std::string);
    std::string GetName() const;
    std::string GetEmail() const;
    std::string getUser() const;
    std::string getPasword() const;
    int GetNumber() const;
    void ShowInfo() const;
    void ConfirmAppointment();
    void CancelAppointment();
    void DiagnosePatient(const std::string& patientName);
    
private:
    int number;
    std::string name;
    std::string email;
    std::string password;
    std::string username;
    std::string idDoctor;
    std::unique_ptr<Appointment> appointment;                           //I relate patient w/ appointment
    std::unique_ptr<int[]> uniqueArray = std::make_unique<int[]>(5);    //I create an array for the multipl
    std::unique_ptr<Speciality> speciality;
};

# endif