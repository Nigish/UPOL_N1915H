#!/bin/bash

cat $1

while read line
do
	if [[ $line == *"-"* ]];
	then
		from=$( cut -d '-' -f 1 <<< "$line" )
		to=$( cut -d '-' -f 2 <<< "$line" )
		echo $from
		echo $to
		for (( from; from <= to; from++ ))
		do
			sed "${from}q;d" $1
		done
	else
		sed "${line}q;d" $1
	fi
done