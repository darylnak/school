#!/bin/bash

for file in *.c; do
  sed -i '/^\/\*/,/^\*\/$/d' $file
done
