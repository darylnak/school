#! /bin/bash

for file in *.c ; do
  egrep "(^printf|[^a-eg-zA-Z]printf|fprintf)" $file > temp
  if [ -s temp ]; then
    grep "#include *<stdio.h>" $file > temp

    if [ ! -s temp ]; then
      echo "#include <stdio.h>" > temp
      cat $file >> temp
      mv temp $file 
    fi      
  fi
done
