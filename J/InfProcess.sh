proc () 
{
	while :
	do
		echo $1
		sleep 1
	done
}

proc p1 &
proc1_id=$!

proc p2 &
proc2_id=$!

sleep 3
echo $proc1_id $proc2_id
kill $proc2_id
kill $proc1_id
