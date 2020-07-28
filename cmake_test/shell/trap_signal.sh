#!/bin/bash
trap "trap" 2
function trap()
{
  echo "You press Ctrl+C"
  pgrep dcos_test_tda4_
  pgrep dcos_test_tda4_ | xargs sudo kill
  pgrep bug | xargs sudo kill
}
while getopts "n:" opt
do
    case $opt in
        n)
            loop=$OPTARG
        ;;
        ?)
        echo "未知参数"
        exit 1;;
    esac
done
echo ${loop}
i=0
while :
do
  let i++
  echo loop cnt: ${i}
  sudo ./dcos_test_tda4_all.sh ${i} &
  sleep 20
  sudo ./killall_dcos_test.sh
  pgrep dcos_test_tda4_
  pgrep dcos_test_tda4_ | xargs sudo kill
done
