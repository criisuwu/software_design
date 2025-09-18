/* ------------------------------------------------
File: main.cpp
Author: Cristina Homobono Fernández
Date: 17/09/2025
Goal: Do a fcatorial of a number, get the precision
        at solving the constant of number e and get
        the precision at solving e^x
---------------------------------------------------*/

#include <iostream>
#include <cmath>

// ? Para el punto uno
int doFactorial(int num)
{
    // int num;
    // int temp;
    int total = 1;

    // std::cout << "Porfavor introduzca un numero entero: ";
    // std::cin >> num;
    // temp = num;

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
        // std::cout << "El factorial de " << temp << " es: " << total << "\n";
    }
    return total;
}

// ? Para el punto dos, y hago uso de la funcion 1
void getConstant()
{
    float num;
    float total = 1;
    float temp;
    float fact;

    std::cout << "Introduzca cuantos terminos quiere que tenga la suma para calcular e: ";
    std::cin >> num;
    temp = num;

    while(num > 0)
    {
        fact = doFactorial(num);
        total += 1 / fact;
        printf("%f\n", total);
        num--;
    }
    std::cout << "El valor de e con precision " << temp << " es: " << total << "\n";
}

// ? Para el punto tres

// ! Esta es una funcion para hacer el factorial con el exponente
int factorialExp(int num) //con esta funcion solo queda sumarle el uno del inicio de la sucesion y ya estaria
{
    // int num;
    int i;
    int total = 1;

    // std::cout << "Porfavor introduzca un numero entero: ";
    // std::cin >> num;
    i = 1;

    while(num > 0)
    {
        total = pow(total, i) / num;
        num--;
        i++;
    }
    return total;
}
// * Duda, preguntar si x es igual al numero de terminos en la suma o cada uno es independiente
void getValue()
{
    float num;
    float total = 1;
    float temp;
    float fact;

    std::cout << "Introduzca cuantos terminos quiere que tenga la suma para calcular e: ";
    std::cin >> num;
    temp = num;

    while(num > 0)
    {
        fact = factorialExp(num);
        total += 1 / fact;
        printf("%f\n", total);
        num--;
    }
    std::cout << "El valor de e con precision " << temp << " es: " << total << "\n";
}

int main()
{
    //doFactorial();
    getConstant();
    return 0;
}