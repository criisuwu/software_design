/* ------------------------------------------------
File: ejercicio61.cpp
Author: Cristina Homobono Fernández
Date: 17/09/2025
Goal: Do a fcatorial of a number
---------------------------------------------------*/

#include <iostream>
#include <cmath>

int main()
{
    int num;
    int temp;
    int total = 1;

    std::cout << "Porfavor introduzca un numero entero: ";
    std::cin >> num;
    temp = num;

    if(num == 0)
        std::cout << "El factorial de " << num << " es: 1\n";
    else if (num < 0) 
        std::cout << "Numero no valido\n";
    else
    {
        while(num > 0)
        {
            total *= num;
            num--;
        }
        std::cout << "El factorial de " << temp << " es: " << total << "\n";
    }
    return 0;
}