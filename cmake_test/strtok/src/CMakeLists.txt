cmake_minimum_required(VERSION 2.8)
set(CMAKE_C_FLAGS "-Wall -O0 -g")

set(src_file strtok.c)

add_executable(strtok ${src_file})
target_link_libraries(strtok -pthread)
