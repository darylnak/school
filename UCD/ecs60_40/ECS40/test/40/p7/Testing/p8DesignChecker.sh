#!  /bin/bash

testerDirectory="/home/ssdavis/40/p8/Testing"

if [ $# -ne 1 ]; then
  >&2 echo "usage p8DesignChecker.sh: $testerDirectory/p8DesignChecker.sh simulator.out_directory"
  exit
fi

if [[ $1 =~ Testing ]]; then # Use from this directory is not allowed
  >&2 echo "You may not use Testing as your own source directory!"
  exit
fi

cd $1

rm -f designResults.txt
designError=0
dos2unix *.cpp *.h &> /dev/null

grep "/\*" scrabble.cpp > temp
if [ -s temp ]; then
  cat temp >> designResults.txt
  echo 'Fatal design error: "\*" found.' >> designResults.txt
  ((++designError))
fi

grep "set *< *Word *>" scrabble.cpp > temp
if [ ! -s temp ]; then
  echo "Fatal design error: set <Word> not found." >> designResults.txt
  echo "Zero for assignment." >> designResults.txt
  ((++designError))
fi


egrep -v "(fstream|values)" scrabble.cpp | grep "\[" > temp
if [ -s temp ]; then
  echo 'Fatal design error: "[" found that is not involved with "values" or in opening a file.' >> designResults.txt
  echo "Zero for assignment." >> designResults.txt
  ((++designError))
fi

egrep "map *< *char, *short *>" scrabble.cpp   > temp
if [ ! -s temp ]; then
  echo 'Fatal design error: map <char, short> not found.' >> designResults.txt
  echo "Zero for assignment." >> designResults.txt
  ((++designError))
fi

egrep "(rotate|next_permutation)" scrabble.cpp   > temp
if [ ! -s temp ]; then
  echo 'Fatal design error: rotate or next_permutation not found.' >> designResults.txt
  echo "Zero for assignment." >> designResults.txt
  ((++designError))
fi

# non-fatal designerrors from here on


echo $designError  # Only standard out

