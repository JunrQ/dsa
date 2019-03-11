obj = main.o vector.o

main : $(obj)
	g++ $(obj) -o main

main.o : main.cpp
	g++ -c -ggdb -std=c++11 main.cpp

vector.o : vector.cpp
	g++ -c -ggdb -std=c++11 vector.cpp

.PHONY:
clean :
	rm main $(obj)
