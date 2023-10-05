#include <stdio.h>

int main() {
  double a = 0, b = 0, x = 0;
  int err = 0;

  // Ввод значений a, b и x
  printf("Введите значение a, b, x: ");

  if (scanf("%lf%lf%lf", &a, &b, &x) != 3)
    err = 1;
  if (err)
    printf("Value is not corecct\n");
  else {
    // Вычисление произведения a и b
    double product = a * b;
    // Проверка условия и вывод результата
    if (product < x) {
      double quotient = product / x;
      printf("Частное произведения a и b и x: %.2lf\n", quotient);
    } else if (product > x) {
      double difference = product - x;
      printf("Разность произведения a и b и x: %.2lf\n", difference);
    } else
      printf("Произведение a и b равно x\n");
  }

  return 0;
}
