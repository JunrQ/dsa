#---------------------------------------------------------------
# Data Structure and Algorithms
# ZhouJ
#---------------------------------------------------------------

ifndef CXX
CXX = g++
endif

INCPATH = -I./include -I./src
CFLAGS = -std=c++11 -O1 -ggdb -Wall -finline-functions $(INCPATH)

vector : tests/test_vector.cpp src/vector.cpp
	$(CXX) $(CFLAGS) $^ -o build/$@

list : tests/test_list.cpp src/list.cpp
	$(CXX) $(CFLAGS) $^ -o build/$@

stack : tests/test_stack.cpp
	$(CXX) $(CFLAGS) $^ -o build/$@

clean : 
	rm -rf build/*

