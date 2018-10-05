#! /bin/bash

testerDirectory="/home/ssdavis/40/p8/Testing"

if [ $# -ne 1 ]; then
  echo "usage Tester.sh: $testerDirectory/Tester.sh p8.out_directory" 1>&2
  exit
fi

if [[ $1 =~ Testing ]]; then # Use from this directory is not allowed
  echo "You may not use Testing as your own source directory!"  1>&2
  exit
fi

if [[ ! -e $1/p8.out ]]; then # p8.out not found
  echo "p8.out not found in $1!"  1>&2
  exit
fi

cd $1
cp $testerDirectory/File*.txt $testerDirectory/in*.txt .
fileNum=1
opScore=0
echo Operation testing:  1>&2

while [[ $fileNum -lt 5 ]]; do
  echo $fileNum  1>&2
  echo "File#: $fileNum -1" >> operationsResults.txt
  rm -f out${fileNum}*.txt
  (p8.out File$fileNum.txt 1 < in${fileNum}.txt | head -200 > out${fileNum}-1.txt )&
  sleep 2
  pkill p8.out &> /dev/null
  rm core &> /dev/null
  if [[ -s out${fileNum}-1.txt ]]; then
    diff out${fileNum}-1.txt $testerDirectory/out${fileNum}-1.txt > temp

    if [ -s temp ] ; then
      echo "Not OK" >> operationsResults.txt
      echo "Yours:" >> operationsResults.txt
      cat out${fileNum}-1.txt >> operationsResults.txt
      echo -e "\n\nSean's:" >> operationsResults.txt
      cat  $testerDirectory/out${fileNum}-1.txt >> operationsResults.txt
      break
    else
      echo "OK" >> operationsResults.txt
      (( opScore += 2 ))
    fi
  fi

  echo "File#: $fileNum -2 " >> operationsResults.txt
  rm -f out$fileNum.txt  
  (p8.out File$fileNum.txt 2 < in${fileNum}.txt | head -1000 > out${fileNum}-2.txt )&
  sleep 2
  pkill p8.out &> /dev/null
  rm core &> /dev/null
  if [[ -s out${fileNum}-2.txt ]]; then
    diff out${fileNum}-2.txt $testerDirectory/out${fileNum}-2.txt > temp

    if [ -s temp ] ; then
      echo "Not OK" >> operationsResults.txt
      echo "Yours:" >> operationsResults.txt
      cat out${fileNum}-2.txt >> operationsResults.txt
      echo -e "\n\nSean's:" >> operationsResults.txt
      cat  $testerDirectory/out${fileNum}-2.txt >> operationsResults.txt
      break
    else
      echo "OK" >> operationsResults.txt
      (( opScore += 5 ))
    fi
  else
    echo "No output created so zero for operation." >> operationsResults.txt
  fi

  fileNum=$((fileNum + 1))
done  # while less than 5 

echo $opScore   # this is the only line that goes to stdout

