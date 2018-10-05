#!  /bin/bash

testerDirectory="/home/ssdavis/40/p9/Testing"

if [ $# -ne 1 ]; then
  >&2 echo "usage DesignChecker.sh: $testerDirectory/DesignChecker.sh p9_directory "
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

grep "/\*" *.cpp *.h > temp
if [ -s temp ]; then
  cat temp >> designResults.txt
  echo 'Fatal design error: "/*" found.' >> designResults.txt
  (( ++designError ))
fi

if grep "#include *<" *.cpp *.h | egrep -v "(iostream|stdexcept|cassert|string|fstream|list)" >& /dev/null ; then
  echo 'Fatal design error: system header other than iostream, stdexcept, cassert' >> designResults.txt
  echo 'string, fstream, list found in directory.' >> designResults.txt
  (( +designError ))
fi

# non-fatal design errors from here on

if ! awk ' /class/, /^} *;/ ' stack.h | grep "list *< *T *>" >& /dev/null ; then
  echo '"list <T>" not found in stack.h.'  >> designResults.txt
fi

if ! awk ' /class/, /^} *;/ ' stack.h | grep "void push *(.*T" >& /dev/null ; then
  echo '"void push(...T" not found in stack.h.'  >> designResults.txt
fi

if ! awk ' /class/, /^} *;/ ' stack.h | grep "void pop *(.*T" >& /dev/null ; then
  echo '"void pop(...T" not found in stack.h.'  >> designResults.txt
fi

if ! awk ' /class *Queue/, /^} *;/ ' queue.h | grep "void push *(.*T" >& /dev/null ; then
  echo '"void push(...T" not found in queue.h.'  >> designResults.txt
fi

if ! awk ' /class *Queue/, /^} *;/ ' queue.h | grep "void pop *(.*T" >& /dev/null ; then
  echo '"void pop(...T" not found in queue.h.'  >> designResults.txt
fi

if ! awk ' /class *Queue/, /^} *;/ ' queue.h | grep "Queue *( *int" >& /dev/null ; then
  echo '"Queue(int" constructor not found in queue.h.'  >> designResults.txt
fi

if ! awk ' /class *Whoops/, /^} *;/ ' queue.h | grep "Whoops *( *const *string" >& /dev/null ; then
  echo '"Whoops(const string" not found in queue.h.'  >> designResults.txt
fi

if ! awk ' /class *Whoops/, /^} *;/ ' queue.h | grep "const *string *& *what*(" >& /dev/null ; then
  echo '"const string& what(" not found in queue.h.'  >> designResults.txt
fi

if ! awk ' /class *BST *$/, /^} *;/ ' BST.h | grep "void push *([a-z ]*T" >& /dev/null ; then
  echo '"void push(...T" not found in BST.h.'  >> designResults.txt
fi

if ! awk ' /class *BST *$/, /^} *;/ ' BST.h | grep "void pop *( *T[&a-zA-Z ]*)" >& /dev/null ; then
  echo '"void pop(...T...)" not found in BST.h.'  >> designResults.txt
fi

if ! awk ' /class *BST *$/, /^} *;/ ' BST.h | grep "void push *(.*T[&a-zA-Z ]*)" >& /dev/null ; then
  echo '"void push(...T...)" not found in BST.h.'  >> designResults.txt
fi

if ! awk ' /class *BST *$/, /^} *;/ ' BST.h | grep "void pop *(.*BSTNode *< *T *>" >& /dev/null ; then
  echo '"void pop(...BSTNode<T>" not found in BST.h.'  >> designResults.txt
fi

if ! awk ' /class *BST *$/, /^} *;/ ' BST.h | grep "void push *(.*BSTNode *< *T *>" >& /dev/null ; then
  echo '"void push(...BSTNode<T>" not found in BST.h.'  >> designResults.txt
fi


if ! awk ' /class *BST *$/, /^} *;/ ' BST.h | grep "BSTNode *< *T *> *\*root" >& /dev/null ; then
  echo '"BSTNode<T> *root" not found in BST.h.'  >> designResults.txt
fi

if ! grep "class *BSTNode" BST.h >& /dev/null ; then
  echo '"class BSTNode" not found in BST.h.'  >> designResults.txt
fi

echo $designError  # Only standard out

