cmake_minimum_required(VERSION 2.8)
set(CMAKE_C_FLAGS "-Wall -O0 -g")

set(src_file getopt.c)

add_executable(getopt ${src_file})
