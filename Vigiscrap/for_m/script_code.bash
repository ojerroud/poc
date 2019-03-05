#!/usr/bin/env bash
path_src="src"
path_exe="exe"
path_res="res"
name1="containers"
name2="profil"
id=$1
path="sav/"
extension=".html"
nb_time=$(<nb_time_shell)
nb_time_total=$((nb_time))

if [ ! -d "$path_src" ]; then
	mkdir $path_src
fi
if [ ! -d "$path_res" ]; then
	mkdir $path_res
fi
if [ ! -d "$path_exe" ]; then
	mkdir $path_exe
fi

gcc $path_src/news_container.c -o $path_exe/$name1
gcc $path_src/news_profil.c -o $path_exe/$name2
echo -e "Timeline, Container, Proprio, Date, Text, Titre, Auteur, Nb_comm, Image_profil" > $path_res/result.csv
while [ 1 ]
do
	nb_time=$(($nb_time-1))
	./$path_exe/$name1 $path$id.$nb_time.timeline$extension $((nb_time+1)) >> $path_res/result.csv
	if [ "$nb_time" -eq "0" ]
	then
		break
	fi
done
./$path_exe/$name2 $path$id.profile$extension >> $path_res/result.csv