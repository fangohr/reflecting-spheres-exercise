CXX=clang++

bounce: bounce.cc screen.hh screen.o
	${CXX} -ansi -pedantic -Wall -g -obounce bounce.cc screen.o

screen.o: screen.cc screen.hh 
	${CXX} -ansi -pedantic -Wall -g -c screen.cc

clean:
	rm -f bounce bounce.o

test:
	py.test -v 
