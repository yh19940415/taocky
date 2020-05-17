#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char **argv)
{
  char *p = NULL;
  printf("print the NULL char pointer to create coredump\n");
  printf("%s\n", p);


  return 0;
}
