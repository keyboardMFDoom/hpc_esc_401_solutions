#!/bin/bash
( for F in *.csv ; do cat $F | ./mapper3.py ; done ) | sort | ./reducer3.py >> results
