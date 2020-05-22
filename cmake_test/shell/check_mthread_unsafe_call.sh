#!/bin/bash

output_directory=./
code_pathname=""
unsafe_func_pathname=""

#1.parse input arguments
while getopts ":f:c:" opt
do
    case $opt in
        c)
            code_pathname=$OPTARG
        ;;
        f)
            unsafe_func_pathname=$OPTARG
        ;;
        ?)
        echo "未知参数"
        exit 1;;
    esac
done

#2.check the input arguments
if [ "${code_pathname}" == "" ] || [ "${unsafe_func_pathname}" == "" ]; then
echo -e "input arguemnts error:\n  -c code pathname\n  -f unsafe func pathname\n"
exit -1
fi
echo thread unsafe functions: \"${unsafe_func_pathname}\"
echo -e "search in source code:  \"${code_pathname}\" \n\n"

#3.grep info show and storage
out_date_dir=${output_directory}/$(date +%Y_%m_%d_%H_%M)_check_thread_unsafe
mkdir ${out_date_dir}
result=""
while read line
do
  echo ${line} func match cases
  result=$(grep "${line}(" ${code_pathname}/* -nR)
  if [ "${result}" != "" ]; then
    echo -e "${result}\n"
    touch ${out_date_dir}/$line.txt
    echo -e "${result}\n" >> ${out_date_dir}/$line.txt
  fi
done < $unsafe_func_pathname
