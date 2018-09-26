lab1: main.o determinant.o readMatrix.o
	g++ main.o determinant.o readMatrix.o -o lab1

main.o: main.cpp
	g++ -c main.cpp

determinant.o: determinant.cpp determinant.hpp
	g++ -c determinant.cpp

readMatrix.o: readMatrix.cpp readMatrix.hpp
	g++ -c readMatrix.cpp

clean:
	rm *.o lab1
