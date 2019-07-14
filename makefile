# Name of the program
PROGRAM = Lab12

#Headers to include in compilation
HEADERS = card.cpp deck.cpp term.cpp SortingList.cpp sortingOperations.cpp lab12.cpp

# Name of the object files
OBJECTS = card.o deck.o term.o SortingList.o sortingOperations.o lab12.o

# Compiles the normal program 
$(PROGRAM): $(OBJECTS) 
	g++ -std=c++11 -o $@ $^
%.o: %.cpp $(HEADERS)
	g++ -std=c++11 -c $< -o $@

# Removes all the object files as well as the program and test program
clean:
	rm -i *.o $(PROGRAM) 
