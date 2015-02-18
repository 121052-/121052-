echo Enter number
read n
sum=0
i=1
while [$i -le $n ];
do
sum=` expr $sum + $i `
i=` expr $i + 1`
done
echo $sum

sum=0
i=1
for i in `seq 1 $n`;
do
sum=` expr $sum + $i `
done
echo $sum
