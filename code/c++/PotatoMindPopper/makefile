CXX = g++

CXXFLAGS = -Wall -Wextra -Werror -pedantic -std=c++11 -g

OBJS =	\
		main.o \
		koffiebord.o \
		stapel.o \

all: main

main: $(OBJS)
	$(CXX) $(CXXFLAGS) -o main $(OBJS)

main.o: main.cc stapel.h koffiebord.h
	$(CXX) $(CXXFLAGS) -c main.cc

stapel.o: stapel.cc stapel.h koffiebord.h
	$(CXX) $(CXXFLAGS) -c stapel.cc

koffiebord.o: koffiebord.cc koffiebord.h
	$(CXX) $(CXXFLAGS) -c koffiebord.cc

clean:
	rm -f *.o main
