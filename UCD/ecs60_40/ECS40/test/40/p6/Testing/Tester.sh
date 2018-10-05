#! /bin/bash

testerDirectory="/home/ssdavis/40/p6/Testing"

if [ $# -ne 1 ]; then
  echo "usage Tester.sh: $testerDirectory/Tester.sh calendar.out_directory" 1>&2
  exit
fi

if [[ $1 =~ Testing ]]; then # Use from this directory is not allowed
  echo "You may not use Testing as your own source directory!"  1>&2
  exit
fi

if [[ ! -e $1/calendar.out ]]; then # calendar.out not found
  echo "calendar.out not found in $1!"  1>&2
  exit
fi

cd $1

rm -f appts4.* DOW.dat in*.txt out*.txt >& /dev/null
cp $testerDirectory/appts4.csv $testerDirectory/DOW.dat $testerDirectory/in*.txt . 

fileNum=1
opScore=0

echo Operation testing:  1>&2

while [[ $fileNum -lt 7 ]]; do
  echo $fileNum  1>&2
  echo "File#: $fileNum " >> operationsResults.txt
  rm -f out$fileNum.txt  
  (calendar.out appts4.csv < $testerDirectory/in$fileNum.txt | tail -140 > out$fileNum.txt )&
  sleep 2
  pkill calendar.out &> /dev/null
  rm core &> /dev/null
  if [[ -s out$fileNum.txt ]]; then
    diff out$fileNum.txt $testerDirectory/out$fileNum.txt > temp

    if [ -s temp ] ; then
      echo "Not OK" >> operationsResults.txt
      echo "Yours:" >> operationsResults.txt
      cat out$fileNum.txt >> operationsResults.txt
      echo -e "\n\nSean's:" >> operationsResults.txt
      cat  $testerDirectory/out$fileNum.txt >> operationsResults.txt
    else
      echo "OK" >> operationsResults.txt
      (( opScore += 4 ))
    fi
  else
    echo "No output created so zero for operation." >> operationsResults.txt
  fi

  fileNum=$((fileNum + 1))
done  # while less than 10

echo "Memory leak check (6 points):" >> operationsResults.txt
rm -f out$fileNum.txt >& /dev/null
(valgrind calendar.out appts4.csv < $testerDirectory/in6.txt >& out$fileNum.txt )&
sleep 4
pkill valgrind >& /dev/null
rm core >& /dev/null
rm vgcore* >& /dev/null

if [[ -s out$fileNum.txt ]]; then
  if grep "lost.*[1-9]" out$fileNum.txt >& /dev/null ; then
    echo "Memory leak found." >> operationsResults.txt
  else
    echo "OK +4"  >> operationsResults.txt
    (( opScore += 4 ))
  fi

  if ! grep "ERROR SUMMARY: 0 errors from 0 contexts" out$fileNum.txt >& /dev/null ; then
    echo "Memory error found." >> operationsResults.txt
  else
    echo "OK +2" >> operationsResults.txt
    (( opScore += 2 ))
  fi
else
  echo "Program did not terminate normally so memory leak could not checked." >> operationsResults.txt
fi

if [ -e appts.csv.old ]; then
  mv appts.csv.old appts.csv
fi

echo $opScore   # this is the only line that goes to stdout

