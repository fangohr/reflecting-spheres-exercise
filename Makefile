CXX=clang++

bounce: bounce.cc
	${CXX} -ansi -pedantic -Wall -obounce bounce.cc

clean:
	rm -f bounce bounce.o

test:
	py.test -v 
