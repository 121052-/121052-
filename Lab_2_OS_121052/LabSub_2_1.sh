ch='y'
while [ $ch = 'y' -o $ch = 'Y' ]
do
        s=0
        n=0
        flag=0
        while [ $flag -eq 0 ]
        do
                echo -n "ENTER THE NO:="
                read n
                if [ $n -lt 50 ]
                then
                        flag=1
                else
                        echo "NUMBER MUST BE LESS THEN 50"
                fi
        done 
   s=0
        s=`expr $n \* $n`
        echo "THE SQUARE OF $n IS:= $s"
        echo "DO YOU WANT TO CONTINUE PRESS:= Y/N"
        read ch
done
