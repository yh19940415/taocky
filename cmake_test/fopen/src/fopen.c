#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char **argv)
{

  FILE *pfile = NULL;

  pfile = fopen("/home/dji/.dcos/dcos_topic_list", "w+");
  fprintf(pfile, "%s %s %s %d", "We", "are", "in", 2014);
  printf("addr:%p\n", pfile);

  fclose(pfile);



  return 0;
}
