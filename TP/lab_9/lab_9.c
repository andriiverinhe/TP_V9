#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Функция для сравнения длин слов
int compare(const void *a, const void *b) {
  const char *str1 = *(const char **)a;
  const char *str2 = *(const char **)b;
  return strlen(str2) - strlen(str1);
}

// Функция для размещения слов в порядке убывания длины
char *sortWordsByLength(char *input) {
  char *words[1000]; // Массив указателей на слова
  int wordCount = 0;

  // Разбиваем строку на слова
  char *token = strtok(input, "!?;:., ");
  while (token != NULL) {
    words[wordCount] = token;
    wordCount++;
    token = strtok(NULL, "!?;:., ");
  }

  // Сортируем слова в порядке убывания длины

  qsort(words, wordCount, sizeof(char *), compare);

  // Собираем отсортированные слова в новую строку
  char *sortedString = (char *)malloc(strlen(input) + 1);
  sortedString[0] = '\0'; // Начальное значение пустой строки

  for (int i = 0; i < wordCount; i++) {
    strcat(sortedString, words[i]);
    if (i != wordCount - 1)
      strcat(sortedString, " "); // Добавляем пробел между словами
  }
  return sortedString;
}

int main() {
  char input[1000] = {'\0'};
  printf("Введите строку: ");
  fgets(input, sizeof(input), stdin);

  // Убираем символ новой строки, который добавляется fgets
  input[strcspn(input, "\n")] = '\0';

  printf("Исходная строка: \n|%s|\n", input);
  char *sortedString = sortWordsByLength(input);

  printf("Отсортированные слова в новой строке:\n|%s|\n", sortedString);

  // Освобождаем память, выделенную для sortedString
  if (sortedString)
    free(sortedString);

  return 0;
}