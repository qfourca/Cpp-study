cc=gcc
pp=g++

program=main
bincal=binCalculate
add=adder

$(program) : $(program).cpp 
	$(pp) -o $@ $^
	
all :
	$(pp) -o $(program) $(program).cpp $(bincal).cpp $(add).cpp Calculate.h
	./$(program)

after : 
	rm $(program)
	$(pp) -o $(program) $(program).cpp
	./$(program)

clean :
	rm -rf *.o	