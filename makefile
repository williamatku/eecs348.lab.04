prog: main.o matrix.o
	g++ -g -std=c++11 -Wall main.o matrix.o -o prog

dev:
	make prog
	./prog
	make clean
	
main.o: main.cpp matrix.h
	g++ -g -std=c++11 -Wall -c main.cpp

matrix.o: matrix.h matrix.cpp 
	g++ -g -std=c++11 -Wall -c matrix.cpp

clean:
	rm *.o prog
