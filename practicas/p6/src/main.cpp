#include "../import/Robot.h"
#include <vector>
#include <thread> //biblioteca que permite trabajar con hilos de C++
#include <chrono>
#include <iostream>

int main(){
    //Creo 3 robots para las pruebas

    Robot r1(1), r2(2), r3(3);

    //Simulo tareas recurrentes invocando al método dummy para cada robot
    r1.dummy(20); //asigno 4 segudnos
    r2.dummy(2); //2 segs.
    r3.dummy(3); //3segs

    //Esperar a que todos terminen sus actividades
    std::this_thread::sleep_for(std::chrono::seconds(6));

    //Ver los estados finales

    std::cout << "\n--- Estados fianles ---\n ";
    std::cout << "Robot " << r1.getId() << ": " << r1.getEstado() << std::endl;
    std::cout << "Robot " << r2.getId() << ": " << r2.getEstado() << std::endl;
    std::cout << "Robot " << r3.getId() << ": " << r3.getEstado() << std::endl;

    return 0;
}