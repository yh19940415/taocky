#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct struct_fun_ptr
{
  int (*pfunc)(int i, int j);
}struct_fun_ptr_t;

int char_array(char value[])
{
  printf("strlen:%ld\nsizeof:%ld\n", strlen(value), sizeof(value));


  return 0;
}

void func(int n, char **str )
{
  int i;
  for(i = 0; i < n; i++)
  printf("\nstr[%d] = %s\n", i, str[i]);
}

void double_array(const char ** strings, int count)
{
  int i = 0;
  for (i = 0; i < count; i++) {
    printf("%s\n", strings[i]);
  }
}

int main(int argc, char **argv)
{

  printf("sizeof(struct_fun_ptr_t):%ld\n", sizeof(struct_fun_ptr_t));

  double d = 1.1234567890123456789012345678901234567890;
  printf("double:%.30f\n", d);

  char array[128];

  char_array(array);

  printf("array:%s\n", array);


  const char test[4][10] = {"1234","5678","abcd","efgh"};

  double_array(&test[0], 4);

  return 0;
}
