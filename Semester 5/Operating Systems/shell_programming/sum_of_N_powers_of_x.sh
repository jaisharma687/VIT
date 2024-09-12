echo enter values of x and n
read x
read n
sum=1
pow=1
for((i=1;i<=n;i++))
do
	pow=`expr $pow \* $x`
      	sum=`expr $sum + $pow`
done
echo result = $sum
