#! /bin/bash
# Author: Sean Davis

if [ $# -ne 0 ] ; then
  filenames="$*"
else
  filenames=`ls *.txt`
fi

for file in $filenames ; do
  echo "Displaying first 3 lines of $file:"
  head -n 3 $file
  echo -e "\nDelete file $file? (y/n) \c"
  read reply
  [ "$reply" = "y" ] && rm $file
done
 
