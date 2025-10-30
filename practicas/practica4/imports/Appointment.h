#ifndef APPOINTMENT_H
#define APPOINTMENT_H

#include <string>
#include <iostream>

class Appointment {
public:
    // Constructor
    Appointment(const std::string& date, const std::string& place, const std::string& info);

    std::string getDate() const;
    std::string getPlace() const;
    std::string getInfo() const;
    void setDate(const std::string& date);
    void setPlace(const std::string& place);
    void addInfo(const std::string& info);
    void moveAppointment(const std::string& newDate);
    void cancelAppointment();
    void seeAppointment() const;    //No estoy segura de si esto deberia de estar en paciente y doctor o aqui
    void confirmAppointment();
    void changeStatusAppointment();
    void displayAppointment() const;
    
private:
    std::string Date;
    std::string Place;
    std::string Info;
};

#endif
