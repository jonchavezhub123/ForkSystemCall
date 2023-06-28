#
# PROGRAM: Lab Training Exercise
# AUTHOR:  Jonathan Chavez
#

CXXFLAGS = -Wall -Werror -std=c++11

forksystem: forksystem.o
	g++ $(CXXFLAGS) -o forksystem forksystem.o

forksystem.o: forksystem.cpp
	g++ $(CXXFLAGS) -c forksystem.cpp

clean:
	rm -f *.o forksystem


