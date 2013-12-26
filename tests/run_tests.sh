#!/bin/bash

make -C ../

results=results/
exe=../bin/ppinterp

for test in $(ls *.pp)
do
{
  echo -n "Launching $test..."
  expected=$(cat $results$test)
  actual=$($exe $test)
  if [ "$actual" != "$expected" ]
    then 
      echo " failed"
      echo "Actual value: $actual"
      echo "Expected value: $expected"
    else
      echo " passed"
  fi
}
done