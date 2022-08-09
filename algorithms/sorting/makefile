sorting.out: sorting.o
	g++ -o sorting.out sorting.o
sorting.o: selection_sort.cpp
	g++ -c -o sorting.o selection_sort.cpp
clean:
	rm -f sorting.out sorting.o