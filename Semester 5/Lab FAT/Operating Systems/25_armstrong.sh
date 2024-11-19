echo enter the number to check if its an armstrong number
read n
a=$n
s=0
while [ $n != 0 ]
do
	x=$((n % 10))
	y=$((x * x * x))
	s=$((s + y))
	n=$((n / 10))
done
if [ $a == $s ]; then
	echo "its an armstrong number"
else
	echo "its not an armstrong number"
fi