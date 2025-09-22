/* ------------------------------------------------
File: ejercicio5.cpp
Author: Cristina Homobono Fernández
Date: 17/09/2025
Goal: Generate a random number and it stops when
        the user guess the number
---------------------------------------------------*/

#include <iostream>

int main()
{
    int num;
    int guess;

    srand(time(0));
    num = rand() % 100 + 1;
    while(true)
    {
        std::cout << "Intenta adivinar el numero: ";
        std::cin >> guess;
        if(guess == num)
        {
            std::cout << "Lo adivinaste, el numero era: " << num << "\n";
            break;
        }
        else if(guess >= num)
            std::cout << "El numero a adivinar es mas bajo que " << guess << "\n";
        else if(guess <= num)
            std::cout << "El numero a adivinar es mas alto que " << guess << "\n";
    }
    std::cout << num << "\n";
    return 0;
}
