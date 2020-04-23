#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int recursive_roll_back_file(char *pathname)
{
  /*
  //parse file path and name
  char *p;
  char *name;
  char *path;
  name = (p = strrchr(pathname, '/'))? ++p: pathname;

  int len = name - pathname;
  if (len > 0 && len < 256) {
    path = (char *)malloc(len);
    memcpy(path, pathname, len);
  } else {
    printf("error:please input path, len %d\ncall exit(-1):%s %d\n", len, __FUNCTION__, __LINE__);
    exit(-1);
  }

  printf("path:%s name:%s\n", path, name);

  */
  static int back_cnt = 0;
  if (strlen(pathname) > 256 - 4 || back_cnt > 100) {
     printf("error:pathname len %ld is more than (256 -4), \ncall exit(-1):%s %d\n", strlen(pathname), __FUNCTION__, __LINE__);
  }
  if (access(pathname, F_OK) == 0) {
    back_cnt++;
    char rec_pname[256];
    memset(rec_pname, 256, 0);
    snprintf(rec_pname, 256, "%s.%d",pathname, back_cnt);

    if (access(rec_pname, F_OK) == 0) {
      recursive_roll_back_file(pathname);
      back_cnt--;
    }

    if (back_cnt > 1) {
      char old_name[256];
      memset(old_name, 256, 0);
      snprintf(old_name, 256, "%s.%d",pathname, back_cnt -1);
      rename(old_name, rec_pname);
      printf("old:%s new:%s\n", old_name, rec_pname);
    } else {
      rename(pathname, rec_pname);
      printf("pathname:%s new:%s\n", pathname, rec_pname);
    }

  } else {
    printf("error:pathname %s not exsit \n%s %d\n", pathname, __FUNCTION__, __LINE__);
  }

  return 0;
}

int main(int argc, char **argv)
{

  int ret = recursive_roll_back_file(argv[1]);

  FILE *fpath = NULL;
  fpath = fopen(argv[1], "a+");

  fwrite("this is a test lalal\n", 1, sizeof("this is a test lalal\n"), fpath);

  fclose(fpath);

  if (ret != 0) {
    printf("error");
  }
  return 0;
}
