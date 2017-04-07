#!/bin/bash

function basename {
	path=$1

	if [ -d $path ] && [ ${#path} -ne 1 ] && [ "${path:${#path} - 1}" == "/" ]; then
		path=${path%?}
	fi

	file=`echo $path |tr "/" "\n" |tail -n 1 |tr "\n" "/"`
	file=${file:0:-1}

	if [ "$file" == "" ]; then
		file="/"
	fi

	echo $file
}

basename $1