#!/bin/bash
read str
n=${#str}
a=0
let b=n-1
let n=n/2
for (( i=1;i<=n;i++ ))
do
	if [[ ${str:a:1} != ${str:b:1} ]]
	then
		echo "Not palindrome"
		exit 1
	fi
	let a++
	let b--
done
echo "Palindrome"
