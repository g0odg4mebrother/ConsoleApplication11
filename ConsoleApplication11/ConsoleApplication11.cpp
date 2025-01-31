#include <iostream>
#include <string>

using namespace std;

// Структура для представления комплексных чисел
struct Complex {
    double real = 0;
    double imag = 0;

    // Оператор сложения
    Complex operator+(const Complex& other) const {
        return { real + other.real, imag + other.imag };
    }

    // Оператор вычитания
    Complex operator-(const Complex& other) const {
        return { real - other.real, imag - other.imag };
    }

    // Оператор умножения
    Complex operator*(const Complex& other) const {
        return { real * other.real - imag * other.imag,
               real * other.imag + imag * other.real };
    }

    // Оператор деления
    Complex operator/(const Complex& other) const {
        double denominator = other.real * other.real + other.imag * other.imag;
        if (denominator == 0) {
            throw runtime_error("Деление на ноль");
        }
        return { (real * other.real + imag * other.imag) / denominator,
               (imag * other.real - real * other.imag) / denominator };
    }

    // Печать комплексного числа
    friend ostream& operator<<(ostream& os, const Complex& c) {
        os << c.real << (c.imag >= 0 ? "+" : "") << c.imag << "i";
        return os;
    }
};

// Структура для описания автомобиля
struct Car {
    double length;
    double clearance;
    double engineVolume;
    double enginePower;
    double wheelDiameter;
    string color;
    string transmissionType;

    // Функция для задания значений автомобиля
    void setValues(double len, double cle, double vol, double pow, double diam, const string& col, const string& transType) {
        length = len;
        clearance = cle;
        engineVolume = vol;
        enginePower = pow;
        wheelDiameter = diam;
        color = col;
        transmissionType = transType;
    }

    // Функция для отображения значений автомобиля
    void displayValues() const {
        cout << "Длина: " << length << " м" << endl;
        cout << "Клиренс: " << clearance << " см" << endl;
        cout << "Объем двигателя: " << engineVolume << " л" << endl;
        cout << "Мощность двигателя: " << enginePower << " л.с." << endl;
        cout << "Диаметр колес: " << wheelDiameter << " дюймов" << endl;
        cout << "Цвет: " << color << endl;
        cout << "Тип коробки передач: " << transmissionType << endl;
    }
};

// Функция для поиска автомобилей по цвету
void findCarsByColor(Car cars[], int size, const string& color) {
    cout << "Автомобили цвета \"" << color << "\":" << endl;
    bool found = false;
    for (int i = 0; i < size; i++) {
        if (cars[i].color == color) {
            cars[i].displayValues();
            found = true;
            cout << "--------------------------" << endl;
        }
    }
    if (!found) {
        cout << "Автомобили не найдены." << endl;
    }
}

int main() {
    setlocale(LC_ALL, "");

    // Задание 1: Работа с комплексными числами
    Complex c1{ 1, 2 };
    Complex c2{ 3, 4 };

    cout << "c1: " << c1 << endl;
    cout << "c2: " << c2 << endl;
    cout << "Сумма: " << (c1 + c2) << endl;
    cout << "Разность: " << (c1 - c2) << endl;
    cout << "Произведение: " << (c1 * c2) << endl;

    try {
        cout << "Частное: " << (c1 / c2) << endl;
    }
    catch (const exception& e) {
        cerr << e.what() << endl;
    }

    // Задание 2: Работа со структурой Car
    const int Num_Car = 3;
    Car cars[Num_Car];

    cars[0].setValues(4.5, 15, 2.0, 150, 16, "Красный", "Автомат");
    cars[1].setValues(4.2, 12, 1.8, 120, 15, "Синий", "Механика");
    cars[2].setValues(4.8, 18, 2.5, 200, 17, "Красный", "Автомат");

    for (int i = 0; i < Num_Car; i++) {
        cars[i].displayValues();
        cout << "--------------------------" << endl;
    }

    string searchColor;
    cout << "Введите цвет для поиска: ";
    getline(cin, searchColor);
    findCarsByColor(cars, Num_Car, searchColor);

    return 0;
}