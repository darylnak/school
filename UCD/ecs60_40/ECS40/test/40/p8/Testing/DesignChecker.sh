#!  /bin/bash

testerDirectory="/home/ssdavis/40/p8/Testing"

if [ $# -ne 2 ]; then
  >&2 echo "usage DesignChecker.sh: $testerDirectory/DesignChecker.sh p8_directory operation_score"
  exit
fi

if [[ $1 =~ Testing ]]; then # Use from this directory is not allowed
  >&2 echo "You may not use Testing as your own source directory!"
  exit
fi

cd $1

rm -f designResults.txt *.o
designError=0
dos2unix indexpager.cpp indexpager.h &> /dev/null

grep "/\*" indexpager.cpp > temp
if [ -s temp ]; then
  cat temp >> designResults.txt
  echo 'Fatal design error: "/*" found.' >> designResults.txt
  (( ++designError ))
fi

if egrep "(struct |stdio|string\.h|stdlib\.h|malloc|free|fopen)" indexpager.cpp >& /dev/null ; then
  echo 'Fatal design error: struct, stdio, string.h, stdlib.h, malloc, free,' >> designResults.txt
  echo 'or fopen found in file(s).' >> designResults.txt
  (( +designError ))
fi

if  grep " \[" indexpager.cpp indexpager.h  >& /dev/null   ; then
  echo 'Fatal design error: "[" found.'  >> designResults.txt
  (( ++ designError ))
fi

if grep "c_str" indexpager.cpp  >& /dev/null  ; then
  echo 'Fatal design error: "c_str" found.'  >> designResults.txt
  (( ++ designError ))
fi

if grep "char" indexpager.cpp indexpager.h >& /dev/null ; then
  echo 'Fatal design error: "char" found.'  >> designResults.txt
  (( ++ designError ))
fi

if ! grep "map.*< *string *, *int.*>" indexpager.cpp indexpager.h >& /dev/null ; then
  echo 'Fatal design error: no map of string to int found.'  >> designResults.txt
  (( ++ designError ))
fi


if ! grep "multimap.*<.*,.*>" indexpager.cpp indexpager.h >& /dev/null ; then
  echo 'Fatal design error: no multimap found.'  >> designResults.txt
  (( ++ designError ))
fi
# non-fatal design errors from here on

if ! grep "const_iterator" indexpager.cpp >& /dev/null ; then
  echo 'No "const interator" found.'  >> designResults.txt
fi

echo $designError  # Only standard out

