#include <stdio.h>
// цикл
// Функция для нахождения НОД (наибольшего общего делителя)
int findGCD(int a, int b) {
  while (b != 0) {
    int temp = b;
    b = a % b;
    a = temp;
  }
  return a;
}

// Функция для нахождения НОК (наименьшего общего кратного)
int findLCM(int a, int b) {
  int gcd = findGCD(a, b);
  int lcm = (a * b) / gcd;
  return lcm;
}

// рекурсия
// Функция для нахождения НОД (наибольшего общего делителя)
int recFindGCD(int a, int b) { return (b == 0) ? a : recFindGCD(b, a % b); }

// Функция для нахождения НОК (наименьшего общего кратного)
int recFindLCM(int a, int b) {
  int gcd = recFindGCD(a, b);
  int lcm = (a * b) / gcd;
  return lcm;
}

int main() {
  int num1 = 0, num2 = 0;
  printf("Введите два натуральных числа: ");

  if (scanf("%d %d", &num1, &num2) == 2) {
    if (num1 <= 0 || num2 <= 0) {
      printf("Пожалуйста, введите натуральные числа.\n");
    } else {
      int lcm = findLCM(num1, num2);
      int recLcm = recFindLCM(num1, num2);
      if (lcm >= 1 && recLcm >= 1) {
        printf("Наименьшее общее кратное в цикле: %d\n", lcm);
        printf("Наименьшее общее кратное в рекурсии: %d\n", recLcm);
      } else {
        printf("Искомое число слишком большое!\n");
      }
    }
  } else
    printf("Числа не верные!\n");
  return 0;
}