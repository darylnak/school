#!/bin/bash

for file in *.c; do
  if grep -Ehq '^(printf|fprintf)' $file; then
    if !(grep -q "#include <stdio.h>" $file); then
      touch ${file}Temp
      echo "#include stdio.h" > ${file}Temp
      cat $file >> ${file}Temp
      rm $file
      mv ${file}Temp $file
    fi
  fi
done
