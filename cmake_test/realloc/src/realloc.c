#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
  char *p;
  p = calloc(2, 1);
  printf("p1: %s\n", p);

  strncpy(p, "1234567", 10);

  printf("p2: %s\n", p);
  printf("len:%ld\n", strlen(p));

  return 0;
}
