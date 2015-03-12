echo "Enter basic salary : "
read salary
echo Enter percentage of HRA;
read per;

fin=`echo  $salary \* $per / 100 | bc`

echo "Gross salary is : $fin"
