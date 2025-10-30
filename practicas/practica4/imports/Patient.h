# ifndef PATIENT.H
# define PATIENT.H

#include <iostream>
#include <memory>
#include "imports/Appointment.h"
#include "imports/Login.h"

class Patient {
public:
    Patient (const std::string& name = "",
            const std::string& idPatient = "",
            const std::string& email = "",
            const std::string& user,
            const std::string& pass,
            int number = 0,
            int phone = 0);
    std::string changeData(std::string);
    std::string GetName() const;
    std::string GetEmail() const;
    std::string getUser() const;
    std::string getName() const;
    int GetNumber() const;
    void ShowInfo() const;
    void RequestAppointment();
    void CancelAppointment();   //No estoy segura de si aqui deberia de tener el metodo de checkDisponibility
    void ConfirmAppointment();
    void ChangeAppointment();
    bool ConfirmNotification(bool state);   //No estoy segura si esto es de patient o de Notification

private:
    int number;
    int phone;
    std::string user;
    std::string pwd;
    std::string name;
    std::string email;
    std::string idPatient;
    std::unique_ptr<Appointment> appointment;                           //I relate patient w/ appointment
    std::unique_ptr<int[]> uniqueArray = std::make_unique<int[]>(5);    //I create an array for the multiple appointments a patient can get.
};

# endif