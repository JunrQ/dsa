#---------------------------------------------------------------
# Data Structure and Algorithms
# ZhouJ
#---------------------------------------------------------------

ifndef CXX
CXX = g++
endif

INCPATH = -I./include
CFLAGS = -std=c++11 -fPIC -O2 -ggdb -Wall -finline-functions $(INCPATH)

TAR = vector
OBJS = $(addprefix build/, $(addsuffix .o, $(TAR)))

vector : tests/test_vector.cpp build/vector.o
	$(CXX) -c $<
	$(CXX) -o build/vector build/vector.o

clean : 
	rm -rf build

build/%.o : src/%.cpp
	@mkdir -p $(@D)
	$(CXX) $(INCPATH) $(CFLAGS) -c $< -o $@

