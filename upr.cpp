#include <iostream>
#include <cmath>    
#include <iomanip>    

int main() {
    double x, y;
    std::cout << "Введите значение x: ";
    std::cin >> x;
    std::cout << "Введите значение y: ";
    std::cin >> y;

    double numerator = sin(x) + cos(y);
    double denominator = cos(x) - sin(y);
    double tg_xy = tan(x * y);

    if (denominator == 0) {
        std::cout << "Ошибка: деление на ноль!" << std::endl;
        return 1; 
    }

    double result = (numerator / denominator) * tg_xy;

    std::cout << std::fixed << std::setprecision(4); 
    std::cout << "Результат выражения: " << result << std::endl;

    return 0;

    int number;

    std::cout << "Введите двухзначное число: ";
    std::cin >> number;

    if (number < 10 || number > 99) {
        std::cout << "Ошибка: введите двухзначное число!" << std::endl;
        return 1;
    }

    int firstDigit = number / 10;   // Первая цифра (десятки)
    int secondDigit = number % 10;  // Вторая цифра (единицы)

    // Сравниваем цифры и выводим результат
    if (firstDigit > secondDigit) {
        std::cout << "Первая цифра больше: " << firstDigit << std::endl;
    } else if (firstDigit < secondDigit) {
        std::cout << "Вторая цифра больше: " << secondDigit << std::endl;
    } else {
        std::cout << "Цифры равны: " << firstDigit << " и " << secondDigit << std::endl;
    }

    return 0;
}

