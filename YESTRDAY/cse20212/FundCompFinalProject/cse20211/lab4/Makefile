part2: part2main.o part2fn.o
	gcc -lm part2main.o part2fn.o -o part2

part2main.o: part2main.c part2fn.h
	gcc -lm -c part2main.c

part2fn.o: part2fn.c
	gcc -lm -c part2fn.c

clean:
	rm *.o part2 
