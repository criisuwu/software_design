/* ------------------------------------------------
File: ejercicio8.cpp
Author: Cristina Homobono Fernández
Date: 17/09/2025
Goal: It will print all the half hours between the
        given hours
---------------------------------------------------*/

#include <chrono>
#include <iostream>
#include <string>


// * Trasnforma la string que recibimos con formarto hh:mm,
// * y devuelve la hora y los minutos
std::chrono::minutes parse_hora(const std::string& s)
{
    int h;
    int m;
    
    h = std::stoi(s.substr(0, 2));
    m = std::stoi(s.substr(3, 2));
    return std::chrono::hours{h} + std::chrono::minutes{m};
}

// * Y esta funcion los devuelve al formato string
std::string to_string_hora(std::chrono::minutes t) {
    auto h = std::chrono::duration_cast<std::chrono::hours>(t).count();
    auto m = (t % std::chrono::hours{1}).count();
    std::string hh = (h < 10 ? "0" : "") + std::to_string(h);
    std::string mm = (m < 10 ? "0" : "") + std::to_string(m);
    return hh + ":" + mm;
}

int main()
{
    std::string horaIni;
    std::string horaFin;
    

    std::cout << "Introduzca la hora de inicio de franja horaria(HH:MM): \n";
    std::cin >> horaIni;

    std::cout << "Introduzca la hora de fin de franja horaria(HH:MM): \n";
    std::cin >> horaFin;

    auto initMins = parse_hora(horaIni);
    auto finMis = parse_hora(horaFin);

    if (initMins >= finMis)
    {
        std::cout << "Error: La hora de inicio debe ser anterior a la hora de fin." << std::endl;
        return 1;
    }

    std::cout << "Slots generados:" << std::endl;
    
    auto current = initMins;
    while (current <= finMis) {
        std::cout << to_string_hora(current) << std::endl;
        current += std::chrono::minutes{30};
    }
    return 0;
}