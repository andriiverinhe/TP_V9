#include <limits.h>
#include <math.h>
#include <stdio.h>

// Контрольное значение интеграла
#define CONTROL_VALUE 2.93972

// Значение числа Пи
#define PI 3.1415926535

// Функция для вычисления приближенного значения интеграла методом
// прямоугольников
double getIntegral(double h, int n, double a, double b) {
  double integ = 0.0;
  double f = 0.0;
  double x = 0.0;

  for (int k = 0; k <= n - 1; k++) {
    // Вычисляем значение x в середине интервала
    x = a + (k * h) + (h / 2);

    if (x > a && x <= 0)
      f += (pow(x, 2) - (2.0 * pow(x, 3))) * cos(pow(x, 2));
    else if (x > 0 && x <= b)
      f += exp(sin(2.0 * x));
  }

  integ = f * h;
  return integ;
}

int main() {
  // Заданные пределы интегрирования
  double a = PI / -2.0;
  double b = PI / 2.0;

  int n = 1; // Начальное количество разбиений интервала
  double h = 0.0;

  double integral = 1.0;
  double tmp = 0.0;

  double accuracy = 0.0;
  printf("Enter accuracy: ");
  if ((scanf("%lf", &accuracy)) == 1 && !isnan(accuracy) && !isinf(accuracy)) {
    if (accuracy == 0.0)
      accuracy = 0.000001;

    // Итеративный расчет интеграла с заданной точностью
    do {
      h = (b - a) / n;
      tmp = integral;
      if (n * 2 > INT_MAX)
        break;
      integral = getIntegral(h, n, a, b);
      n *= 2;
    } while (fabs((tmp - integral) / 3.0) >= accuracy);

    // Вывод результата
    printf("Calculated integral: %.6lf\n", integral);
    printf("Control value: %.6lf\n", CONTROL_VALUE);

    // Проверка на близость к контрольному значению
    if (fabs(integral - CONTROL_VALUE) < accuracy)
      printf("The integral is close to the control value.\n");
    else
      printf("The integral is not close to the control value.\n");
  } else
    printf("Accuracy is not correct!\n");
  return 0;
}
