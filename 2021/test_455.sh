#!/bin/bash
res_1=$(cat 455_input_1.txt | python 455.py)
true_res_1=$"3 3\n3 4\n"
echo "$res_1"
echo "$true_res_1"
if [ "$res_1" != "$true_res_1" ]; then
  echo "fail"
fi
# cat 455_input_2.txt | python 455.py