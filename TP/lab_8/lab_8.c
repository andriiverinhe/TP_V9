#include <ctype.h>
#include <stdio.h>
#include <termios.h>
#include <unistd.h>

int mygetch() {
  struct termios oldt, newt;
  int c;
  tcgetattr(STDIN_FILENO, &oldt);
  newt = oldt;
  newt.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSANOW, &newt);
  c = getchar();
  tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
  return c;
}
/*
 * Функция char atbash(char c) шифрует только буквы латинского алфавита
 */
char atbash(char c) {
  if (isalpha(c)) { // Проверка, является ли символ буквой (латинской или
                    // кириллической)
    if (islower(c)) { // Если символ в нижнем регистре (латиница или кириллица)
      return 'z' - (c - 'a'); // Инвертируем порядок букв в алфавите, вычитая из
                              // 'z' разницу между символом и 'a'
    } else { // Если символ в верхнем регистре (латиница или кириллица)
      return 'Z' - (c - 'A'); // Инвертируем порядок букв в алфавите, вычитая из
                              // 'Z' разницу между символом и 'A'
    }
  }
  return c; // Если символ не является буквой, возвращаем его без изменений
}

int main() {
  printf("Введите текст для шифрования шифром Атбаш (нажмите [Home] для "
         "завершения):\n");

  int c;
  while (1) {
    c = mygetch();
    if (c == 27) {          // 27 - код клавиши [Home]
      int next = mygetch(); // Считываем следующий символ
      if (next == 91) {     // 91 - код клавиши [
        int key = mygetch(); // Считываем код функциональной клавиши
        if (key == 72) // 72 - код клавиши Home
          break;
      }
    }
    putchar(atbash(c));
  }
  printf("\n");

  return 0;
}