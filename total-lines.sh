#!/bin/bash

total=0  # Initialize total variable

# Loop through each .cpp file in the directory ~/ese/DS/
for file in ~/ese/DS/*.cpp
do
  # Add the number of lines in each file to total
  total=$((total + $(wc -l < "$file")))
done

# Output the total number of lines
echo $total
