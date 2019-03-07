obj = main.o vector.o

test : $(obj)
	g++ -o $(obj)

main.o : test.cpp
	g++ -c -std=c++11 test.cpp

vector.o : vector.cpp
	g++ -c -std=c++11 vector.cpp

clean :
	rm test $(obj)