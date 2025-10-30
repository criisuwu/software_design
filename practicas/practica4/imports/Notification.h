#ifndef NOTIFICATION_H
#define NOTIFICATION_H

#include <string>
#include <iostream>

class Notification {
public:
    // Constructor
    Notification(const std::string& info, bool state = false);

    std::string getInfoAppointment() const;
    bool getState() const;
    void setState(bool state);
    void sendNotification();
    bool changeState(bool newState);
    void displayNotification() const;

private:
    std::string InfoAppointment;
    bool State;
};

#endif
