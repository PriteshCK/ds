i=1
while read LINE; do
	echo "// $LINE" > "$i.cpp"
	echo "" >> "$i.cpp"
	((i++))
done < questions
