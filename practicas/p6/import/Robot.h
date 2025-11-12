#ifndef ROBOT_H
#define ROBOT_H

#include <string>
#include <chrono> //para gestionar los tiempos.
#include <mutex> //para gestionar acciones en paralelo
#include <vector>

struct Appointment {
    std::string patientName;
    std::string time;
    std::string destination;
};

struct Login {
    std::string username;
    std::string password;
};

class Robot{
private:
    int id; //identificador del robot
    std::string state; 
    std::chrono::steady_clock::time_point ultimaActividad;
    std::mutex mtx;

    //  **MI CODIGO**
    bool active;
    int position;
    double speed;
    std::string dimensions;

public:
    Robot(int id);
    
    void dummy(int segundos);
    std::string getState();
    std::chrono::steady_clock::time_point getUltimaActividad();
    int getId();

    //  **MI CODIGO**
    void Move(int newPos);
    void PrintTicket(const std::string& ticketInfo);
    bool CheckList(const Appointment& appointment, const Login& userLogin);
    void Talk(const std::string& phrase);
    bool ScanSpace();
    bool CheckCredential(const std::string& credential);
    bool ChangeState(bool newState);
    void ShowInfo() const;

};

#endif