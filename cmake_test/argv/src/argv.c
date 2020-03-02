#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_main {
  int argc;
  char argv[3][128];
}s_main_t;

void add_buf(char *buf)
{
  sprintf(buf, "hao1\n");
  sprintf(buf+strlen(buf), "hao2\n");
}

void test_main(int argc, char argv[3][128])
{

  int i = atoi(argv[0]);
  printf("i:%d\n", i);
}

int main(void)
{
  printf("argv test begin\n");

  char argv[3][128] ={"param1", "param2_1", "param33333"};

  printf("1: %s\n", argv[0]);
  printf("2: %s\n", argv[1]);
  printf("3: %s\n", argv[2]);

  //printf("4: %s", &argv);

  char *addr[3];

  addr[0] = argv[0];
  addr[1] = argv[1];
  addr[2] = argv[2];
  printf("1: %s\n", addr[0]);
  printf("2: %s\n", addr[1]);
  printf("3: %s\n", addr[2]);


  char cbuf[3][128];
  strncpy(cbuf[0], argv[0], 128);
  strncpy(cbuf[1], argv[1], 128);
  strncpy(cbuf[2], argv[2], 128);

  printf("cbuf1: %s\n", cbuf[0]);
  printf("cbuf2: %s\n", cbuf[1]);
  printf("cbuf3: %s\n", cbuf[2]);


  char buf[10];
  sprintf(buf, "haocky\n");


  printf("siezof %ld\n", strlen(buf));

  sprintf(buf+strlen(buf) , "yuhao22222222\n");


  printf("buf:%s\n", buf);

  printf("siezof %ld\n", strlen(buf));



  char buf_addr[100];
  add_buf(buf_addr);
  printf("add_buf:%s", buf_addr);

  char my[5]="all";
  printf("my:%d\n", strncmp(my, "all", 3));

  printf("my:%d\n", strncmp(my, "aall", 3));

  printf("my:%d\n", strncmp(my, "a", 3));

  s_main_t a1, *a2;
  strncpy(a1.argv[0], "77", 128);
  strncpy(a1.argv[1], "99", 128);
  a1.argc = 2;

  a2 = malloc(sizeof(s_main_t));
  a2->argc = 2 ;
  strncpy(a2->argv[0], "77", 128);
  strncpy(a2->argv[1], "99", 128);
  test_main(a2->argc, &a2->argv[0]);

  printf("argv test end\n");
  return 0;
}
