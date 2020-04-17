#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define CMD_KIND 17
int main(int argc, char **argv)
{
  char cmd[CMD_KIND][256] = {
    "sudo dcos_debug ms get_log_level -maid 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 >> /var/dji/dcos/debug_pressure_test.log\n",
    "sudo dcos_debug ms set_log_level -level 2 -maid 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 >> /var/dji/dcos/debug_pressure_test.log",
    "sudo dcos_debug shmem busy -maid 1 v2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 >> /var/dji/dcos/debug_pressure_test.log",
    "sudo dcos_debug shmem brief -maid 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 >> /var/dji/dcos/debug_pressure_test.log",

    "sudo dcos_debug inst stat -maid 9 >> /var/dji/dcos/debug_pressure_test.log",
    "sudo dcos_debug inst stat -id 63 -maid 9 >> /var/dji/dcos/debug_pressure_test.log",
    "sudo dcos_debug inst stat -host_name dji_sys -maid 9 >> /var/dji/dcos/debug_pressure_test.log",
    "sudo dcos_debug ms module -id 63 1 -maid 9 >> /var/dji/dcos/debug_pressure_test.log",
    "sudo dcos_debug ms module -host_name dji_sys -maid 9 >> /var/dji/dcos/debug_pressure_test.log",
    "sudo dcos_debug ms agent -id 63 -maid 9 >> /var/dji/dcos/debug_pressure_test.log",
    "sudo dcos_debug ms agent -host_name dji_sys -maid 9 >> /var/dji/dcos/debug_pressure_test.log",
    "sudo dcos_debug ms show-stream -maid 9 >> /var/dji/dcos/debug_pressure_test.log",
    "sudo dcos_debug ms clear-stream -maid 9 >> /var/dji/dcos/debug_pressure_test.log",
    "sudo dcos_debug ms sysstat -maid 9 >> /var/dji/dcos/debug_pressure_test.log",
    "sudo dcos_debug version show -id 63 1 -maid 9 >> /var/dji/dcos/debug_pressure_test.log",
    "sudo dcos_debug version show -host_name dji_sys -maid 9 >> /var/dji/dcos/debug_pressure_test.log",

    "sudo date >> /var/dji/dcos/debug_pressure_test.log",
                      };

  int i = 0;
  long cnt = 0;
  while (1) {
    cnt++;
    printf("cnt:%ld\n", cnt);
    system("sudo dcos_debug service list | grep dcos_debug_server_");

    for (i = 0; i < CMD_KIND; i++) {
      system(cmd[i]);
    }

  }

  return 0;
}
