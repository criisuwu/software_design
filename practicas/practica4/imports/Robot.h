#ifndef ROBOT_H
#define ROBOT_H

#include <iostream>
#include <string>
#include "Appointment.h"
#include "Login.h"

class Robot {
public:
    // Constructor
    Robot(const std::string& idRobot = "", int position = 0, double speed = 0.0, bool state = false, int dimensions = 0);

    void Move(int newPos);
    void PrintTicket(const std::string& ticketInfo);
    bool CheckList(const Appointment& appointment, const Login& userLogin);
    void Talk(const std::string& phrase);
    bool ScanSpace();
    bool CheckCredential(const std::string& credential);
    bool ChangeState(bool newState);
    void ShowInfo() const;
    
private:
    std::string idRobot;
    int position;
    double speed;
    bool state;
    int dimensions;
};

#endif
