#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <pthread.h>

#define PARAM_FILE_LEN 256

typedef struct dcos_param2_handle{
  char file_full_path_name[PARAM_FILE_LEN];
  char struct_full_path_name[PARAM_FILE_LEN];
  char key[PARAM_FILE_LEN];
  //char value[PARAM_FILE_LEN];
  char dynamic_key[PARAM_FILE_LEN * 2];
  uint8_t maid;
  uint8_t hostid;
  uint8_t mid;
  uint8_t param2_mode;
  uint8_t param2_type;
  uint8_t operate;
  uint8_t is_inited;
  uint8_t param_cbk_inited;

  int32_t array_row;
  int32_t array_col;
  int32_t file_len;
  int32_t struct_len;
  int32_t data_length;
  uint64_t cjson;
  pthread_mutex_t lock;
//  uint8_t data[0];
}dcos_param2_handle_t __attribute__((aligned(4)));

typedef struct dcos_param2_handle_1{
  char file_full_path_name[PARAM_FILE_LEN];
  char struct_full_path_name[PARAM_FILE_LEN];
  char key[PARAM_FILE_LEN];
  //char value[PARAM_FILE_LEN];
  char dynamic_key[PARAM_FILE_LEN * 2];
//  uint8_t data[0];
}dcos_param2_handle_t_1 __attribute__((aligned(4)));

typedef struct dcos_param2_handle_2{
  char file_full_path_name[PARAM_FILE_LEN];
  char struct_full_path_name[PARAM_FILE_LEN];
  char key[PARAM_FILE_LEN];
//  char value[PARAM_FILE_LEN];
  char dynamic_key[PARAM_FILE_LEN * 2];
  uint8_t maid;
  uint8_t hostid;
  uint8_t mid;
  uint8_t param2_mode;
  uint8_t param2_type;
  uint8_t operate;
  uint8_t is_inited;
  uint8_t param_cbk_inited;
//  uint8_t data[0];
}dcos_param2_handle_t_2 __attribute__((aligned(4)));

typedef struct dcos_param2_handle_3{
  char file_full_path_name[PARAM_FILE_LEN];
  char struct_full_path_name[PARAM_FILE_LEN];
  char key[PARAM_FILE_LEN];
//  char value[PARAM_FILE_LEN];
  char dynamic_key[PARAM_FILE_LEN * 2];
  uint8_t maid;
  uint8_t hostid;
  uint8_t mid;
  uint8_t param2_mode;
  uint8_t param2_type;
  uint8_t operate;
  uint8_t is_inited;
  uint8_t param_cbk_inited;

  int32_t array_row;
//  uint8_t data[0];
}dcos_param2_handle_t_3 __attribute__((aligned(4)));


typedef struct dcos_param2_handle_4{
  char file_full_path_name[PARAM_FILE_LEN];
  char struct_full_path_name[PARAM_FILE_LEN];
  char key[PARAM_FILE_LEN];
//  char value[PARAM_FILE_LEN];
  char dynamic_key[PARAM_FILE_LEN * 2];
  uint8_t maid;
  uint8_t hostid;
  uint8_t mid;
  uint8_t param2_mode;
  uint8_t param2_type;
  uint8_t operate;
  uint8_t is_inited;
  uint8_t param_cbk_inited;

  int32_t array_row;
  int32_t array_col;
  int32_t file_len;
//  uint8_t data[0];
}dcos_param2_handle_t_4 __attribute__((aligned(4)));

typedef struct dcos_param2_handle_5{
  char file_full_path_name[PARAM_FILE_LEN];
  char struct_full_path_name[PARAM_FILE_LEN];
  char key[PARAM_FILE_LEN];
//  char value[PARAM_FILE_LEN];
  char dynamic_key[PARAM_FILE_LEN * 2];
  uint8_t maid;
  uint8_t hostid;
  uint8_t mid;
  uint8_t param2_mode;
  uint8_t param2_type;
  uint8_t operate;
  uint8_t is_inited;
  uint8_t param_cbk_inited;

  int32_t array_row;
  int32_t array_col;
  int32_t file_len;
  int32_t struct_len;
  int32_t data_length;
//  uint8_t data[0];
}dcos_param2_handle_t_5 __attribute__((aligned(4)));

int main()
{
    printf("sizeof:%ld\n", sizeof(dcos_param2_handle_t));
    printf("1sizeof:%ld\n", sizeof(dcos_param2_handle_t_1));
    printf("2sizeof:%ld\n", sizeof(dcos_param2_handle_t_2));
    printf("3sizeof:%ld\n", sizeof(dcos_param2_handle_t_3));
    printf("4sizeof:%ld\n", sizeof(dcos_param2_handle_t_4));
    printf("5sizeof:%ld\n", sizeof(dcos_param2_handle_t_5));
    return 0;
}

