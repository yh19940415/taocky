#ifndef __PERFORMANCE_TIME_H
#define __PERFORMANCE_TIME_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include <stdarg.h>
#include <unistd.h>

#ifdef __cplusplus
extern "C" {
#endif

#define PERF_POINT_LEN 16

int recursive_roll_back_file(char *pathname)
{
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

int get_time(uint64_t *time_us)
{
  struct timespec ts;
  clock_gettime(CLOCK_REALTIME, &ts);
  *time_us = ts.tv_sec * 1000000 + ts.tv_nsec/1000;

  return 0;
}

typedef struct perf_time
{
  uint64_t start_time;
  uint64_t pre_time;
  uint64_t last_time;

  uint64_t point[PERF_POINT_LEN];

  uint64_t delta_ms;

}perf_time_t;

/*
#define PERF_TIME_LOG(format, ...)                                    \
  do {                                                                \
    fprintf(stderr, "--line:%d, func:%s\n", __LINE__, __FUNCTION__);  \
    fprintf(stderr, format, ##__VA_ARGS__);                            \
  } while(0)
*/
#define PERF_TIME_LOG(format, ...)                                    \
  do {                                                                \
    fprintf(stderr, format, ##__VA_ARGS__);                            \
  } while(0)


#define PERF_TIME_START()                       \
  perf_time_t time = {0};                     \
  int perf_time_cnt = 0;                      \
  get_time(&time.start_time);                  \
  time.point[perf_time_cnt] = time.start_time; \
  time.last_time = time.start_time;

#define PERF_TIME_POINT()                          \
  time.pre_time = time.last_time;                 \
  get_time(&time.last_time);                      \
  time.delta_ms = time.last_time - time.pre_time; \
  if (perf_time_cnt < PERF_POINT_LEN -1 ) {          \
    perf_time_cnt++;                                \
    time.point[perf_time_cnt] = time.last_time; \
    PERF_TIME_LOG("%-10d:delta:%10ld last_time:%20ld pre_time:%20ld start_time:%20ld\n", perf_time_cnt, time.delta_ms, time.last_time, time.pre_time, time.start_time);\
  } else {  \
    PERF_TIME_LOG("error:perf_time_cnt is greater than PERF_POINT_LEN:%d\n", PERF_POINT_LEN);\
    PERF_TIME_LOG("%-10d:delta:%10ld last_time:%20ld pre_time:%20ld start_time:%20ld\n", perf_time_cnt, time.delta_ms, time.last_time, time.pre_time, time.start_time);\
  }

#define PERF_TIME_AVERAGE()                          \
  if (perf_time_cnt < PERF_POINT_LEN ) {          \
    PERF_TIME_LOG("\n\ntotoal count%-d:\taverage:%ld\tlast_time:%ld\tpre_time:%ld\tstart_time:%ld\n", perf_time_cnt, (time.last_time - time.start_time)/perf_time_cnt, time.last_time, time.pre_time, time.start_time);\
  } else {  \
    PERF_TIME_LOG("error:perf_time_cnt is greater than PERF_POINT_LEN:%d\n", PERF_POINT_LEN);\
  }


#define PERF_TIME_POINT_FILE(fpath, array, length)                          \
  time.pre_time = time.last_time;                 \
  get_time(&time.last_time);                      \
  time.delta_ms = time.last_time - time.pre_time; \
  if (perf_time_cnt < PERF_POINT_LEN -1 ) {          \
    perf_time_cnt++;                                \
    time.point[perf_time_cnt] = time.last_time; \
    memset(array, 0, length);\
    snprintf(array, length, "%-10d:delta:%10ld last_time:%20ld pre_time:%20ld start_time:%20ld\n", perf_time_cnt, time.delta_ms, time.last_time, time.pre_time, time.start_time);\
    fwrite(array,1, strlen(array), fpath);\
  } else {  \
    memset(array, 0, length);\
    snprintf(array, length, "error:perf_time_cnt is greater than PERF_POINT_LEN:%d\n", PERF_POINT_LEN);\
    fwrite(array,1, strlen(array), fpath);\
    memset(array, 0, length);\
    snprintf(array, length, "%-10d:delta:%10ld last_time:%20ld pre_time:%20ld start_time:%20ld\n", perf_time_cnt, time.delta_ms, time.last_time, time.pre_time, time.start_time);\
    fwrite(array,1, strlen(array), fpath);\
  }

#define PERF_TIME_AVERAGE_FILE(fpath, array, length)                          \
  if (perf_time_cnt < PERF_POINT_LEN ) {          \
    memset(array, 0, length);\
    snprintf(array, length, "\n\ntotoal count%-d:\taverage:%ld\tlast_time:%ld\tpre_time:%ld\tstart_time:%ld\n", perf_time_cnt, (time.last_time - time.start_time)/perf_time_cnt, time.last_time, time.pre_time, time.start_time);\
    fwrite(array,1, strlen(array), fpath);\
  } else {  \
    memset(array, 0, length);\
    snprintf(array, length, "error:perf_time_cnt is greater than PERF_POINT_LEN:%d\n", PERF_POINT_LEN);\
    fwrite(array,1, strlen(array), fpath);\
  }


#ifdef __cplusplus
}
#endif

#endif
