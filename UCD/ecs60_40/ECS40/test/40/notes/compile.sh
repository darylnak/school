#! /bin/bash

for arg in $@ ; do
  rm a.out 2> /dev/null

  if [ ! -r $arg ] 
  then 
    echo $arg is not readable
  else
    if [[ $arg == *.c ]] 
    then
      if gcc $arg
      then
        a.out
      else
          echo $arg did not compile
      fi # if compiling worked
    elif [[ $arg == *.cpp ]] 
    then
      g++ $arg
      if test -e a.out
        then
          a.out
      fi # if a.out exists
    else
      echo $arg is not a C or C++ file
    fi # if arg is .c
  fi # if readable
done 
