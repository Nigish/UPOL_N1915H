#!/bin/bash

for i in {0001..1000}; do
	day=$(($RANDOM%30 + 1))
	month=$(($RANDOM%11 + 1))
	year=$(($RANDOM%100 + 1970))
	#format pro 01.02.2017
	print=$(printf %02d.%02d.%02d $day $month $year)
	echo $print >> files/$i
	#format pro 1.2.2017
	#echo $day/$month/$year > files/$i
done