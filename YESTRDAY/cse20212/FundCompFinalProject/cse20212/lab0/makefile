all:	mortgage

mortgage: mortgage.o
	g++ mortgage.o -o mortgage

mortgage.o: mortgage.cpp mortgage.h
	g++ -c mortgage.cpp mortgage.h

clean:
		rm -f *.o mortgage
