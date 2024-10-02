#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>   // Для работы с файлами

using namespace std;

// Структура для хранения информации о поездах
struct TRAIN {
    string destination;     // Название пункта назначения
    int trainNumber;        // Номер поезда
    string departureTime;   // Время отправления (в формате ЧЧ:ММ)
    int platformNumber;     // Номер платформы
    bool highSpeed;         // Высокоскоростной поезд или нет

    // Функция для вывода информации о поезде
    void print() const {
        cout << "Поезд №" << trainNumber << " до " << destination 
             << " отправляется в " << departureTime
             << " с платформы №" << platformNumber
             << (highSpeed ? " (Высокоскоростной)" : "") << endl;
    }
};

// Функция для сравнения поездов по названию пункта назначения
bool compareByDestination(const TRAIN& a, const TRAIN& b) {
    return a.destination < b.destination;
}

// Функция для сравнения поездов по номерам платформ
bool compareByPlatform(const TRAIN& a, const TRAIN& b) {
    return a.platformNumber < b.platformNumber;
}

// Функция для преобразования времени из строки в минуты
int timeToMinutes(const string& time) {
    int hours = stoi(time.substr(0, 2));
    int minutes = stoi(time.substr(3, 2));
    return hours * 60 + minutes;
}

// Функция для поиска поездов, отправляющихся после введенного времени
void searchTrainsByTime(const vector<TRAIN>& trains) {
    string inputTime;
    cout << "Введите время (ЧЧ:ММ) для поиска поездов, отправляющихся после этого времени: ";
    cin >> inputTime;
    int inputMinutes = timeToMinutes(inputTime);

    bool found = false;
    cout << "\nПоезда, отправляющиеся после " << inputTime << ":\n";

    for (const auto& train : trains) {
        if (timeToMinutes(train.departureTime) > inputMinutes) {
            train.print();
            found = true;
        }
    }

    if (!found) {
        cout << "Нет поездов, отправляющихся после указанного времени.\n";
    }
}

// Функция для вывода всех поездов
void displayAllTrains(const vector<TRAIN>& trains) {
    cout << "\nСписок всех поездов:\n";
    for (const auto& train : trains) {
        train.print();
    }
}

// Функция для вывода поездов, отсортированных по номерам платформ
void displayTrainsByPlatform(vector<TRAIN>& trains) {
    sort(trains.begin(), trains.end(), compareByPlatform);
    cout << "\nСписок поездов, отсортированных по номерам платформ:\n";
    for (const auto& train : trains) {
        train.print();
    }
}

// Функция для поиска поездов по пункту назначения
void searchTrainsByDestination(const vector<TRAIN>& trains) {
    string inputDestination;
    cout << "Введите пункт назначения для поиска поездов: ";
    cin >> inputDestination;

    bool found = false;
    cout << "\nПоезда до пункта назначения " << inputDestination << ":\n";

    for (const auto& train : trains) {
        if (train.destination == inputDestination) {
            train.print();
            found = true;
        }
    }

    if (!found) {
        cout << "Нет поездов, следующих до указанного пункта назначения.\n";
    }
}

// Функция для загрузки данных из файла
vector<TRAIN> loadTrainsFromFile(const string& filename) {
    ifstream file(filename);
    vector<TRAIN> trains;
    
    if (!file.is_open()) {
        cerr << "Не удалось открыть файл: " << filename << endl;
        return trains;
    }

    TRAIN temp;
    while (file >> temp.destination >> temp.trainNumber >> temp.departureTime >> temp.platformNumber >> temp.highSpeed) {
        trains.push_back(temp);
    }

    file.close();
    return trains;
}

// Функция для сохранения данных о поездах в файл
void saveTrainsToFile(const string& filename, const vector<TRAIN>& trains) {
    ofstream file(filename);
    if (!file.is_open()) {
        cerr << "Не удалось открыть файл для записи: " << filename << endl;
        return;
    }

    for (const auto& train : trains) {
        file << train.destination << " "
             << train.trainNumber << " "
             << train.departureTime << " "
             << train.platformNumber << " "
             << train.highSpeed << endl;
    }

    file.close();
}

// Функция для изменения данных о поезде
void modifyTrainData(vector<TRAIN>& trains) {
    int trainNumber;
    cout << "Введите номер поезда для изменения данных: ";
    cin >> trainNumber;

    for (auto& train : trains) {
        if (train.trainNumber == trainNumber) {
            cout << "Введите новый пункт назначения: ";
            cin >> train.destination;
            cout << "Введите новое время отправления (ЧЧ:ММ): ";
            cin >> train.departureTime;
            cout << "Введите новый номер платформы: ";
            cin >> train.platformNumber;
            cout << "Высокоскоростной поезд (1 - да, 0 - нет): ";
            cin >> train.highSpeed;

            // Сохранение обновленных данных в файл
            saveTrainsToFile("trains.txt", trains);

            cout << "Данные о поезде обновлены.\n";
            return;
        }
    }

    cout << "Поезд с номером " << trainNumber << " не найден.\n";
}

// Функция для добавления нового поезда
void addTrain(vector<TRAIN>& trains) {
    TRAIN newTrain;
    cout << "Введите пункт назначения: ";
    cin >> newTrain.destination;
    cout << "Введите номер поезда: ";
    cin >> newTrain.trainNumber;
    cout << "Введите время отправления (ЧЧ:ММ): ";
    cin >> newTrain.departureTime;
    cout << "Введите номер платформы: ";
    cin >> newTrain.platformNumber;
    cout << "Высокоскоростной поезд (1 - да, 0 - нет): ";
    cin >> newTrain.highSpeed;

    trains.push_back(newTrain);
    
    // Сохранение обновленных данных в файл
    saveTrainsToFile("trains.txt", trains);

    cout << "Новый поезд добавлен.\n";
}

int main() {
    // Загрузка данных из файла
    vector<TRAIN> trains = loadTrainsFromFile("trains.txt");

    if (trains.empty()) {
        cout << "Данные о поездах отсутствуют или не загружены.\n";
        return 1;
    }

    // Сортировка поездов по названию пункта назначения
    sort(trains.begin(), trains.end(), compareByDestination);

    int choice;
    do {
        // Меню
        cout << "\nМеню:\n";
        cout << "1. Вывести все поезда\n";
        cout << "2. Поиск поездов по времени\n";
        cout << "3. Вывести поезда, отсортированные по номерам платформ\n";
        cout << "4. Поиск поездов по пункту назначения\n";
        cout << "5. Изменить данные о поезде\n";
        cout << "6. Добавить новый поезд\n";
        cout << "7. Выход\n";
        cout << "Выберите действие: ";
        cin >> choice;

        switch (choice) {
            case 1:
                displayAllTrains(trains);
                break;
            case 2:
                searchTrainsByTime(trains);
                break;
            case 3:
                displayTrainsByPlatform(trains);
                break;
            case 4:
                searchTrainsByDestination(trains);
                break;
            case 5:
                modifyTrainData(trains);
                break;
            case 6:
                addTrain(trains);
                break;
            case 7:
                cout << "Выход из программы.\n";
                break;
            default:
                cout << "Неверный выбор. Попробуйте снова.\n";
                break;
        }

    } while (choice != 7);

    return 0;
}
