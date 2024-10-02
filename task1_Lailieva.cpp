#include <iostream>
#include <cmath>      
#include <iomanip>    

//I. Функция для вычисления выражения ((sinx + cosy)/(cos x - sin y)) * tg(x * y)
void calculateTrigExpression() {
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
        return;
    }

    double result = (numerator / denominator) * tg_xy;

    std::cout << std::fixed << std::setprecision(4); 
    std::cout << "Результат выражения: " << result << std::endl;
}
//II. Написать программу, которая подсчитывает: 7) площадь прямоугольного треугольника по двум катетам а, b;
void calculateTriangleArea() {
    double a, b;
    std::cout << "Введите длину катета a: ";
    std::cin >> a;
    std::cout << "Введите длину катета b: ";
    std::cin >> b;

    double area = 0.5 * a * b; 

    std::cout << std::fixed << std::setprecision(4);
    std::cout << "Площадь треугольника: " << area << std::endl;
}
//III. Написать программу, которая определяет:7) какая из цифр двухзначного числа больше: первая или вторая;
void compareDigits() {
    int number;

    std::cout << "Введите двухзначное число: ";
    std::cin >> number;

    if (number < 10 || number > 99) {
        std::cout << "Ошибка: введите двухзначное число!" << std::endl;
        return;
    }

    int firstDigit = number / 10;   
    int secondDigit = number % 10;  

    if (firstDigit > secondDigit) {
        std::cout << "Первая цифра больше: " << firstDigit << std::endl;
    } else if (firstDigit < secondDigit) {
        std::cout << "Вторая цифра больше: " << secondDigit << std::endl;
    } else {
        std::cout << "Цифры равны: " << firstDigit << " и " << secondDigit << std::endl;
    }
}



int main() {
    calculateTrigExpression();
    
    compareDigits();

    calculateTriangleArea();

    return 0;
}
