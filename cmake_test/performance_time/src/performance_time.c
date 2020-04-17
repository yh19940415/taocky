#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#include "performance_time.h"


int main(int argc, char **argv)
{
  uint8_t i = 0;
  int loop = atoi(argv[1]);
  printf("loop = %d\n", loop);

  int loop2 = atoi(argv[2]);
  printf("loop2 = %d\n", loop2);

  int j = 0;
  PERF_TIME_START();
  for (i = 0; i < loop; i++) {
    j = 0;
    while (j < loop2) {
      j++;
    }
    PERF_TIME_POINT();
  }

  PERF_TIME_AVERAGE();

  printf("end\n");


  return 0;
}
