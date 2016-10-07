swap: swap.cc
	c++ -ansi -pedantic -Wall  -MD -MP -o swap swap.cc 


valgrind:
	gcc -ansi -pedantic -Wall -g -o val valgrind.cc
	valgrind --leak-check=full ./val 
