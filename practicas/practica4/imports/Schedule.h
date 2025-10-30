#ifndef SCHEDULE_H
#define SCHEDULE_H

#include <string>
#include <iostream>

class Schedule {
private:
    int Hour;
    std::string Appointment; //Lo pongo asi porque no estoy segura de si tiene que ir anidado con mi clase appointment
public:
    // Constructor
    Schedule(int hour, const std::string& appointment);

    int getHour() const;
    std::string getAppointment() const;
    void setHour(int hour);
    void setAppointment(const std::string& appointment);
    void displaySchedule() const;   //Lo pongo tambien aqui porque todavia no estoy segura de si va aqui o en Patient
    void showInfo() const;
};

#endif
