#!/bin/bash
num=$#
echo $num
if [ "$num" -gt 3 ]; then
  echo "$num"  is greater than 3
  exit 1
elif [ "$num" -gt 2 ]; then
  echo "$num"  is greater than 2
  exit 0
elif [ "$num" -gt 1 ]; then
  echo "$num" is greater than 1
  exit 1
else
  echo "$num" is euqal to 1
fi



