#include "../import/Robot.h"
#include <iostream>
#include <thread>
#include <chrono>

// **CODIGO PROPORCIONADO EN EL ENUNCIADO**

//Constructor para inicializar Robot
Robot::Robot(int id) : id(id), state("Libre"){
    ultimaActividad = std::chrono::steady_clock::now();
    active = true;  // estado booleano separado
    position = 0;
    speed = 1.0;
    dimensions = "50x50x100 cm";
}

//Este método simula el acompañamiento del robot durante "x" segundos, definidos en la variable "segundos"
void Robot::dummy(int segundos) {
    //Acá creo un hilo para simular la tarea sin bloquear el hilo principal
    std::thread([this, segundos]() {
        {
            //Acá se protege el acceso al state con mutex
            std::lock_guard<std::mutex> lock(mtx);
            state = "Ocupado";
            std::cout << "[Robot " << id << "] acompañado por " << segundos << "segundos. \n";
        }

        // Esta linea simula el tiempo de acompañamiento del robot al paciente
        std::this_thread::sleep_for(std::chrono::seconds(segundos));
        {
        //Acá protege el acceso al state para cambiar el state
            std::lock_guard<std::mutex> lock(mtx);
            state = "Libre";
            ultimaActividad = std::chrono::steady_clock::now();
            std::cout << "[Robot " << id << "] Finalizó. Estado: Libre. \n";
        }
    }).detach(); //hilo separado, no bloquea.
}

// Devuevle el state del robot pero protege acceso a state con mutex para evitar incoherencias
// en caso de que otro proceso quiera modificar el state.
std::string Robot::getState(){
    std::lock_guard<std::mutex> lock(mtx);
    return state;  
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

//  **MI CODIGO**
// * Movimiento del robot (Los prints son para el main)
void Robot::Move(int newPos) {
    std::cout << "Robot " << id << " moviéndose de posición " << position
              << " a " << newPos << "..." << std::endl;
    position = newPos;
}

// * Informacion del ticket
void Robot::PrintTicket(const std::string& ticketInfo) {
    std::cout << "Imprimiendo ticket: " << ticketInfo << std::endl;
}

// * Miara citas
bool Robot::CheckList(const Appointment& appointment, const Login& userLogin) {
    std::cout << "Revisando las citas: " << std::endl;
    return true;
}

// * Modulo de sonido
void Robot::Talk(const std::string& phrase) {
    std::cout << "Robot dice: " << phrase << std::endl;
}

// * Sensor del siguelineas
bool Robot::ScanSpace() {
    std::cout << "Escaneando el entorno..." << std::endl;
    return true;
}

// * Confimar info
bool Robot::CheckCredential(const std::string& credential) {
    std::cout << "Verificando credencial: " << credential << " -> válida" << std::endl;
    return true;
}

// * Verificar si esta ocupado o libre
bool Robot::ChangeState(bool newState) {
    active = newState;
    std::cout << "El robot ahora está " << (active ? "activo" : "inactivo") << std::endl;
    return active;
}

void Robot::ShowInfo() const {
    std::cout << "\t*Info del robot*\t" << std::endl;
    std::cout << "Robot ID: " << id << std::endl;
    std::cout << "Posición: " << position << std::endl;
    std::cout << "Velocidad: " << speed << std::endl;
    std::cout << "Estado: " << (active ? "Activo" : "Inactivo") << std::endl;
    std::cout << "Dimensiones: " << dimensions << std::endl;
}