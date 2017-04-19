#!/bin/bash

for file in *.c; do
  sed '/^\/\*/,/^\*\/$/d' $file
done
