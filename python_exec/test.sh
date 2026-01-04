#!/bin/bash

echo starting test.sh
while read line
do
  echo "XXXX"
  echo $line
  if [[ $line = "q" ]]
  then
    echo "quitting"
    exit
  fi
done
