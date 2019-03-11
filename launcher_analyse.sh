#!/usr/bin/env sh
path_src='src'
path='res'
name='result.csv'
if [ ! -d "$path" ]; then
	mkdir $path
fi
python3 $path_src/main.py