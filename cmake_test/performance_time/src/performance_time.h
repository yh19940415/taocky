#ifndef __PERFORMANCE_TIME_H
#define __PERFORMANCE_TIME_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include <stdarg.h>

#ifdef __cplusplus
extern "C" {
#endif

#define PERF_POINT_LEN 16

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


#ifdef __cplusplus
}
#endif

#endif
