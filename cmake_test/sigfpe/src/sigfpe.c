#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<stdint.h>



int main(int argc, char **argv)
{


  uint8_t i = 0;
  uint8_t j = 0;

  i = atoi(argv[1]) - 1;

  j = atoi(argv[2]) -1;

  printf("i = %d, j = %d\n", i, j);

  fflush(stdout);

  printf("i %j = %d", i%j);


  return 0;
}
