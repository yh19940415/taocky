#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct param
{
  char name[128];

} param_t;

typedef struct param_data
{
  int i;
  char name[128];
  int j;

} param_data_t;

void pointer(void * addr)
{
  param_data_t data1;
  data1.i = 1;
  data1.name ="124";
  data1.j = 2;

}

int main(int argc, char **argv)
{
  param_data_t data;
  pointer(&data);

  printf("data i: %d\n", data.i);
  printf("data name: %s\n", data.name);
  printf("data j: %d\n", data.j);
  return 0;
}
