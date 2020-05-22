#!/bin/bash
test_param2_client=0
test_service_client_cpp=0
test_sub_cpp=0
test_tmsync_sub_cpp=0
test_tda4_log=./log_dcos_test_tda4_2_$(date +%Y_%m_%d_%H_%M).log
dcos_test_process_start_up()
{
  echo $(date) | tee -a ${test_tda4_log}

  test_param2_client > /dev/null 2>&1 &
  test_param2_client=$!
  echo test_param2_client ${test_param2_client} | tee -a ${test_tda4_log}

  test_service_client_cpp > /dev/null 2>&1 &
  test_service_client_cpp=$!
  echo test_service_client_cpp ${test_service_client_cpp} | tee -a ${test_tda4_log}

  test_sub_cpp > /dev/null 2>&1 &
  test_sub_cpp=$!
  echo test_sub_cpp ${test_sub_cpp} | tee -a ${test_tda4_log}

  test_tmsync_sub_cpp > /dev/null 2>&1 &
  test_tmsync_sub_cpp=$!
  echo test_tmsync_sub_cpp ${test_tmsync_sub_cpp} | tee -a ${test_tda4_log}
}

dcos_test_check_process_alive()
{
  pid=0

  eval $(dcos_debug ms sysstat | grep test_param2_client | awk '{printf("pid=%d",$8)}')
  if [ ${test_param2_client} != $[pid] ]
  then
    echo "test_param2_client wrong" | tee -a ${test_tda4_log}
  fi

  eval $(dcos_debug ms sysstat | grep test_service_client_cpp | awk '{printf("pid=%d",$8)}')
  if [ ${test_service_client_cpp} != $[pid] ]
  then
    echo "test_service_client_cpp wrong" | tee -a ${test_tda4_log}
  fi

  eval $(dcos_debug ms sysstat | grep test_sub_cpp | awk '{printf("pid=%d",$8)}')
  if [ ${test_sub_cpp} != $[pid] ]
  then
    echo "test_sub_cpp wrong" | tee -a ${test_tda4_log}
  fi

  eval $(dcos_debug ms sysstat | grep test_tmsync_sub_cpp | awk '{printf("pid=%d",$8)}')
  if [ ${test_tmsync_sub_cpp} != $[pid] ]
  then
    echo "test_tmsync_sub_cpp wrong" | tee -a ${test_tda4_log}
  fi
}

#1.start process
echo dcos_test_process_start_up | tee -a ${test_tda4_log}
dcos_test_process_start_up

#2.check process
echo dcos_test_check_process_alive degin | tee -a ${test_tda4_log}
count=0
while :
do
  ((count++))
  echo ${count} | tee -a ${test_tda4_log}
  dcos_test_check_process_alive
  sleep 5
done



echo dcos_test end | tee -a ${test_tda4_log}
