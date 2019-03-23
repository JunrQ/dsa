obj = test.o vector.o

main : $(obj)
	g++ $(obj) -o main

test.o : test.cpp
	g++ -c -ggdb -std=c++11 test.cpp

vector.o : vector.cpp
	g++ -c -ggdb -std=c++11 vector.cpp

.PHONY:
clean :
	rm main $(obj)
