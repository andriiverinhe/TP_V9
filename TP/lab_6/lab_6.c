#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Количество элементов массива вводить с клавиатуры,
// массив заполнить случайными
// числами.Необходимые расчёты и модификации реализовать в виде функций.

int checkValue(int arr[0], int i, int value) {
  int check = 0;
  for (int j = 0; j <= i && !check; j++) {
    if (value == arr[j])
      check = 1;
  }
  return check;
}

// Функция для заполнения массива случайными числами
void fillArray(int arr[], int size) {
  srand(time(NULL)); // Инициализация генератора случайных чисел
  for (int i = 0; i < size; i++) {
    int value = rand() % 100 + 1;
    while (checkValue(arr, i, value)) {
      value = rand() % 100 + 1;
    }
    arr[i] = value; // Генерируем случайное число от 1 до 100
  }
}

// Функция для вывода массива на экран
void printArray(int arr[], int size) {
  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

int gcd(int a, int b) {
  while (b != 0) {
    int temp = b;
    b = a % b;
    a = temp;
  }
  return a;
}
// Функция для поиска двух взаимно простых чисел в массиве
void findTwoMutuallyPrime(int arr[], int size, int *first, int *second) {
  for (int i = 0; i < size - 1; i++) {
    for (int j = i + 1; j < size; j++) {
      if (gcd(arr[i], arr[j]) == 1) {
        if (arr[i] > arr[j]) {
          int tmp = j;
          j = i;
          i = tmp;
        }
        *first = i;
        *second = j;
        return; // Найдены взаимно простые числа, завершаем поиск
      }
    }
  }
  // Если не найдены взаимно простые числа, устанавливаем first и second в -1
  *first = -1;
  *second = -1;
}
// mod := 1 || 2; 1 - поиск меньшего числа 2 - поиск большего числа
int findIndex(int arr[], int size, int mod) {
  int index = 0;
  int tmpValue = arr[index];
  for (int i = 0; i < size; i++) {
    if (mod == 1 && tmpValue > arr[i]) {
      tmpValue = arr[i];
      index = i;
    }
    if (mod == 2 && tmpValue < arr[i]) {
      tmpValue = arr[i];
      index = i;
    }
  }
  return index;
}

void swapNumberInArray(int arr[], int index1, int index2) {
  int tmpValue = arr[index1];
  arr[index1] = arr[index2];
  arr[index2] = tmpValue;
}

int main() {
  int size;
  printf("Введите количество элементов массива(максимально количесто элементов "
         "100): ");
  if (scanf("%d", &size) != 1 || size > 100) {
    printf("Размер введён не правильно.\n");
    return 1;
  }
  if (size <= 0) {
    printf("Количество элементов должно быть положительным числом.\n");
    return 1; // Завершаем программу с ошибкой
  }

  int arr[size]; // Объявляем массив с заданным количеством элементов

  // Заполняем массив случайными числами
  fillArray(arr, size);

  // Выводим массив на экран
  printf("Исходный массив: ");
  printArray(arr, size);
  int copyArr[size];
  for (int i = 0; i < size; i++)
    copyArr[i] = arr[i];

  int firstIndx = 0, secondIndx = 0;

  // Поиск индекса двух взаимно простых чисел в массиве
  findTwoMutuallyPrime(arr, size, &firstIndx, &secondIndx);
  // Поиск Максимально и Минимального числа, функция возвращает индекс числа
  int minValueIndx = findIndex(arr, size, 1);
  int maxValueIndx = findIndex(arr, size, 2);
  printf("Максимально число массива: %d\nМинимальное число массива: %d\n",
         arr[maxValueIndx], arr[minValueIndx]);
  if (firstIndx != -1 && secondIndx != -1) {
    printf(
        "Первое взаимно простое число: %d\nВторое взаимно простое число: %d\n",
        arr[firstIndx], arr[secondIndx]);
    swapNumberInArray(arr, firstIndx, maxValueIndx);
    if (maxValueIndx == secondIndx)
      secondIndx = firstIndx;
    if (firstIndx == minValueIndx)
      minValueIndx = maxValueIndx;
    swapNumberInArray(arr, secondIndx, minValueIndx);
  } else {
    printf("Нет взаимно простых чисел!\n");
    arr[maxValueIndx] = 0;
    arr[minValueIndx] = 0;
  }
  printf("  Исходный массив: ");
  printArray(copyArr, size);
  printf("Измененный массив: ");
  printArray(arr, size);

  return 0;
}