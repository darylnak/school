#!  /bin/bash

testerDirectory="/home/ssdavis/40/p7/Testing"

if [ $# -ne 1 ]; then
  >&2 echo "usage p7DesignChecker.sh: $testerDirectory/p7DesignChecker.sh simulator.out_directory"
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

grep "/\*" editor.cpp > temp
if [ -s temp ]; then
  cat temp >> designResults.txt
  echo 'Fatal design error: "\*" found.' >> designResults.txt
  ((++designError))
fi

grep "#include *<" editor.cpp | grep -v "< *string *>" | grep -v "< *iostream *>" \
  | grep -v "< *fstream *>" | grep -v "< *vector *>" > temp
if [ -s temp ]; then
  echo 'Fatal design error: "#include<" other than string, iostream, fstream, and vector found.' >> designResults.txt
  cat temp >> designResults.txt 
  echo "Zero for assignment." >> designResults.txt
  ((++designError))
fi


egrep -v "(open|fstream)" editor.cpp | grep -n "\[" > temp
if [ -s temp ]; then
  echo 'Fatal design error: "[" found that is not involved in opening a file.' >> designResults.txt
  cat temp >> designResults.txt 
  echo "Zero for assignment." >> designResults.txt
  ((++designError))
fi

egrep -n "(\.|->)at" editor.cpp   > temp
if [ -s temp ]; then
  echo 'Fatal design error: .at or ->at found.' >> designResults.txt
  cat temp >> designResults.txt
  echo "Zero for assignment." >> designResults.txt
  ((++designError))
fi

# non-fatal designerrors from here on


grep -v "^ *//" editor.cpp | awk '/main *\(/,/}/' | grep "vector *< *string *>" > temp
if [ ! -s temp ]; then
  echo 'Design error: vector <string> not found in main()' >> designResults.txt
fi

grep -v "^ *//" editor.cpp | grep "int *main *( *int.*char *\*.*)" > temp
if [ ! -s temp ]; then
  echo 'Design error: command line parameters not found in main()' >> designResults.txt
fi

echo $designError  # Only standard out

