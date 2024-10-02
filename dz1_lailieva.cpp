#include <iostream>
//Задание 7. От полуночи минутная стрелка описала угол K градусов (целочисленное значение). Определить, какое время (ч, мин) показывают часы. 
//Указание: использовать операции целочисленного деления.

int main() {
    int K;  
    std::cout << "Введите угол (в градусах): ";
    std::cin >> K;

    int totalMinutes = K / 6;

    int hours = totalMinutes / 60; 
    int minutes = totalMinutes % 60; 

    hours = hours % 12;

    if (hours == 0) {
        hours = 12;
    }

    std::cout << "Время: " << hours << " часов " << minutes << " минут\n";

    return 0;
}
