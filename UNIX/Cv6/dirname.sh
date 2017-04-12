#!/bin/bash

function dirname {
	file=$1

	if [ -d $file ] && [ ${#file} -ne 1 ]; then
		file=${file%?}
	fi

	dir=`echo $file |tr "/" "\n" |head -n -1 |tr "\n" "/"`

	if [ ${#dir} -gt 1 ]; then
		dir=${dir%?}
	fi

	if [ "$dir" == "" ]; then
		dir="."
	fi

	echo $dir
}

dirname $1