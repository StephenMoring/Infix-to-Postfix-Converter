## stephen moring

main.x : in2post.o
	g++ -o main.x in2post.o

in2post.o : in2post.cpp
	g++ -c -std=c++11 in2post.cpp

make clean :
	rm *.o
	rm main.x 
