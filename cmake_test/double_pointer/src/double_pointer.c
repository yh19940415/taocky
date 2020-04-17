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

param_data_t* pointer(void )
{
  param_data_t *data1 = (param_data_t *)malloc(sizeof(param_data_t));
  data1->i = 1;
  //data1.name ="124";
  data1->j = 2;

 return data1;
}

typedef enum {
  PARMA_LOCAL = 0,
  PARMA_REMOTE = 1,
  PARMA_GLOBAL = 2,
} param_mode_t;

void sizof_test(char len[])
{
  printf("len %ld\n", sizeof(*len));
}

int main(int argc, char **argv)
{
  param_data_t data;


  printf("data i: %d\n", data.i);
  printf("data name: %s\n", data.name);
  printf("data j: %d\n", data.j);

  param_mode_t mode;
  mode = PARMA_REMOTE;


  param_data_t * p = pointer();

  printf("p:%d\n", p->i);
  printf("p:%d\n", p->j);

  char str_array[10];
  char s1[20] = "123456789012345678";
  printf("str_array:%ld\n", sizeof(*(&str_array)));

  strncpy(str_array, s1, sizeof(str_array));
  printf("str_array:%s\n", str_array);

  memcpy(str_array, s1, sizeof(str_array));
  printf("str_array:%s\n", str_array);

  char len[45] = "12345";
  printf("len %ld\n", sizeof(len));

  sizof_test(&len);


  printf("sizeof("") %ld\n", sizeof(""));

  printf("strncpmy1("") %d\n", strncmp("abc","abd", 4));
  printf("strncpmy2("") %d\n", strncmp("ab1","abd", 4));
  printf("strncpmy3("") %d\n", strncmp("abc","ab1", 4));
  printf("strncpmy4("") %d\n", strncmp("ab","abd", 4));
  printf("strncpmy5("") %d\n", strncmp("abc","ab", 4));

  char value[10];

  printf("value:%x\n", value);
  printf("value:%x\n", &value);
  printf("value:%x\n", &value[0]);

  printf("value:%x\n", &value[0]);

  printf("sizeof:%ld\n", sizeof("set"));

  return 0;
}
