#!/bin/bash

sudo ./dcos.sh $1 $2 $3 $4
state=$?
if [ $state == 0 ]; then
  echo run success
elif [ $state == 1 ]; then
  echo run error
else
  echo "can not match return code"
fi
echo $?

