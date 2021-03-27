CC=g++
CCFLAGS=-std=c++2a
SOURCES=functions.cpp main.cpp
OBJECTS=functions.o main.o

#build rules
myprog: $(OBJECTS)
	$(CC) $(CCFLAGS) $(OBJECTS) -o driver.exe $(LIBS)

.cpp.o:
	$(CC) $(CCFLAGS) -c $<

depend:
	$(CC) -M $(SOURCES) > incl.defs

clean:
	rm -f *.o
	rm -f *.exe

run:
	./driver.exe
