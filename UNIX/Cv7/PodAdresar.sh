#!/bin/bash

for i in {00..9999}; do
	photo=fotky/XYZ${i}.jpg
	if [ -e $photo ]; then
		date=`cat $photo`
		file=`paste -d "/" <(echo $date | cut -f3 -d "/") <(echo $date | cut -f1 -d "/") <(echo $date | cut -f2 -d "/")`

		mkdir -p PodAdresar/$file
		cp $photo PodAdresar/$file/
	fi
done
