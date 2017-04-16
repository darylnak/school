#!  /bin/bash

testerDirectory="/home/ssdavis/40/p1/Testing"

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


if [[ `awk '/(typedef struct|class *Calendar)/, /(} *Calendar;|} *;)/' calendar.h |  grep -v "//" | grep "Day *\* *days;" | wc -l ` -ne 1 ]] ; then
 echo 'Design error: "Day *days;" not found in typedef struct Calendar in calendar.h.'  >> designResults.txt
fi

if [[ `awk '/(typedef struct|class *Calendar)/, /(} *Calendar;|} *;)/' calendar.h |  grep -v "//" | grep "int *count;" | wc -l ` -ne 1 ]] ; then
 echo 'Design error: "int count;" not found in typedef struct Calendar in calendar.h.'  >> designResults.txt
fi

if [[ `awk '/(typedef struct|class *Calendar)/, /(} *Calendar;|} *;)/' calendar.h |  grep -v "//" | grep "int *size;" | wc -l ` -ne 1 ]] ; then
 echo 'Design error: "int size;" not found in typedef struct Calendar in calendar.h.'  >> designResults.txt
fi

if [[ `awk '/void.*create/, /^}/' calendar.cpp | grep -v "//" | grep "30" | wc -l ` -lt 1 ]] ; then
 echo 'Design error: "30" not found in create() function in calendar.cpp.'  >> designResults.txt
fi

if [[ `awk '/void.*readFile/, /^}/' calendar.cpp | grep -v "//" | grep "readFile *( *Calendar *\*[^,]*)" | wc -l ` -lt 1 ]] ; then
 echo 'Design error: "readFile(Calendar * )" function not found in calendar.cpp.'  >> designResults.txt
fi

if [[ `awk '/void.*readFile/, /^}/' calendar.cpp | grep -v "//" | grep "strtok" | wc -l ` -lt 3 ]] ; then
 echo 'Design error: At least three "strtok" not found in readFile() function in calendar.cpp.'  >> designResults.txt
fi

if [[ `awk '/void.*readFile/, /^}/' calendar.cpp |  grep -v "//" |grep "create *(.*&dayTemp.*)" | wc -l ` -ne 1 ]] ; then
 echo 'Design error: Call to create() with &dayTemp not found in readFile() function in calendar.cpp.'  >> designResults.txt
fi

if [[ `awk '/void.*readFile/, /^}/' calendar.cpp | grep -v "//" | grep "equal *(.*&dayTemp.*)" | wc -l ` -ne 1 ]] ; then
 echo 'Design error: Call to equal() with &dayTemp not found in readFile() function in calendar.cpp.'  >> designResults.txt
fi

if [[ `awk '/void.*readFile/, /^}/' calendar.cpp | grep -v "//" | grep "lessThan *(.*&dayTemp.*)" | wc -l ` -ne 1 ]] ; then
 echo 'Design error: Call to lessThan() with &dayTemp not found in readFile() function in calendar.cpp.'  >> designResults.txt
fi

if [[ `awk '/void.*readFile/, /^}/' calendar.cpp | grep -v "//" | grep "read *(.*&.*)" | wc -l ` -ne 1 ]] ; then
 echo 'Design error: Call to read() with an address of a day exactly once not found in readFile() function in calendar.cpp.'  >> designResults.txt
fi

if [[ `awk '/void.*readFile/, /^}/' calendar.cpp | grep -v "//" | grep "close" | wc -l ` -ne 1 ]] ; then
 echo 'Design error: Call to "close" or "fclose" not found in readFile() function in calendar.cpp.'  >> designResults.txt
fi

if [[ `awk '/void.*resize/, /^}/' calendar.cpp | grep -v "//" | grep "resize *( *Calendar *\*[^,]*)" | wc -l ` -lt 1 ]] ; then
 echo 'Design error: "resize(Calendar * )" function not found in calendar.cpp.'  >> designResults.txt
fi

if [[ `awk '/void.*resize/, /^}/' calendar.cpp | grep "realloc" | wc -l ` -ne 0 ]] ; then
 echo 'Design error: "realloc" found in resize() in calendar.cpp.'  >> designResults.txt
fi

if [[ `awk '/void.*resize/, /^}/' calendar.cpp | grep -v "//" | egrep "(malloc|new)" | wc -l ` -ne 1 ]] ; then
 echo 'Design error: "malloc" or "new" not found in resize() in calendar.cpp.'  >> designResults.txt
fi

if [[ `awk '/void.*resize/, /^}/' calendar.cpp | grep -v "//" | egrep "(free|delete)" | wc -l ` -ne 1 ]] ; then
 echo 'Design error: "free" or "delete" not found in resize() in calendar.cpp.'  >> designResults.txt
fi

if [[ `awk '/void.*dateSearch/, /^}/' calendar.cpp | grep -v "//" | grep "dateSearch *( *Calendar *\*[^,]*)" | wc -l ` -lt 1 ]] ; then
 echo 'Design error: "dateSearch(Calendar * )" function not found in calendar.cpp.'  >> designResults.txt
fi

if [[ `awk '/void.*dateSearch/, /^}/' calendar.cpp | grep -v "//" | grep "getDate *([^,]*,[^,]*,[^,]*)" | wc -l ` -ne 1 ]] ; then
 echo 'Design error: Call to getDate() with three parameters not found in dateSearch() function in calendar.cpp.'  >> designResults.txt
fi

if [[ `awk '/void.*dateSearch/, /^}/' calendar.cpp | grep -v "//" | grep "equal *([^,]*,[^,]*)" | wc -l ` -ne 1 ]] ; then
 echo 'Design error: Call to equal() with two parameters not found in dateSearch() function in calendar.cpp.'  >> designResults.txt
fi

if [[ `awk '/void.*getDate/, /^}/' calendar.cpp | grep -v "//" | grep "getDate *([^,]*,[^,]*,[^,]*)" | wc -l ` -lt 1 ]] ; then
 echo 'Design error: getDate() with three parameters not found in calendar.cpp.'  >> designResults.txt
fi

if [[ `awk '/void.*subjectSearch/, /^}/' calendar.cpp | grep -v "//" | grep "subjectSearch *( *Calendar *\*[^,]*)" | wc -l ` -lt 1 ]] ; then
 echo 'Design error: "subjectSearch(Calendar * )" function not found in calendar.cpp.'  >> designResults.txt
fi

if [[ `awk '/void.*subjectSearch/, /^}/' calendar.cpp | grep -v "//" | grep "subjectSearch *([^,]*,[^,]*)" | wc -l ` -ne 1 ]] ; then
 echo 'Design error: Call to subjectSearch() with two parameters not found in subjectSearch() function in calendar.cpp.'  >> designResults.txt
fi

if [[ `awk '/void.*destroy/, /^}/' calendar.cpp | grep -v "//" | grep "void *destroy *( *Calendar *\*[^,]*)" | wc -l ` -lt 1 ]] ; then
 echo 'Design error: "destroy(Calendar * )" function not found in calendar.cpp.'  >> designResults.txt
fi

if [[ `awk '/void.*destroy/, /^}/' calendar.cpp | grep -v "//" | grep "^ *destroy *([^,]*calendar.*days[^,]*) *;" | wc -l ` -ne 1 ]] ; then
 echo 'Design error: Call to destroy() with a pointer to one of the days as a parameter not found in destroy() function in calendar.cpp.'  >> designResults.txt
fi

if [[ `awk '/void.*destroy/, /^}/' calendar.cpp | grep -v "//" | egrep "(free|delete).*days[^,]*;" | wc -l ` -ne 1 ]] ; then
 echo 'Design error: days not deallocated in destroy() function in calendar.cpp.'  >> designResults.txt
fi



if [[ `awk '/(typedef struct|class *Day)/, /(} *Day;|} *;)/' day.h |  grep -v "//" | grep "short *day;" | wc -l ` -ne 1 ]] ; then
 echo 'Design error: "short day;" not found in typedef struct Day in day.h.'  >> designResults.txt
fi

if [[ `awk  '/(typedef struct|class *Day)/, /(} *Day;|} *;)/' day.h |  grep -v "//" | grep "short *month;" | wc -l ` -ne 1 ]] ; then
 echo 'Design error: "short month;" not found in typedef struct Day in day.h.'  >> designResults.txt
fi

if [[ `awk  '/(typedef struct|class *Day)/, /(} *Day;|} *;)/' day.h |  grep -v "//" | grep "short *year;" | wc -l ` -ne 1 ]] ; then
 echo 'Design error: "short year;" not found in typedef struct Day in day.h.'  >> designResults.txt
fi

if [[ `awk  '/(typedef struct|class *Day)/, /(} *Day;|} *;)/' day.h |  grep -v "//" | grep "Appointment *\* *appts\[ *8 *\];" | wc -l ` -ne 1 ]] ; then
 echo 'Design error: array of eight Appointment pointers named "appts" not found in typedef struct Day in day.h.'  >> designResults.txt
fi

if [[ `awk '/void.*create/, /^}/' day.cpp | grep -v "//" | grep "create *([^,]*,[^,]*,[^,]*,[^,]*)" | wc -l ` -lt 1 ]] ; then
 echo 'Design error: create() with four parameters not found in day.cpp.'  >> designResults.txt
fi

if [[ `awk '/(bool|int).*equal/, /^}/' day.cpp | grep -v "//" | grep "equal *( *Day *\*.*, *Day *\*.*)" | wc -l ` -lt 1 ]] ; then
 echo 'Design error: equal() with two Day* parameters not found in day.cpp.'  >> designResults.txt
fi

if [[ `awk '/(bool|int).*lessThan/, /^}/' day.cpp | grep -v "//" | grep "lessThan *( *Day *\*.*, *Day *\*.*)" | wc -l ` -lt 1 ]] ; then
 echo 'Design error: lessThan() with two Day* parameters not found in day.cpp.'  >> designResults.txt
fi

if [[ `awk '/void.*read/, /^}/' day.cpp | grep -v "//" | grep "read *( *Day *\*[^,]*)" | wc -l ` -lt 1 ]] ; then
 echo 'Design error: read() with only a Day* parameter not found in day.cpp.'  >> designResults.txt
fi

if [[ `awk '/void.*read/, /^}/' day.cpp | grep -v "//" | egrep "(malloc|new).*Appointment.*;" | wc -l ` -lt 1 ]] ; then
 echo 'Design error: Dynamic allocation of an Appointment not found in read() in day.cpp.'  >> designResults.txt
fi

if [[ `awk '/void.*read/, /^}/' day.cpp | grep -v "//" | grep "read *([^,]*);" | wc -l ` -ne 1 ]] ; then
 echo 'Design error: Call to read() with one parameter not found in read() in day.cpp.'  >> designResults.txt
fi

if [[ `awk '/void.*read/, /^}/' day.cpp | grep -v "//" | grep "lessThan *([^,]*,[^,]*)" | wc -l ` -lt 1 ]] ; then
 echo 'Design error: Call to lessThan with two parameters not found in read() in day.cpp.'  >> designResults.txt
fi

if [[ `awk '/void.*print/, /^}/' day.cpp | grep -v "//" | grep "print *( *Day *\*[^,]*)" | wc -l ` -lt 1 ]] ; then
 echo 'Design error: print() with with only a Day parameter not found in day.cpp.'  >> designResults.txt
fi

if [[ `awk '/void.*print/, /^}/' day.cpp | grep -v "//" | grep "print *( *day.*appts[^,]*)" | wc -l ` -lt 1 ]] ; then
 echo 'Design error: Call to print() with only an Appointment* not found in print() in day.cpp.'  >> designResults.txt
fi

if [[ `awk '/void.*subjectSearch/, /^}/' day.cpp | grep -v "//" | grep "subjectSearch *([^,]*,[^,]*)" | wc -l ` -lt 1 ]] ; then
 echo 'Design error: subjectSearch() with two parameters not found in day.cpp.'  >> designResults.txt
fi

if [[ `awk '/void.*subjectSearch/, /^}/' day.cpp | grep -v "//" | grep "equal *([^,]*,[^,]*)" | wc -l ` -lt 1 ]] ; then
 echo 'Design error: Call to equal with two parameters not found in subjectSearch() in day.cpp.'  >> designResults.txt
fi

if [[ `awk '/void.*subjectSearch/, /^}/' day.cpp | grep -v "//" | grep  "print *( *day.*appts[^,]*)" | wc -l ` -lt 1 ]] ; then
 echo 'Design error: Call to print with only an Appointment* notfound in subjectSearch() in day.cpp.'  >> designResults.txt
fi

if [[ `awk '/void.*destroy/, /^}/' day.cpp | grep -v "//" | grep "destroy *( *Day *\*[^,]*)" | wc -l ` -lt 1 ]] ; then
 echo 'Design error: destroy() with with only a Day parameter not found in day.cpp.'  >> designResults.txt
fi

if [[ `awk '/void.*destroy/, /^}/' day.cpp | grep -v "//" | grep "^ *destroy *([^,]*day.*appt[^,]*) *;" | wc -l ` -ne 1 ]] ; then
 echo 'Design error: Call to destroy() with a pointer to one of the appointments as a parameter not found in destroy() function in day.cpp.'  >> designResults.txt
fi

if [[ `awk '/void.*destroy/, /^}/' day.cpp | grep -v "//" | egrep "(free|delete).*day.*appt[^,]*;" | wc -l ` -ne 1 ]] ; then
 echo 'Design error: appointments not deallocated in destroy() function in day.cpp.'  >> designResults.txt
fi


if [[ `awk '/(typedef struct|class *Appointment)/, /(} *Appointment;|];)/' appt.h |  grep -v "//" | grep "Time *startTime;" | wc -l ` -ne 1 ]] ; then
 echo 'Design error: "startTime" not found in typedef struct or class Appointment in appt.h.'  >> designResults.txt
fi

if [[ `awk '/(typedef struct|class *Appointment)/, /(} *Appointment;|];)/' appt.h |  grep -v "//" | grep "Time *endTime;" | wc -l ` -ne 1 ]] ; then
 echo 'Design error: "endTime" not found in typedef struct or class Appointment in appt.h.'  >> designResults.txt
fi

if [[ `awk '/(typedef struct|class *Appointment)/, /(} *Appointment;|];)/' appt.h |  grep -v "//" | grep "char *\* *subject;" | wc -l ` -ne 1 ]] ; then
 echo 'Design error: "subject" not found in typedef struct or class Appointment in appt.h.'  >> designResults.txt
fi
if [[ `awk '/(typedef struct|class *Appointment)/, /(} *Appointment;|];)/' appt.h |  grep -v "//" | grep "char *\* *location;" | wc -l ` -ne 1 ]] ; then
 echo 'Design error: "location" not found in typedef struct or class Appointment in appt.h.'  >> designResults.txt
fi

if [[ `awk '/void.*read/, /^}/' appt.cpp | grep -v "//" | grep "read *([^,]*Appointment *\*[^,]*)" | wc -l ` -lt 1 ]] ; then
 echo 'Design error: read() with only Appointment pointer as its parameter not found in appt.cpp.'  >> designResults.txt
fi

if [[ `awk '/void.*read/, /^}/' appt.cpp | grep -v "//" | grep "read *([^,]*Time[^,]*)" | wc -l ` -lt 1 ]] ; then
 echo 'Design error: Call to read() with a Time pointer as its only parameter not found in read() in appt.cpp.'  >> designResults.txt
fi

if [[ `awk '/void.*read/, /^}/' appt.cpp | grep -v "//" | grep "strtok *(.*)" | wc -l ` -ne 2 ]] ; then
 echo 'Design error: Two calls to strtok() not found in read() in appt.cpp.'  >> designResults.txt
fi

if [[ `awk '/void.*print/, /^}/' appt.cpp | grep -v "//" | grep "print *([^,]*Appointment *\*[^,]*)" | wc -l ` -lt 1 ]] ; then
 echo 'Design error: print() with only Appointment pointer as its parameter not found in appt.cpp.'  >> designResults.txt
fi

if [[ `awk '/void.*print/, /^}/' appt.cpp | grep -v "//" | grep "print *([^,]*Time[^,]*)" | wc -l ` -lt 1 ]] ; then
 echo 'Design error: Call to print() with a Time pointer as its only parameter not found in printhh) in appt.cpp.'  >> designResults.txt
fi

if [[ `awk '/(int|bool).*lessThan/, /^}/' appt.cpp | grep -v "//" | grep "lessThan *([^,]*Appointment *\*[^,]*,[^,]*Appointment *\*[^,]*)" | wc -l ` -lt 1 ]] ; then
 echo 'Design error: lessThanread() with only two Appointment pointers as its parameters not found in appt.cpp.'  >> designResults.txt
fi

if [[ `awk '/(int|bool).*lessThan/, /^}/' appt.cpp | grep -v "//" | grep "lessThan *([^,]*,[^,]*);" | wc -l ` -ne 1 ]] ; then
 echo 'Design error: Call to lessThan() with two parameters not found in lessThanread() in appt.cpp.'  >> designResults.txt
fi

if [[ `awk '/void.*destroy/, /^}/' appt.cpp | grep -v "//" | grep "destroy *([^,]*Appointment *\*[^,]*)" | wc -l ` -lt 1 ]] ; then
 echo 'Design error: destroy() with only Appointment pointer as its parameter not found in appt.cpp.'  >> designResults.txt
fi

if [[ `awk '/void.*destroy/, /^}/' appt.cpp | grep -v "//" | egrep "(free|delete).*(subject|location)" | wc -l ` -ne 2 ]] ; then
 echo 'Design error: subject and/or location were not deallocated in destroy() in appt.cpp.'  >> designResults.txt
fi



if [[ `awk '/(typedef struct|class *Time)/, /(} *Time;|];)/' time.h |  grep -v "//" | grep "short *hour;" | wc -l ` -ne 1 ]] ; then
 echo 'Design error: "short hour" not found in typedef struct or class Time in time.h.'  >> designResults.txt
fi

if [[ `awk '/(typedef struct|class *Time)/, /(} *Time;|];)/' time.h |  grep -v "//" | grep "short *minute;" | wc -l ` -ne 1 ]] ; then
 echo 'Design error: "short minute" not found in typedef struct or class Time in time.h.'  >> designResults.txt
fi

if [[ `awk '/void.*read/, /^}/' time.cpp | grep -v "//" | grep "strtok*(.*)" | wc -l ` -ne 3 ]] ; then
 echo 'Design error: strtok() not called three times in read() in time.cpp.'  >> designResults.txt
fi

if [[ `awk '/void.*read/, /^}/' time.cpp | grep -v "//" | grep "read *([^,]*Time *\*[^,]*)" | wc -l ` -lt 1 ]] ; then
 echo 'Design error: read() with only Time pointer as its parameter not found in time.cpp.'  >> designResults.txt
fi

if [[ `awk '/void.*print/, /^}/' time.cpp | grep -v "//" | grep "print *([^,]*Time *\*[^,]*)" | wc -l ` -lt 1 ]] ; then
 echo 'Design error: print() with only Time pointer as its parameter not found in time.cpp.'  >> designResults.txt
fi

if [[ `awk '/(int|bool).*lessThan/, /^}/' time.cpp | grep -v "//" | grep "lessThan *([^,]*Time *\*[^,]*,[^,]*Time *\*[^,]*)" | wc -l ` -lt 1 ]] ; then
 echo 'Design error: lessThan() with two Time pointers as its parameters not found in time.cpp.'  >> designResults.txt
fi



if [[ ` grep -v "^ *#" Makefile| egrep "calendar.out *: " | wc -l ` -ne 1 ]] ; then
 echo 'Design error: No rule to test dependencies of calendar.out in Makefile'  >> designResults.txt
fi

if [[ ` grep -v "^ *#" Makefile| egrep "main.o *: " | wc -l ` -ne 1 ]] ; then
 echo 'Design error: No rule to test dependencies of main.o in Makefile'  >> designResults.txt
fi

if [[ ` grep -v "^ *#" Makefile | grep main.cpp | grep "\-ansi" | grep "\-Wall" | grep "\-g" | wc -l ` -ne 1 ]] ; then
 echo 'Design error: -ansi, -Wall, and/or -g missing from build line for main.o in Makefile'  >> designResults.txt
fi

if [[ ` grep -v "^ *#" Makefile| egrep "calendar.o *: " | wc -l ` -ne 1 ]] ; then
 echo 'Design error: No rule to test dependencies of calendar.o in Makefile'  >> designResults.txt
fi

if [[ ` grep -v "^ *#" Makefile | grep calendar.cpp | grep "\-ansi" | grep "\-Wall" | grep "\-g" | wc -l ` -ne 1 ]] ; then
 echo 'Design error: -ansi, -Wall, and/or -g missing from build line for calendar.o in Makefile'  >> designResults.txt
fi

if [[ ` grep -v "^ *#" Makefile| egrep "day.o *: " | wc -l ` -ne 1 ]] ; then
 echo 'Design error: No rule to test dependencies of day.o in Makefile'  >> designResults.txt
fi

if [[ ` grep -v "^ *#" Makefile | grep day.cpp | grep "\-ansi" | grep "\-Wall" | grep "\-g" | wc -l ` -ne 1 ]] ; then
 echo 'Design error: -ansi, -Wall, and/or -g missing from build line for day.o in Makefile'  >> designResults.txt
fi

if [[ ` grep -v "^ *#" Makefile| egrep "appt.o *: " | wc -l ` -ne 1 ]] ; then
 echo 'Design error: No rule to test dependencies of appt.o in Makefile'  >> designResults.txt
fi

if [[ ` grep -v "^ *#" Makefile | grep appt.cpp | grep "\-ansi" | grep "\-Wall" | grep "\-g" | wc -l ` -ne 1 ]] ; then
 echo 'Design error: -ansi, -Wall, and/or -g missing from build line for appt.o in Makefile'  >> designResults.txt
fi

if [[ ` grep -v "^ *#" Makefile| egrep "time.o *: " | wc -l ` -ne 1 ]] ; then
 echo 'Design error: No rule to test dependencies of time.o in Makefile'  >> designResults.txt
fi

if [[ ` grep -v "^ *#" Makefile | grep time.cpp | grep "\-ansi" | grep "\-Wall" | grep "\-g" | wc -l ` -ne 1 ]] ; then
 echo 'Design error: -ansi, -Wall, and/or -g missing from build line for time.o in Makefile'  >> designResults.txt
fi

if [[ ` grep -v "^ *#" Makefile| grep "clean *:" | wc -l ` -ne 1 ]] ; then
 echo 'Design error: No rule for clean in Makefile'  >> designResults.txt
fi

if [[ ` grep -v "^ *#" Makefile | grep rm | grep calendar.out | grep main.o | grep calendar.o | grep day.o | grep appt.o | grep time.o | wc -l ` -ne 1 ]] ; then
 echo 'Design error: clean does not remove each individual files in Makefile'  >> designResults.txt
fi




# fatal errors from here on

if [[ `awk '/#include/, /^{/' *.cpp *.h | egrep -v "\(|\)" | egrep "(void|int|char|double|float|Day|Calendar|Appointment|Time)" | wc -l ` -ne 0 ]] ; then
 echo 'Fatal design error: "Global variable found above first function/typedef in a file.'  >> designResults.txt
  (( ++ designError ))
fi

if [[ `awk '/^}/, /^{/' *.cpp *.h | egrep -v "\(|\)|^}" | egrep "(void|int|char|double|float|Plane|Flight)" | wc -l ` -ne 0 ]] ; then
 echo 'Fatal design error: "Global variable found between functions in a file.'  >> designResults.txt
  (( ++ designError ))
fi

if grep "goto" *.cpp *.h  &> /dev/null ; then
  echo 'Fatal design error: "goto" found in files.'  >> designResults.txt
  (( ++ designError ))
fi




echo $designError  # Only standard out

