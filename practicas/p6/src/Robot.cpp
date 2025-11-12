#include "../import/Robot.h"
#include <iostream>
#include <thread>
#include <chrono>

//Constructor para inicializar Robot
Robot::Robot(int id) : id(id), estado("Libre"){
    ultimaActividad = std::chrono::steady_clock::now();
}

//Este método simula el acompañamiento del robot durante "x" segundos, definidos en la variable "segundos"
void Robot::dummy(int segundos) {
    //Acá creo un hilo para simular la tarea sin bloquear el hilo principal
    std::thread([this, segundos]() {
        {
            //Acá se protege el acceso al estado con mutex
            std::lock_guard<std::mutex> lock(mtx);
            estado = "Ocupado";
            std::cout << "[Robot " << id << "] acompañado por " << segundos << "segundos. \n";
        }

        // Esta linea simula el tiempo de acompañamiento del robot al paciente
        std::this_thread::sleep_for(std::chrono::seconds(segundos));
        {
        //Acá protege el acceso al estado para cambiar el estado
            std::lock_guard<std::mutex> lock(mtx);
            estado = "Libre";
            ultimaActividad = std::chrono::steady_clock::now();
            std::cout << "[Robot " << id << "] Finalizó. Estado: Libre. \n";
        }
    }).detach(); //hilo separado, no bloquea.
}

// Devuevle el estado del robot pero protege acceso a estado con mutex para evitar incoherencias
// en caso de que otro proceso quiera modificar el estado.
std::string Robot::getEstado(){
    std::lock_guard<std::mutex> lock(mtx);
    return estado;  
}

//este método retorna el tiempo de la última actividad del robot
//esto permite que si tengo varios robots libres, asignarle un paciente
//al que lleve más tiempo inactivo.
std::chrono::steady_clock::time_point Robot::getUltimaActividad(){
    std::lock_guard<std::mutex> lock(mtx);
    return ultimaActividad;
}

int Robot::getId(){
    return id;
}