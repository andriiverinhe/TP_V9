#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// Задания для самостоятельного выполнения Переписать код своего варианта
// лабораторной работы No7 под использование динамической области памяти для
// хранения массивов.
// Требования и ограничения
// Для нечётных вариантов используйте I

void fillSquareMatrix(int *matrix, int size) {
  // Инициализация генератора случайных чисел
  srand(time(NULL));

  // Заполнение каждого элемента массива случайными числами
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      matrix[i * size + j] = rand() % 100; // случайные числа от 0 до 99
    }
  }
}

void printSquareMatrix(int *matrix, int size) {
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      printf("%4d ", matrix[i * size + j]);
    }
    printf("\n");
  }
}

// Функция для вычисления суммы элементов верхнего треугольника матрицы
int upperTriangleSum(int *matrix, int size) {
  int sum = 0;
  for (int i = 0; i < size; i++) {
    for (int j = i; j < size; j++) {
      sum += matrix[i * size + j];
    }
  }
  return sum;
}

// Функция для вычисления суммы элементов нижнего треугольника матрицы
int lowerTriangleSum(int *matrix, int size) {
  int sum = 0;
  for (int i = 0; i < size; i++) {
    for (int j = 0; j <= i; j++) {
      sum += matrix[i * size + j];
    }
  }
  return sum;
}

void makeSymmetricMatrixToUpperLower(int *matrix, int size) {
  // Копируем значения из верхнего треугольника в нижний
  for (int i = 0; i < size; i++) {
    for (int j = i + 1; j < size; j++) {
      matrix[j * size + i] = matrix[i * size + j];
    }
  }
}

void makeSymmetricMatrixLowerToUpper(int *matrix, int size) {
  // Копируем значения из нижнего треугольника в верхний
  for (int i = 0; i < size; i++) {
    for (int j = i + 1; j < size; j++) {
      matrix[i * size + j] = matrix[j * size + i];
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
  int *matrix = (int *)malloc(size * size * sizeof(int));
  if (!matrix) {
    fprintf(stderr, "Ошибка выделения памяти для матрицы\n");
    return 1;
  }
  fillSquareMatrix(matrix, size);
  printSquareMatrix(matrix, size);
  int upSum = upperTriangleSum(matrix, size);
  int loSum = lowerTriangleSum(matrix, size);
  printf("Сумма элементов верхнего треугольника: %d\n", upSum);
  printf("Сумма элементов нижнего треугольника: %d\n", loSum);

  if (upSum < loSum) {
    printf("Копируем значения из верхнего треугольника в нижний!\n");
    makeSymmetricMatrixToUpperLower(matrix, size);
  } else if (loSum < upSum) {
    printf("Копируем значения из нижнего треугольника в верхний!\n");
    makeSymmetricMatrixLowerToUpper(matrix, size);
  } else
    printf("Cуммы триугольников равны\n");

  printSquareMatrix(matrix, size);

  // Освобождаем память, выделенную для матрицы
  free(matrix);

  return 0;
}
