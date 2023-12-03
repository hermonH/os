#!/bin/bash
mystr="Hello world"
length=${#mystr}
echo "$length"
lower=${mystr,,}
echo "$lower"
newstr=${mystr/world/universe}
echo "$newstr"
echo "$mystr"
echo "${mystr:5:5}"
