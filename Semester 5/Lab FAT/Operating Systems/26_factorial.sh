echo "enter the no to find the factorial"
read n
f=1
for((i=1;i<=n;i++))
do
f=$(expr $f \* $i)
done
echo "the factorial of " $n " is " $f