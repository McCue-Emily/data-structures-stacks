stacks: postfix.o 
	g++ postfix.o -o postfix

postfix.o: postfix.cpp linkedstack.h node.h
	g++ -c postfix.cpp

clean:
	rm *.o stacks
