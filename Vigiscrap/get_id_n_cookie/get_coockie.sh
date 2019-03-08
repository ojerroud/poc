wget -U Mozilla/ \
     --delete-after \
     --keep-session-cookies \
     --save-cookies cookies.txt \
     --post-data 'user=foo&password=bar' \
     $1


wget -U Mozilla -O webp.txt $1
cat webp.txt | grep -Eo '.{0,0}entity_id".{0,20}' | sed -n -e '/"/,/"}/ p' | cut -d'"' -f2- | sed -e 's/\(^.*"\)\(.*\)\("}.*$\)/\2/'