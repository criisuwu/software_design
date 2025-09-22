/* ------------------------------------------------
File: ejercicio2.cpp
Author: Cristina Homobono Fernández
Date: 17/09/2025
Goal: Get the average mark of the given numbers
---------------------------------------------------*/

#include <iostream>

int main()
{
    float avgMark = 0;
    float mark = 0;

    for(int i = 0; i < 5; i++)
    {
        std::cout << "Introduce una nota: ";
        std::cin >> mark;
        avgMark += mark;
    }
    avgMark = avgMark / 5;
    std::cout << "Tu media es de: " << avgMark << "\n";
    
    return 0;
}