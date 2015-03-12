 read file
l=`wc -l $file|cut -d " " -f 1`
//echo $l
count=0
coch=0
for (( i=1; i<=l; i++))
do
        n=1
        line=`head -$i $file|tail -1`
       // echo $line
        ch=`echo $line|cut -c $n`
       // echo character is $ch
        while [ "$ch" != "" ]
        do
                if [ "$ch" = " " ]
                then
                count=`expr $count + 1`
                else
                coch=`expr $coch + 1`
                fi
                n=`expr $n + 1`
                ch=`echo $line|cut -c $n`

        done
done
echo no. of space $count
echo no. of characters $coch

