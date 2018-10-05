#!  /bin/bash

testerDirectory="/home/ssdavis/40/p4/Testing"

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


if ! grep -v "//" calendar.h | grep "Calendar *( *)" >& /dev/null ; then
 echo 'Design error: Calendar default contructor not found in calendar.h'  >> designResults.txt
fi

if  grep "create *("  calendar.h >& /dev/null  ; then
 echo 'Design error: "create(" found in calendar.h'  >> designResults.txt
fi

if ! grep -v "//" calendar.h | grep "~Calendar *( *)" >& /dev/null ; then
 echo 'Design error: Calendar destructor not found in calendar.h'  >> designResults.txt
fi

if  grep "destroy *("  calendar.h >& /dev/null  ; then
 echo 'Design error: "destroy(" found in calendar.h'  >> designResults.txt
fi


if ! grep -v "//" day.h | grep "Day *( *)" >& /dev/null ; then
 echo 'Design error: Day default constructor not found in day.h'  >> designResults.txt
fi

if ! grep -v "//" day.h | grep "Day *( *int .*int .*int.*)" >& /dev/null ; then
 echo 'Design error: Day "standard" constructor not found in day.h'  >> designResults.txt
fi

if  grep "create *(" day.h >& /dev/null  ; then
 echo 'Design error: "create(" found in day.h'  >> designResults.txt
fi

if ! grep -v "//" day.h | grep "~Day *( *)" >& /dev/null ; then
 echo 'Design error: Day destructor not found in day.h'  >> designResults.txt
fi

if  grep "destroy *(" day.h >& /dev/null  ; then
 echo 'Design error: "destroy(" found in day.h'  >> designResults.txt
fi

if ! grep -v "//" day.h | grep "Day *& *operator *= *(.*Day *&.*)" >& /dev/null ; then
 echo 'Design error: Day overloaded assignment operator not found in day.h'  >> designResults.txt
fi

if ! grep -v "//" day.h | grep "operator *= *( *const.*)" >& /dev/null ; then
 echo 'Design error: "operator= (const ...)" not found in day.h'  >> designResults.txt
fi

if ! grep -v "//" day.h | grep "equal *( *const.*) *const" >& /dev/null ; then
 echo 'Design error: "equal(const ...) const" not found in day.h'  >> designResults.txt
fi

if ! grep -v "//" day.h | grep "lessThan *( *const.*) *const" >& /dev/null ; then
 echo 'Design error: "lessThan (const ...) const" not found in day.h'  >> designResults.txt
fi

if ! grep -v "//" day.h | grep "print *( *) *const" >& /dev/null ; then
 echo 'Design error: "print() const" not found in day.h'  >> designResults.txt
fi

if ! grep -v "//" day.h | grep "subjectSearch *( *const.*) *const" >& /dev/null ; then
 echo 'Design error: "subjectSearch(const ...) const" not found in day.h'  >> designResults.txt
fi


if ! grep -v "//" appt.h | grep "Appointment *( *)" >& /dev/null; then
 echo 'Design error: Appointment default constructor not found in appt.h'  >> designResults.txt
fi

if ! grep -v "//" appt.h | grep "Appointment *( *const *Appointment" >& /dev/null; then
 echo 'Design error: Appointment copy constructor with const parameter not found in appt.h'  >> designResults.txt
fi

if ! grep -v "//" appt.h | grep "Appointment *(.*Appointment *&.*)" >& /dev/null; then
 echo 'Design error: Appointment copy constructor not found in appt.h'  >> designResults.txt
fi

if  grep "create *(" appt.h >& /dev/null  ; then
 echo 'Design error: "create(" found in appt.h'  >> designResults.txt
fi

if ! grep -v "//" appt.h | grep "~Appointment *( *)" >& /dev/null; then
 echo 'Design error: Appointment destructor not found in appt.h'  >> designResults.txt
fi

if  grep "destroy *(" appt.h >& /dev/null  ; then
 echo 'Design error: "destroy(" found in appt.h'  >> designResults.txt
fi

if ! grep -v "//" appt.h | grep "static *int *count" >& /dev/null; then
 echo 'Design error: static count variable not found in appt.h'  >> designResults.txt
fi

if ! grep -v "//" appt.h | grep "static .*getCount *(" >& /dev/null; then
 echo 'Design error: static getCount not found in appt.h'  >> designResults.txt
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


if ! grep -v "//" DayOfWeek.h | grep "void *print *( *)" >& /dev/null; then
 echo 'Design error: DayOfWeek print() not found in DayOfWeek.h'  >> designResults.txt
fi

if ! grep -v "//" DayOfWeek.h | grep "void *print *( *) *const" >& /dev/null; then
 echo 'Design error: DayOfWeek "print() const" not found in DayOfWeek.h'  >> designResults.txt
fi

if ! grep -v "//" DayOfWeek.h | grep "void *read *( *int .*int .*int.*)" >& /dev/null; then
 echo 'Design error: DayOfWeek read() with three int parameters not found in DayOfWeek.h'  >> designResults.txt
fi

if ! awk '/:: *read/,/^}/' DayOfWeek.cpp | grep -v "//" | grep "seekg" >& /dev/null; then
 echo 'Design error: seekg() not found in DayOfWeek read() in DayOfWeek.cpp'  >> designResults.txt
fi

if awk '/:: *read/,/^}/' DayOfWeek.cpp | grep "\[" >& /dev/null; then
 echo 'Fatal design error: Array found in DayOfWeek read() in DayOfWeek.cpp'  >> designResults.txt
 (( ++ designError ))
fi


if ! awk '/main *\(/, /^}/ ' main.cpp | grep -v "//" | grep "Appointment *:: *getCount *(" >& /dev/null; then
 echo 'Design error: static getCount() not called in main()'  >> designResults.txt
fi


if grep "malloc" *.cpp >& /dev/null ; then
 echo 'Design error: malloc found in at least one *.cpp.'  >> designResults.txt
fi

if grep "free" *.cpp >& /dev/null ; then
 echo 'Design error: "free" found in at least one *.cpp file.'  >> designResults.txt
fi



# fatal errors from here on

if grep grep "/\*" *.h *.cpp >& /dev/null ; then
  echo 'Fatal design error: "/*" found. ' >> designResults.txt
  (( ++designError ))
fi

if egrep "(struct |stdio)" *.cpp *.h >& /dev/null ; then
  echo 'Fatal design error: "struct", or "stdio" found in at least one *.cpp and/or *.h file.' >> designResults.txt
  (( ++ designError ))
fi

if [[ `awk '/#include/, /^{/' *.cpp *.h | egrep -v "\(|\)" | grep -v count | grep -v "class" | grep -v "#include" | egrep "(void|int|char|double|float|Day|Calendar|Appointment|Time)" | wc -l ` -ne 0 ]] ; then
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

