/* ------------------------------------------------
File: ejercicio4.cpp
Author: Cristina Homobono Fernández
Date: 17/09/2025
Goal: Draw a pyramid based on the number given
---------------------------------------------------*/

#include <iostream>

int main()
{
    int height = 0;

    std::cout << "Introduce el numero de pisos que quieras que tenga la piramide: ";
    std::cin >> height;

    for(int i = 0; i < height; i++)
    {
        for(int k = (height - 1); i < k; k--)
            std::cout << " ";
        for(int j = 0; j < (1 + (i * 2)); j++)
            std::cout << "*";
        std::cout << "\n";
    }
        
    return 0;
}