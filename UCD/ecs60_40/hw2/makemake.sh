#!/bin/bash

name=null

if [ $# -eq 0 ]; then
  echo "Executable name required."
  echo "usage: makemake.sh executable_name"
  #echo "makemake.sh appt.out: "
  exit 0
else
  name=$1
  echo -n "$1 : " > Makefile
  for file in $(ls *.cpp 2> /dev/null | sort); do
    echo -n "${file%.cpp*}.o " >> Makefile
  done
  echo >> Makefile
  echo -ne '\t' >> Makefile
  echo -n "g++ -ansi -Wall -g -o " >> Makefile
  for arg in $#; do
    echo -n "$@ " >> Makefile
  done
  for file in $(ls *.cpp 2> /dev/null | sort); do
    echo -n "${file%.cpp*}.o " >> Makefile
  done
  shift
  echo >> Makefile
  for file in $(ls *.cpp 2> /dev/null | sort); do
    echo >> Makefile
    echo -n "${file%.cpp*}.o : " >> Makefile
    echo -n "$file " >> Makefile
    echo $(awk -F '"' '/\.h"/ {print $2}' $file) >> Makefile
    echo -ne '\t' >> Makefile
    echo -n "g++ -ansi -Wall -g -c " >> Makefile
    for arg in $#; do
      echo -n "$@ " >> Makefile
    done
    echo -n "$file" >> Makefile
    echo >> Makefile
  done
  echo >> Makefile
  echo "clean : " >> Makefile
  echo -ne '\t' >> Makefile
  echo -n "rm -f $name ">> Makefile
  for file in $(ls *.cpp 2> /dev/null | sort); do
    echo -n "${file%.cpp*}.o  " >> Makefile
  done
fi
