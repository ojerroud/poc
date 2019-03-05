#!/usr/bin/env bash

rm -rf sav
path="sav/"

getUserById()
{
	id=$1
	cookies=$2

	2>&- curl "https://m.facebook.com/profile.php?id=$id" -H 'authority: m.facebook.com' -H 'cache-control: max-age=0' -H 'upgrade-insecure-requests: 1' -H 'user-agent: Mozilla/5.0 (Macintosh; Intel Mac OS X 10_12_6) AppleWebKit/603.3.8 (KHTML, like Gecko) Version/10.1.2 Safari/603.3.8' -H 'accept: text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,image/apng,*/*;q=0.8' -H 'accept-language: en-US,en;q=0.9' -H "$cookies" --compressed
}

getPage()
{
	uri=$1
	cookies=$2

	2>&- curl "https://m.facebook.com$uri" -H 'authority: m.facebook.com' -H 'cache-control: max-age=0' -H 'upgrade-insecure-requests: 1' -H 'user-agent: Mozilla/5.0 (Macintosh; Intel Mac OS X 10_12_6) AppleWebKit/603.3.8 (KHTML, like Gecko) Version/10.1.2 Safari/603.3.8' -H 'accept: text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,image/apng,*/*;q=0.8' -H 'accept-language: en-US,en;q=0.9' -H "$cookies" --compressed
}

getTimelineUrlByProfileSrc()
{
	echo $1 | grep -ioE '<a href="[^"]+"[^>]+>Journal</a>' | grep -oE '"/[^"]+"' | grep -oE '/[^"]+'
}

getDisplayMoreUrlByTimelineSrc()
{
	echo $1 | grep -ioE '<a[^>]+>afficher plus</a>' | grep -oE '"/[^"]+"' | grep -oE '/[^"]+'
}

getYearsUrlByTimelineSrc()
{
	echo $1 | grep -ioE '<a[^>]+>[0-9]{4}</a>' | grep -ioE '"/[^"]+"' | grep -ioE '/[^"]+'
}

id=$1
extension=".html"
cookies=$2 
echo "GETUSER#$id"

if [ ! -d "$path" ]; then
	mkdir $path
fi

profile_src=`getUserById "$id" "$cookies"`
echo $profile_src > "$path$id.profile$extension"

timeline_url=`getTimelineUrlByProfileSrc "$profile_src"`

# echo "===START===" > $id
I=0

while [ 1 ]
do
	timeline_url=`echo "$timeline_url" | sed 's/&amp;/\&/g'`
	timeline_src=`getPage "$timeline_url" "$cookies"`
	# echo "$timeline_src" > "$path$id.timeline$extension"
	echo "$timeline_src" > "$path$id.$I.timeline$extension"
	timeline_url=$(getDisplayMoreUrlByTimelineSrc "$timeline_src")
	I=$(($I+1))
	if [[ -z "$timeline_url" ]]
	then
		break
	fi
done

for yearUrl in `getYearsUrlByTimelineSrc "$timeline_src"`
do
	timeline_url="$yearUrl"
	while [ 1 ]
	do
		timeline_url=`echo "$timeline_url" | sed 's/&amp;/\&/g'`
		timeline_src=`getPage "$timeline_url" "$cookies"`
		# echo "$timeline_src" > "$path$id.timeline$extension"
		echo "$timeline_src" > "$path$id.$I.timeline$extension"
		timeline_url=$(getDisplayMoreUrlByTimelineSrc "$timeline_src")
		I=$(($I+1))
		if [[ -z "$timeline_url" ]]
		then
			break
		fi
	done
done
echo $I > nb_time_shell

# echo "===END===" >> $id
