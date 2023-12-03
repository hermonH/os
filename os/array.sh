#!/bin/bash
array=(1 2 "you" 3.4)
echo " at third index ${array[3]}"
echo "${#array[*]}"
array+=("hello" 4)
echo "${array[*]}"
