#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

struct father
{
  struct child1   {
    struct son {
      int age;
      char name[128];
    }son;
  }child1;  
  
  struct child2 {
    struct son {
      int age;
      char name[128];
    }son;
  }child2;
};

int main(int argc, char **argv)
{

  printf("begin\n");

  struct father f1;
  f1.child1.son.age = 1;
  f1.child2.son.age = 2;
  
  printf("f1.child1.son.age:%d\n", f1.child1.son.age);
  printf("f1.child2.son.age:%d\n", f1.child2.son.age);
  return 0;
  
}
