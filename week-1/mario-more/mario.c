#include <stdio.h>
#include <string.h>

int main(void) {
  int height;
  while (1) {
    printf("Height: ");
    if (scanf("%d", &height) == 1 && height >= 1 && height <= 8) {
      break;
    }
    while (getchar() != '\n')
      ;
  }

  int width = (height * 2) + 2;

  for (int i = 1; i <= height; i++) {
    int j;

    for (j = 1; j < height - i + 1; j++) {
      putchar(' ');
    }

    for (j = height - i; j < height; j++) {
      putchar('#');
    }

    putchar(' ');
    putchar(' ');

    for (j = height + 1; j < width - (height - i + 1); j++) {
      putchar('#');
    }

    putchar('\n');
  }
}
