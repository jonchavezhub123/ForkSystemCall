#
# PROGRAM: Lab Training Exercise
# AUTHOR:  Jonathan Chavez
#

CXXFLAGS = -Wall -Werror -std=c++11

z1866268_project1: z1866268_project1.o
	g++ $(CXXFLAGS) -o z1866268_project1 z1866268_project1.o

z1866268_project1.o: z1866268_project1.cpp
	g++ $(CXXFLAGS) -c z1866268_project1.cpp

clean:
	rm -f *.o z1866268_project1


