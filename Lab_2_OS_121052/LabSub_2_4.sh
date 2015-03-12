echo Enter a number to know whether it is prime or not
flag=0
read a;
for (( i=2; i<a; i++ ))
do
b=`expr $a % $i`
if [ $b -eq 0 ]
then
flag=1
fi
done
if [ $flag -eq 1 ]
then
echo composite number
else
echo prime number
fi
