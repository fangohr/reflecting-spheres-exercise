bounce: bounce.cc
	clang++ -ansi -pedantic -Wall -obounce bounce.cc

clean:
	rm -f bounce bounce.o
