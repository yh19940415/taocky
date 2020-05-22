#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char **argv)
{
  printf("coredump %s\n", NULL);
  char *p = NULL;
  printf("print the NULL char pointer to create coredump\n");
 printf("coredump %s\n", NULL);


  return 0;
}
