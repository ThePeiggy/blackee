# the compiler: gcc for C program, define as g++ for C++
CC = g++

# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
CPPFLAGS  = -std=c++11

  # the build target executable:
TEST = test

all: clean test

test: test.cpp
	$(CC) $(CPPFLAGS) test.cpp card.cpp hand.cpp deck.cpp -o run/test

clean:
	$(RM) $(TEST)