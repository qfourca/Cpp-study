cc=gcc
pp=g++

program=1-1


$(program) : $(program).cpp 
	$(pp) -o $@ $^
	
all :
	$(pp) -o $(program) $(program).cpp 
	./$(program)

after : 
	rm $(program)
	$(pp) -o $(program) $(program).cpp
	./$(program)

clean :
	rm -rf *.o	
