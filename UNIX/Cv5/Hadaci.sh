#!/bin/bash

bot=0;
top=100;
puvcislo=0;

while true; do
cislo=$(shuf -i $bot-$top -n 1);
if [ "$cislo" -eq "$puvcislo" ]
	then echo "=$cislo"
	cor="";
	read cor;
	case "$cor" in
	"Y") break;;

esac
puvcislo=0;
fi;
echo "<$cislo?";
answer="";
read answer;

case "$answer" in
	"Y") top=$cislo ;;
	"N") bot=$cislo ;;
esac
puvcislo=$cislo;
done
echo "WIN";