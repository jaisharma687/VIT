echo "Enter the number to check if it's a palindrome"
read n
original=$n
rev=0
while [ $n -gt 0 ]
do
    rem=$((n % 10))
    rev=$((rev * 10 + rem))
    n=$((n / 10))
done
if [ $original -eq $rev ]; then
    echo "$original is a palindrome"
else
    echo "$original is not a palindrome"
fi