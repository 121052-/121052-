//Last
echo Enter array limit
read limit
echo Enter elements
n=1
while [ $n -le $limit ]
do
read num
eval arr$n=$num
n=`expr $n + 1`
done
echo Enter key element
read key
10. Write a shell script program to search whether element is present in the list or not and also display its position in the list. 
low=1
high=$n
found=0
while [ $found -eq 0 -a $high -gt $low ]
do
mid=`expr \( $low + $high \) / 2`
eval t=\$arr$mid
if [ $key -eq $t ]
then
found=1
elif [ $key -lt $t ]
then
high=`expr $mid - 1`
else
low=`expr $mid + 1`
fi
done

if [ $found -eq 0 ]
then
echo Unsuccessfull search
else
echo Successfull search
fi
