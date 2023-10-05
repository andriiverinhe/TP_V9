#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Структура для представления информации о клубе
struct Club {
  char name[100];
  char address[100];
  char theme[100];
  char openingTime[10];
  char closingTime[10];
  int hasKaraoke;
};

int isValidTimeFormat(const char *time) {
  // Проверка, что строка имеет формат "00:00"
  if (strlen(time) != 5 || time[2] != ':') {
    return 0;
  }

  // Проверка, что первые два символа - цифры (часы)
  for (int i = 0; i < 2; i++) {
    if (!isdigit(time[i])) {
      return 0;
    }
  }

  // Проверка, что последние два символа - цифры (минуты)
  for (int i = 3; i < 5; i++) {
    if (!isdigit(time[i])) {
      return 0;
    }
  }

  // Проверка, что часы и минуты находятся в допустимых диапазонах
  int hours = atoi(time);
  int minutes = atoi(time + 3);
  if (hours < 0 || hours > 23 || minutes < 0 || minutes > 59) {
    return 0;
  }

  return 1;
}

// Функция для считывания времени с проверкой на корректность
void readTime(char *time) {
  int isValid = 0;
  while (!isValid) {
    printf("Введите время в формате 00:00: ");
    scanf("%s", time);
    isValid = isValidTimeFormat(time);
    if (!isValid) {
      printf("Неправильный формат времени. Повторите ввод.\n");
    }
  }
}

// Функция для считывания информации о клубе
struct Club readClubInfo() {
  struct Club club;
  int c;
  while ((c = getchar()) != '\n' && c != EOF)
    ;

  printf("Введите название клуба: ");
  fgets(club.name, sizeof(club.name), stdin);
  club.name[strcspn(club.name, "\n")] = '\0';

  printf("Введите адрес клуба: ");
  fgets(club.address, sizeof(club.address), stdin);
  club.address[strcspn(club.address, "\n")] = '\0';

  printf("Введите тематику клуба: ");
  fgets(club.theme, sizeof(club.theme), stdin);
  club.theme[strcspn(club.theme, "\n")] = '\0';
  printf("Введите время открытия.\n");
  readTime(club.openingTime);
  printf("Введите время закрытия.\n");
  readTime(club.closingTime);

  do {
    printf("Есть ли в клубе караоке? (1 - да, 0 - нет): ");
    int input;
    if (scanf("%d", &input) == 1 && (input == 0 || input == 1)) {
      club.hasKaraoke = input;
      break; // Выходим из цикла, если введено корректное значение
    } else {
      printf("Некорректный ввод. Пожалуйста, введите 1 или 0.\n");
      while (getchar() != '\n')
        ; // Очищаем буфер ввода от некорректного ввода
    }
  } while (1); // Зацикливаемся до ввода корректного значения

  return club;
}

// Функция для вывода информации о клубе
void printClubInfo(struct Club club) {
  printf("Название: %s\n", club.name);
  printf("Адрес: %s\n", club.address);
  printf("Тематика: %s\n", club.theme);
  printf("Время открытия: %s\n", club.openingTime);
  printf("Время закрытия: %s\n", club.closingTime);
  printf("Караоке: %s\n", club.hasKaraoke ? "Да" : "Нет");
}

int main() {
  int capacity = 10; // Начальная вместимость списка клубов
  struct Club *clubs = (struct Club *)malloc(capacity * sizeof(struct Club));
  if (!clubs) {
    fprintf(stderr, "Ошибка выделения памяти\n");
    return 1;
  }

  int clubCount = 0; // Количество клубов в списке

  while (1) {
    printf("\nМеню:\n");
    printf("1. Добавить клуб\n");
    printf("2. Удалить клуб\n");
    printf("3. Просмотреть список клубов\n");
    printf("4. Найти клуб с караоке и с самым долгим временем работы\n");
    printf("5. Выход\n");
    printf("Выберите действие (1-5): ");

    int choice = -1;
    scanf("%d", &choice);

    switch (choice) {
    case 1: // Добавление клуба
      if (clubCount == capacity) {
        // Увеличение размера массива при необходимости
        capacity *= 2;
        clubs = (struct Club *)realloc(clubs, capacity * sizeof(struct Club));
        if (!clubs) {
          fprintf(stderr, "Ошибка выделения памяти\n");
          return 1;
        }
      }
      clubs[clubCount] = readClubInfo();
      clubCount++;
      break;
    case 2: // Удаление клуба
      if (clubCount > 0) {
        printf("Введите номер клуба для удаления (1-%d): ", clubCount);
        int clubToDelete = -1;
        scanf("%d", &clubToDelete);
        if (clubToDelete >= 1 && clubToDelete <= clubCount) {
          for (int i = clubToDelete - 1; i < clubCount - 1; i++) {
            clubs[i] = clubs[i + 1];
          }
          clubCount--;
          printf("Клуб удален\n");
        } else {
          printf("Недопустимый номер клуба\n");
        }
      } else {
        printf("Список клубов пуст\n");
      }
      break;
    case 3: // Просмотр списка клубов
      printf("Список клубов:\n");
      for (int i = 0; i < clubCount; i++) {
        printf("/~~~~~~~~~~~~~~~~~\\");
        printf("\nКлуб %d:\n", i + 1);
        printClubInfo(clubs[i]);
        printf("\\~~~~~~~~~~~~~~~~~/\n");
      }
      if (clubCount == 0)
        printf("Клубов нет\n");
      break;
    case 4: // Поиск клуба с караоке и самым долгим временем работы
    {
      int found = 0;
      int longestDuration = 0;
      int clubIndex = -1;
      for (int i = 0; i < clubCount; i++) {
        if (clubs[i].hasKaraoke &&
            strcmp(clubs[i].closingTime, clubs[i].openingTime) > 0) {
          int duration =
              atoi(clubs[i].closingTime) - atoi(clubs[i].openingTime);
          if (duration > longestDuration) {
            longestDuration = duration;
            clubIndex = i;
          }
          found = 1;
        }
      }
      if (found) {
        printf("Клуб с караоке и самым долгим временем работы:\n");
        printClubInfo(clubs[clubIndex]);
      } else {
        printf("Нет клубов с караоке и допустимым временем работы\n");
      }
    } break;
    case 5:        // Выход
      free(clubs); // Освобождение памяти
      return 0;
    default:
      printf("Недопустимый выбор\n");
    }
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
      ;
  }

  return 0;
}
