#!/usr/bin/env sh
path='res'
name='result.csv'
if [ ! -d "$path" ]; then
	mkdir $path
fi
python3 spacy_test_working.py