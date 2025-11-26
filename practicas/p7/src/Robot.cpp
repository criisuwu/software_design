#include "../import/Robot.h"
#include <iostream>
#include <thread>
#include <chrono>

Robot::Robot(int id) : id(id), state("Libre"), active(true), position(0) {
    lastActivity = std::chrono::steady_clock::now();
}

void Robot::assignTask(int seconds, const std::string& taskType) {
    std::thread([this, seconds, taskType]() {
        {
            std::lock_guard<std::mutex> lock(mtx);
            state = "Ocupado";
            currentTask = taskType;
            std::cout << "[Robot " << id << "] Iniciando " << taskType << " por " << seconds << " segundos.\n";
        }

        // Simular la tarea
        std::this_thread::sleep_for(std::chrono::seconds(seconds));
        
        {
            std::lock_guard<std::mutex> lock(mtx);
            state = "Libre";
            currentTask = "";
            lastActivity = std::chrono::steady_clock::now();
            std::cout << "[Robot " << id << "] " << taskType << " completado. Estado: Libre.\n";
        }
    }).detach();
}

std::string Robot::getState() {
    std::lock_guard<std::mutex> lock(mtx);
    return state;
}

std::chrono::steady_clock::time_point Robot::getLastActivity() {
    std::lock_guard<std::mutex> lock(mtx);
    return lastActivity;
}

int Robot::getId() {
    return id;
}

void Robot::guidePatient(const std::string& patientName, const std::string& destination) {
    std::cout << "[Robot " << id << "] Guiando al paciente " << patientName 
              << " hacia " << destination << std::endl;
    assignTask(30, "Guía de paciente");
}

void Robot::notifyAppointment(const std::string& patientName, const std::string& time) {
    std::cout << "[Robot " << id << "] Notificando a " << patientName 
              << " sobre cita a las " << time << std::endl;
    assignTask(10, "Notificación de cita");
}

void Robot::emergencyAssistance() {
    std::cout << "[Robot " << id << "] Activando modo emergencia!" << std::endl;
    assignTask(60, "Asistencia de emergencia");
}

void Robot::displayInfo() const {
    std::cout << "\n=== INFORMACIÓN DEL ROBOT ===\n";
    std::cout << "ID: " << id << std::endl;
    std::cout << "Estado: " << state << std::endl;
    std::cout << "Activo: " << (active ? "Sí" : "No") << std::endl;
    std::cout << "Posición: " << position << std::endl;
    if (!currentTask.empty()) {
        std::cout << "Tarea actual: " << currentTask << std::endl;
    }
}

void Robot::updateState(const std::string& newState) {
    std::lock_guard<std::mutex> lock(mtx);
    state = newState;
}