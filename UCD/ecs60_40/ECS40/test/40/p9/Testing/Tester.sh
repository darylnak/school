#! /bin/bash

testerDirectory="/home/ssdavis/40/p9/Testing"

if [ $# -ne 1 ]; then
  echo "usage Tester.sh: $testerDirectory/Tester.sh p9.out_directory" 1>&2
  exit
fi

if [[ $1 =~ Testing ]]; then # Use from this directory is not allowed
  echo "You may not use Testing as your own source directory!"  1>&2
  exit
fi

if [[ ! -e $1/p9.out ]]; then # p8.out not found
  echo "p9.out not found in $1!"  1>&2
  exit
fi

cd $1
cp $testerDirectory/file*.txt .
fileNum=1
opScore=0
echo Operation testing:  1>&2

while [[ $fileNum -lt 13 ]]; do
  echo "p9.out file$fileNum.txt" 1>&2
  echo "p9.out file$fileNum.txt: " >> operationsResults.txt
  rm -f out${fileNum}*.txt
  (p9.out file$fileNum.txt  head -200 >& out${fileNum}.txt )&
  sleep 2
  pkill p9.out &> /dev/null
  rm core &> /dev/null
  if [[ -s out${fileNum}.txt ]]; then
    diff out${fileNum}.txt $testerDirectory/out${fileNum}.txt > temp

    if [ -s temp ] ; then
      echo "Not OK" >> operationsResults.txt
      echo "Yours:" >> operationsResults.txt
      cat out${fileNum}.txt >> operationsResults.txt
      echo -e "\n\nSean's:" >> operationsResults.txt
      cat  $testerDirectory/out${fileNum}.txt >> operationsResults.txt
      break
    else
      echo "OK" >> operationsResults.txt
      (( opScore += 1 ))
    fi
  fi
  
  fileNum=$((fileNum + 1))
done

fileNum=8

while [[ $fileNum -lt 13 ]]; do
  echo  "p9b.out file$fileNum.txt" 1>&2 
  rm -f temp &> /dev/null
  echo "p9b.out file$fileNum.txt: " >> operationsResults.txt
  rm -f out${fileNum}*.txt
  (p9b.out file$fileNum.txt >& temp)&
  sleep 2
  pkill p9b.out &> /dev/null
  rm core &> /dev/null

  if [[ -s temp ]]; then
    awk '/p9b.out/ {print $1, $3, $4, $5, $6, $7, $8}' temp > out${fileNum}b.txt
    diff out${fileNum}b.txt $testerDirectory/out${fileNum}b.txt > temp

    if [ -s temp ] ; then
      echo "Not OK" >> operationsResults.txt
      echo "Yours:" >> operationsResults.txt
      cat out${fileNum}b.txt >> operationsResults.txt
      echo -e "\n\nSean's:" >> operationsResults.txt
      cat  $testerDirectory/out${fileNum}b.txt >> operationsResults.txt
      break
    else
      echo "OK" >> operationsResults.txt
      (( opScore += 1 ))
    fi
  fi

  fileNum=$((fileNum + 1))
done

echo $opScore   # this is the only line that goes to stdout

