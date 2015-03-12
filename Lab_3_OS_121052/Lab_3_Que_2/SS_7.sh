//seventh: 7. Write a shell script which displays January if we enter Jan, Janu, Janua or January.(use of case)
echo Enter a word
read mon;
case $mon in
jan|janu|janua|january) echo january ;;
*) echo invalid word ;;
esac
