#!/bin/zsh

for sort in sort1 sort2 sort3; do
  echo "$sort:" >> notes.txt

  for file in random*.txt sorted*.txt reversed*.txt; do
      echo -n "$file:" >> notes.txt
      { (time ./$sort $file > /dev/null) 2>&1 | awk '{print $(NF-1)}'; } >> notes.txt
   done

   echo "\n" >> notes.txt
done
