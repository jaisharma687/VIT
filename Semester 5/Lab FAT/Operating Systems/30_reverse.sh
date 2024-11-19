echo enter the number
read n
rev=0
while((n>0))
do
	rem=`expr $n % 10`
	temp=`expr $rev \* 10`
	rev=`expr $rem + $temp`
	n=`expr $n / 10`
done
echo result = $rev