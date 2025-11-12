#ifndef ROBOT_H
#define ROBOT_H

#include <string>
#include <chrono> //para gestionar los tiempos.
#include <mutex> //para gestionar acciones en paralelo


class Robot{

private:
    int id; //identificador del robot
    std::string estado; 
    std::chrono::steady_clock::time_point ultimaActividad;
    std::mutex mtx;

public:
    Robot(int id);
    
    void dummy(int segundos);
    std::string getEstado();
    std::chrono::steady_clock::time_point getUltimaActividad();
    int getId();

};
#endif