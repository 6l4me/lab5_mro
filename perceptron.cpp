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

    // Инициализация весов и параметров обучения
    double w[2] = {0.0, 0.0}; // Начальные веса
    double learning_rate = 0.1; // Скорость обучения
    int epochs = 100; // Количество эпох

    // Обучающие данные
    std::vector<std::vector<double>> inputs;
    std::vector<int> labels;
  // подготовка данных для обучения
    for (int i = 0; i < N; ++i) {
        inputs.push_back({C1_x1[i], C1_x2[i]});
        labels.push_back(1); // Метка класса C1

        inputs.push_back({C2_x1[i], C2_x2[i]});
        labels.push_back(-1); // Метка класса C2
    }

    // Процесс обучения
    // цикл по эпохам
    for (int epoch = 0; epoch < epochs; ++epoch) {
      //цикл по данным
        for (size_t i = 0; i < inputs.size(); ++i) {
            double x1 = inputs[i][0];
            double x2 = inputs[i][1];
            int true_label = labels[i];

            // Вычисляем выход перцептрона
            double y = w[0] * x1 + w[1] * x2;
            int predicted_label = (y >= 0) ? 1 : -1;

            // Обновление весов, если предсказание неверное
            if (predicted_label != true_label) {
                w[0] += learning_rate * (true_label - predicted_label) * x1;
                w[1] += learning_rate * (true_label - predicted_label) * x2;
            }
        }
    }

    // Открываем файл для записи результатов
    std::ofstream outfile("results.txt");

    // Классификация и запись результатов в файл
    for (size_t i = 0; i < inputs.size(); ++i) {
        double x1 = inputs[i][0];
        double x2 = inputs[i][1];

        // Вычисляем выход
        double y = w[0] * x1 + w[1] * x2;
        if (y >= 0) {
            outfile << "Класс C1" << std::endl;
        } else {
            outfile << "Класс C2" << std::endl;
        }
    }

    outfile.close();
    return 0;
}
