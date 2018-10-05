#! /bin/bash

echo Number of arguments: $#
echo 'Zeroth argument, $0: ' $0 
echo 'First argument, $1: ' $1  
echo 'Second argument, $2: ' $2
echo 'All arguments, $*: ' $* ' $@:' $@ 
shift
echo 'New arguments: $0 = ' $0 ' $1 = ' $1  
echo 'New all args = ' $@

