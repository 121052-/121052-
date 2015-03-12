//Fourth: 4. Write a shell script to find greatest of two. Script must consider the case where two numbers are equal.

echo Enter a number;
read a;
echo Enter another number;
read b;
if [ $a = $b ]
then
echo both are equal;
elif [  $a -gt $b ]
then
echo $a is greater;
else
echo $b is greater;
fi
