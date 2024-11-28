import numpy as np
import matplotlib.pyplot as plt

# Чтение данных из файла
results = []
with open('results.txt', 'r') as file:
    results = file.readlines()

# Генерация данных для классов
N = 5
C1_x1 = np.random.random(N)
C1_x2 = C1_x1 + [np.random.randint(10) / 10 for _ in range(N)]
C2_x1 = np.random.random(N)
C2_x2 = C2_x1 - [np.random.randint(10) / 10 for _ in range(N)] - 0.1

# Визуализация
plt.scatter(C1_x1, C1_x2, s=10, c='red', label='Класс C1')
plt.scatter(C2_x1, C2_x2, s=10, c='blue', label='Класс C2')

# Отображение результатов классификации
for i, result in enumerate(results):
    plt.text(C2_x1[i], C2_x2[i], result.strip(), fontsize=9)

plt.title('Результаты классификации')
plt.xlabel('X1')
plt.ylabel('X2')
plt.plot([0, 1])
plt.grid(True)
plt.legend()
plt.show()
