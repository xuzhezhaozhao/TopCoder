#!/bin/bash

des=/home/xzz/.Desktop/Arena
begin="BEGIN CUT HERE"
end="END CUT HERE"

for sub in *.cpp; do
cp $sub $des/$sub.bak
sed "/$begin/, /$end/d" $des/$sub.bak > $des/$sub

done

exit 0
