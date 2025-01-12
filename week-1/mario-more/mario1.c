#include <stdio.h>
#include <string.h>

int main(void) {
  printf("How tall? ");
  int height;
  scanf("%i", &height);
  int width = (height * 2) + 2;

  int i;
  for(i = 1; i <= height; i++) {
    char level[width];
    int j;

    for(j = 0; j < height - i + 1; j++) {
      level[j] = ' ';
    }

    for(j = height - i; j < height; j++) {
      level[j] = '#';
    }

    level[height] = ' ';

    for(j = height + 1; j < width - (height - i + 1); j++) {
      level[j] = '#';
    }

    level[width - 1] = '\0';

    printf("%s\n", level);
  }
}
