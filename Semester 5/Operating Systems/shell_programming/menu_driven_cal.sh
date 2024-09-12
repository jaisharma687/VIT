echo enter the 2 values
read a
read b
echo 1. Addition 2. Subtraction 3. Multiplication 4. Division
echo enter your choice
read ch
case $ch in
	1)
		c=`expr $a + $b`
		echo sum of two numbers = $c
		;;
	2)
		c=`expr $a - $b`
		echo subtraction of two numbers = $c
		;;
	3)
		c=`expr $a \* $b`
		echo multiplication of two numbers = $c
		;;
	4)
		c=`expr $a / $b`
		echo division of two numbers = $c
		;;
	*)
		echo Invalid choice
		;;
esac
