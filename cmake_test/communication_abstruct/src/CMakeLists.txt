cmake_minimum_required(VERSION 2.8)
set(src_client client.c communication_abstruct.c)

add_executable(strcmp_test ${src_client})

set(src_server server.c communication_abstruct.c)

add_executable(strcmp_test ${src_server})



