#! /bin/bash
# Author: Sean Davis

if [[ $# -eq 0 ]] ; then 
  echo Executable name required.
  echo usage: makemake.sh executable_name
  exit 1
fi

executable=$1
shift

echo -n  "$executable : "  > Makefile

for file in  *.cpp ; do
  echo -n "${file%*cpp}o " >> Makefile
done

echo " " >> Makefile
echo -e -n "\tg++ -ansi -Wall -g -o $executable " >> Makefile


for arg in $* ; do
  echo -n "$arg " >> Makefile
done

for file in *.cpp ; do
    echo -n "${file%*cpp}o " >> Makefile
done

echo " " >> Makefile

for file in *.cpp ; do
  echo -e -n "\n${file%cpp}o : $file " >> Makefile
  awk -F\" ' /#include *\"/ {printf("%s ",$2)} ' $file >> Makefile
  echo -e -n "\n\tg++ -ansi -Wall -g -c " >> Makefile

  for arg in $@ ; do
    echo -n "$arg " >> Makefile
  done

  echo $file >> Makefile
done

echo -e "\nclean : " >> Makefile
echo -n -e "\trm -f $executable " >> Makefile

for file in *.cpp ; do
    echo -n "${file%*cpp}o  " >> Makefile
done

echo " " >> Makefile
