#include <math.h>
#include <stdio.h>

#define EXP 0.000001

int main() {
  double x = 0.0;
  double h = 0.0;
  printf("Enter h: ");
  int err = 0;
  // Считываем значение h с клавиатуры и проверяем на корректность
  if (scanf("%lf", &h) != 1 || isnan(h) || isinf(h)) {
    printf("h is not corect!\n");
    err = 1;
  } else
    printf("h: %lf\n", h);

  // В этом цикле мы вычисляем и выводим значения функции в зависимости от
  // значения x Для x <= 0, используется формула ((x^2 - 2.0 * x^3) * cos(x^2))
  // Для x > 0, используется формула exp(sin(2.0 * x))
  for (; (x - 1.5 < EXP && x + 1.5 > EXP) && !err; x += h) {
    if (x <= 0) {
      printf("f(%.2lf): %.2lf\n", x,
             ((pow(x, 2) - 2.0 * pow(x, 3)) * cos(pow(x, 2))));
    } else
      printf("f(%.2lf): %.2lf\n", x, exp(sin(2.0 * x)));
  }

  return 0;
}