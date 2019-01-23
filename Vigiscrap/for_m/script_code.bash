#!/usr/bin/env bash
id=$1
path="sav/"
extension=".html"
gcc news_container.c
echo - > result.csv
#echo "1-----1" >> test1
#./a.out 100001596874228.0.timeline >> test1
#echo "2-----2" >> test1
#./a.out 100001596874228.1.timeline >> test1
#echo "3-----3" >> test1
#./a.out 100001596874228.2.timeline >> test1
#echo "4-----4" >> test1
#./a.out 100001596874228.3.timeline >> test1
#echo "5-----5" >> test1
#./a.out 100001596874228.4.timeline >> test1
nb_time=$(<nb_time_shell)
nb_time_total=$((nb_time))
nb_time=$((nb_time))
#nb_time=13
while [ 1 ]
do
	echo -e "\n\n$nb_time"-----"$nb_time_total\n" >> result.csv
	nb_time=$(($nb_time-1))
	./a.out $path$id.$nb_time.timeline$extension >> result.csv
	if [ "$nb_time" -eq "0" ]
	then
		break
	fi
done
echo ":)"
gcc news_profil.c
./a.out $path$id.profile$extension >> result.csv