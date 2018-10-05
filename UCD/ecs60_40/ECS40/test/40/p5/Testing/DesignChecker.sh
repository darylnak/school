#!  /bin/bash

testerDirectory="/home/ssdavis/40/p5/Testing"

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

if ! grep -v "//" calendar.h | grep "istream *& *operator *>> *( *istream *&.*, *Calendar *&.*) *;" >& /dev/null ; then
 echo 'Design error: Calendar extraction operator not found in calendar.h'  >> designResults.txt
fi

if ! awk '/operator *>>/,/^}/' calendar.cpp | grep "^} *// *operator *>>" >& /dev/null; then
 echo 'Design error: "} // operator >>" not found in calendar.cpp'  >> designResults.txt
fi


if  grep "readFile"  calendar.h >& /dev/null  ; then
 echo 'Design error: "readFile" found in calendar.h'  >> designResults.txt
fi


if ! grep -v "//" calendar.h | grep "Calendar *( *)" >& /dev/null ; then
 echo 'Design error: Calendar default contructor not found in calendar.h'  >> designResults.txt
fi

if  grep "create"  calendar.h >& /dev/null  ; then
 echo 'Design error: "create" found in calendar.h'  >> designResults.txt
fi

if ! grep -v "//" calendar.h | grep "~Calendar *( *)" >& /dev/null ; then
 echo 'Design error: Calendar destructor not found in calendar.h'  >> designResults.txt
fi

if  grep "destroy"   calendar.* >& /dev/null  ; then
 echo 'Design error: "destroy" found in calendar.*'  >> designResults.txt
fi



if  grep "destroy" day.* >& /dev/null  ; then
 echo 'Design error: "destroy" found in day.*'  >> designResults.txt
fi

if ! grep -v "//" day.h | grep "operator *< *(.*Day" >& /dev/null ; then
 echo 'Design error: operator< not found in day.h'  >> designResults.txt
fi

if ! awk '/operator *</,/^}/' day.cpp | grep "^} *// *operator *<" >& /dev/null; then
 echo 'Design error: "} // operator<" not found in day.cpp'  >> designResults.txt
fi

if ! awk '/operator *==/,/^}/' day.cpp | grep "^} *// *operator *==" >& /dev/null; then
 echo 'Design error: "} // operator==" not found in day.cpp'  >> designResults.txt
fi

if ! awk '/operator *= *\(/,/^}/' day.cpp | grep "^} *// *operator *=" >& /dev/null; then
 echo 'Design error: "} // operator=" not found in day.cpp'  >> designResults.txt
fi

if ! awk '/operator *<</,/^}/' day.cpp | grep "^} *// *operator *<<" >& /dev/null; then
 echo 'Design error: "} // operator<<" not found in day.cpp'  >> designResults.txt
fi

if ! awk '/operator *>>/,/^}/' day.cpp | grep "^} *// *operator *>>" >& /dev/null; then
 echo 'Design error: "} // operator>>" not found in day.cpp'  >> designResults.txt
fi

if  grep "lessThan" day.* >& /dev/null  ; then
 echo 'Design error: "lessThan" found in day.*'  >> designResults.txt
fi

if ! grep -v "//" day.h | grep "operator *== *(.*Day" >& /dev/null ; then
 echo 'Design error: operator== not found in day.h'  >> designResults.txt
fi

if  grep "equal" day.* >& /dev/null  ; then
 echo 'Design error: "equal" found in day.*'  >> designResults.txt
fi

if ! grep -v "//" day.h | grep "istream *& *operator *>> *( *istream *&.*, *Day *&.*) *;" >& /dev/null ; then
 echo 'Design error: extraction operator not found in day.h'  >> designResults.txt
fi

if  grep "read" day.* >& /dev/null  ; then
 echo 'Design error: "read" found in day.*'  >> designResults.txt
fi

if ! grep -v "//" day.h | grep "ostream *& *operator *<< *( *ostream *&.*,.*Day *&.*) *;" >& /dev/null ; then
 echo 'Design error: insertion operator not found in day.h'  >> designResults.txt
fi

if  grep "print" day.* >& /dev/null  ; then
 echo 'Design error: "print" found in day.*'  >> designResults.txt
fi

if ! grep -v "//" day.h | grep "Day *( *)" >& /dev/null ; then
 echo 'Design error: Day default constructor not found in day.h'  >> designResults.txt
fi

if ! grep -v "//" day.h | grep "Day *( *int .*int .*int.*)" >& /dev/null ; then
 echo 'Design error: Day "standard" constructor not found in day.h'  >> designResults.txt
fi

if  grep "create" day.* >& /dev/null  ; then
 echo 'Design error: "create" found in day.*'  >> designResults.txt
fi

if ! grep -v "//" day.h | grep "Day *& *operator *= *(.*Day *&.*)" >& /dev/null ; then
 echo 'Design error: Day overloaded assignment operator not found in day.h'  >> designResults.txt
fi

if ! grep -v "//" day.h | grep "operator *= *( *const.*)" >& /dev/null ; then
 echo 'Design error: "operator= (const ...)" not found in day.h'  >> designResults.txt
fi

if ! grep -v "//" day.h | grep "subjectSearch *( *const.*) *const" >& /dev/null ; then
 echo 'Design error: "subjectSearch(const ...) const" not found in day.h'  >> designResults.txt
fi

if ! grep -v "//" day.h | grep "operator *<< *(.*const *Day" >& /dev/null ; then
 echo 'Design error: "operator<< (...const Day" not found in day.h'  >> designResults.txt
fi


if ! awk '/operator *==/,/^}/' appt.cpp | grep "} *// *operator *==" >& /dev/null; then
 echo 'Design error: "} // operator==" not found in appt.cpp'  >> designResults.txt
fi

if ! awk '/operator *< *\(/,/^}/' appt.cpp | grep "} *// *operator *<" >& /dev/null; then
 echo 'Design error: "} // operator<" not found in appt.cpp'  >> designResults.txt
fi

if ! awk '/operator *<</,/^}/' appt.cpp | grep "} *// *operator *<<" >& /dev/null; then
 echo 'Design error: "} // operator<<" not found in appt.cpp'  >> designResults.txt
fi

if ! awk '/operator *>>/,/^}/' appt.cpp | grep "} *// *operator *>>" >& /dev/null; then
 echo 'Design error: "} // operator>>" not found in appt.cpp'  >> designResults.txt
fi

if ! grep -v "//" appt.h | grep "operator *< *(.*Appointment" >& /dev/null ; then
 echo 'Design error: operator< not found in appt.h'  >> designResults.txt
fi

if  grep "lessThan" appt.* >& /dev/null  ; then
 echo 'Design error: "lessThan" found in appt.*'  >> designResults.txt
fi

if ! grep -v "//" appt.h | grep "operator *== *(.*char *\*" >& /dev/null ; then
 echo 'Design error: operator== not found in appt.h'  >> designResults.txt
fi

if  grep "equal" appt.* >& /dev/null  ; then
 echo 'Design error: "equal" found in appt.*'  >> designResults.txt
fi

if ! grep -v "//" appt.h | grep "istream *& *operator *>> *( *istream *&.*, *Appointment *&.*) *;" >& /dev/null ; then
 echo 'Design error: extraction operator not found in appt.h'  >> designResults.txt
fi

if  grep "read" appt.* >& /dev/null  ; then
 echo 'Design error: "read" found in appt.*'  >> designResults.txt
fi

if ! grep -v "//" appt.h | grep "ostream *& *operator *<< *( *ostream *&.*,.*Appointment *&.*) *;" >& /dev/null ; then
 echo 'Design error: insertion operator not found in appt.h'  >> designResults.txt
fi

if  grep "print" appt.* >& /dev/null  ; then
 echo 'Design error: "print" found in appt.*'  >> designResults.txt
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

if  grep "create" appt.* >& /dev/null  ; then
 echo 'Design error: "create" found in appt.*'  >> designResults.txt
fi

if ! grep -v "//" appt.h | grep "~Appointment *( *)" >& /dev/null; then
 echo 'Design error: Appointment destructor not found in appt.h'  >> designResults.txt
fi

if  grep "destroy" appt.* >& /dev/null  ; then
 echo 'Design error: "destroy" found in appt.*'  >> designResults.txt
fi

if ! grep -v "//" appt.h | grep "static *int *count" >& /dev/null; then
 echo 'Design error: static count variable not found in appt.h'  >> designResults.txt
fi

if ! grep -v "//" appt.h | grep "static .*getCount *(" >& /dev/null; then
 echo 'Design error: static getCount not found in appt.h'  >> designResults.txt
fi

if ! grep -v "//" appt.h | grep "operator *== *( *const.*) *const" >& /dev/null; then
 echo 'Design error: "operator== (const ...) const" not found in appt.h'  >> designResults.txt
fi

if ! grep -v "//" appt.h | grep "operator *< *( *const.*) *const" >& /dev/null; then
 echo 'Design error: "operator< (const ...) const" not found in appt.h'  >> designResults.txt
fi

if ! grep -v "//" appt.h | grep "operator *<< *(.*, *const *Appointment" >& /dev/null; then
 echo 'Design error: "operator<< (...,const Appointment" not found in appt.h'  >> designResults.txt
fi




if ! awk '/operator *< *\(/,/^}/' time.cpp | grep "^} *// *operator *<" >& /dev/null; then
 echo 'Design error: "} // operator<" not found in time.cpp'  >> designResults.txt
fi

if ! awk '/operator *<</,/^}/' time.cpp | grep "} *// *operator *<<" >& /dev/null; then
 echo 'Design error: "} // operator<<" not found in time.cpp'  >> designResults.txt
fi

if ! awk '/operator *>>/,/^}/' time.cpp | grep "^} *// *operator *>>" >& /dev/null; then
 echo 'Design error: "} // operator>>" not found in time.cpp'  >> designResults.txt
fi

if ! grep -v "//" time.h | grep "operator *< *(.*Time" >& /dev/null ; then
 echo 'Design error: operator< not found in time.h'  >> designResults.txt
fi

if  grep "lessThan" time.* >& /dev/null  ; then
 echo 'Design error: "lessThan" found in time.*'  >> designResults.txt
fi

if ! grep -v "//" time.h | grep "istream *& *operator *>> *( *istream *&.*, *Time *&.*) *;" >& /dev/null ; then
 echo 'Design error: extraction operator not found in time.h'  >> designResults.txt
fi

if  grep "read" time.* >& /dev/null  ; then
 echo 'Design error: "read" found in time.*'  >> designResults.txt
fi

if ! grep -v "//" time.h | grep "ostream *& *operator *<< *( *ostream *&.*,.*Time *&.*) *;" >& /dev/null ; then
 echo 'Design error: insertion operator not found in time.h'  >> designResults.txt
fi

if  grep "print" time.* >& /dev/null  ; then
 echo 'Design error: "print" found in time.*'  >> designResults.txt
fi

if ! grep -v "//" time.h | grep "operator *< *( *const.*) *const" >& /dev/null; then
 echo 'Design error: "operator< (const ...) const" not found in time.h'  >> designResults.txt
fi

if ! grep -v "//" time.h | grep "operator *<< *(.*, *const *Time" >& /dev/null; then
 echo 'Design error: "operator<< (..., const Time" not found in time.h'  >> designResults.txt
fi




if ! awk '/operator *<</,/^}/' DayOfWeek.cpp | grep "^} *// *operator *<<" >& /dev/null; then
 echo 'Design error: "} // operator<<" not found in DayOfWeek.cpp'  >> designResults.txt
fi

if ! awk '/operator *>>/,/^}/' DayOfWeek.cpp | grep "^} *// *operator *>>" >& /dev/null; then
 echo 'Design error: "} // operator>>" not found in DayOfWeek.cpp'  >> designResults.txt
fi

if ! grep -v "//" DayOfWeek.h | grep "istream *& *operator *>> *( *istream *&.*, *DayOfWeek *&.*) *;" >& /dev/null ; then
 echo 'Design error: extraction operator not found in DayOfWeek.h'  >> designResults.txt
fi

if  grep "// .*read" DayOfWeek.* >& /dev/null  ; then
 echo 'Design error: "// read" found in DayOfWeek.*'  >> designResults.txt
fi

if ! grep -v "//" DayOfWeek.h | grep "ostream *& *operator *<< *( *ostream *&.*,.*DayOfWeek *&.*) *;" >& /dev/null ; then
 echo 'Design error: insertion operator not found in DayOfWeek.h'  >> designResults.txt
fi

if  grep "print" DayOfWeek.* >& /dev/null  ; then
 echo 'Design error: "print" found in DayOfWeek.*'  >> designResults.txt
fi

if ! awk '/operator *>>/,/^}/' DayOfWeek.cpp | grep -v "//" | grep "seekg" >& /dev/null; then
 echo 'Design error: seekg() not found in DayOfWeek extraction operator in DayOfWeek.cpp'  >> designResults.txt
fi



if ! awk '/operator *<</,/^}/' linkedlist.cpp | grep "^} *// *operator *<<" >& /dev/null; then
 echo 'Design error: "} // operator<<" not found in linkedlist.cpp'  >> designResults.txt
fi

if ! awk '/operator *=/,/^}/' linkedlist.cpp | grep "^} *// *operator *=" >& /dev/null; then
 echo 'Design error: "} // operator=" not found in linkedlist.cpp'  >> designResults.txt
fi

if ! awk '/operator *\[ *\].*const/,/^}/' linkedlist.cpp | grep "^} *//.*operator *\[ *\]" >& /dev/null; then
 echo 'Design error: "} // operator[]" not found for const[] in linkedlist.cpp'  >> designResults.txt
fi

if ! awk '/operator *\+=/,/^}/' linkedlist.cpp | grep "// *operator *+=" >& /dev/null; then
 echo 'Design error: "} // operator+=" not found in linkedlist.cpp'  >> designResults.txt
fi

if ! awk '/^LinkedList *:: *LinkedList/,/^}/' linkedlist.cpp | grep "// *LinkedList" >& /dev/null; then
 echo 'Design error: "} // LinkedList" not found in linkedlist.cpp'  >> designResults.txt
fi

if ! awk '/^LinkedList *:: *~LinkedList/,/^}/' linkedlist.cpp | grep "// *~LinkedList" >& /dev/null; then
 echo 'Design error: "} // ~LinkedList" not found in linkedlist.cpp'  >> designResults.txt
fi

if ! awk '/class *ListNode/,/^} *;/' linkedlist.h | grep -v "//" | grep "ostream *& *operator *<< *( *ostream *&.*,.*LinkedList *&.*) *;" >& /dev/null ; then
 echo 'Design error: insertion operator not found in ListNode class linkedlist.h'  >> designResults.txt
fi

if  awk '/class *ListNode/,/^} *;/' linkedlist.h | grep "public" >& /dev/null ; then
 echo 'Design error: "public" found in ListNode class in linkedlist.h'  >> designResults.txt
fi

if ! grep -v "//" linkedlist.h | grep "~ListNode" >& /dev/null ; then
 echo 'Design error: destructor not found in ListNode class in linkedlist.h'  >> designResults.txt
fi

if ! awk '/class *LinkedList/,/^} *;/' linkedlist.h | grep -v "//" | grep "ostream *& *operator *<< *( *ostream *&.*,.*LinkedList *&.*) *;" >& /dev/null ; then
 echo 'Design error: insertion operator not found in List class linkedlist.h'  >> designResults.txt
fi

if ! awk '/class *LinkedList/,/^} *;/' linkedlist.h | grep -v "//" | grep "find *(.*char" >& /dev/null ; then
 echo 'Design error: find method not found in List class linkedlist.h'  >> designResults.txt
fi

if ! awk '/class *LinkedList/,/^} *;/' linkedlist.h | grep -v "//" | grep "operator *= *(.*LinkedList" >& /dev/null ; then
 echo 'Design error: assignment operator not found in List class linkedlist.h'  >> designResults.txt
fi

if ! awk '/class *LinkedList/,/^} *;/' linkedlist.h | grep -v "//" | grep "LinkedList *( *)" >& /dev/null ; then
 echo 'Design error: default constructor not found in List class linkedlist.h'  >> designResults.txt
fi

if ! awk '/class *LinkedList/,/^} *;/' linkedlist.h | grep -v "//" | grep "~LinkedList *( *)" >& /dev/null ; then
 echo 'Design error: destructor not found in List class linkedlist.h'  >> designResults.txt
fi

if ! awk '/class *LinkedList/,/^} *;/' linkedlist.h | grep -v "//" | grep "operator *\[ *\] *( *int.*) *const" >& /dev/null ; then
 echo 'Design error: const version of operator[] not found in List class linkedlist.h'  >> designResults.txt
fi

if ! awk '/class *LinkedList/,/^} *;/' linkedlist.h | grep -v "//" | grep "operator *\[ *\] *( *int.*) *;" >& /dev/null ; then
 echo 'Design error: non-const version of operator[] not found in List class linkedlist.h'  >> designResults.txt
fi

if ! awk '/class *LinkedList/,/^} *;/' linkedlist.h | grep -v "//" | grep "operator *+= *(.*Appointment" >& /dev/null ; then
 echo 'Design error: operator+= not found in List class linkedlist.h'  >> designResults.txt
fi

if ! awk '/class *ListNode/,/^} *;/' linkedlist.h | grep "operator *<< *(.*, * const *LinkedList" >& /dev/null ; then
 echo 'Design error: "operator<< (..., const LinkedList" not found in ListNode class in linkedlist.h'  >> designResults.txt 
fi

if ! awk '/class *LinkedList/,/^} *;/' linkedlist.h | grep "operator *<< *(.*, * const *LinkedList" >& /dev/null ; then
 echo 'Design error: "operator<< (..., const LinkedList" not found in LinkedList class in linkedlist.h'  >> designResults.txt
fi

if ! grep -v "//" linkedlist.h | grep "find *( *const.*) *const" >& /dev/null; then
 echo 'Design error: "find (const ...) *const" not found in linkedlist.h'  >> designResults.txt
fi

if ! grep -v "//" linkedlist.h | grep "operator *= *( *const" >& /dev/null; then
 echo 'Design error: "operator= (const" not found in linkedlist.h'  >> designResults.txt
fi



if ! awk '/main *\(/, /^}/ ' main.cpp | grep -v "//" | grep "Appointment *:: *getCount *(" >& /dev/null; then
 echo 'Design error: static getCount() not called in main()'  >> designResults.txt
fi

if ! awk '/main *\(/, /^}/ ' main.cpp | grep -v "//" | grep ">> *calendar;" >& /dev/null; then
 echo 'Design error: Calendar extraction operator not called in main()'  >> designResults.txt
fi







if grep "malloc" *.cpp >& /dev/null ; then
 echo 'Design error: malloc found in at least one *.cpp.'  >> designResults.txt
fi

if grep "free" *.cpp >& /dev/null ; then
 echo 'Design error: "free" found in at least one *.cpp file.'  >> designResults.txt
fi



# fatal errors from here on

if awk '/operator *>>/,/^}/' DayOfWeek.cpp | grep "\[" >& /dev/null; then
 echo 'Fatal design error: Array found in DayOfWeek extraction operator in DayOfWeek.cpp'  >> designResults.txt
 (( ++ designError ))
fi

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

