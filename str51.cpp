#include <iostream>

// Функция, которая возвращает вторую справа цифру натурального числа
int f(int x) {
    if (x < 10) {
        std::cout << "Число " << x << " меньше двух цифр!\n";
        return 0; 
    }
    return (x / 10) % 10;
}

int main() {
    int a, b, c;

    std::cout << "Введите число a: ";
    std::cin >> a;
    std::cout << "Введите число b: ";
    std::cin >> b;
    std::cout << "Введите число c: ";
    std::cin >> c;

    int z = f(a) + f(b) - f(c);

    std::cout << "Результат z = f(a) + f(b) - f(c): " << z << std::endl;

    return 0;
}
