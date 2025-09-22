/* ------------------------------------------------
File: ejercicio1.cpp
Author: Cristina Homobono Fernández
Date: 17/09/2025
Goal: Do a program that make the simple operations
---------------------------------------------------*/

#include <iostream>

int main()
{
    float num1 = 0;
    float num2 = 0;
    float total = 0;
    int numInt1;
    int numInt2;

    std::cout << "Porfavor introduzca el primer numero: ";
    std::cin >> num1;
    std::cout << "Porfavor introduzca el segundo numero: ";
    std::cin >> num2;

    total = num1 + num2;
    std::cout << "La suma de " << num1 << " y " << num2 << " es: " << total << "\n";
    total = num1 - num2;
    std::cout << "La resta de " << num1 << " y " << num2 << " es: " << total << "\n";
    total = num1 * num2;
    std::cout << "La multiplicacion de " << num1 << " y " << num2 << " es: " << total << "\n";
    total = num1 / num2;
    std::cout << "La division de " << num1 << " y " << num2 << " es: " << total << "\n";
    numInt1 = static_cast<int>(num1);       //Esto es un casteo de un float a un int
    numInt2 = static_cast<int>(num2);
    total = numInt1 % numInt2;
    total = numInt1 % numInt2;
    std::cout << "El modulo de " << num1 << " y " << num2 << " es: " << total << "\n";

    return 0;
}