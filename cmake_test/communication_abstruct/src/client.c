#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char **argv)
{
  char cmd1[128] = "dcos_debug ms sysstat";

  int ret = strncmp(cmd1, "dcos_debug ms sysstat", 128);


  printf("this is a test: ret %d\n", ret);



   char buffer[10] = "tmp_naem";



   char *path = tmpnam(buffer);

   char cmd[128]={""};
   memset(&cmd[0], 0, 128);

   sprintf(cmd, "%s > %s", "ls", buffer);
   system(cmd);
   printf("临时名称 1: %s\n", buffer);

   char *ptr = tmpnam(NULL);
   printf("临时名称 2: %s\n", ptr);




   return 0;
}
