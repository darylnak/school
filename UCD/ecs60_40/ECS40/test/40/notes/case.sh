#! /bin/bash

while [ $# -gt 0 ] ; do
  case $1 in 
    *.tar.gz) echo $1 is gzipped tar ;; 
    *.Z) echo $1 is compressed ;; 
    *.cpp | *.c ) echo $1 is C based ;;
    parameters.sh) echo $1 is parameters.sh ;;
    *.tar) echo $1 is just tarred ;; 
    *.tar.Z) echo $1 compressed tar ;; 
    *) echo echo $1 is neither compressed nor tarred 
  esac 

  shift
done # while

