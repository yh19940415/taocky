#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#include "performance_time.h"


int main(int argc, char **argv)
{
  recursive_roll_back_file("/tmp/taocky/test.txt");
  char array[128];
  int length = 128;
  printf("strlen(array):%ld", strlen(array));
  FILE *fpath;
  fpath = fopen("/tmp/taocky/test.txt", "w+");
  if (fpath == NULL) {
    printf("error:open /tmp/taocky/test.txt error\n");
    return 0;
  }

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
    PERF_TIME_POINT_FILE(fpath, array, length);
  }

  PERF_TIME_AVERAGE_FILE(fpath, array, length);

  printf("end\n");



  memset(array, 0, 128);
  snprintf(array, 128, "this is s array test\n");

  fwrite(array,1, strlen(array), fpath);
  fclose(fpath);
  int loop0 = atoi(argv[1]);
  int myarray [loop0];
  for (i = 0; i < loop0; i++) {
    myarray[i] = i;
    printf("array[%d]:%d\n", i, myarray[i]);
  }
  return 0;
}
