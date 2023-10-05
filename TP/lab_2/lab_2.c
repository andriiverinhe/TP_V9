#include <math.h>
#include <stdio.h>

// Требования и ограничения
// Значение x вводить с клавиатуры. Обработать ввод с клавиатуры таким образом,
// чтобы расчёт вёлся только для допустимых значений вводимых параметров.
// Программа должна содержать единственный оператор if.

#define MY_PI 3.1415926535 // Число ПИ

int main() {
  double x = 0.0;
  printf("Enter x -> ");
  if ((scanf("%lf", &x)) == 1 && !isnan(x) && !isinf(x)) {
    double y = acos((2.0 * x) / (1 + pow(x, 2)));
    if (y != 0) {
      double sinY = sin((MY_PI / y));
      if (sinY > 0)
        printf("y(x) = %lf\nz(y) = %lf\n", y, log(sinY));
      else
        printf("sin(y) is not correct!\n");
    } else {
      printf("y is not correct!\n");
    }
  } else
    printf("x is not incorrect!\n");
  return 0;
}
