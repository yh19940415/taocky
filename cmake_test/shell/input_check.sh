#!/bin/bash
debug_cmd_pathname=""
output_directory=""
count=0

#1.parse input arguments
while getopts ":f:o:n:" opt
do
    case $opt in
        f)
            debug_cmd_pathname=$OPTARG
        ;;
        o)
            output_directory=$OPTARG
        ;;
        n)
            count=$OPTARG
        ;;
        ?)            
        echo -e "未知参数\n exit -1"
        exit -1;;
    esac
done

if [[ ! -n ${debug_cmd_pathname} || ! -n ${output_directory} || ${count} -eq 0 ]]; then
    echo -e "input is worng\n  debug_cmd_pathname ${debug_cmd_pathname}\n  output_directory ${output_directory}\n  conut ${count}"
    echo "exit -1"
    exit -1
fi

