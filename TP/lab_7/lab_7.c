#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Требования и ограничения Размеры массива вводить с клавиатуры,
// массив заполнить случайными числами.
// Необходимые расчёты и модификации реализовать в виде функций.

// Преобразовать матрицу в симметричную, отразив тот треугольник матрицы, сумма
// элементов которого меньше.

void fillSquareMatrix(int **matrix, int size) {
  // Инициализация генератора случайных чисел
  srand(time(NULL));

  // Заполнение каждого элемента массива случайными числами
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      matrix[i][j] = rand() % 100; // случайные числа от 0 до 99
    }
  }
}

void printSquareMatrix(int **matrix, int size) {
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      printf("%4d ", matrix[i][j]);
    }
    printf("\n");
  }
}

// Функция для вычисления суммы элементов верхнего треугольника матрицы
int upperTriangleSum(int **matrix, int size) {
  int sum = 0;
  for (int i = 0; i < size; i++) {
    for (int j = i; j < size; j++) {
      sum += matrix[i][j];
    }
  }
  return sum;
}

// Функция для вычисления суммы элементов нижнего треугольника матрицы
int lowerTriangleSum(int **matrix, int size) {
  int sum = 0;
  for (int i = 0; i < size; i++) {
    for (int j = 0; j <= i; j++) {
      sum += matrix[i][j];
    }
  }
  return sum;
}

void makeSymmetricMatrixToUpperLower(int **matrix, int size) {
  // Копируем значения из верхнего треугольника в нижний
  for (int i = 0; i < size; i++) {
    for (int j = i + 1; j < size; j++) {
      matrix[j][i] = matrix[i][j];
    }
  }
}
void makeSymmetricMatrixLowerToUpper(int **matrix, int size) {
  // Копируем значения из нижнего треугольника в верхний
  for (int i = 0; i < size; i++) {
    for (int j = i + 1; j < size; j++) {
      matrix[i][j] = matrix[j][i];
    }
  }
}

int main() {
  int size = 0;
  printf("Введите размер квадратной матрицы: ");
  scanf("%d", &size);
  if (size < 1) {
    fprintf(stderr, "Не верный размер матрицы\n");
    return 1;
  }
  int **matrix = (int **)malloc(size * sizeof(int *));
  if (matrix == NULL) {
    fprintf(stderr, "Ошибка выделения памяти для массива указателей\n");
    return 1;
  }

  for (int i = 0; i < size; i++) {
    matrix[i] = (int *)malloc(size * sizeof(int));
    // Проверка успешности выделения памяти для строки
    if (matrix[i] == NULL) {
      fprintf(stderr, "Ошибка выделения памяти для строки %d\n", i);
      return 1;
    }
  }
  fillSquareMatrix(matrix, size);  // Заполнение массива
  printSquareMatrix(matrix, size); // вывод массива
  int upSum = upperTriangleSum(matrix, size); // Cумма верхнего триугольника
  int loSum = lowerTriangleSum(matrix, size); // Cумма нижнего триугольника
  printf("Cумма верхнего триугольника: %d\n", upSum);
  printf("Cумма нижнего триугольника: %d\n", loSum);

  if (upSum < loSum) {
    printf("Копируем значения из верхнего треугольника в нижний!\n");
    makeSymmetricMatrixToUpperLower(matrix, size);
  } else if (loSum < upSum) {
    printf("Копируем значения из нижнего треугольника в верхний!\n");
    makeSymmetricMatrixLowerToUpper(matrix, size);
  } else
    printf("Cуммы триугольников равны\n");

  printSquareMatrix(matrix, size);

  for (int i = 0; i < size; i++) {
    free(matrix[i]);
  }
  free(matrix);
  return 0;
}