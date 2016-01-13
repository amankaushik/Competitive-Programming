op=$(diff aux/output.out aux/expectedOutput.out)
if [ "$op" != "" ]
then
	echo "Output Not as expected."
	echo $op
else 
	echo "Output as expected."
fi