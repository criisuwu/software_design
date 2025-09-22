/* ------------------------------------------------
File: ejercicio7.cpp
Author: Cristina Homobono Fernández
Date: 17/09/2025
Goal: It's a rock, paper, scissors simulator
---------------------------------------------------*/

#include <ctime>
#include <iostream>

int main()
{
    char option;
    int num;
    int res;
    int round = 0;
    int compPoint = 0;
    int humPoint = 0;

    while(round < 3)
    {
        std::cout << "Introduzca r(rock), p(paper) o s(scissors)" << "\n";
        std::cin >> option;
        while(option != 'r' && option != 'p' && option != 's')
        {
            std::cout << "Introduzca r(rock), p(paper) o s(scissors)" << "\n";
            std::cin >> option;
        }
        srand(time(0));
        num = rand() % 3 + 1;
        res = (option - num + 3) % 3;
        if (res == 0)
        {
            compPoint += 0;
            humPoint += 0;
        }
        else if (res == 1)
            humPoint++;
        else
            compPoint++;
        round++;
    }
    if (compPoint < humPoint)
        std::cout << "¡El jugador gana!\n";
    else if(compPoint > humPoint)
        std::cout << "¡El ordenador gana!\n";
    else
        std::cout << "¡Es un empate!\n";
    return 0;
}