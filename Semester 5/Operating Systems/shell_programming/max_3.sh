echo enter 3 values
read a
read b
read c
if [ $a -gt $b ] && [ $a -gt $c ]; then
	echo "the greatest value is " $a
elif [ $b -gt $c ]; then
	echo "the greatest value is " $b
else 
	echo "the greatest value is " $c
fi

