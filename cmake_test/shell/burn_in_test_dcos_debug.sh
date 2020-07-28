#!/bin/bash

#//1.Unknown command
#//2.execute failed
#//3.execute successful

output_directory=.
dcos_debug_cmd_pathname=""

#1.parse input arguments
while getopts ":f:c:" opt
do
    case $opt in
        f)
            dcos_debug_cmd_pathname=$OPTARG
        ;;
        ?)
        echo "未知参数"
        exit 1;;
    esac
done

#2.check the input arguments
if [ "${dcos_debug_cmd_pathname}" == "" ]; then
echo -e "input arguemnts error:\n  -f unsafe func pathname\n"
exit -1
fi
echo dcos_debug_cmd_pathname: \"${dcos_debug_cmd_pathname}\"

#3.execute command
#out_date_dir=${output_directory}/$(date +%Y_%m_%d_%H_%M)_dcos_debug
out_date_dir=./test_dcos_debug
mkdir ${out_date_dir}
result=""
while read line
do
  echo dcos_debug ${line}
  result=$(dcos_debug ${line})
  #4.need to check the command whether executed successfully
  if [ "${result}" != "" ]; then
    echo -e "${result}\n"
    cmd_file=${out_date_dir}/$(echo ${line} | sed -e 's/ /_/g').txt
    touch ${cmd_file}
    echo -e "${result}\n" >> ${cmd_file}
  fi
done < $dcos_debug_cmd_pathname


