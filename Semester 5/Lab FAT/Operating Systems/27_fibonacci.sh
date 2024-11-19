echo "enter the number of terms"
read n
a=1
b=0
c=0
echo Fibonacci Series:
for((i=1;i<=n;i++))
do
echo $c
c=`expr $a + $b`
a=$b
b=$c
done