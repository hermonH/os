read -p "Enter string : " str1
str1=$(sed 's/ //g' <<< $str1)
str1=$(sed 's/,//g' <<< $str1)
str1=$(sed 's/-//g' <<< $str1)
str1=$(sed 's/?//g' <<< $str1)
str1=$(sed "s/'//g" <<< $str1)
str=$(sed 'y/ABCDEFGHIJKLMNOPQRSTUVWXYZ/abcdefghijklmnopqrstuvwxyz/' <<< $str1) 
rev=""
len=${#str}
i=$((len-1))
while [ $i -ge 0 ]
do
	rev+=${str:i:1}
    i=$((i-1))
done
if [ $str == $rev ]
then
	echo It is a palindrome
else
	echo It is not a palindrome
fi
