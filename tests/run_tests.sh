#!/bin/bash

make -C ../

results=results/
exe=../bin/ppinterp

for test in $(ls *.pp)
do
{
  expected=$(cat $results$test)
  actual=$($exe $test)
  if [ "$actual" != "$expected" ]
    then 
      echo "Test $test failed"
      echo "Actual value: $actual"
      echo "Expected value: $expected"
    else
      echo "Test $test passed"
  fi
}
done