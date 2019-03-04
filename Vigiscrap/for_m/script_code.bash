#!/usr/bin/env bash
name="containers"
name2="profil"
id=$1
path="sav/"
extension=".html"
gcc news_container.c -o $name
# echo "Resultats" > result.csv
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
#nb_time=13
echo -e "Timeline, Container, Proprio, Date, Text, Titre, Auteur, Nb_comm, Image_profil" > result.csv
while [ 1 ]
do
	nb_time=$(($nb_time-1))
	# echo ./a.out $path$id.$nb_time.timeline$extension
	./$name $path$id.$nb_time.timeline$extension $((nb_time+1)) >> result.csv
	if [ "$nb_time" -eq "0" ]
	then
		break
	fi
done
gcc news_profil.c -o $name2
./$name2 $path$id.profile$extension >> result.csv