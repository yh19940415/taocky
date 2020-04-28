#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
  char *p;
  p = calloc(2, 1);

  printf("p1: %s", p);

  strncpy(p, "abcdefg", 10);

  printf("p2: %s", p);

  return 0;
}
