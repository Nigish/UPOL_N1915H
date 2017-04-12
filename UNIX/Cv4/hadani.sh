#!/bin/bash

from=$1
to=$2

if [ "$#" == "1" ]; then
	from=0
	to=$1
elif [ "$#" == "0" ]; then
	from=0
	to=100
fi

guess=$(shuf -i 0-100 -n 1)
echo "$guess"

while true; do
	answer=""
	znak=""
	read answer

	znak=${answer:0:1}
	cislo=${answer:1:-1}

	if [ "$znak" == ">" ] && [ "$guess" -gt "$cislo" ];
		then echo "TRUE"
	elif [ "$znak" == "<" ] && [ "$guess" -lt "$cislo" ];
		then echo "TRUE"
	elif [ "$znak" == "=" ] && [ "$guess" == "$cislo" ]; 
		then echo "YOU WIN!"
		break
	else echo "FALSE"
	fi
done
