#!/bin/bash

killall test_service_server_cpp
rm /tmp/dcos/test_service_server_cpp
killall test_service_client_cpp
rm /tmp/dcos/test_service_client_cpp
killall test_pub
rm /tmp/dcos/test_pub
killall test_sub
rm /tmp/dcos/test_sub
killall test_tmsync_pub_cpp
rm /tmp/dcos/test_tmsync_pub_cpp
killall test_tmsync_sub_cpp
rm /tmp/dcos/test_tmsync_sub_cpp
killall dcos_param2_server
rm /tmp/dcos/dcos_param2_server
killall test_param2_client
rm /tmp/dcos/test_param2_client

rm /tmp/dcos/debug_*
