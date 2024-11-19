echo "Enter the number to check if it's a prime number"
read n
is_prime=1
if [ $n -lt 2 ]; then
    is_prime=0
else
    for((i=2;i*i<=n;i++))
    do
        if [ $((n % i)) -eq 0 ]; then
            is_prime=0
            break
        fi
    done
fi
if [ $is_prime -eq 1 ]; then
    echo "$n is a prime number"
else
    echo "$n is not a prime number"
fi