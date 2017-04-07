#!/bin/bash

from=$1
increment=$2
to=$3

if [ "$#" == "2" ]; then
        increment=1
        from=$1
        to=$2
elif [ "$#" == "1" ]; then
        from=1
        to=$1
        increment=1
fi

tmp=" "
if [ $from -gt $to ]; then
        for ((i=$from; i>=$to; i=i+$increment)); do
                tmp+=$i
                tmp+=,
        done
else
        for ((i=$from; i<=$to; i=i+$increment)); do
                tmp+=$i
                tmp+=,
        done
fi
r=${tmp:0:-1}
echo $r