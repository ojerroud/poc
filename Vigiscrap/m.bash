#!/usr/bin/env bash
facebook=$1
key=$2
cookie='cookie: datr=bjYGXAgvssLqBJjL-UngKTNv; noscript=1; sb=dDYGXLbhCHI9e0d8HAMnkji-; c_user=100025777429176; xs=38%3Au6gA28VBFDGZxw%3A2%3A1543911373%3A15540%3A16189; fr=1cgKrn8h179dDxVal.AWUOTLT_yqztYpf7Zl07CUCatVA.BcBjZu.cI.AAA.0.0.BcBjfL.AWV8QpTo; pl=n'

getId()
{
	cookie=$2

	2>&- curl $facebook -H 'authority: m.facebook.com' -H 'cache-control: max-age=0' -H 'upgrade-insecure-requests: 1' -H 'user-agent: Mozilla/5.0 (Macintosh; Intel Mac OS X 10_12_6) AppleWebKit/603.3.8 (KHTML, like Gecko) Version/10.1.2 Safari/603.3.8' -H 'accept: text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,image/apng,*/*;q=0.8' -H 'accept-language: en-US,en;q=0.9' -H "$cookie" --compressed
}

id=`getId "$facebook" "$cookie" | grep -Eo '.{0,0}entity_id".{0,20}' | sed -n -e '/"/,/"}/ p' | cut -d'"' -f2- | sed -e 's/\(^.*"\)\(.*\)\(",.*$\)/\2/'`


if [ "$key" == "all" ]
then
	bash for_m/script_scrap.bash "$id" "$cookie"
	bash for_m/script_code.bash $id
	exit 0
fi
if [ "$key" == "scrap" ]
then
	bash for_m/script_scrap.bash "$id" "$cookie"
	exit 0
fi
if [ "$key" == "clean" ]
then
	rm -rf res sav exe nb_time_shell 
	exit 0
fi
if [ "$key" == "parse" ]
then
	bash for_m/script_code.bash $id
	exit 0
fi
echo "usage: bash m.bash \$[lien de la page facebook] [all/scrap/parse/clean]"