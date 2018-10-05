#!  /bin/bash

testerDirectory="/home/ssdavis/40/p3/Testing"

if [ $# -ne 1 ]; then
  >&2 echo "usage DesignChecker.sh: $testerDirectory/DesignChecker.sh calendar_directory"
  exit
fi

if [[ $1 =~ Testing ]]; then # Use from this directory is not allowed
  >&2 echo "You may not use Testing as your own source directory!"
  exit
fi

cd $1

rm -f designResults.txt *.o
designError=0
dos2unix *.cpp *.h &> /dev/null

grep "/\*" *.h *.cpp > temp
if [ -s temp ]; then
  cat temp >> designResults.txt
  echo 'Fatal design error: "/*" found. ' >> designResults.txt
  (( ++designError ))
fi

if ! grep -v "//" calendar.h | grep "dateSearch.*( *) *const" >& /dev/null ; then
 echo 'Design error: dateSearch() const not found in calendar.h'  >> designResults.txt
fi

if ! grep -v "//" calendar.h | grep "subjectSearch.*( *) *const" >& /dev/null  ; then
 echo 'Design error: subjectSearch() const not found in calendar.h'  >> designResults.txt
fi

if ! grep -v "//" day.h | grep "equal *(const.*) *const" >& /dev/null ; then
 echo 'Design error: equal (const ...) const not found in day.h'  >> designResults.txt
fi

if ! grep -v "//" day.h | grep "lessThan *(const.*) *const" >& /dev/null ; then
 echo 'Design error: lessThan (const ...) const not found in day.h'  >> designResults.txt
fi

if ! grep -v "//" day.h | grep "print *( *) *const" >& /dev/null; then
 echo 'Design error: print() const not found in day.h'  >> designResults.txt
fi

if ! grep -v "//" day.h | grep "subjectSearch *(const.*) *const" >& /dev/null ; then
 echo 'Design error: subjectSearch (const ...) const not found in day.h'  >> designResults.txt
fi

if ! grep -v "//" appt.h | grep "equal *(const.*) *const" >& /dev/null; then
 echo 'Design error: equal (const ...) const not found in appt.h'  >> designResults.txt
fi

if ! grep -v "//" appt.h | grep "lessThan *(const.*) *const" >& /dev/null ; then
 echo 'Design error: lessThan (const ...) const not found in appt.h'  >> designResults.txt
fi

if ! grep -v "//" appt.h | grep "print *( *) *const" >& /dev/null ; then
 echo 'Design error: print() const not found in appt.h'  >> designResults.txt
fi

if ! grep -v "//" time.h | grep "lessThan *(const.*) *const" >& /dev/null ; then
 echo 'Design error: lessThan (const ...) const not found in time.h'  >> designResults.txt
fi

if ! grep -v "//" time.h | grep "print *( *) *const" >& /dev/null ; then
 echo 'Design error: print() const not found in time.h'  >> designResults.txt
fi

if ! grep "<cstring>" calendar.cpp >& /dev/null ; then
  echo 'Design error: cstring not found in calendar.cpp.'  >> designResults.txt
fi

if ! grep "<cstdlib>" calendar.cpp >& /dev/null ; then
  echo 'Design error: cstdlib not found in calendar.cpp.'  >> designResults.txt
fi

if [[ `awk '/void.*Calendar::create/, /^}/' calendar.cpp | grep -v "//" | grep "malloc" | wc -l ` -gt 0 ]] ; then
 echo 'Design error: malloc found in create() in calendar.cpp.'  >> designResults.txt
fi

if [[ `awk '/void.*Calendar::create/, /^}/' calendar.cpp | grep -v "//" | grep "new" | wc -l ` -ne 1 ]] ; then
 echo 'Design error: new not found in create() in calendar.cpp.'  >> designResults.txt
fi

if [[ `awk '/void.*Calendar::resize/, /^}/' calendar.cpp | grep -v "//" | grep "malloc" | wc -l ` -gt 0 ]] ; then
 echo 'Design error: malloc found in resize() in calendar.cpp.'  >> designResults.txt
fi

if [[ `awk '/void.*Calendar::resize/, /^}/' calendar.cpp | grep -v "//" | grep "new" | wc -l ` -ne 1 ]] ; then
 echo 'Design error: new not found in resize() in calendar.cpp.'  >> designResults.txt
fi

if [[ `awk '/void.*Day::read/, /^}/' day.cpp | grep -v "//" | grep "malloc" | wc -l ` -gt 0 ]] ; then
 echo 'Design error: malloc found in read() in day.cpp.'  >> designResults.txt
fi

if [[ `awk '/void.*Day::read/, /^}/' day.cpp | grep -v "//" | grep "new" | wc -l ` -ne 1 ]] ; then
 echo 'Design error: new not found in read() in day.cpp.'  >> designResults.txt
fi

if [[ `awk '/void.*Appointment::read/, /^}/' appt.cpp | grep -v "//" | grep "malloc" | wc -l ` -gt 0 ]] ; then
 echo 'Design error: malloc found in read() in appt.cpp.'  >> designResults.txt
fi

if [[ `awk '/void.*Appointment::read/, /^}/' appt.cpp | grep -v "//" | grep "new" | wc -l ` -ne 2 ]] ; then
 echo 'Design error: Two "new" not found in read() in appt.cpp.'  >> designResults.txt
fi

if ! grep "<cstring>" time.cpp >& /dev/null ; then
  echo 'Design error: cstring not found in time.cpp.'  >> designResults.txt
fi

if ! grep "<cstdlib>" time.cpp >& /dev/null ; then
  echo 'Design error: cstdlib not found in time.cpp.'  >> designResults.txt
fi

if [[ `grep "malloc" *.cpp | wc -l ` -gt 0 ]] ; then
 echo 'Design error: malloc found in at least one *.cpp file.'  >> designResults.txt
fi

if [[ `grep "free" *.cpp | wc -l ` -gt 0 ]] ; then
 echo 'Design error: "free" found in at least one *.cpp file.'  >> designResults.txt
fi



# fatal errors from here on

if egrep "(struct|stdio)" *.cpp *.h >& /dev/null ; then
  echo 'Fatal design error: "struct", or "stdio" found in at least one *.cpp and/or *.h file.' >> designResults.txt
  (( ++ designError ))
fi


if [[ `awk '/#include/, /^{/' *.cpp *.h | egrep -v "\(|\)" | grep -v "class" | egrep "(void|int|char|double|float|Day|Calendar|Appointment|Time)" | wc -l ` -ne 0 ]] ; then
 echo 'Fatal design error: "Global variable found above first function/class in a file.'  >> designResults.txt
  (( ++ designError ))
fi

if [[ `awk '/^}} *[^;]*/, /::/' *.cpp *.h | egrep -v "\(|\)|^}" | egrep "(void|int|short|char|double|float|Day|Calendar|Appointment|Time)" | wc -l ` -ne 0 ]] ; then
 echo 'Fatal design error: "Global variable found between functions in a file.'  >> designResults.txt
  (( ++ designError ))
fi

if grep "goto" *.cpp *.h  &> /dev/null ; then
  echo 'Fatal design error: "goto" found in files.'  >> designResults.txt
  (( ++ designError ))
fi

echo $designError  # Only standard out

