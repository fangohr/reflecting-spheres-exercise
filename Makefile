CXX=clang++

bounce: bounce.cc
	${CXX} -ansi -pedantic -Wall -g -obounce bounce.cc

clean:
	rm -f bounce bounce.o

test:
	py.test -v 
