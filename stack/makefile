obj = test.o

main : $(obj)
	g++ $(obj) -o main

test.o : test.cpp
	g++ -c -ggdb -std=c++11 test.cpp

.PHONY:
clean : 
	rm main $(obj)