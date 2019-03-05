#!/usr/bin/env bash
key=$2
id=$1

if [ "$key" == "scrap" ]
then
 	for_m/script_scrap.bash $id 'cookie: datr=bjYGXAgvssLqBJjL-UngKTNv; noscript=1; sb=dDYGXLbhCHI9e0d8HAMnkji-; c_user=100025777429176; xs=38%3Au6gA28VBFDGZxw%3A2%3A1543911373%3A15540%3A16189; fr=1cgKrn8h179dDxVal.AWUOTLT_yqztYpf7Zl07CUCatVA.BcBjZu.cI.AAA.0.0.BcBjfL.AWV8QpTo; pl=n'
	exit 0
fi
if [ "$key" == "clean" ]
then
	rm -rf res sav exe nb_time_shell 
	exit 0
fi
if [ "$key" == "parse" ]
then
	for_m/script_code.bash $id
	exit 0
fi
echo "usage: bash m.bash \$id [scrap/clean/parse]"