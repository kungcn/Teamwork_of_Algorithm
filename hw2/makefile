cp: main.o read.o project.o close_pair_pivot.o
	g++ -o cp *.o

main.o: ./src/main.cpp ./src/header.h ./src/def.h
	g++ -o main.o -c -std=c++11 ./src/main.cpp

read.o: ./src/readFile.cpp ./src/readFile.h ./src/header.h ./src/def.h
	g++ -o read.o -c -std=c++11 ./src/readFile.cpp

project.o: ./src/project.cpp ./src/project.h ./src/header.h ./src/def.h
	g++ -o project.o -c -std=c++11 ./src/project.cpp

close_pair_pivot.o: ./src/close_pair_pivot.cpp ./src/close_pair_pivot.h ./src/def.h ./src/header.h
	g++ -o close_pair_pivot.o -c -std=c++11 ./src/close_pair_pivot.cpp

clean:
	rm *.o cp
