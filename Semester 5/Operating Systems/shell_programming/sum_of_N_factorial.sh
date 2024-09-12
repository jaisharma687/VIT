echo enter the value of n
read n
sum=0
fact=1
for((i=1;i<=n;i++))
do
	fact=`expr $fact \* $i`
	sum=`expr $sum + $fact`
done
echo result is = $sum
