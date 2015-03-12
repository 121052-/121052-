echo Enter file name
read file
echo do you want to change read write permission?
read l
if (l=='Y' || l=='y')
then
chmod g+rw $file
echo permission changed
else
echo abort operation
fi


