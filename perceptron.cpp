#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>

int main() {
    std::srand(std::time(0)); // Инициализация генератора случайных чисел

    const int N = 5;
    std::vector<double> C1_x1(N);
    std::vector<double> C1_x2(N);
    std::vector<double> C2_x1(N);
    std::vector<double> C2_x2(N);

    // Генерация данных для класса C1
    for (int i = 0; i < N; ++i) {
        C1_x1[i] = static_cast<double>(std::rand()) / RAND_MAX;
        C1_x2[i] = C1_x1[i] + (std::rand() % 10) / 10.0;
    }

    // Генерация данных для класса C2
    for (int i = 0; i < N; ++i) {
        C2_x1[i] = static_cast<double>(std::rand()) / RAND_MAX;
        C2_x2[i] = C2_x1[i] - (std::rand() % 10) / 10.0 - 0.1;
    }

    // Веса
    double w[2] = {-0.3, 0.3};

    // Открываем файл для записи результатов
    std::ofstream outfile("results.txt");
    
    // Классификация и запись результатов в файл
    for (int i = 0; i < N; ++i) {
        double x[2] = {C2_x1[i], C2_x2[i]};
        double y = w[0] * x[0] + w[1] * x[1];
        
        if (y >= 0) {
            outfile << "Класс C1" << std::endl;
        } else {
            outfile << "Класс C2" << std::endl;
        }
    }

    outfile.close();
    return 0;
}
