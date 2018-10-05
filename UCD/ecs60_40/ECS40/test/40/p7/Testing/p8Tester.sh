#! /bin/bash

testerDirectory="/home/ssdavis/40/p7/Testing"

if [ $# -ne 1 ]; then
  echo "usage p7tester.sh: $testerDirectory/p7tester.sh p7.out_directory" 1>&2
  exit
fi

if [[ $1 =~ Testing ]]; then # Use from this directory is not allowed
  echo "You may not use Testing as your own source directory!"  1>&2
  exit
fi

if [[ ! -e $1/p7.out ]]; then # simulator not found
  echo "p7.out not found in $1!"  1>&2
  exit
fi

cd $1
fileNum=1
opScore=0
echo Operation testing:  1>&2

while [[ $fileNum -lt 15 ]]; do
  echo $fileNum  1>&2
  echo -n $fileNum: >> operationsResults.txt
  rm -f out$fileNum.txt
  rm -f source.txt &> /dev/null
  cp $testerDirectory/source.txt .
  (p7.out source.txt $testerDirectory/input$fileNum.txt out$fileNum.txt )&
  sleep 1
  pkill p7.out &> /dev/null
  rm core &> /dev/null
  diff out$fileNum.txt $testerDirectory/out$fileNum.txt &> temp

  if [[ ( ! -e out$fileNum.txt) || ( -s temp ) ]]; then
    echo -e "\nDifferences on " input$fileNum.txt >> operationsResults.txt
    echo Yours: >> operationsResults.txt
    cat out$fileNum.txt  >> operationsResults.txt
    echo -e "\nSean's:" >> operationsResults.txt
    cat $testerDirectory/out$fileNum.txt >> operationsResults.txt
  else
    echo OK >> operationsResults.txt
    (( opScore += 2 ))
  fi

  fileNum=$((fileNum + 1))
done  # while less than 15

while [[ $fileNum -lt 18 ]]; do
  echo $fileNum  1>&2
  echo -n $fileNum: >> operationsResults.txt
  rm -f out$fileNum.txt
  rm -f source.txt &> /dev/null
  cp $testerDirectory/source.txt .
  (p7.out source.txt $testerDirectory/input$fileNum.txt out$fileNum.txt > temp )&
  sleep 1
  pkill p7.out &> /dev/null
  rm core &> /dev/null
  cat temp >> out$fileNum.txt
  diff out$fileNum.txt $testerDirectory/out$fileNum.txt &> temp

  if [[ ( ! -e out$fileNum.txt) || ( -s temp ) ]]; then
    echo -e "\nDifferences on " input$fileNum.txt >> operationsResults.txt
    echo Yours: >> operationsResults.txt
    cat out$fileNum.txt  >> operationsResults.txt
    echo -e "\nSean's:" >> operationsResults.txt
    cat $testerDirectory/out$fileNum.txt >> operationsResults.txt
  else
    echo OK >> operationsResults.txt
    (( opScore += 2 ))
  fi

  fileNum=$((fileNum + 1))
done  # while less than 18

echo $opScore   # this is the only line that goes to stdout

