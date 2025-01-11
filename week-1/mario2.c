#include <stdio.h>
#include <string.h>

int main(void) {
  int height;
  do {
    printf("Height: ");
  } while (scanf("%d", &height) != 1 || height < 1 || height > 8);

  int width = (height * 2) + 2;

  for(int i = 1; i <= height; i++) {
    int j;

    for(j = 0; j < height - i + 1; j++) {
      putchar(' ');
    }

    for(j = height - i; j < height; j++) {
      putchar('#');
    }

    putchar(' ');
    putchar(' ');

    for(j = height + 1; j < width - (height - i + 1); j++) {
      putchar('#');
    }

    putchar('\n');
    putchar('\0');
  }
}
