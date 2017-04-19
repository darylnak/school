#!/bin/bash

for file in *.c; do
  if grep -Ehq '^(printf|fprintf)' $file; then
    if !(grep -q "#include <stdio.h>" $file); then
      sed -i '' '1s/.*/#include <stdio.h>\n/' $file
    fi
  fi
done
