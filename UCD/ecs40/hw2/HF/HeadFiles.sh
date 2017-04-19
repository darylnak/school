#!/bin/bash

if [ $# -eq 0 ]; then
  for file in *.txt; do
    echo "Displaying first 3 lines of $file:"
    head -n 3 $file
    echo
    read -p "Delete file $file? (y/n) " choice
    if [ "$choice" == "y" ]; then
      rm $file
    else
      continue;
    fi
  done
else
  for arg in $@; do
    echo "Displaying first 3 lines of $arg:"
    head -n 3 $arg
    echo
    read -p "Delete file $arg? (y/n) " choice
    if [ "$choice" == "y" ]; then
      rm $arg
    else
      continue;
    fi
  done
fi
