#! /bin/bash

if [ $# -ne 1 ]; then
  echo "usage: cppChecker.sh directory_name"
  exit 1
fi
python ~ssdavis/40/cppstyle/nsiqcppstyle.py -f ~ssdavis/40/cppstyle/filefilter.txt --no-update $@

