#ifndef SISTEMA_H
#define SISTEMA_H

#include <sqlite3.h>
#include <memory>
#include <vector>
#include <algorithm>
#include "User.h"
#include "Patient.h"
#include "Doctor.h"
#include "Admin.h"
#include "Robot.h"

class Sistema {
private:
    sqlite3* db;
    std::vector<std::shared_ptr<Robot>> robots;
    static Sistema* instance;
    
public:
    Sistema();
    ~Sistema();
    
    static Sistema& getInstance() {
        if (!instance) instance = new Sistema();
        return *instance;
    }
    
    // Gestión de base de datos
    bool connectDatabase();
    bool registerUser(const std::string& username, const std::string& password, const std::string& role,
                     const std::string& name = "", const std::string& email = "", 
                     const std::string& specialty = "", const std::string& telephone = "");
    std::unique_ptr<User> loginUser(const std::string& username, const std::string& password);
    
    // Gestión de robots
    void initializeRobots(int count);
    void showRobotsStatus() const;
    void assignRobotTask(int robotId, int seconds, const std::string& taskType);
    void assignAnyRobot(int seconds, const std::string& taskType);
    void freeRobot(int robotId);
    
    // Funcionalidades administrativas
    std::vector<std::shared_ptr<User>> getDoctorsList() const;
    std::vector<std::shared_ptr<User>> getAllUsers() const;
    bool assignScheduleToDoctor(int idDoctor, const std::string& day,
                            const std::string& start, const std::string& end);

};

#endif