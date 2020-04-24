#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct sensor_table {
  char *md5;
};
#define VER_sensor_table "21498714317391438"

#define STRUCT_INIT(struct_addr, type_of_struct) \
                  memset(struct_addr, 0, sizeof(struct type_of_struct));\
                  ((struct_addr)->md5 = VER_##type_of_struct)

int main(int argc, char **argv)
{
  struct sensor_table st;
  STRUCT_INIT(&st, sensor_table);


  printf("verison mad5:%s\n", st.md5);

  return 0;
}
