#include <iostream>
#include <vector>
#include <limits.h> // Для INT_MAX

using namespace std;

int main() {
    int n, m;
    cout << "Введите количество строк (n): ";
    cin >> n;
    cout << "Введите количество столбцов (m): ";
    cin >> m;

    vector<vector<int>> matrix(n, vector<int>(m));

    // Заполняем матрицу случайными числами
    srand(time(0)); // Инициализация генератора случайных чисел
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            matrix[i][j] = rand() % 100; 
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    int max_sum = INT_MIN; 
    int max_col_index = -1; 

    // Находим столбец с максимальной суммой
    for (int j = 0; j < m; ++j) {
        int col_sum = 0;
        for (int i = 0; i < n; ++i) {
            col_sum += matrix[i][j];
        }

        if (col_sum > max_sum) {
            max_sum = col_sum;
            max_col_index = j;
        }
    }

    // Находим минимальный элемент в столбце с максимальной суммой
    int min_in_max_col = INT_MAX;
    for (int i = 0; i < n; ++i) {
        if (matrix[i][max_col_index] < min_in_max_col) {
            min_in_max_col = matrix[i][max_col_index];
        }
    }

    cout << "Столбец с максимальной суммой: " << max_col_index + 1 << endl;
    cout << "Минимальный элемент в этом столбце: " << min_in_max_col << endl;

    return 0;
}
