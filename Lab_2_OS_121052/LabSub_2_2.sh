echo Enter any character;
read a;
b= grep $a test.sh;
if [ $? -eq 0 ]
then              
echo character found ;
fi
