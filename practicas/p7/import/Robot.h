#ifndef ROBOT_H
#define ROBOT_H

#include <string>
#include <chrono>
#include <mutex>
#include <thread>
#include <iostream>

class Robot {
private:
    int id;
    std::string state;
    std::chrono::steady_clock::time_point lastActivity;
    std::mutex mtx;
    bool active;
    int position;
    std::string currentTask;

public:
    Robot(int id);
    
    // Métodos del sistema de robots
    void assignTask(int seconds, const std::string& taskType = "Acompañamiento");
    std::string getState();
    std::chrono::steady_clock::time_point getLastActivity();
    int getId();
    bool isActive() const { return active; }
    
    // Métodos para el sistema de citas
    void guidePatient(const std::string& patientName, const std::string& destination);
    void notifyAppointment(const std::string& patientName, const std::string& time);
    void emergencyAssistance();
    
    // Mostrar información
    void displayInfo() const;

private:
    void updateState(const std::string& newState);
};

#endif