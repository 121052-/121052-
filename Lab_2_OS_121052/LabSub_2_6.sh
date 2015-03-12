 d=`date|cut -d " " -f 4|cut -d ":" -f 1`
if [ $d -gt 4 -a $d -lt 12 ]
then
echo Good Morning
elif [ $d -gt 12 -a $d -lt 16 ]
then
echo Good Afternoon
elif [ $d -gt 16 -a $d -lt 20 ]
then
echo Good Evening
else
echo Good Night
fi
