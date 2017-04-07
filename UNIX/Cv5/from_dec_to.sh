#!/bin/bash

to_dec() {
	num=$(printf '%d\n' "'$1")
	x=55
	y=10

	rozsah='^[0-9]+$'
	if [[ $1 =~ $rozsah ]] &&[ "$1" - lt "y" ]; 
		then
		echo $1
	else
		echo $((num - x))
	fi
}
#to_dec "A"

from_dec() {
	echo " "$2" o "$1" p" | dc
}
from_dec $1 $2
#from_dec 255 16
